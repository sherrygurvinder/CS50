/**
 * fifteen.c
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

//#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
int move(int tile);
int won(void);
int get_int()
{       
    int n;
    scanf("%d",&n);
    return n;
}
int main(int argc,char* argv[])
{   
    int i,j,tile;
    // ensure proper usage
    if(argc!= 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (1)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (i = 0; i < d; i++)
        {
            for (j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        tile = get_int();
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    // TODO
    int i,j,temp=0,count=0;
    count=d*d;
    for(i=0;i<d;i++)
    {   
        for(j=0;j<d;j++)
        {  
            count--;
            board[i][j]=count;
            if(d%2==0)
            {   
                temp=board[i][j];
                if(temp==1)
                {
                    board[i][j]=board[i][j-1];
                    board[i][j-1]=temp;
                }
            }   
         }      
    } 
    board[i-1][j-1]='_';  
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    // TODO
    int i,j;
    for(i=0;i<d;i++)
    {
        for(j=0;j<d;j++)
        {    printf("\t");
            
            if(board[i][j]==95)
            {
                printf("%c",board[i][j]); 
            }
            else
            {
                printf("%d",board[i][j]);
            }
            
        }
        printf("\n");
    } 
    
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
int move(int tile)
{
    // TODO
    int i,j,flag=0;
    for(i=0;i<d;i++)
    {
        for(j=0;j<d;j++)
            {
               
                if(board[i][j]==tile)
                {
                    flag=1;
                    break; 
                }
            }
            if(flag==1)
            break;           
    }          
    printf(" \n tile %d",tile);
    if(board[i-1][j]==95)
    {
        board[i-1][j]=tile;
        board[i][j]=95;
        return 1;
    }
    else if(board[i+1][j]==95)
    {
        board[i+1][j]=tile;
        board[i][j]=95;
        return 1;
    }
    else if(board[i][j-1]==95)
    {
        board[i][j-1]=tile;
        board[i][j]=95;
        return 1;
    }
    else if(board[i][j+1]==95)
    {
        board[i][j+1]=tile;
        board[i][j]=95;
        return 1;
    }
    else
        return 0;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
int won(void)
{
    // TODO
    int i,j,flag=0,count=1;
    for(i=0;i<d;i++)
    {
        for(j=0;j<d;j++)
        {
            if(count==board[i][j]||board[d][d]==95)
            {
                flag=1;
            }
            else
            {
                flag=0;
            }
            count++;  
        }        
    }
    if(flag==1)
    {
        return 1;
    }       
    else
    {
        return 0;
    }        

}
