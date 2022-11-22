#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n,edge[16][16],dp[16][(1<<16)];

int go(int here, int visited){
    if(visited == (1<<n) -1){
        return edge[here][0] ? edge[here][0] : INF;
    }
    int &ret = dp[here][visited];
    if(ret != -1) return ret;
    ret = INF;
    for(int i=0;i<n;i++){
        if(visited & (1<<i)) continue;
        if(!edge[here][i]) continue;
        ret = min(ret,go(i,visited | (1<<i)) + edge[here][i]);
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>edge[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout<<go(0,1);
}