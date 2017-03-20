import sqlite3
from flask import Flask, flash, redirect, render_template, request, session, url_for
from flask_session import Session
from passlib.apps import custom_app_context as pwd_context
from tempfile import gettempdir
from bs4 import BeautifulSoup
import requests
import datetime
from helpers import *

# configure application
app = Flask(__name__)
db_cash=0
# ensure responses aren't cached
if app.config["DEBUG"]:
    @app.after_request
    def after_request(response):
        response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
        response.headers["Expires"] = 0
        response.headers["Pragma"] = "no-cache"
        return response

# custom filter
app.jinja_env.filters["usd"] = usd

# configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = gettempdir()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# configure CS50 Library to use SQLite database

db = sqlite3.connect("finance.db")
c=db.cursor()
@app.route("/")
@login_required
def index():
    print("helllo.................................")
    if request.method=="POST" or request.method=="GET":
        print("if statement")
        rows = db.execute("SELECT cash FROM users WHERE username=?", (session["user_id"],))
        for row in rows:
            if row != None:
                cash = row[0]
        #return render_template("index.html")
        data = db.execute("SELECT * FROM details WHERE username=?", (session["user_id"],))

        print("............value of rows.....................")
        rows = data.fetchall()
    return render_template("index.html",cash=cash,rows=rows)
    #return apology("index")
@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    cash=0
    """Buy shares of stock."""
    if request.method=="GET" or request.method=="POST":
        print("helllo")
        rows=db.execute("SELECT cash FROM users WHERE username=?",(session["user_id"],))
        for row in rows:
            if row!=None:
                cash=row[0]
        print(cash)
        return render_template("buy.html",cash=cash)
    else:
        return render_template("buy.html")

@app.route("/checkprice",methods=["GET","POST"])
@login_required
def checkprice():
    required_cash=0
    cash=0
    remaining_cash=0
    if request.method == 'POST':
        print("1")
        share=request.form['sharename']
        quantity=int(request.form['q'])
        rows = db.execute("SELECT cash FROM users WHERE username=?", (session["user_id"],))
        for row in rows:
            if row != None:
                cash = row[0]
        sym_data = lookup(share)
        required_cash = sym_data["price"] *quantity
        if request.form['submit'] == 'CHECK PRICE':
            print("2")
            rows = db.execute("SELECT cash FROM users WHERE username=?", (session["user_id"],))
            for row in rows:
                if row != None:
                    cash = row[0]
            print(quantity)
            sym_data = lookup(share)
            required_cash = sym_data["price"] * int(quantity)
            return render_template("buy.html", cash=cash, required_cash=required_cash,share=share,quantity=quantity)
        elif request.form['submit'] == 'BUY':
            print("3")
            print(request.form['sharename'])
            print(required_cash)
            print(quantity)
            #c.execute("INSERT INTO stocks VALUES ('2006-01-05','BUY','RHAT',100,35.14)")
            now = datetime.datetime.now()
            time = now.strftime("%Y-%m-%d %H:%M")
            type=request.form['submit']
            print("Current date and time using str method of datetime object:")
            print(time)
            print(type)
            if cash>=required_cash:
                cash=cash-required_cash
                print(required_cash)
                print(cash)
                #db.execute("INSERT INTO details VALUES (username,share,price,quantity,time,tran_type)")
                db.execute("INSERT INTO detail(username,share,price,quantity,time,tran_type)VALUES(?,?,?,?,?,?)",
                           (session["user_id"],request.form['sharename'],sym_data["price"],quantity,time,type),)
                rows = db.execute("SELECT username,share,price,SUM(quantity),time,tran_type FROM detail WHERE username=? AND share=? GROUP BY share",
                                  (session["user_id"], request.form['sharename']))
                row = rows.fetchall()
                print("................group by.............")
                print(row[0][0], row[0][1], row[0][2], row[0][3], row[0][4], row[0][5])
                print(row)
                db.execute("DELETE FROM details WHERE username=? AND share=?",(session["user_id"],request.form['sharename'],))
                db.execute("INSERT INTO details(username,share,price,quantity,time,tran_type)VALUES(?,?,?,?,?,?)",
                               (row[0][0],row[0][1],row[0][2],row[0][3],row[0][4], row[0][5]))
                #db.execute("INSERT INTO details VALUES(?,?,?,?,?,?)"s6996639+6LO,0OLP
                db.execute("""UPDATE users SET cash = ? WHERE username= ? """,(cash,session["user_id"]))

                db.commit()
                return render_template("buy.html",cash=cash)
            else:
                return apology("insufficient balance")
    elif request.method == 'GET':
        return render_template('contact.html')
    #print(symbol_data.price)
    print(required_cash)
    return render_template("buy.html", cash=cash,required_cash=required_cash)
