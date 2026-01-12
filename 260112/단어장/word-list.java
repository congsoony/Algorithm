

import java.util.*;

public class Main {
    public static int n;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        TreeMap<String,Integer> tr = new TreeMap<>();
        for(int i =0;i<n;i++){
            String s = sc.next();
            tr.merge(s,1,Integer::sum);
        }

        for(Map.Entry<String,Integer> e: tr.entrySet()){
            System.out.println(e.getKey()+" "+e.getValue());
        }
    }
}
