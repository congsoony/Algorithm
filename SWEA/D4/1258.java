import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Solution {
    public static int dy[]=new int[]{-1,0,1,0};
    public static int dx[]=new int[]{0,1,0,-1};
    public static int n;
    public static int board[][];
    public static int minx,miny,maxx,maxy;
    public static void main(String[] args) throws FileNotFoundException {
        //System.setIn(new FileInputStream("input.txt"));
        Scanner sc= new Scanner(System.in);
        int Test = sc.nextInt();
        for(int test=1;test<=Test;test++){
            n = sc.nextInt();
            board= new int[n][n];
            for(int i =0;i<n;i++){
                for(int j=0;j<n;j++){
                    board[i][j]=sc.nextInt();
                }
            }
            List<int[]> res = new ArrayList<>();
            for(int i =0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(board[i][j]>0){
                        minx=miny = (int)1e9;
                        maxx=maxy = 0;
                        dfs(i,j);
                        res.add(new int[]{maxy-miny+1,maxx-minx+1});
                    }
                }
            }
            res.sort((a,b)->{
                if (a[0]*a[1]==b[0]*b[1]){
                    return a[0]-b[0];
                }
                return a[0]*a[1]-b[0]*b[1];
            });
            System.out.print("#"+test+" "+res.size()+" ");
            for(int r[] :res){
                System.out.print(r[0]+" "+r[1]+" ");
            }
            System.out.println();
        }
    }
    public static boolean isrange(int y,int x){
        return 0<=y&&y<n&&0<=x&&x<n;
    }
    public static void dfs(int y,int x){
        if(!isrange(y,x))
            return;
        if(board[y][x]==0)return;
        board[y][x]=0;
        maxx=Math.max(maxx,x);
        maxy=Math.max(maxy,y);
        minx=Math.min(minx,x);
        miny=Math.min(miny,y);
        for(int i =0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            dfs(ny,nx);
        }
    }

}
