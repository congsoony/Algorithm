import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String a = sc.next();
        String b = sc.next();
        int arr1[] =new int[n+1];
        int arr2[] = new int[n+1];
        for(int i =0;i<n;i++){
            arr1[i]=a.charAt(i)=='H'?1:0;
            arr2[i]=b.charAt(i)=='H'?1:0;
        }
        int res = 0;
        int cnt = 0;
        for(int i =n-1;i>=0;i--){
            if((arr1[i]+cnt)%2!=arr2[i]){
                cnt++;
                res++;
            }
        }
        System.out.println(res);
    }
}