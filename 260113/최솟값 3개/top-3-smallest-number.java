import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        PriorityQueue<Integer> pq=new PriorityQueue<>();
        int n = sc.nextInt();
        int t;
        for(int i =0;i<n;i++){
            t = sc.nextInt();
            pq.add(t);
            if(pq.size()<3){
                System.out.println(-1);
            }
            else{
                int a = pq.poll();
                int b = pq.poll();
                int c = pq.poll();
                System.out.println(a*b*c);
                pq.add(a);
                pq.add(b);
                pq.add(c);
            }
        }
    }
}