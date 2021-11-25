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
        int n =Integer.parseInt(br.readLine());
        StringTokenizer st= new StringTokenizer(br.readLine());
        Integer arr[] = new Integer[n];
        for(int i=0;i<n;i++)
            arr[i]=Integer.parseInt(st.nextToken());
        Arrays.sort(arr);
        int sum=0;
        if(n%2==0) {
            int sum2=0;
            int mid=n/2-1;
            int mid2=n/2;
            for(int i=0;i<n;i++) {
                sum+=Math.abs(arr[i]-arr[mid]);
                sum2+=Math.abs(arr[i]-arr[mid2]);
            }
            if(sum<=sum2)
                System.out.println(arr[mid]);
            else
                System.out.println(arr[mid2]);
            
        }else {
            System.out.println(arr[n/2]);
        }
    }
}