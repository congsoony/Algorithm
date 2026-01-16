import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("input.txt"));
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<Integer> l = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            l.add(sc.nextInt());
        }
        TreeSet<Integer> tr = new TreeSet<>();
        for (int i = 1; i <= 2*n; i++) {
            tr.add(i);
        }
        for(int i =0;i<n;i++){
            tr.remove(l.get(i));
        }
        int res =0;
        for(int i =0;i<n;i++){
            if(tr.ceiling(l.get(i))!=null)
                res++;
        }
        System.out.println(res);
        
    }

}