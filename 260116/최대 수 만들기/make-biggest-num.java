import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("input.txt"));

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<String>l = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            l.add(sc.next());
        }
        l.sort((a,b)->{
            return (b+a).compareTo(a+b);
        });
        StringBuilder sb = new StringBuilder();
        for(String s:l)sb.append(s);
        System.out.println(sb.toString());
    }
}