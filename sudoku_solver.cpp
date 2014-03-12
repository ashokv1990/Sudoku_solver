#include <iostream>
#include <vector>
#include<list>
#include <queue>
#include<map>

#include "limits.h"

#ifndef RC_DEBUG
//#define RC_DEBUG
#endif

#define gridsize 9
#define matrixsize 3

bool sudokusolver(int arr[][gridsize] , int i , int j);

void sudoku(int arr[][gridsize])
{
    std::cout << "calling sudoku solver" << '\n';
    sudokusolver(arr , 0 , 0);
    
}

bool checkvalidity(int arr[gridsize][gridsize] , int row , int col , int val)
{
  
    
    for(int r = 0 ; r < gridsize ; r ++)
    {
        
        if(arr[r][col] == val)
        {
            return false;
        }
    }
    
    for(int c = 0 ; c < gridsize ; c ++)
    {
        if(arr[row][c] == val)
        {
            return false;
        }
    }
    
    for(int i = row - row % matrixsize ;  i < row - row % matrixsize + matrixsize ; i ++)
    {
      for(int j= col - col % matrixsize ;  j < matrixsize + col- col % matrixsize ; j ++)
      {
          
          if(arr[i][j] == val)
          {
              return false;
          }
      }
    }
    
    return true;
}
bool sudokusolver(int arr[gridsize][gridsize] , int i , int j)
{
    if( i == gridsize)
    {
        i = 0;
      
        if(++j == gridsize)
        {
            std::cout << "Returning true" << std::endl;
            for(int a = 0 ; a <gridsize ; a ++)
            {
                for(int b =0 ; b <gridsize ; b++)
                {
                    std::cout << arr[a][b] << '\t';
                   
                }
                
                
                
                std::cout << std::endl;
            }
            
            return true;
        }
       
    }
    
  
    for (int c = 1 ; c <= 9 ; c++)
    {
        if(checkvalidity(arr , i , j , c))
        {
            
            arr[i][j] = c;
            
            if(sudokusolver(arr , i + 1 , j ))
            {
                return true;
            }
        }
        //std::cout << i<<":"<<j;
     
        
    }
    
   arr[i][j] = 0;
   return false;
}

int main(int argc , char ** argv)
{
     int arr[gridsize][gridsize] ;
     sudoku(arr);
    return 0;
}
