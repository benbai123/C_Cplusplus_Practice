#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/**
 * A Hamiltonian path (or traceable path)
 * is a path in an undirected graph that
 * visits each vertex exactly once.
 * A Hamiltonian cycle (or Hamiltonian circuit) is
 * a Hamiltonian path that is a cycle.
 * From wiki: http://en.wikipedia.org/wiki/Hamiltonian_path
 */

// the number of nodes in the test graphic
int node_amount = 12;
// the number of Hamiltonian cycles
int hamiltonian_cycle_amount = 0;

// Graph Representation with nodes
// not use [0][x] and [x][0]
int graph_array[13][13] = {
                 0,0,0,0,0,0,0,0,0,0,0,0,0,
                 0,0,1,0,0,1,0,0,0,0,0,0,0,
                 0,1,0,1,0,0,0,1,1,0,0,0,0,
                 0,0,1,0,1,0,0,0,1,0,0,0,0,
                 0,0,0,1,0,1,0,0,0,1,0,0,0,
                 0,1,0,0,0,0,1,0,0,0,1,0,0,
                 0,0,0,0,0,1,0,1,0,0,0,1,0,
                 0,0,1,0,0,0,1,0,1,0,0,0,0,
                 0,0,1,1,0,0,0,1,0,1,0,0,0,
                 0,0,0,0,1,0,0,0,1,0,1,0,1,
                 0,0,0,0,0,1,0,0,0,0,0,1,0,
                 0,0,0,0,0,0,1,0,0,0,1,0,1,
                 0,1,0,0,0,0,0,0,0,1,0,1,0
                };

// the array store the result through recursive
int result_array[13] = {0};

/**
 * The function that find all Hamiltonian cycle
 * and output to console
 * param node_index: int, nth node in path
 */
void hamiltonian ( int node_index );
/**
 * The function that check whether current node
 * is valid in Hamiltonian cycle.
 */
bool promising ( int node_index );

int main()
{
  printf("\n");
  result_array[1] = 1;  // start from first node
  hamiltonian( 1 );  // start to find all Hamiltonian cycles recursively

  if( hamiltonian_cycle_amount == 0 )  // no Hamiltonian cycles found
   printf("\nThere is no Hamiltonian cycles in this graph\n\n");

  printf("\n");

  system("PAUSE");
  return 0;
}

void hamiltonian ( int node_index )
{
  int j, k;
  if( promising(node_index) )  // current node is valid in a Hamiltonian cycles
  {
     if( node_index == (node_amount) )  // at latest node
     {  hamiltonian_cycle_amount = 1;  // increase hamiltonian_cycle_amount
        printf(" v%d", result_array[1]);  // print out the result
        for( k = 2;k <= node_amount;k ++ )
          printf(" ¡÷ v%d", result_array[k]);
        printf("\n\n");
     }
     else  // not latest node
     {
        for( j = 2;j <= node_amount;j ++ )  // recursively scan from second node to latest node
        {
           result_array[node_index+1] = j; // store result
           hamiltonian( node_index+1 );  // call function recursively
        }
     }
  }

}

bool promising ( int node_index )
{
  int j, k;
  bool isValid = true; // default to valid

  j = 1;

  if (node_index == 1) // first node, valid
    isValid =  true;
  if( (node_index == (node_amount)) && (!graph_array[result_array[node_index]][result_array[1]]) )
     isValid =  false;  // latest node but not connected to first node, invalid

  else if( ( node_index > 1 ) && (!graph_array[result_array[node_index-1]][result_array[node_index]]) )
     isValid =  false;  // not connected between current node and previous node, invalid

  else
  {
    while( (j < node_index) && isValid)  // check all previous nodes
    {
       if( result_array[node_index] == result_array [j] )
         isValid = false;  // current point already in path, invalid
       j++;
    }
  }
  return isValid;  // return whether current node is valid
}
