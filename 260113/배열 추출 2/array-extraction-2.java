import java.util.*;

public class Main {
    public static int n;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        int num;
        PriorityQueue<Integer>pq = new PriorityQueue<>(
                (o1, o2) -> {
            if(Math.abs(o1)==Math.abs(o2))return o1-o2;
            return Math.abs(o1)-Math.abs(o2);
        });
        for(int i =0;i<n;i++){
            num = sc.nextInt();
            if(num!=0) {
                pq.add(num);
            }
            else {
                Integer res = pq.poll();
                System.out.println(res==null?0:res);
            }
        }
    }
}
