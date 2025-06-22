import java.util.*;
class Solution {
    public static int answer = 0;
    public static int []sel=new int[5];
    public static Set<Integer> s[];
    public int solution(int n, int[][] q, int[] ans) {
        s=new HashSet[q.length];
        for(int i =0;i<q.length;i++){
            s[i]=new HashSet<>();
            for(int j =0;j<5;j++)
                s[i].add(q[i][j]);
        }
        dfs(n,ans,0,1);
        return answer;
    }
    public static void dfs(int n,int[] ans,int h,int idx){
        if(h>=5){
            int cnt[]=new int[s.length];
            for(int i =0;i<s.length;i++){
                for(int j=0;j<5;j++){
                    if(s[i].contains(sel[j]))
                        cnt[i]++;
                }
            }
            for(int i =0;i<s.length;i++){
                if(cnt[i]!=ans[i])return;
            }
            answer++;
            return;
        }
        for(int i=idx;i<=n;i++){
            sel[h]=i;
            dfs(n,ans,h+1,i+1);
            sel[h]=0;
        }
    }
}