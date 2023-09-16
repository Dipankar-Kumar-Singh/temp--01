#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &v , int x , int y){
    int best = 1e9  ;
    int n = v.size() ;
    for(int start = 0 ; start < y; start++){

        int sum = 0 ; 
        int point = start ;
        int elements = 0 ;
        for(int i = 0 ; i < x ; i++){
            if(point >= n ) break;
            sum += v[point] ;
            point += y ;
            elements++;
        }

        if(elements < x) continue;
        int group_best = sum ;

        while(point < n ){
            group_best = min(group_best , sum) ;
            int front_index = point -  (x) * y ; 
            sum -= v[front_index] ;
            sum += v[point] ;
            group_best = min(group_best , sum) ;
            point += y ;
        }

        best = min(best , group_best) ;
    }
    return best ;
}


int main(){
    
}
