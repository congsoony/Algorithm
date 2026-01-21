import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] arr = new int[n+2][n+2];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                arr[i][j] = sc.nextInt();
        int res = 0;
        for (int i = 2; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if(arr[i-1][j]==0){
                    arr[i-1][j]^=1;
                    arr[i][j]^=1;
                    arr[i][j+1]^=1;
                    arr[i+1][j]^=1;
                    arr[i][j-1]^=1;
                    res++;
                }
            }
        }
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if(arr[i][j]==0){
                    res=-1;
                }
            }
        }
        System.out.println(res);

    }
}