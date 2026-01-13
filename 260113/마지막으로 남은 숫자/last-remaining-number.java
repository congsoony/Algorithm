import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
     
        PriorityQueue<Long> pq= new PriorityQueue<>(Collections.reverseOrder());
        for(int i =0;i<n;i++){
            long t = sc.nextLong();
            pq.add(t);
        }
        while(pq.size()>1){
            long num = pq.poll()-pq.poll();
            if(num!=0)
                pq.add(num);
        }
        Long res = pq.poll();
        System.out.println(res==null?-1:res);
    }
}