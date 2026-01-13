import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        HashMap<Integer,Node> h = new HashMap<>();
        int n = sc.nextInt();
        for(int i =1;i<=n;i++) {
            Node node = new Node(i);
            h.put(i, node);
        }
        int q= sc.nextInt();
        for(int i =0;i<q;i++){
            int t= sc.nextInt();
            int a = sc.nextInt();
            int b;
            if(t==1){
                singleNode(h.get(a));
            }
            else if(t==2){
                b=sc.nextInt();
                addPrev(h.get(a),h.get(b));
            }
            else if(t==3){
                b = sc.nextInt();
                addNext(h.get(a),h.get(b));
            }
            else if(t==4){
                Node node = h.get(a);
                Node left = node.prev;
                Node right = node.next;
                System.out.print((left==null?0:left.value)+" ");
                System.out.println(right==null?0:right.value);
            }
        }
        for(int i =1;i<=n;i++){
            Node node = h.get(i);
            Node right = node.next;
            System.out.print((right==null?0:right.value)+ " ");
        }
    }
    public static void singleNode(Node cur){
        Node left = cur.prev;
        Node right = cur.next;
        cur.prev = cur.next = null;
        if(left!=null)
            left.next=right;
        if (right!=null)
            right.prev =left;
    }
    public static void addPrev(Node cur,Node newnode){
        Node prev = cur.prev;
        cur.prev=newnode;
        newnode.next = cur;
        if(prev!=null) {
            newnode.prev = prev;
            prev.next = newnode;
        }
    }
    public static void addNext(Node cur,Node newnode){
        Node next= cur.next;
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
    int value;

    public Node(int value) {
        this.value = value;
        prev=null;
        next=null;
    }
}