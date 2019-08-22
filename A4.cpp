#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class sixteen
{
public:
  static const int SIZE=3;//represents the number of rows and columns the game board has.
  static const int WIN=16;// represents the number that must be in a tile in order to win.
  sixteen();// the default constructor, sets all the elements in board to 0 except for the top left and bottom left elements, will be set to the value of 2.
  void moveLeft();// slides all the tiles on each row to the left and combines two adjacent non zero tiles from left to right into one tile and set a value 2 in a random position.
  void moveRight();// slides all the tiles on each row to the right and combines two adjacent non zero tiles from right to left into one tile and set a value 2 in a random position.
  void moveUp(); //slides all the tiles on each column to the top and combines two adjacent non zero tiles from top to bottom into one tile and set a value 2 in a random position.
  void moveDown();// slides all the tiles on each column to the bottom and combines two adjacent non zero tiles from bottom to top into one tile and set a value 2 in a random position.
  int over() const;// it checks the status of the game and determines loss and win, otherwsie it returns continue.
  void output() const;// it outputs the game board on the screen after each move.

private:
  int board[SIZE][SIZE];//declared 2d array that represents the game board.
};


int main()
{
  sixteen board;
  char userinput;

  cout<< "Which direction would you like to move? (U, D, L, R): ";
  cin>> userinput;

  /* The following loop repromt the user to enter a valid letter and then calls the the right function according to the user's input and calls the over function to check the
  game status and  calls the output function. */
  while(userinput!= 'U' and userinput!= 'u' and userinput!= 'D' and userinput!= 'd' and userinput!='L' and userinput!= 'l' and userinput!= 'R' and userinput!= 'r' and cin.fail())
  {
    cout<< "Invalid move"<<endl;
    cout<< "Which direction would you like to move? (U, D, L, R): ";
    cin>> userinput;
  }

  while(userinput== 'U' or userinput== 'u' or userinput== 'D' or userinput== 'd' or userinput=='L' or userinput== 'l' or userinput== 'R' or userinput== 'r' or !cin.fail())
  {

    if(board.over()==1)
    {
      cout<<endl;
      cout<< " You Won"<< endl;
      break;
    }
    else if(board.over()==-1)
    {
      cout<<endl;
      cout<< " Game Over"<< endl;
      break;
    }

    if(userinput=='L' or userinput=='l')
    {

      board.moveLeft();
      board.output();

      if(board.over()==1)
      {
        cout<<endl;
        cout<< " You Won"<< endl;
        break;
      }
      else if(board.over()==-1)
      {
        cout<<endl;
        cout<< " Game Over"<< endl;
        break;
      }


    }

    if(userinput=='R' or userinput=='r')
    {

      board.moveRight();
      board.output();


      if(board.over()==1)
      {
        cout<<endl;
        cout<< " You Won"<< endl;
        break;
      }
      else if(board.over()==-1)
      {
        cout<<endl;
        cout<< " Game Over"<< endl;
        break;
      }


    }

    if(userinput=='U' or userinput=='u')
    {

      board.moveUp();
      board.output();

      if(board.over()==1)
      {
        cout<<endl;
        cout<< " You Won"<< endl;
        break;
      }
      else if(board.over()==-1)
      {
        cout<<endl;
        cout<< " Game Over"<< endl;
        break;
      }



    }

    if(userinput=='D' or userinput=='d')
    {

      board.moveDown();
      board.output();

      if(board.over()==1)
      {
        cout<<endl;
        cout<< " You Won"<< endl;
        break;
      }
      else if(board.over()==-1)
      {
        cout<<endl;
        cout<< " Game Over"<< endl;
        break;
      }



    }


    cout<< "Which direction would you like to move? (U, D, L, R): ";
    cin>> userinput;

    if(board.over()==1)
    {
      cout<<endl;
      cout<< " You Won"<< endl;
      break;
    }
    else if(board.over()==-1)
    {
      cout<<endl;
      cout<< " Game Over"<< endl;
      break;
    }


    while(userinput!= 'U' and userinput!= 'u' and userinput!= 'D' and userinput!= 'd' and userinput!='L' and userinput!= 'l' and userinput!= 'R' and userinput!= 'r' and cin.fail())
    {
      cout<< "Invalid move"<<endl;
      cout<< "Which direction would you like to move? (U, D, L, R): ";
      cin>> userinput;
    }
  }

  return 0;
}


