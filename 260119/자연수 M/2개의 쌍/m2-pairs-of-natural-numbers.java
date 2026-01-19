import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {

        System.setIn(new FileInputStream("input.txt"));
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<Integer> l = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            while(x-- >0){
                l.add(y);
            }
        }
        l.sort((a,b)->a-b);

        int left=0,right = l.size()-1;
        int res = 0;
        while(left<right){
            res = Math.max(res,l.get(left++)+l.get(right--));
        }
        System.out.println(res);
    }

}