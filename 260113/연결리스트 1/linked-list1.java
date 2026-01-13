
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        Node cur = new Node(s);
        int n = sc.nextInt();
        for(int i =0;i<n;i++){
            int t= sc.nextInt();
            if(t==1){
                s =sc.next();
                addPrev(cur,s);
            }
            else if(t==2){
                s=sc.next();
                addNext(cur,s);
            }
            else if(t==3){
                cur = Optional.ofNullable(cur.prev).orElse(cur);
            }
            else{
                cur = Optional.ofNullable(cur.next).orElse(cur);
            }

            Node left = cur.prev;
            Node right = cur.next;
            System.out.print(left==null?"(Null) ":left.value+" ");
            System.out.print(cur.value+" ");
            System.out.println(right==null?"(Null) ":right.value);
            //System.out.println(left==null?"(Null)":left.value+" "+cur.value+" "+right==null?"(Null)":right.value);
        }
    }
    public static void addPrev(Node cur,String value){
        Node prev = cur.prev;
        Node newnode = new Node(value);
        cur.prev=newnode;
        newnode.next = cur;
        if(prev!=null) {
            newnode.prev = prev;
            prev.next = newnode;
        }
    }
    public static void addNext(Node cur,String value){
        Node next= cur.next;
        Node newnode = new Node(value);
        cur.next = newnode;
        newnode.prev=cur;
        if(next!=null){
            newnode.next=next;
            next.prev = newnode;
        }
    }
}
class Node{
    Node prev;
    Node next;
    String value;

    public Node(String value) {
        this.value = value;
        prev=null;
        next=null;
    }
}