import java.util.*;
class Solution {
    public int solution(int[] players, int m, int k) {
        int answer = 0;
        Queue<Integer> q=new LinkedList<>();
        int cap = 0;
        for(int i =0;i<players.length;i++) {
            while(!q.isEmpty() && q.peek()+k<=i) {
                q.poll();
                cap-=m;
            }
            while(m+cap<=players[i]){
                answer++;
                q.add(i);
                cap+=m;
            }
        }
        return answer;
    }
}