import java.util.*;

class Node {
	
	int data;
	Node link;
	
	Node(int d,Node l){
		data=d;
		link=l;
	}
}

class queue {
	
	protected Node front;
	protected Node rear;
	int size;
	
	queue(){
		front=null;
		rear=null;
		size=0;
	}
	
	boolean isEmpty() {
		return rear==null;
	}
	
	void enqueue(int x) {
		Node nptr=new Node(x,null);
		if(rear==null) {
			front=nptr;
		}
		else {
			rear.link=nptr;
		}
		rear=nptr;
		size++;
	}
	
	int dequeue() {
		int n=front.data;
		front=front.link;
		if(front==null) {
			rear=null;
		}
		size--;
		return n; 
	}
	
	int see() {
		int n=front.data;
		return n;
	}
	
}

class graph{
	
	int n;									// Number of vertices in graph
	ArrayList<ArrayList<Integer>> adj;		// Adjacency List
	int time;								
	
	graph(int V) {
		
		/* Constructor for class graph */
		
		n=V;
		adj=new ArrayList<ArrayList<Integer>>();
		time=0;
		for(int i=0;i<n;i++) {
			adj.add(new ArrayList<Integer>());
		}
	}
	
	void add_edge(graph g,int a,int b){
		
		/* A method for adding an edge between two vertices*/
			
		g.adj.get(a).add(b);
		g.adj.get(b).add(a); // **IMP** USE THIS STATEMENT ONLY IF THE GRAPH IS UNDIRECTED
		
	}
	
	int[] BFS(graph g,int x){
		
		/* Breadth First Search */
		
		/* x is the source vertex */
		
		queue q=new queue();
		
		int inf=Integer.MAX_VALUE;					
		int[] dist=new int[g.n];
		boolean[] visit=new boolean[g.n];
		
		for(int i=0;i<g.n;i++) {
			dist[i]=inf;
			visit[i]=false;
		}
		
		dist[x]=0;
		q.enqueue(x);
		visit[x]=true;
		
		while(!q.isEmpty()) {
			
			int v=q.dequeue();
			ArrayList<Integer> v_arr=g.adj.get(v);
			
			for(int w : v_arr) {

				if(dist[w]==inf) {
					dist[w]=dist[v]+1;
					visit[w]=true;
					q.enqueue(w);
				}
			}
		}
		return dist;
	}
	
	void DFS(graph g) {
		
		/* Depth First Search*/
		
		int inf=-1;				 
		int[] colour=new int[g.n];
		for(int i=0;i<g.n;i++) {
			colour[i]=inf;
		}
		g.time=0;
		for(int j=0;j<g.n;j++) {
			if(colour[j]==inf) {
				DFS_Visit(g,j,colour);
			}
		}
	}
	
	void DFS_Visit(graph g,int u,int[] colour) {
		
		int inf=-1;
		colour[u]=1;		 
		
		g.time+=1;
		int[] discover=new int[g.n];
		int[] finish=new int[g.n];
		
		discover[u]=g.time;					
		
		for(int v:g.adj.get(u)) {
			
			if(colour[v]==inf) {
				DFS_Visit(g,v,colour);
			}
			
		}
		
		colour[u]=2;	
		g.time+=1;
		finish[u]=g.time;
	}
	
	
}

public class graph_dsa {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int V = 5;
        graph g1=new graph(V);
        
        g1.add_edge(g1, 0, 1);
        g1.add_edge(g1, 0, 4);
        g1.add_edge(g1, 1, 2);
        g1.add_edge(g1, 1, 3);
        g1.add_edge(g1, 1, 4);
        g1.add_edge(g1, 2, 3);
        g1.add_edge(g1, 3, 4);
        
        g1.BFS(g1, 0);				
        g1.DFS(g1);
	}

}
