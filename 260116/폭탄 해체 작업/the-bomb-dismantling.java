import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("input.txt"));
        Scanner sc = new Scanner(System.in);
        List<int[]>l =new ArrayList<>();
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            int a=sc.nextInt();
            int b = sc.nextInt();
            l.add(new int[]{a,b});
        }
        l.sort((a,b)-> a[1]-b[1]);
        int res = 0;
        for(int t[]:l){
            pq.add(t[0]);
            res+=t[0];
            if(pq.size()>t[1]){
                res-=pq.poll();
            }
        }
        System.out.println(res);
    }

}