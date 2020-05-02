#include <iostream>
#include <list> 
using namespace std;

// Returning (boolean) connectivity (whether or not dest can be reached from src)
bool bfs(list<int>* adjList, int src, int dest, int n){
    list<int> queue;
    bool* visited = new bool[n + 1];
    for(int i = 0; i < n + 1; i++){
        visited[i] = false;
    }

    queue.push_back(src);
    visited[src] = true;

    list<int>::iterator i; 

    while(!queue.empty()){
        int adjNode = queue.front();
        queue.pop_front();

        if(adjNode == dest){
            return true;
        }

        for(i = adjList[adjNode].begin(); i != adjList[adjNode].end(); ++i){ 
            if(!visited[*i]){ 
                queue.push_back(*i);
                visited[*i] = true; 
            }
        }
    }
    return false;
}

int main (){
    // Gathering input and building adjacency matrix
    int n, m;
    cin >> n >> m;

    list<int>* adj = new list<int>[n + 1];
    
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    int p, q;
    cin >> p >> q;

    // Printing output
    if(bfs(adj, p, q, n)){
        cout << "yes";
    }
    else if(bfs(adj, q, p, n)){
        cout << "no";
    }
    else{
        cout << "unknown";
    }
}