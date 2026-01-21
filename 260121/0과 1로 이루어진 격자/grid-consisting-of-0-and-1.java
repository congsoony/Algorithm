import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] grid = new String[n];
        int arr[][]=new int[n][n];
        for (int i = 0; i < n; i++) {
            grid[i] = sc.next();
            for(int j =0;j<n;j++){
                arr[i][j]=grid[i].charAt(j)-'0';
            }
        }
        int res = 0;
        for (int i = n-1; i >=0; i--) {  
            for(int j =n-1;j>=0;j--){
                if((arr[i][j]+res)%2==1){
                    res++;
                }
            }
        }
        System.out.println(res);
    }
}