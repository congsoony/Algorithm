import java.util.*;
class Solution {
    public String solution(long n, String[] bans) {
        n--;
        long num=0;
        List<Long>list=new ArrayList<>();
        for(String b:bans){
            list.add(getNumber(b));
        }
        Collections.sort(list);
        for(long t:list){
            if(t<=n) n++;
            else break;
        }
        StringBuilder sb = new StringBuilder();
        long[] inum =getLeng(n);
        for(int i =0;i<inum[0];i++){
            char c = (char)(inum[1]%26+'a');
            inum[1]/=26;
            sb.append(c);
        }
        sb.reverse();
        return sb.toString();
    }

    public long getNumber(String b){
        long num = 0;
        for(int i =1;i<b.length();i++){
            num+=(long)Math.pow(26,i);
        }
        for(int i=0;i<b.length();i++){
            long c = b.charAt(i) - 'a';
            long p = b.length()-i-1;
            num+=(long)Math.pow(26,p)*c;
        }
        return num;
    }
    public long[] getLeng(long n){
        long num=0;
        for(long i =1;;i++){
            long t=(long)Math.pow(26,i);
            if(t+num>n)return new long[]{i,n-num};
            num+=t;
        }
    }
}