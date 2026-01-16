import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int arr[] =new int[n+1];
        Arrays.fill(arr,(int)1e9);
        arr[0]=0;
        for(int i =2;i<=n;i++){
            arr[i]=Math.min(arr[i],arr[i-2]+1);
            if(i-5>=0)
                arr[i]=Math.min(arr[i],arr[i-5]+1);
        }
        System.out.println(arr[n]==(int)1e9?-1:arr[n]);
        
    }
}