import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static int n;
    public static List<Integer>[] list;
    public static int[] color;
    public static void main(String[] args) throws IOException {
        BufferedReader br =new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        list = new List[n+1];
        color = new int[n+1];
        for(int i =1;i<=n;i++) {
            list[i] = new ArrayList<>();
            color[i] = Integer.parseInt(st.nextToken());
        }
        int a,b;
        for(int i =0;i<n-1;i++){
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            list[a].add(b);
            list[b].add(a);
        }
        System.out.println(dfs(1,0,0));
        br.close();
    }
    public static int dfs(int cur,int before,int col){
        int res = color[cur]==col?0:1;
        for(int next:list[cur]){
            if(next!=before){
                res+=dfs(next,cur,color[cur]);
            }
        }
        return res;
    }

}

