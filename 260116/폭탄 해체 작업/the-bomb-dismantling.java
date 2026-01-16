import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("input.txt"));
        Scanner sc = new Scanner(System.in);
        List<int[]>l =new ArrayList<>();
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b)->{
            if(a[0]==b[0]){
                return a[1]-b[1];
            }
            return b[0]-a[0];
        });
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

        int arr[]=new int[10001];
        int res =l.get(0)[0];
        int before=l.get(0)[1];
        arr[before] = res;
        for(int i =1;i<n;i++){
            if(before <l.get(i)[1]){
                before = l.get(i)[1];
                arr[before]=l.get(i)[0];
            }
            else{
                pq.add(l.get(i));
            }
        }
        for(int i =1;i<=10000;i++){
            if(pq.isEmpty())break;
            int p[] = pq.peek();
            if(p[1]<i) {
                pq.poll();
            }
            else if(p[0]>arr[i]){
                arr[i]=p[0];
                pq.poll();
            }
        }
        res =0;
        for(int i =0;i<=10000;i++){
            res+=arr[i];
        }
        System.out.println(res);
    }

}