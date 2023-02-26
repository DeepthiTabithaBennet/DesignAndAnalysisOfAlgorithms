#include<iostream>
using namespace std;

int main(){
    int a, b, u, v, n, i, j, ne = 1;
 
    int visited[10] = {0}, min, mincost=0, cost[10][10];
        
    cout << "Enter the number of nodes: ";
    cin >> n;
 
    cout << "\nEnter the adjacency matrix:\n";
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            cin >> cost[i][j];
            if(cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }
 
    visited[1] = 1;
    cout << endl;
 
    while(ne < n){
        for(i = 1, min = 999; i <= n; i++){
            for(j = 1; j <= n; j++){
                if(cost[i][j] < min){
                    if(visited[i] != 0){
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }
 
        if(visited[u] == 0 || visited[v] == 0){
            cout << "Edge : " << ne++ << "(" << a << ", "<< b << ")  cost : " << min << endl;
            mincost += min;
            visited[b] = 1;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    cout << "Minimun cost = " << mincost;
    return 0;
}

/*

Sample Input:
1 2 3 4 5
5 4 3 2 1
1 3 5 4 2
4 3 5 1 2
2 5 3 1 4  

*/
