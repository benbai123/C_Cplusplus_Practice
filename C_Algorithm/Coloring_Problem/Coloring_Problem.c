#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * Graph coloring
 * Coloring the vertices of a graph such that
 * no two adjacent vertices share the same color;
 * Wiki: http://en.wikipedia.org/wiki/Graph_coloring
 */

FILE *res;

// The 2-D array denotes a graph adjacent status,
// For example, [a, b] are adjacent vertices,
// [a, d] are also adjacent vertices.
// the index starts from 1,
// [0][x] and [x][0] are not considered
                           // #,a,b,c,d,e,f
int _adjacentMatrix [7][7] = {0,0,0,0,0,0,0, // not use
               0,0,1,0,1,0,0, // a
               0,1,0,1,0,1,0, // b
               0,0,1,0,0,0,1, // c
               0,1,0,0,0,1,0, // d 
               0,0,1,0,1,0,1, // e
               0,0,0,1,0,1,0  // f
              };

int _verticeAmount = 6;  // six points

// three colors
char _colors[4][20] = { "NULL",
                      "RED",
                      "GREEN",
                      "WHITE"
                      };

// temp store the result
int _result[7] = {0};

void m_coloring( int i );
bool promising( int i );

int main()
{
  res = fopen("result.txt", "w");
  printf("there are %d vertices, the color combinations are as below: \n\n", _verticeAmount);
  fprintf(res, "there are %d vertices, the color combinations are as below: \n\n", _verticeAmount);
  m_coloring( 0 );
  fclose( res );



      system("PAUSE");
      return 0;
}

/**
 * The coloring function that will recursively create different combinations
 * then call promising function to test whether the combination is valid.
 *
 * Three actions:
 *         Output the result if
 *         the current combination is valid and reach the latest vertice.
 *         
 *         Continue add color - vertice to extend combination if
 *         the current combination is valid but not reach the latest vertice.
 *
 *         Terminate the recursive to skip any combination
 *         that starts with the current combination if
 *         the current combination is not valid.
 *
 */
void m_coloring ( int i )
{
  int color; // color index for test
  int j; // index for output result

  if( promising(i) )  // coloring success
  {
    if( i == _verticeAmount ) // is latest vertice
    {
      for( j = 1;j <= _verticeAmount;j ++ )  // output the result
      {
        if (j > 1) {
          printf(",");
          fprintf(res, ", ");
        }
        printf("%s", _colors[_result[j]]);
        fprintf(res, "%s", _colors[_result[j]]);
      }
      printf("\n\n");
      fprintf(res, "\n\n");

    }

    else  // not latest vertice
    {
       for( color = 1;color <= 3;color ++ )  // test each color
       {
          _result[i+1] = color;  // set color to next vertice
          m_coloring(i+1); // recursive to continue combination
       }
    }
  }
}

/**
 * check whether has adjacent virtice share color with current virtice
 * return bool
 * true: no adjacent vertice share the same color, can 
 * continue this combination
 * false: has adjacent vertice share the same color,
 * this combination should be terminated
 */
bool promising( int currentVerticeIndex )
{
   int j = 1; // start from first virtice
   bool sw = true;  // default to success (no two adjacent vertices share the same color)

   while( (j < currentVerticeIndex) && sw)  // scan all previous vertices
   {
      // if found an adjacent vertice share the same color
      if( _adjacentMatrix[currentVerticeIndex][j] && (_result[currentVerticeIndex] == _result[j])) {
        sw = false;  // set to fail (has two adjacent vertices share the same color)
        break;
      }
      j++;
   }

   return sw;  // return the result (success or fail)
}
