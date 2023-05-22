#include <iostream>
#define I 32767

using namespace std;



int main()
{
    int n;
    cin>>n;
    int cost [n][n] {
            {I, I, I, I, I, I, I, I},
            {I, I, 25, I, I, I, 5, I},
            {I, 25, I, 12, I, I, I, 10},
            {I, I, 12, I, 8, I, I, I},
            {I, I, I, 8, I, 16, I, 14},
            {I, I, I, I, 16, I, 20, 18},
            {I, 5, I, I, I, 20, I, I},
            {I, I, 10, I, 14, 18, I, I},
    };
    

    int near[n];
    int t[2][6];
    int min=23456;
    int u,v;


    //initialize near array to I
    for(int i=0;i<n;i++){
        near[i]=I;
    }
    

    //find minimum of the cost array
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(cost[i][j]<min){
                min=cost[i][j];
                u=i;v=j;
            }
        }
    }

    //update initial minimum edge to the result array and update the near array
    t[0][0]=u;
    t[0][1]=v;
    near[u]=near[v]=0;

    //Update the near array 
    for(int i=1;i<n;i++){
        if(cost[i][u]<cost[i][v] && near[i]!=0){
            near[i]=u;
        }
        else{
            near[i]=v;
        }
    }

    //now take a loop for remaining vertices
    int k=1;
    for(int i=1;i<n-1;i++){
        min=I;
        
        //find minimum in the near array
        for(int j=0;j<n;j++){
            if(near[j]!=0 && cost[j][near[j]]<min){
                min=cost[j][near[j]];
                k=j;
            }
        }

        //update the result(t)array 
        t[0][i]=k;
        t[1][i]=near[k];
        near[k]=0;

        //again update the near array
        for(int j=1;j<n;j++){
            if(near[j]!=0 && cost[j][k]<cost[j][near[k]]){
                near[j]=k;
            }
        }


    }

    //print the edeges
    for(int i=0;i<2;i++){
        for(int j=0;j<6;j++){
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}
