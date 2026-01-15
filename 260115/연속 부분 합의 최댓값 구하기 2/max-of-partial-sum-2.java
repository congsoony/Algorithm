import java.io.*;
import java.util.*;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("input.txt"));
        Scanner sc = new Scanner(System.in);

        int n =sc.nextInt();
        int arr[] =new int[n+1];
        int dp[] = new int[n+1];
        Arrays.fill(arr,(int)-1e9);
        int res =(int)-1e9;
        for(int i =1;i<=n;i++){
            arr[i]=sc.nextInt();
            dp[i] = Math.max(dp[i-1]+arr[i],arr[i]);
            res = Math.max(dp[i],res);
        }
        System.out.println(res);
    }
}