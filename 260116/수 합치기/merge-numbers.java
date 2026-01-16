import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("input.txt"));
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int t;
        for(int i =0;i<n;i++){
            t = sc.nextInt();
            pq.add(t);
        }
        int res = 0;
        while(pq.size()>1){
            int a = pq.poll();
            int b = pq.poll();
            res +=a+b;
            pq.add(a+b);
        }
        System.out.println(res);

    }
}