#include <iostream>
#define I 344678

using namespace std;

// needs: edges,set,included,result(t)
int edges[3][9] = {{1, 1, 2, 2, 3, 4, 4, 5, 5},
                   {2, 6, 3, 7, 4, 5, 7, 6, 7},
                   {25, 5, 12, 10, 8, 16, 14, 20, 18}};

int set[8];
int included[9] = {0};
int t[2][6];

// union opeartion on set
void unionop(int u, int v)
{
    if (set[u] < set[v])
    {
        set[u] = set[u] + set[v];
        set[v] = u;
    }
    else
    {
        set[v] = set[v] + set[u];
        set[u] = v;
    }
}

// find parent opeartion on set
int findop(int u)
{
    int x = u;
    int v = 0;
    while (set[x] > 0)
    {
        x = set[x];
    }
    while (u != x)
    {
        v = set[u];
        set[u] = x;
        u = v;
    }
    return x;
}

int main()
{

    int i = 0;
    int n = 7;
    int min = I;
    int k = -1;
    int u = 0;
    int v = 0;

    while (i < n - 1)
    {
        min = I;

        // find minimum edge and update min and store edegs in u and v
        for (int j = 0; j < 9; j++)
        {

            if (included[j] == 0 && edges[2][j] < min)
            {
                min = edges[2][j];
                k = j;
                u = edges[0][j];
                v = edges[1][j];
            }
        }

        // now upadte set and add the edges in result if they do not find cycle
        if (findop(u) != findop(v))
        {
            t[0][i] = u;
            t[1][i] = v;
            unionop(findop(u), findop(v));
            i++;
        }
        included[k] = 1;
    }

    // print the edeges
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout << t[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
