#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Sixteen.h>

using namespace std;



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