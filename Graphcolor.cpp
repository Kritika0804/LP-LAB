#include <iostream>
#include<map>

using namespace std;

int main()
{
    int n;
    cout<<"Enter the total number of vertices :- ";
    cin>>n;
    
    int graph[n][n];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            graph[i][j]=0;
        }
    }
    
    int e;
    cout<<"Enter the total number of edges :- ";
    cin>>e;
    cout<<"Enter the edges :- \n";
    int x,y;
    for(int i = 0 ; i < e ; i++){
        cin>>x>>y;
        graph[x][y] = 1;
        graph[y][x] = 1;
    }
    
    int result[n];
    bool availble[n];
    
   
    
    for(int i=0;i<n;i++){
        result[i]=-1;
        availble[i]=false;
    }
    
    result[0]=0;
    
    for(int i=1;i<n;i++){
        
        for(int j=0;j<n;j++){
            if(graph[i][j]!=0 && result[j]!=-1){
                availble[result[j]]=true;
            }
        }
        
        int index;
        for(index=0;index<n;index++){
            if(!availble[index]){
                break;
            }
        }
        result[i]=index;
        
        for(int j=0;j<n;j++){
            if(graph[i][j]!=0 && result[j]!=-1){
                availble[j]=false;
            }
        }
        
        
    }
    
    map<int,string>m;
        m[0] = "red";
        m[1] = "green";
        m[2] = "voilet";
        m[3] = "blue";
        m[4] = "yellow";
        m[5] = "orange";
        m[6] = "white";
        m[7] = "black";
        
        for(int i = 0 ; i < n ; i++){
        cout<<"The color of the vertex "<<i<<" is "<<m[result[i]]<<endl;
        }
        

    return 0;
}