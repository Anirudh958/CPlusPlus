#include <iostream>
#include <vector>
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
};
int main(){
    graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.printGraph();
    return 0;
}