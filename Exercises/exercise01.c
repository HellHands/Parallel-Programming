/* Description of the content of the file and important remarks. *
 * File: <exercise01.c>                Author:  <Prithvi Raj Moorani>
 * Date: <20 October 2017>                     Version: <01>
 */

#include <stdio.h>
 
int main (void)
{
  int P = 4;
	int Q = 6;
	int R = 8;
	int a[P][Q], b[Q][R], c[P][R];
	int sum;

	a[0][0]=1;
	a[0][1]=2;
	a[0][2]=3;
	a[0][3]=4;
	a[0][4]=5;
	a[0][5]=6;

	a[1][0]=1;
	a[1][1]=2;
	a[1][2]=3;
	a[1][3]=4;
	a[1][4]=5;
	a[1][5]=6;

	a[2][0]=1;
	a[2][1]=2;
	a[2][2]=3;
	a[2][3]=4;
	a[2][4]=5;
	a[2][5]=6;

	a[3][0]=1;
	a[3][1]=2;
	a[3][2]=3;
	a[3][3]=4;
	a[3][4]=5;
	a[3][5]=6;

	b[0][0]=1;
	b[0][1]=2;
	b[0][2]=3;
	b[0][3]=4;
	b[0][4]=5;
	b[0][5]=6;
	b[0][6]=7;
	b[0][7]=8;

	b[1][0]=1;
	b[1][1]=2;
	b[1][2]=3;
	b[1][3]=4;
	b[1][4]=5;
	b[1][5]=6;
	b[1][6]=7;
	b[1][7]=8;

	b[2][0]=1;
	b[2][1]=2;
	b[2][2]=3;
	b[2][3]=4;
	b[2][4]=5;
	b[2][5]=6;
	b[2][6]=7;
	b[2][7]=8;

	b[3][0]=1;
	b[3][1]=2;
	b[3][2]=3;
	b[3][3]=4;
	b[3][4]=5;
	b[3][5]=6;
	b[3][6]=7;
	b[3][7]=8;

	b[4][0]=1;
	b[4][1]=2;
	b[4][2]=3;
	b[4][3]=4;
	b[4][4]=5;
	b[4][5]=6;
	b[4][6]=7;
	b[4][7]=8;

	b[5][0]=1;
	b[5][1]=2;
	b[5][2]=3;
	b[5][3]=4;
	b[5][4]=5;
	b[5][5]=6;
	b[5][6]=7;
	b[5][7]=8;
	
	printf ("Array A!\n");
	for (int i = 0; i < P; i++)
	{
		for (int j = 0; j < Q; j++){
			printf ("%d \t", a[i][j]);
		}		
		printf ("\n\n");
	}
	
	printf ("Arraz B!\n");
	for (int i = 0; i < Q; i++)
	{
		for (int j = 0; j < R; j++){
			printf ("%d \t", b[i][j]);
		}		
		printf ("\n\n");
	}

	for (int row = 0; row < P; row++)
	{
		for (int col = 0; col < R; col++)
		{
		    sum = 0;
		    
		    for (int i=0; i<Q; i++)
		    {
					sum += a[row][i] * b[i][col];
		    }
		    
		    c[row][col] = sum;
		}
	}

	printf ("Arraz C!\n");
	for (int i = 0; i < P; i++)
	{
		for (int j = 0; j < R; j++){
			printf ("%d \t", c[i][j]);
		}		
		printf ("\n\n");
	}
	printf ("\n");
 
  return 0;
}