#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <queue>
// Switch DEBUG to false if you don't want to print the factors
#define DEBUG false

using namespace std;

int M, N;
int grid[1001][1001];
bool visited[1000001];
// unordered_map<int, vector<pair<int, int>>> factors;

vector<pair<int, int>> get_factors(int x) {
    // We will store all factors in `result`
    vector<pair<int, int>> result;
    int i = 1;
    // This will loop from 1 to int(sqrt(x))
    while(i*i <= x) {
        // Check if i divides x without leaving a remainder
        if(x % i == 0) {
            result.push_back(make_pair(i, x/i));
        }
        i++;
    }
    // Print in case of debug mode
    if(DEBUG) {
        for(int i=0; i<result.size(); i++) {
            cout << result[i].first << ',' << result[i].second << ' ';
        }
        cout << '\n';
    }
    // Return the list of factors of x
    return result;
}

bool bfs(){
    queue<pair<int, int>> q;

    q.push(make_pair(1, 1));
    visited[grid[1][1]] = true;

    pair<int, int> s;
    while(!q.empty()){
        s = q.front();
        q.pop();

        if(s.first == M && s.second == N){
            return true;
        }

        for(pair<int, int> factors : get_factors(grid[s.first][s.second])){ 
            if(factors.first <= M && factors.second <= N && (!visited[grid[factors.first][factors.second]] || (factors.first == M && factors.second == N))){
                q.push(factors);
                visited[grid[factors.first][factors.second]] = true;
            }
            if(factors.second <= M && factors.first <= N && (!visited[grid[factors.second][factors.first]] || (factors.second == M && factors.first == N))){
                q.push(make_pair(factors.second, factors.first));
                visited[grid[factors.second][factors.first]] = true;
            }
        }
    }
    return false;
}

int main() {

    // Gathering input
    cin >> M >> N;
    for(int i = 1; i <= M; i++){
        for(int j = 1; j <= N; j++){
            cin >> grid[i][j];
        }
    }

    // Printing output
    if(bfs()){
        cout << "yes";
    }
    else{
        cout << "no";
    }

    return 0;
}