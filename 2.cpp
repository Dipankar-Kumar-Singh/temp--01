#include <bits/stdc++.h>
using namespace std;
int solution(int N , vector<int> &A , vector<int> &B) {
    vector<vector<int>> g ;
    g = vector<vector<int>> (N) ;
    vector<int> isAlive(N, 1) ;
    vector<int> deg(N) ;
    
    for(int i = 0 ; i < A.size() ; i++){
        deg[A[i]]++ ;
        deg[B[i]]++ ;
        g[A[i]].push_back(B[i]) ;
        g[B[i]].push_back(A[i]) ;
    }

    queue<int> q ;

    for(int i = 0 ; i < N ; i++){
        if(deg[i] <= 1 ) {
            q.push(i) ;
        } 
    }

    int time = 0 ;

    while(!q.empty()) {

        queue<int> q2 ;

        int anyremoved = 0 ;
        
        while(!q.empty()) { 
            int v = q.front() ;
            q.pop() ;

            if(deg[v] == -1 ) continue;

            if(deg[v] <= 1)  {
                deg[v] = -1 ;
                anyremoved++ ;
                for(auto child : g[v]) { 
                    deg[child]-- ;
                    if(deg[child] <= 1 && deg[child] >=0  ){ 
                        q2.push(child) ;
                    }
                }
            }
        }   

        q = q2 ;
        if(anyremoved) time++ ;
    }
    return time ; 
}

int main(){
    // cout << solution(4, vector<int>{0,1,2} , vector<int>{1,2,0}) << endl ;
    // cout << solution(4, vector<int>{0,1,2,3} , vector<int>{1,2,3,0}) << endl ;
    // cout << solution(7, vector<int>{0,1,2,4,5} , vector<int>{1,2,3,5,6}) << endl ;
}