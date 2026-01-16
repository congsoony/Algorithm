import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("input.txt"));
        Scanner sc = new Scanner(System.in);
        List<int[]>l =new ArrayList<>();
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            int a=sc.nextInt();
            int b = sc.nextInt();
            l.add(new int[]{a,b});
        }
        l.sort((a,b)->{
            if(a[1]==b[1]){
                return b[0]-a[0];
            }
            return a[1]-b[1];
        });
        int res =l.get(0)[0];
        int before=l.get(0)[1];
        for(int i =1;i<n;i++){
            if(before <l.get(i)[1]){
                res+=l.get(i)[0];
                before = l.get(i)[1];
            }
        }
        System.out.println(res);
    }

}