import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("input.txt"));

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<int[]> l = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int s = sc.nextInt();
            int e = sc.nextInt();
            l.add(new int[]{s,e});

        }
        l.sort((a,b)->a[1]-b[1]);
        int e = l.get(0)[1];
        int res =1;

        for(int i =1;i<n;i++) {
            if(l.get(i)[0]<e)
                continue;
            res++;
            e= l.get(i)[1];
        }
        System.out.println(res);
    }
}