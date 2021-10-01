#include<bits/stdc++.h>
using namespace std;
void traversedfs(int** edges,bool* visited,int n,int s){
    visited[s] = 1;
    for(int i=0;i<n;i++){
        if(!visited[i] && edges[i][s] == 1){
            traversedfs(edges,visited,n,i);
        }
    }
}
int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
    int n,e;
    cin>>n>>e;
        int**  edges = new int*[n];
        for(int i=0;i<n;i++){
            edges[i] = new int[n];
            for(int j=0;j<n;j++){
                edges[i][j] = 0;
            }
        }
        for(int i=0;i<e;i++){
            int f,s;
            cin>>f>>s;
            edges[s][f] = 1;
            edges[f][s] = 1;
        }
        bool* visited = new bool[n];
        for(int i=0;i<n;i++){
            visited[i] = 0;
        }
        int c = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(c==1){
                    c++;
                    break;
                }
                traversedfs(edges,visited,n,i);
                c++;
            }
        }
        if(c==1){
            cout<<"true"<<"\n";
        }
        else{
            cout<<"false"<<"\n";
        }
       
    }
    return 0;
}