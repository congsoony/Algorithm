import java.util.*;
class Solution {
    public static int n,m;
    public static int board[][],check[][];
    public static int cnt = 0;
    public static int dy[]=new int[]{0,1,0,-1};
    public static int dx[]=new int[]{-1,0,1,0};
    public int solution(String[] storage, String[] requests) {
        int answer = 0;
        n = storage.length;
        m = storage[0].length();
        board  = new int [n+2][m+2];
        check = new int [n+2][m+2];
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                board[i+1][j+1] = storage[i].charAt(j)-'A'+1;
            }
        }
        for(String r :requests){
            if(r.length()==1){
                bfs(r.charAt(0)-'A'+1);
            }
            else{
                erase(r.charAt(0)-'A'+1);
            }
        }
        for(int i =1;i<=n;i++){
            for(int j =1;j<=m;j++){
                answer+=board[i][j]>0?1:0;
            }
        }
        return answer;
    }
    public static void bfs(int c) {
        Queue<int[]> q =new LinkedList<int[]>();
        q.add(new int[]{0,0});
        cnt++;
        check[0][0]=cnt;
        List<int[]> el = new ArrayList<>();
        while(!q.isEmpty()){
            int[] temp = q.poll();
            int y=temp[0];
            int x=temp[1];
            for(int i=0;i<4;i++){
                int ny=y+dy[i];
                int nx=x+dx[i];
                if(isrange(ny,nx) &&check[ny][nx]!=cnt){
                    if(board[ny][nx]==0){
                        q.add(new int[]{ny,nx});
                        check[ny][nx]=cnt;
                    }
                    else if(board[ny][nx]==c){
                        el.add(new int[]{ny,nx});
                        check[ny][nx]=cnt;
                    }
                }
            }
        }
        for(int yx[]:el){
            board[yx[0]][yx[1]]=0;
        }
    }
    public static void erase(int c){
        for(int i =1;i<=n;i++){
            for(int j =1;j<=m;j++){
                if(board[i][j]==c){
                    board[i][j]=0;
                }
            }
        }
    }
    public static boolean isrange(int y,int x){
        return 0<=y&&y<n+2&&0<=x&&x<m+2;
    }
}