class el{

	int data;
	int rank;
}

class disjoint{
	
	el[] arr;
	
	disjoint(int n){

		/* Constructor for class disjoint */
    
		arr=new el[n];
    
		for(int i=0;i<n;i++) {
			arr[i]=new el();
			arr[i].data=i;
			arr[i].rank=1;
		}
    
	}
	
	int find(int x){

		if(arr[x].data==x) {
			return x;
		}
		else {
			return arr[x].data=find(arr[x].data);
		}
    
	}
	
	void union(int x, int y) {
		
		unify(find(x),find(y));
	}
	
	void unify(int x, int y) {
		
		if(arr[x].rank>arr[y].rank) {
			arr[y].data=x;
		}
		else {
			arr[x].data=y;
			
			if(arr[x].rank==arr[y].rank) {
				arr[y].rank+=1;
			}
      
		}
		
	}
	
	
}

public class dsu {

  public static void main(String[] args) {

  }

}
