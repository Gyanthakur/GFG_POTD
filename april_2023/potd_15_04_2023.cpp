#include<bits/stdc++.h>
using namespace std;



int totalTime(int n, vector<int> &arr, vector<int> &time) {
        vector<int> last_time(n,INT_MIN);
        int cur_time = -1;
        for(int &i: arr){
            cur_time = max(cur_time+1,time[i-1]+last_time[i-1]);
            last_time[i-1]=cur_time;
        }
        return cur_time;
    }