// the follwoing is a constructor that assign values to the board.
sixteen::sixteen()
{
  board[0][0]=2;
  board[1][0]=0;
  board[2][0]=2;

  for(int i=0; i< SIZE; i++)
  {
    for(int j=1; j<SIZE; j++)
    {
      board[i][j]=0;

    }
  }

}
// the follwoing function moves everthing to the left and adds numbers that are a like and sets a value of 2 on a random postion.
void sixteen::moveLeft()
{
  srand(time(0));

  for(int i=0; i< SIZE; i++)
  {
    for(int j=0; j< SIZE; j++)
    {
      if (board[i][j] > 0)
      {

        if(board[i][j]==board[i][j-1] and j!=0)
        {
          board[i][j-1]+= board[i][j];
          board[i][j]=0;
          
        }

        if(board[i][j-2]==board[i][j] and board[i][j-1]==0 and j!=0 and j!=1)
        {
          board[i][j-2]+= board[i][j];
          board[i][j]=0;
        }

        if(board[i][j-1]==0 and board[i][j-2]!=0 and j!=0 and j!=1)
        {
          board[i][j-1]+=board[i][j];
          board[i][j]=0;
          
        }

        if(board[i][j-1]==0 and board[i][j-2]==0 and j!=0 and j!=1)
        {
          board[i][j-2]+= board[i][j];
          board[i][j]=0;
          
        }

        if(board[i][j-1]==0 and j!=0 and j!=2)
        {
          board[i][j-1]+= board[i][j];
          board[i][j]=0;

        }

      }
    }
  }

  int indexcolumn;
  int indexrow;
  int bug=0;

  for(int i=0; i<SIZE; i++)
  {
    for(int j=0; j<SIZE; j++)
    {
      if(board[i][j]!=0)
      {
        bug++;
        {
          if(bug==9)
          {
            return;
          }
        }
      }
    }
  }

  do
  {
    indexcolumn= rand() % SIZE;
    indexrow= rand() % SIZE;

    if(board[indexcolumn][indexrow]==0)
    {
      board[indexcolumn][indexrow]=2;
      break;
    }
  }
  while(true);

}

// the follwoing function moves everthing to the right and adds numbers that are a like and sets a value of 2 on a random postion.
void sixteen::moveRight()
{
  srand(time(0));

  for(int i=0; i< SIZE; i++)
  {
    for(int j=0; j< SIZE; j++)
    {

      if (board[i][j] > 0)
      {

        if(board[i][j]==board[i][j+1] and j!=2)
        {
          board[i][j+1]+= board[i][j];
          board[i][j]=0;

          if(board[i][j-1]>0 and board[i][j]==0 and j!=0)
          {
            board[i][j]+= board[i][j-1];
            board[i][j-1]=0;
          }
          
        }

        if(board[i][j+2]==board[i][j] and board[i][j+1]==0 and j!=2 and j!=1)
        {
          board[i][j+2]+= board[i][j];
          board[i][j]=0;
        }

        if(board[i][j+1]==0 and board[i][j+2]!=0 and j!=2 and j!=1)
        {
          board[i][j+1]+=board[i][j];
          board[i][j]=0;
          
        }

        if(board[i][j+1]==0 and board[i][j+2]==0 and j!=2 and j!=1)
        {
          board[i][j+2]+= board[i][j];
          board[i][j]=0;
          
        }

        if(board[i][j+1]==0 and j!=0 and j!=2)
        {
          board[i][j+1]+= board[i][j];
          board[i][j]=0;

          if(board[i][j-1]>0 and board[i][j]==0)
          {
            board[i][j]+= board[i][j-1];
            board[i][j-1]=0;
          }

        }

      }
      
    }
  }

  int indexcolumn;
  int indexrow;
  int bug=0;

  for(int i=0; i<SIZE; i++)
  {
    for(int j=0; j<SIZE; j++)
    {
      if(board[i][j]!=0)
      {
        bug++;
        {
          if(bug==9)
          {
            return;
          }
        }
      }
    }
  }

  do
  {
    indexcolumn= rand() % SIZE;
    indexrow= rand() % SIZE;

    if(board[indexcolumn][indexrow]==0)
    {
      board[indexcolumn][indexrow]=2;
      break;
    }
  }
  while(true);

}

