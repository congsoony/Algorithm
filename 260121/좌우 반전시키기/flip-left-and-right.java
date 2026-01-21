import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] arr = new int[N+1];
        for (int i = 0; i < N; i++) {
            arr[i] = sc.nextInt();
        }
        int res= 0;
        for(int i =1;i<N;i++){
            if(arr[i-1]==0){
                arr[i-1]^=1;
                arr[i]^=1;
                arr[i+1]^=1;
                res++;
            }
        }
        for(int i=0;i<N;i++){
            if(arr[i]==0)res=-1;
        }
        System.out.println(res);
    }
}