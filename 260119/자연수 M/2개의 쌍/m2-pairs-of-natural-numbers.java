import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {

        System.setIn(new FileInputStream("input.txt"));
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<int[]> l = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            l.add(new int[]{x,y});
        }
        l.sort((a,b)->a[1]-b[1]);

        int left=0,right = l.size()-1;
        int res = 0;
        while(left<=right){
            int cnt1 = l.get(left)[0];
            int val1 = l.get(left)[1];
            int cnt2 = l.get(right)[0];
            int val2 = l.get(right)[1];
            res= Math.max(res,val1+val2);
            if(cnt1<cnt2){
                left++;
                l.set(right,new int[]{cnt2-cnt1,val2});
            }
            else if(cnt1>cnt2){
                right--;
                l.set(left,new int[]{cnt1-cnt2,val1});
            }
            else{
                left++;
                right--;
            }
        }
        System.out.println(res);
    }

}