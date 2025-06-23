import java.util.*;

class Solution {
    int num = (int)1e6+1;
    int parent[];
    int child[];
    List<Integer> adj[];
    public int[] solution(int[] nodes, int[][] edges) {
        int[] answer = new int[2];
        parent = new int[num];
        child =new int[num];
        adj= new ArrayList[num];

        for(int i =0;i<num;i++)adj[i]=new ArrayList<>();
        for(int i =0;i<num;i++)parent[i]=i;
        for(int e[] : edges){
            union(e[0],e[1]);
            child[e[0]]++;
            child[e[1]]++;
        }
        Set<Integer> s = new HashSet<>();
        for(int node:nodes){
            adj[find(node)].add(node);
            s.add(find(node));
        }
        for(int node: s){
            int treecnt[] = oddeven(adj[node]);
            if(treecnt[0]==1)
                answer[0]++;
            if(treecnt[1]==1)
                answer[1]++;
        }
        return answer;
    }
    public void union(int a,int b){
        a= find(a);
        b= find(b);
        parent[b]=a;
    }
    public int find(int idx){
        if(parent[idx]==idx)return idx;
        return parent[idx]=find(parent[idx]);
    }
    public int[] oddeven(List<Integer> l){
        int treecnt[]=new int[2];//홀짝 역홀짝
        for(int node:l){
            if((node%2== 0 && child[node]%2==1)  ||(node%2==1 &&child[node]%2==0) ) {
                treecnt[1]++;
            }
            else if((node%2== 0 && child[node]%2==0)  ||(node%2==1 &&child[node]%2==1)){
                treecnt[0]++;
            }
        }
        return treecnt;
    }
}