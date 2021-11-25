import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;
import java.util.StringTokenizer;
 
public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br =new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        int t=Integer.parseInt(br.readLine());
        for(int test=0;test<t;test++) {
            int n=Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine());
            Deque<String> dq=new ArrayDeque<>();
            dq.addFirst(st.nextToken());
            for(int i=1;i<n;i++) {
                String s= st.nextToken();
                if(dq.getFirst().compareTo(s)<0) {
                    dq.addLast(s);
                }
                else
                    dq.addFirst(s);
            }
            for(String res:dq) {
                bw.write(res);
            }
            bw.write("\n");
        }
        br.close();
        bw.close();
    }
}