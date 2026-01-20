import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;

import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("input.txt"));
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String a = sc.next();
        String b = sc.next();
        int arr1[] = new int[n];
        int arr2[] = new int[n];
        for(int i =0;i<n;i++){
            arr1[i]=a.charAt(i)=='G'?1:0;
            arr2[i]=b.charAt(i)=='G'?1:0;
        }
        int res =0;
        for(int i =0;i<n;i++){
            int cnt=0;
            while(arr1[i]!=arr2[i]){
                i++;
                cnt=1;
            }
            res+=cnt;
        }
        System.out.println(res);
    }
}