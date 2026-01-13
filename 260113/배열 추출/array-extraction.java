import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        PriorityQueue<Integer>pq = new PriorityQueue<>(Collections.reverseOrder());
        for (int i = 0; i < n; i++) {
            int x = sc.nextInt();
            if(x==0){
                Integer res = pq.poll();
                System.out.println(res==null?0:res);
            }
            else
                pq.add(x);
            
        }
    }
}