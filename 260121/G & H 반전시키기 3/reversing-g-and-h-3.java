import java.io.FileInputStream;
import java.io.IOException;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("input.txt"));
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String a = sc.next();
        String b = sc.next();
        int arr1[]=new int[n];
        int arr2[]=new int[n];
        for(int i =0;i<n;i++){
            arr1[i]=a.charAt(i)=='G'?1:0;
            arr2[i]=b.charAt(i)=='G'?1:0;

        }
        int res = 0;
        for(int i =n-1;i>=0;i--){
            if(arr1[i]!=arr2[i]){
                res++;
                for(int j=0;j<4 &&i>=0;j++,i--){
                    if(arr1[i]==arr2[i])break;
                    arr1[i]=arr2[i];
                }
                i++;
            }
        }
        System.out.println(res);
    }
}