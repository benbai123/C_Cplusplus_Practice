
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/**
 * The eight queens puzzle is the problem of
 * placing eight chess queens on an 8กั8 chessboard
 * so that no two queens attack each other. 
 */

// define some values to shorten the code

// status message and params
// printf(statmsg, statparam); will become
// printf("there are %d queens in a %d x %d chessboard\n\n answer(s): \n\n", number_of_queens, number_of_queens, number_of_queens);
#define statmsg "there are %d queens in a %d x %d chessboard\n\n answer(s): \n\n"
#define statparam number_of_queens, number_of_queens, number_of_queens
// answer message and params
#define ansmsg "put col[%d] queen to row %d\n"
#define ansparam outIdx, col[outIdx]
int number_of_queens;  // n queens in nxn chessboard
                       // note: don't too large (ex, over 25)
int *col;  // chessboard
FILE *outptr; // output file
int cnt; // result count

// function to solve this problem
void queens( int currentCol );
// function to determing whether the status is valid
bool promising( int currentCol );

int main()
{

  cnt = 0;
  
  printf("please enter the number of queens:\n");
  scanf("%d", &number_of_queens);
  // col[0] not used, start from col[1]
  col = (int*) malloc ((number_of_queens+1)*sizeof(int));
  outptr = fopen("QueenSol.txt", "w" );

  printf(statmsg, statparam);
  fprintf(outptr, statmsg, statparam);
  // call function to solve problem
  // pass 0 into it but it will then start from 1
  queens( 0 );

  if (cnt == 0) {
     printf(" no result\n\n");
     fprintf(outptr, " no result\n\n");
  }
  fclose( outptr );
  free(col);

  system("PAUSE");
  return 0;
}

void queens( int currentCol )
{
 int row;    // row index to test
 int outIdx; // index for output result
 if( promising(currentCol) )  // if valid
 {
   if( currentCol == number_of_queens )  // output if at latest col
   {
     cnt++;
     for( outIdx = 1; outIdx <= number_of_queens; outIdx++ )
     {
       printf(ansmsg, ansparam);
       fprintf(outptr, ansmsg, ansparam);
     }
     printf("\n\n");
     fprintf(outptr, "\n\n");
   }

   // call function recursively if not latest col
   else
   {
     for(row = 1; row <= number_of_queens; row++ )  // test next col from row 1 to row n
     {
       col[currentCol + 1] = row;
       queens( currentCol + 1 );
     }
   }

 }
}

// check whether current stats is valid
bool promising( int currentCol )
{
  int idx = 1; // loop index
  bool isValid = true; // is valid? default to true


  // test whether previous queens will attack current queen
  while( (idx < currentCol) && isValid )
  {
    // found invalid status
    // in the same row
    // or diagonal
    if( (col[currentCol] == col[idx])
        || (abs( col[currentCol] - col[idx]) == currentCol - idx) )
    {
        isValid = false;  // set to invalid, stop loop
    }
    idx++;  // increase index and contiune

  }
  return isValid;
}
