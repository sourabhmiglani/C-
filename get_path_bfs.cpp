#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int> m;
bool bfs(int** edges,bool* &visited,int v1,int v2,vector<int> &v,int n){
    queue<int> q;
    q.push(v1);
    visited[v1] = 1;
    v.push_back(v1);
    m[v1] = v1;
    while(q.size()!=0){
        int front = q.front();
        //cout<<front<<" ";
        q.pop();
        for(int i=0;i<n;i++){
            if(!visited[i] && edges[i][front] ==1){
                visited[i] = 1;
                m[i] = front;
                if(i == v2){
                    return true;
                }
                q.push(i);
                
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
        if(bfs(edges,visited,v1,v2,v,n)){
            int ans = v2;
            while(m[ans]!=ans){
               cout<<ans<<" ";
                ans = m[ans];
           }
           
            cout<<ans<<"\n";
            
        }
    }
    return 0;
}