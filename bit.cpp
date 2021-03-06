//Binary Indexed Tree: 

#include<bits/stdc++.h> 
using namespace std;

//getSum 
int getSum(int *bit,int n,int k){
	int ans = 0;
	for(int i=k;i>0; i-=(i & -i)){
		ans+=bit[i];
	}
	return ans;
}

//update
void update(int *bit,int n,int index,int val){
	for(int i= index;i<=n;i += (i & -i)){
		bit[i]+= val;
	}
}

int main(){
	ios:: sync_with_stdio(false);
  	cin.tie(0);
  	int n;
  	cin>>n;
  	//init block 
  	int bit[n+1];
  	memset(bit,0,sizeof(bit));

  	int * data = new int [n+1];
  	for(int i=1;i<=n;++i){
  		int e;
  		cin>>e;
  		data[i] = e;
  		update(bit,n,i,e);
  	}

  	//queries

  	int q;
  	cin>>q;

  	while(q--){
  		int option; 
  		cin>>option;
  		if(option == 1 ){
  			int l,r;
  			cin>>l>>r;
  			cout<<getSum(bit,n,r) - getSum(bit,n,l-1)<<endl;
  		}
  		else{
  			int index,val;
  			cin>>index>>val;
  			update(bit,n,index,val);
  			cout<<"Updated"<<endl;
  		}

  }
}