@app.route("/my-link/")
@login_required
def buy_database():
    print("...........................")
    print(request.form['avail_cash'])
    #cash=int(request.form['req_cash'])


@app.route("/history")
@login_required
def history():
    """Show history of transactions."""
    rows = db.execute("SELECT * FROM detail WHERE username=?", (session["user_id"],))
    rows1 = db.execute("SELECT * FROM details WHERE username=?", (session["user_id"],))
    return render_template("history.html",rows=rows,rows1=rows1)

@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in."""

    # forget any user_id
    session.clear()

    # if user reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username")

        # ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password")

        # query database for username
        #rows = db.execute("SELECT * FROM users WHERE username = :username", username=request.form.get("username"))
        rows=db.execute("SELECT * FROM users WHERE username=? and hash=?",(request.form['username'],request.form['password']))
        #rows= db.execute("SELECT * FROM users WHERE username = ?", (request.form['username'],))
        count=0
        db_user=""
        db_pass=""
        cash1=0
        for row in rows:
            if row!=None:
                count=1
            db_user=row[1]
            db_pass=row[2]
            cash1=row[3]
        #print(count)
        #print("....." +db_user)
        global cash
        cash=cash1
        print(cash)
        db.commit()
        # ensure username exists and password is correct
        if count==0:
            return apology("INVALID USER")

        #if len(rows) != 1 or not pwd_context.verify(request.form.get("password"), rows[0]["hash"]):
        ##if len(rows)
          #  return apology("invalid username and/or password")

        # remember which user has logged in
        session["user_id"] =db_user

        # redirect user to home page
        return redirect(url_for("index"))

    # else if user reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")

@app.route("/logout")
def logout():
    """Log user out."""

    # forget any user_id
    session.clear()

    # redirect user to login form
    return redirect(url_for("login"))

@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    print("qoute call ")
    if request.method=="GET":
        print("qoute run")
        return render_template("quote.html")
    elif request.method=="POST":
        print(request.form['symbol'])
        print("call back")
        symbol_data=lookup(request.form['symbol'])

        print(symbol_data)
        user = {'nickname': 'Miguel'}
        #"name": row[1],
        #"price": price,
        #"symbol": row[0].upper()
        return render_template('qouted.html',symbol_data=symbol_data)
        #return render_template("quote.html")
    else:
        print("else part of qoute")
        return apology("TODO")

@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user."""
    if request.method == "POST":
        print("hellooo...................")
        # ensure username was submitted
        if not request.form.get("user"):
            print("username")
            return apology("must provide username")
        # ensure password was submitted
        elif request.form['pass']=="":
            print("pass1")
            return apology("must provide password")
        elif request.form['pass']!=request.form['pass1']:
            print("pass2")
            return apology("Password Mismatch")

        # redirect user to home page
        db.execute("INSERT INTO users(username,hash)VALUES(?,?)",(request.form.get("user"),request.form.get("pass")))
        #user rows = data.fetchall()name=request.form['user'],password=request.form['pass'])
        db.commit()
        return redirect(url_for("index"))

    # else if user reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("register.html")
    ##return apology("login")

@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock."""
    i=0
    data = db.execute("SELECT share,SUM(quantity),price FROM details WHERE username=? GROUP BY share",
                      (session["user_id"],))
    rows = data.fetchall()
    for row in rows:
        if row != None:
            # share[i]=row[0]
            print(row[0])
            #print(row[1])
            #print(row[2])
    if request.method=="GET":

        return render_template("sell.html",rows=rows,count="gurvinder")

    if request.form['sell']=="sell":
        print(".............................")
        data = db.execute("SELECT share,SUM(quantity) FROM details WHERE username=? AND share=?",
                          (session["user_id"],request.form['share']))
        rows = data.fetchall()
        for row in rows:
            if row != None:
                # share[i]=row[0]
                print(row[0])
                #print(row[1])
        quant = row[1]-int(request.form['quant'])
        db.execute("""UPDATE details SET quantity=?,tran_type=? WHERE username= ? AND share=? """,
                 (quant,request.form['sell'], session["user_id"],request.form['share'],))
        db.commit()
        return render_template("sell.html")
        #db.execute("""UPDATE users SET cash = ? WHERE username= ? """, (cash, session["user_id"]))
        #db.commit()
    elif request.method=="GET":

        return render_template("sell.html",rows=rows,count="gurvinder")

    else:
        return apology("maffi")
@app.route("/page.html")
def page():
    return render_template("page.html")