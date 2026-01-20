import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {

        System.setIn(new FileInputStream("input.txt"));
        Scanner sc = new Scanner(System.in);
        int c = sc.nextInt();
        int n = sc.nextInt();
        int[] redStones = new int[c];
        for (int i = 0; i < c; i++) {
            redStones[i] = sc.nextInt();
        }
        int[][] blackStones = new int[n][2];
        for (int i = 0; i < n; i++) {
            blackStones[i][0] = sc.nextInt();
            blackStones[i][1] = sc.nextInt();
        }
        Arrays.sort(blackStones, (a,b)->a[0]-b[0]);
        Arrays.sort(redStones);
        int res = 0;
        PriorityQueue<Integer>pq= new PriorityQueue<>();
        int idx = 0;
        for(int i =0;i<c;i++){
            while(idx<n &&blackStones[idx][0]<=redStones[i]){
                pq.add(blackStones[idx][1]);
                idx++;
            }
            while(!pq.isEmpty()&& pq.peek()<redStones[i]){
                pq.poll();
            }
            if(!pq.isEmpty()){
                res++;
                pq.poll();
            }
        }
        System.out.println(res);
    }

}