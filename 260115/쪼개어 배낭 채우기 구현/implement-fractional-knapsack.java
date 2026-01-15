import java.io.*;
import java.util.*;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("input.txt"));
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        List<double[]> list =new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int w = sc.nextInt();
            int v = sc.nextInt();
            list.add(new double[]{w,v});
        }
        list.sort((a,b)->{
            double c =a[1]/a[0];
            double d = b[1]/b[0];
            if(c>d)return -1;
            else if(c<d)return 1;
            return 0;
        });
        double res = 0;
        for(double t[]:list) {
            if(m>=t[0]) {
                res += t[1];
                m-=t[0];
            }
            else {
                res += t[1] *(m/t[0]);
                m=0;
            }
            if(m==0)break;
        }
        System.out.printf("%.3f",res);

    }
}