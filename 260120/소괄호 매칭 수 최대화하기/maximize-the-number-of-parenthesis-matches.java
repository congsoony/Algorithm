import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;

import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("input.txt"));
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] arr = new String[n];
        List<Pair>list =new ArrayList<>();
        for (int i = 0; i < n; i++) {
            arr[i] = sc.next();
            int cnt =0;
            for(char c:arr[i].toCharArray()){
                if(c=='(')
                    cnt--;
                else
                    cnt++;
            }
            list.add(new Pair(cnt,arr[i]));
        }
        list.sort((a,b)->{
            if(a.x==b.x)return a.y.compareTo(b.y);
            return a.x-b.x;
        });
        long res = 0;
        long cnt=0;
        StringBuilder sb = new StringBuilder();
        for(Pair p:list){
            sb.append(p.y);
        }

        String s = sb.toString();
        for(char c : s.toCharArray()){
            if(c=='(')
                cnt++;
            else{
                res+=cnt;
            }
        }
        System.out.println(res);
    }
}
class Pair{
    int x;
    String y;

    public Pair(int x, String y) {
        this.x = x;
        this.y = y;
    }
}