#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


/// Initialization of array's for Floyd-Warshall algorithm: D - main array of shortest ways between every 2 vertices,
/// pi - array of succesors which contains the number of next vertex in the shortest path.
int size = 5;
int** pi = new int*[size];
int** D = new int*[size];



void FloydWarshall(int** &D)
{
    for(int k=0;k<size;k++)
        {
        for(int i=0;i<size;i++)
        {
            for(int j=0;j<size;j++)
            {
                if(D[i][j] > (D[i][k]+D[k][j]))
                    pi[i][j] = pi[i][k];
                D[i][j] = min(D[i][j],(D[i][k]+D[k][j]));
            }
        }
}
}

/// Printing function which uses vector to create full shortest path between nodes
void printPath(int start, int end)
{
    if(start == end)
    {
        cout << start;
        return;
    }
    if(D[start][end] == 9999)
        return;
    vector<int> path;
    path.push_back(start);
    while(start != end)
    {
        start = pi[start][end];
        path.push_back(start);
    }
    for(int i=0;i<path.size();i++)
    {
        cout << path[i] << " ";
    }
}



int main()
{
///Array's filling (9999 - Weight of non-existent edges)
for(int i=0;i<size;i++)
    pi[i] = new int[size];
for(int i=0;i<size;i++)
    D[i] = new int[size];

D[0][0] = 0;
D[0][1] = 3;
D[0][2] = 8;
D[0][3] = 9999;
D[0][4] = -4;
D[1][0] = 9999;
D[1][1] = 0;
D[1][2] = 9999;
D[1][3] = 1;
D[1][4] = 7;
D[2][0] = 9999;
D[2][1] = 4;
D[2][2] = 0;
D[2][3] = 9999;
D[2][4] = 9999;
D[3][0] = 2;
D[3][1] = 9999;
D[3][2] = -5;
D[3][3] = 0;
D[3][4] = 9999;
D[4][0] = 9999;
D[4][1] = 9999;
D[4][2] = 9999;
D[4][3] = 6;
D[4][4] = 0;


for(int i=0;i<size;i++)
    for(int j=0;j<size;j++)
    {
        pi[i][j] = j;
    }
/// ///////////////////////////



/// FloydWarshall function call with array of elements D.
FloydWarshall(D);

for(int i=0;i<size;i++)
{
    for(int j=0;j<size;j++)
    {
        if(D[i][j] == 9999)
            cout << "oo" << " ";
        else
        cout<< D[i][j] << " ";

    }
cout << endl;
}
cout << endl << endl;

/// Printing function call
printPath(0,3);



/// Memory clearing
for(int i=0;i<size;i++)
    delete[] pi[i];
delete [] pi;
for(int i=0;i<size;i++)
    delete [] D[i];
delete [] D;
return 0;
}
