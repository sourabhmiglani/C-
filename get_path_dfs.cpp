#include<bits/stdc++.h>
using namespace std;
bool dfs(int** edges,bool* &visited,int v1,int v2,vector<int> &v,int n){
    visited[v1] = 1;
    if(v1 == v2){
        return true;
    }
    for(int i=0;i<n;i++){
        if(!visited[i] && edges[v1][i] ){
            v.push_back(i);
            visited[i] = 1;
            if(dfs(edges,visited,i,v2,v,n))
                return true;
            else{
                v.pop_back();
            }
           
        }
    }
    return false;
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
        int v1,v2;
        cin>>v1>>v2;
        bool* visited = new bool[n];
        for(int i=0;i<n;i++){
            visited[i] = 0;
        }
        vector<int> v;
        if(dfs(edges,visited,v1,v2,v,n)){
            reverse(v.begin(),v.end());
            for(auto i:v){
                cout<<i<<" ";
            }
            cout<<v1;
            cout<<"\n";
            
        }
    }
    return 0;
}