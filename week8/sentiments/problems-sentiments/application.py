from flask import Flask, redirect, render_template, request, url_for
import os
import sys
import nltk

import helpers
from analyzer import Analyzer

app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/search")
def search():

    # validate screen_name
    screen_name = request.args.get("screen_name", "").lstrip("@")
    if not screen_name:
        return redirect(url_for("index"))

    # get screen_name's tweets
    tweets = helpers.get_user_timeline(screen_name,100)

    positive, negative, neutral = 0.0, 0.0, 0.0

    positives = os.path.join(sys.path[0], "positive-words.txt")
    negatives = os.path.join(sys.path[0], "negative-words.txt")
    analyzer = Analyzer(positives, negatives)

    for tweet in tweets:
        tokenizer = nltk.tokenize.TweetTokenizer()
        tokens = tokenizer.tokenize(tweet)
        for token in tokens:
            score = analyzer.analyze(token)

        print(tweet)
        if score > 0.0:
            positive=positive+1
        elif score < 0.0:
            negative=negative+1
        else:
            neutral=neutral+1

        analyzer.count = 0

    # generate chart
    chart = helpers.chart(positive, negative, neutral)

    # render results
    return render_template("search.html", chart=chart, screen_name=screen_name)
