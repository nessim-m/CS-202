#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Sixteen.h>

using namespace std;

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