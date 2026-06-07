#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class graph{
    public:
        int v;
        vector<vector<int>> adj;
        graph(int vertices){
            v=vertices;
            adj.resize(v);
        }
        void addEdge(int u, int v,bool directed=false){
            adj[u].push_back(v);
            if(!directed){
                adj[v].push_back(u);
            }
        }
        void printGraph(){
            for(int i=0;i<v;i++){
                cout<<"Vertex "<<i<<": ";
                for(int num: adj[i]){
                    cout<<num<<" ";
                }
                cout<<endl;
            }
        }
        void DFS(int start,vector<bool>& visited){
            visited[start]=true;
            cout<<start<<" ";
            for(int neighbour: adj[start]){
                if(!visited[neighbour]){
                    DFS(neighbour,visited);
                }
            }
        }
        void BFS(int start){
            vector<bool> visited;
            visited.resize(v,false);
            queue<int> q;
            visited[start]=true;
            q.push(start);
            while(!q.empty()){
                int current=q.front();
                q.pop();
                cout<<current<<" ";
                for(int neighbour: adj[current]){
                    if(!visited[neighbour]){
                        visited[neighbour]=true;
                        q.push(neighbour);
                    }
                }
            }
        }
};
int main(){
    graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.printGraph();
    int v=4;
    cout<<"DFS traversal starting from vertex 0: ";
    vector<bool> visited(v, false);
    g.DFS(0, visited);
    cout<<endl;
    cout<<"BFS traversal starting from vertex 0: ";
    g.BFS(0);
    cout<<endl;
    return 0;
}