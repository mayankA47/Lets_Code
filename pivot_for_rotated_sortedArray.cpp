#include<iostream>
using namespace std;
int main() {
	int n;
	cin>>n;
	int *a = new int [n];
	for(int i=0;i<n;i++) cin>>a[i];
	int l,h,m;
	l=0;
	h=n-1;
	while(l<=h){
		m = (l+h)/2;
		//is current index pivot?
		if(m<n-1)
		if(a[m]>a[m+1])
		break;
		//pivot on left side
		if(a[l]>a[m])
		h=m-1;
		else
		l=m+1;
	}
	cout<<m;
	return 0;
}