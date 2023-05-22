
#include <iostream>

using namespace std;
#define I 456788

/*
5 7
0 1 4
0 2 8
1 3 5
1 2 2
2 3 5
2 4 9
3 4 4
*/

int findminv(int distance[], bool visited[], int n)
{
    int minv = -1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && (minv == -1 || distance[i] < minv))
        {
            minv = i;
        }
    }
    return minv;
}

int main()
{
    int n, e;
    cin >> n >> e;

    int edges[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int f, s, w;
        cin >> f >> s >> w;
        edges[f][s] = w;
        edges[s][f] = w;
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<edges[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    cout << endl;

    int distance[n];
    bool visited[n];


    //initialize distance and visited
    for (int i = 0; i < n; i++)
    {
        distance[i] = I;
        visited[i] = false;
    }

    distance[0] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        //find minimum vertex
        int minv = findminv(distance, visited, n);

        visited[minv] = true;

        for (int j = 0; j < n; j++)
        {
            if (edges[minv][j] != 0 && !visited[j])
            {
                //relaxation
                int dist = distance[minv] + edges[minv][j];
                if (dist < distance[j])
                {
                    distance[j] = dist;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << " " << distance[i] << endl;
    }

    return 0;
}
