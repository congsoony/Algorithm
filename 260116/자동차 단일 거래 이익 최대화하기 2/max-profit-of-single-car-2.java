import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] prices = new int[n];
        for(int i = 0; i < n; i++)
            prices[i] = sc.nextInt();
        // Please write your code here.
        int res = 0;
        int min=prices[0];
        int max= prices[0];
        for(int i =1;i<n;i++){
            if(min>prices[i]){
                min = prices[i];
            }
            else{
                res = Math.max(res,prices[i]-min);
            }
        }
        System.out.println(res);
    }
}