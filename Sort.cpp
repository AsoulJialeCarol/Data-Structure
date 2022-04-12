#include<iostream>
#include<queue>
using namespace std;
int a[10005],x[10005],cnt[10005],res[10005];
int n;
void insert_sort(){
	int p;
	for(int i=1;i<n;i++){
		p=i;
		while(p>0&&a[p]<a[p-1]){//��ǰ�����������������������ͽ��� 
			swap(a[p],a[p-1]);
			p--;
		}
	}
}
void shell_sort(){
	int d=n,p;
	while(d>0){
		d/=2;//������������統n=10��d=5����0,5��Ϊһ���������1,6һ�飬�Դ����� 
		for(int i=0;i<d;i++)//��֪���d���Ϊ1���ص���򵥵Ĳ������� 
			for(int j=i;j<n;j+=d){
				p=j;
				while(p>i&&a[p-d]>a[p]){
					swap(a[p-d],a[p]);
					p-=d;
				}
			}
	}
}
void bubble_sort(){
	bool flag=1;
	while(flag){
		flag=0;
		for(int i=0;i<n-1;i++)
			if(a[i]>a[i+1]){
				swap(a[i],a[i+1]);
				flag=1;
			}
	}
}
void cocktail_sort(){
	bool flag=1;
	int cnt=0;
	while(flag){
		cnt++;//��������ϸ����³����� 
		flag=0;
		if(cnt%2){
			for(int i=1;i<n-1;i++)
				if(a[i+1]<a[i]){
					swap(a[i+1],a[i]);
					flag=1;
				}
		}
		else{
			for(int i=n;i>0;i--)
				if(a[i]<a[i-1]){
					swap(a[i],a[i-1]);
					flag=1;
				}
		}
	}
}
struct interval{
	int le,ri;
};
void quick_sort(){
	int l,r,i,j,m;
	queue<interval> q;//�ǵݹ���죬Ҳ�ܺ�д�� 
	q.push(interval{0,n-1});
	while(!q.empty()){
		l=q.front().le,r=q.front().ri;
		i=l,j=r+1;
		q.pop();
		if(l>=r) continue;
		m=(l+r)/2;
		if(a[m]>a[r])
			swap(a[m],a[r]);
		if(a[l]<a[m])
			swap(a[l],a[m]);
		if(a[l]>a[r])
			swap(a[l],a[r]);
		while(i<j){
			i++;while(a[i]<a[l]) i++;
			j--;while(a[j]>a[l]) j--;
			if(i<j) swap(a[i],a[j]);
		}
		swap(a[l],a[j]);
		q.push(interval{l,j-1});//��������Сʱ���Ե��ò����������ڱ�Դ�����еĲ��� 
		q.push(interval{j+1,r});//����û�в�����Ϊ���䣬�Ͳ�������ʹ���� 
	}
}
void selection_sort(){
	for(int i=0;i<n-1;i++){
		int min=a[i],p=i;
		for(int j=i+1;j<n;j++)
			if(a[j]<min){
				min=a[j];
				p=j;
			}
		swap(a[i],a[p]);
	}
}
void heap_sort(){
	priority_queue<int> pq;
	for(int i=0;i<n;i++)
		pq.push(i);
	for(int i=0;i<n;i++){
		a[i]=pq.top();
		pq.pop();
	}
}
void merge_sort(int l,int r){
	if(l>=r) return;
	int m=(l+r)/2;
	merge_sort(l,m);
	merge_sort(m+1,r);
	int i=l,j=m+1;
	for(int k=l;k<=r;k++){
		if((i<=m&&a[i]<a[j])||j>r) x[k]=a[i++];
		else x[k]=a[j++];
	}
	for(int k=l;k<=r;k++)
		a[k]=x[k];
}
void count_sort(){
	for(int i=1;i<=10005;i++)
		cnt[i]=0;
	for(int i=0;i<n;i++)
		cnt[a[i]]++;
	for(int i=1;i<=10005;i++)
		cnt[i]+=cnt[i-1];
	for(int i=n-1;i>=0;i--)
		res[cnt[a[i]]--]=a[i];
	for(int i=0;i<n;i++)
		a[i]=res[i+1];
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	quick_sort();
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
}
