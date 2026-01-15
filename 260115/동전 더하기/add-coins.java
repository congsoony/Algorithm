import java.io.*;
import java.util.*;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("input.txt"));
        Scanner sc = new Scanner(System.in);

        int n,k;
        List<Integer> list = new ArrayList<>();
        n = sc.nextInt();
        k = sc.nextInt();
        for(int i =0;i<n;i++){
            int t = sc.nextInt();
            list.add(t);
        }

        list.sort((a,b)->b-a);
        int res = 0;
        for(int i =0;i<n;i++){
            res+=k/list.get(i);
            k%=list.get(i);
        }
        System.out.println(res);
    }
}