// the follwoing function moves everthing to the top and adds numbers that are a like and sets a value of 2 on a random postion.
void sixteen::moveUp()
{

  srand(time(0));

  for(int i=0; i< SIZE; i++)
  {
    for(int j=0; j< SIZE; j++)
    {
      if (board[i][j] > 0)
      {

        if(board[i][j]==board[i-1][j] and i!=0)
        {
          board[i-1][j]+= board[i][j];
          board[i][j]=0;
          
        }

        if(board[i-2][j]==board[i][j] and board[i-1][j]==0 and i!=0 and i!=1)
        {
          board[i-2][j]+= board[i][j];
          board[i][j]=0;
        }

        if(board[i-1][j]==0 and board[i-2][j]!=0 and i!=0 and i!=1)
        {
          board[i-1][j]+=board[i][j];
          board[i][j]=0;
          
        }

        if(board[i-1][j]==0 and board[i-2][j]==0 and i!=0 and i!=1)
        {
          board[i-2][j]+= board[i][j];
          board[i][j]=0;
          
        }

        if(board[i-1][j]==0 and i!=0 and i!=2)
        {
          board[i-1][j]+= board[i][j];
          board[i][j]=0;

        }

      }
    }
  }


  int indexcolumn;
  int indexrow;
  int bug=0;

  for(int i=0; i<SIZE; i++)
  {
    for(int j=0; j<SIZE; j++)
    {
      if(board[i][j]!=0)
      {
        bug++;
        {
          if(bug==9)
          {
            return;
          }
        }
      }
    }
  }

  do
  {
    indexcolumn= rand() % SIZE;
    indexrow= rand() % SIZE;

    if(board[indexcolumn][indexrow]==0)
    {
      board[indexcolumn][indexrow]=2;
      break;
    }
  }
  while(true);


}

// the follwoing function moves everthing to the bottom and adds numbers that are a like and sets a value of 2 on a random postion.
void sixteen::moveDown()
{

  srand(time(0));

  for(int i=0; i< SIZE; i++)
  {
    for(int j=0; j< SIZE; j++)
    {

      if (board[i][j] > 0)
      {

        if(board[i][j]==board[i+1][j] and i!=2)
        {
          board[i+1][j]+= board[i][j];
          board[i][j]=0;

          if(board[i-1][j]>0 and board[i][j]==0 and i!=0)
          {
            board[i][j]+= board[i-1][j];
            board[i-1][j]=0;
          }
          
        }

        if(board[i+2][j]==board[i][j] and board[i+1][j]==0 and i!=2 and i!=1)
        {
          board[i+2][j]+= board[i][j];
          board[i][j]=0;
        }

        if(board[i+1][j]==0 and board[i+2][j]!=0 and i!=2 and i!=1)
        {
          board[i+1][j]+=board[i][j];
          board[i][j]=0;
          
        }

        if(board[i+1][j]==0 and board[i+2][j]==0 and i!=2 and i!=1)
        {
          board[i+2][j]+= board[i][j];
          board[i][j]=0;
          
        }

        if(board[i+1][j]==0 and i!=0 and i!=2)
        {
          board[i+1][j]+= board[i][j];
          board[i][j]=0;

          if(board[i-1][j]>0 and board[i][j]==0)
          {
            board[i][j]+= board[i-1][j];
            board[i-1][j]=0;
          }
        }

      }
      
    }
  }

  int indexcolumn;
  int indexrow;
  int bug=0;

  for(int i=0; i<SIZE; i++)
  {
    for(int j=0; j<SIZE; j++)
    {
      if(board[i][j]!=0)
      {
        bug++;
        {
          if(bug==9)
          {
            return;
          }
        }
      }
    }
  }

  do
  {
    indexcolumn= rand() % SIZE;
    indexrow= rand() % SIZE;


    if(board[indexcolumn][indexrow]==0)
    {
      board[indexcolumn][indexrow]=2;
      break;
    }
  }
  while(true);


}

// the following function checks the game status and return a value accordingly.
int sixteen::over() const
{
  int check=0;

  for(int i=0; i<SIZE; i++)
  {
    for(int j=0; j<SIZE; j++)
    {
      if( board[i][j]==16)
      {
        return 1;
      }
    }
  }


  for(int i=0; i<SIZE; i++)
  {
    for(int j=0; j<SIZE; j++)
    {
      if(board[i][j]!=board[i][j-1] and board[i][j]!= board[i][j+1] and board[i][j]!= board[i-1][j] and board[i][j]!=board[i+1][j] and board[i][j]!=0)
      {
        check++;
        if(check==9)
        {
          return -1;
        }
      }

      else
      {
        return 0;
      }
    }
  }

}

// the following outputs the board on the screen when its called.
void sixteen::output() const
{

  for(int i=0; i<SIZE; i++)
  {
    for(int j=0; j<SIZE; j++)
    {
      if(board[i][j]==0)
        cout<< "- ";
      else
        cout<<board[i][j]<< " ";
    }
    cout<< endl;
  }

}