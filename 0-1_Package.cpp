#include <bits/stdc++.h>
using namespace std;
struct cmdt{//Commodity����Ʒ 
	int p;//�۸� 
	double w;//���� 
} a[1000005],s[1000005];//a�����¼ÿ����Ʒ��s�����¼��ż 
int pl[1000005],pr[100005];//pl[i]��¼s[i]����˵�λ�ã�pr[i]��¼���Ҷ� 
int main(){
	int n;//nΪ��Ʒ����  
	double M;//MΪ�������� 
	scanf("%d%lf",&n,&M);
	for(int i=1;i<=n;i++){
		scanf("%d%lf",&a[i].p,&a[i].w);
	}
	s[0].p=s[0].w=0;//��ʼ�� 
	pl[0]=pr[0]=0;
	for(int i=1;i<=n;i++){
		pl[i]=pr[i-1]+1;//s[i]����ָ��Ϊs[i-1]��ָ��+1 
		int p1=pl[i-1],p2=pl[i-1],p3=pl[i];//p1�����ұ���s[i-1]��p2��¼s[i-1]����һ�����ܱ�����s[i]��Ԫ��
		for(p1;p1<=pr[i-1];p1++){//p3��¼s[i]Ŀǰ���һ��Ԫ�ص���һλ 
			int pp=s[p1].p+a[i].p;//��s[i-1]�е�Ԫ�����ɵ���ż 
			double ww=s[p1].w+a[i].w;
			if(ww>M) break;//�������ڱ������������ѭ������Ϊ��������������� 
			while(p2<=pr[i-1]&&s[p2].w<ww){//������С�ڸ���ż��s[i-1]�е�Ԫ��ȫ������s[i] 
				s[p3]=s[p2];
				p2++,p3++;
			}
			if(pp<s[p2-1].p) continue;//��֧�䣬���� 
			if(p2>pr[i-1]){//p2���������е�Ԫ�أ���ǰ��żû�б�֧�䣬�����s[i] 
				s[p3].p=pp;
				s[p3].w=ww;
				p3++;
			}
			else if(p2<=pr[i-1]&&s[p2].w>=ww){
				if(s[p2].w==ww){//�������뵱ǰ��ż��ȣ�ȡp��ļ���s[i] 
					s[p3].p=max(pp,s[p2].p),s[p3].w=ww,p2++,p3++;
				}
				else{
					s[p3].p=pp,s[p3].w=ww,p3++;//����ǰ��ż����s[i] 
					while(p2<=pr[i-1]&&s[p2].p<=pp){//����ֵС��������֧�� 
						p2++;
					}
				}
			}
		}
		if(p2<=pr[i-1]){
			s[p3++]=s[p2++];//��s[i-1]��ʣ���Ԫ�ؼ��� 
		}
		pr[i]=p3-1;//s[i]��ָ��Ϊѭ��������p3��ǰһ��λ�� 
	}
	printf("Price:%d Weight:%.1lf\n",s[pr[n]].p,s[pr[n]].w);
	printf("The commodities chosen:");
	int p=s[pr[n]].p;
	double w=s[pr[n]].w;
	//(p,w)�����Ͻǵ���ż��������ʼѰ����Щ��Ʒ���Ž����� 
	for(int i=n;i>=1;i--){
		bool flag=0;
		for(int j=pl[i-1];j<=pr[i-1];j++){
			if(p==s[j].p&&w==s[j].w) flag=1;//��s[i-1]���кͣ�p��w����ż��ͬ��Ԫ�أ����i��Ԫ��û�б��Ž����� 
		}
		if(flag) continue;
		else{
			printf("%d ",i);
			p-=a[i].p;//������ż 
			w-=a[i].w;
		}
	}
	return 0;
}
