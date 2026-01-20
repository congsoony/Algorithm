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
        TreeSet<int[]>tr =new TreeSet<>((a,b)->{
            if(a[0]==b[0])return a[1]-b[1];
            return a[0]-b[0];
        });

        for (int i = 0; i < n; i++) {
            blackStones[i][0] = sc.nextInt();
            blackStones[i][1] = sc.nextInt();
            tr.add(new int[]{-blackStones[i][0],blackStones[i][1]});

        }
        Arrays.sort(redStones);
        int res = 0;

//        for(int i=0;i<c;i++){
//            System.out.println(redStones[i]);
//        }
        //for(int t[] :tr) System.out.println(-t[0]+" "+t[1]);

        for(int i =0;i<c;i++){
            int t[]=tr.ceiling(new int[]{-redStones[i],redStones[i]});
            if(t!=null){
                if(redStones[i]<=t[1]){
                    tr.remove(t);
                    res++;

                }
            }
        }
        System.out.println(res);
    }

}