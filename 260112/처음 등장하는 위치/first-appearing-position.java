
import java.util.*;

public class Main {
    public static int n;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        List<Integer> list =new ArrayList<>();
        int a;
        TreeMap<Integer,Integer> tr = new TreeMap<>();
        for(int i =0;i<n;i++){
            a = sc.nextInt();
            if(tr.containsKey(a))continue;
            tr.put(a,i+1);
        }
        for(Map.Entry<Integer,Integer> e : tr.entrySet()){
            System.out.println(e.getKey()+" "+e.getValue());
        }

    }
}
