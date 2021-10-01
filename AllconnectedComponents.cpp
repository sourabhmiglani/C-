#include<bits/stdc++.h>
using namespace std;
void DFS(vector<int>* edges,int n,int sv,bool* visited,vector<int> &f){
      f.push_back(sv);
      visited[sv] = 1;
      for(int i : edges[sv]){
       
          if(!visited[i]){
           DFS(edges,n,i,visited,f);
              
          }
      
      }
   
  
}
//Time Complexity->O(V+E)
void BFS(vector<int>* edges,int n,int sv,bool* &visited,vector<int> &f){
    f.push_back(sv);
    queue<int> q;
    q.push(sv);
    
    //cout<<"sv"<<sv<<"\n";
    while(q.size()!=0){
        int front = q.front();
        q.pop();
        visited[front] = 1;
        
        for(int i : edges[front]){
            if(visited[i] == 0){
                q.push(i);
                f.push_back(i);
                visited[i] = 1;
                //cout<<sv<<" "<<i<<"\n";
            }
        }
    }
}
void solve(){
      int n,e;
      cin>>n>>e;
    vector<int> edges[n+1];
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
         edges[f].push_back(s);
        edges[s].push_back(f);
    }
    bool* visited = new bool[n+1];
    for(int j=0;j<=n;j++)
        visited[j] = 0;
    //cout<<"1"<<"\n";
    for(int i=1;i<=n;i++){
      
        
       if(!visited[i]){
           vector<int> f;
           //cout<<"x"<<" ";
           BFS(edges,n,i,visited,f);
           sort(f.begin(),f.end());
           for(auto i:f)
            	cout<<i<<" ";
           cout<<"\n";
       } 
    }
     delete[] visited;
}
void add(vector<int> adj[],int f,int s){
    adj[f].push_back(s);
    adj[s].push_back(f);
}
int main(){
    
    // write your code here
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--){
  solve();
        
        
    }
    return 0;
}
