import java.util.*;

class Solution {
    int check[][][];
    int res =(int)1e8;
    int N,M;
    public void dfs(int[][] info, int n, int m,int idx){
        if(check[n][m][idx]==1||res<n)return;
        check[n][m][idx]=1;
        if(idx>=info.length){
            res = Math.min(res,n);
            return;
        }

        if(n+info[idx][0]<N){
            dfs(info,n+info[idx][0],m,idx+1);
        }
        if(m+info[idx][1]<M){
            dfs(info,n,m+info[idx][1],idx+1);
        }
    }
    public int solution(int[][] info, int n, int m) {
        int answer = 0;
        check = new int[n+1][m+1][info.length+1];
        N=n;
        M=m;
        dfs(info,0,0,0);
        return res>=(int)1e8?-1:res;
    }
}