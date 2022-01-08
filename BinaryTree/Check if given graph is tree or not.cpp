#include<iostream>
#include<list>
using namespace std;

class Graph{
    int V; // no of vertices
    list<int> *adj; // pointer to a DLL for adjacency lists
    bool isCyclic(int v,bool visited[],int parent);
public:
    Graph(int V){
        this->V=V;
        adj=new list<int>[V];
    }

    void addEdge(int v,int w){
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    bool isTree();
};

int main(){
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.isTree()? cout << "Graph is Tree\n":
                 cout << "Graph is not Tree\n";
 
    Graph g2(5);
    g2.addEdge(1, 0);
    g2.addEdge(0, 2);
    g2.addEdge(2, 1);
    g2.addEdge(0, 3);
    g2.addEdge(3, 4);
    g2.isTree()? cout << "Graph is Tree\n":
                 cout << "Graph is not Tree\n";
 
    return 0;
}



// Functions to check if there is loop in an undirected graph and also to check if it is a tree or not.

bool Graph::isCyclic(int v,bool visited[],int parent){
    visited[v]=true;

    list<int>::iterator i;
    for(i=adj[v].begin();i!=adj[v].end();i++){
        if(!visited[*i]){
            if(isCyclic(*i,visited,v))
                return true;
        }
        else if(*i != parent)
            return true;
    }

    return false;
}

bool Graph::isTree(){
    bool *visited=new bool[V];
    for(int i=0;i<V;i++)
        visited[i]=false;

    if(isCyclic(0,visited,-1))
        return false;

    for(int u=0;u<V;u++)
        if(!visited[u])
            return false;

    return true;
}
