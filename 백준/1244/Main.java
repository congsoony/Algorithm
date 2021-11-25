import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
 
public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br =new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n=Integer.parseInt(br.readLine());
        StringTokenizer st=new StringTokenizer(br.readLine());
        int light[] = new int[n+1];
        for(int i=1;i<=n;i++) {
            light[i]=Integer.parseInt(st.nextToken());
        }
        int m=Integer.parseInt(br.readLine());
        for(int i=0;i<m;i++) {
            int a,b;
            st=new StringTokenizer(br.readLine());
            a=Integer.parseInt(st.nextToken());
            b= Integer.parseInt(st.nextToken());
            if(a==1) {
                for(int j=b;j<=n;j+=b) {
                    light[j]^=1;
 
                }
            }
            else {
                int l=b;
                int r=b;
                int l2=b;
                int r2=b;
                while(l>=1&&r<=n&&light[l]==light[r]) {
                    l2=l;
                    r2=r;
                    l--;
                    r++;
                }
                for(int j=l2;j<=r2;j++)
                    light[j]^=1;                
            }
        }
        int idx=0;
        for(int i=1;i<=n;i++,idx++) {
            if(idx!=0&&idx%20==0)
                bw.write("\n");
            bw.write(light[i]+" ");
        }
        br.close();
        bw.close();
        
    }
}
 
