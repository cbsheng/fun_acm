#include<iostream>
using namespace std;

const int size=10000;
const int mod=9901;

__int64 sum(__int64 p,__int64 n);  
__int64 power(__int64 p,__int64 n);  //反复平方法求 (p^n)%mod

int main(void)
{
	int A,B;
	int p[size];//A的分解式,p[i]^n[i]
	int n[size];

	while(cin>>A>>B)
	{
		int i,k=0;  //p,n指针

		/*常规做法：分解整数A (A为非质数)*/
		for(i=2;i*i<=A;)   //根号法+递归法
		{
			if(A%i==0)
			{
				p[k]=i;
				n[k]=0;
				while(!(A%i))
				{
					n[k]++;
					A/=i;
				}
				k++;
			}
			if(i==2)  //奇偶法
				i++;
			else
				i+=2;
		}
		/*特殊判定：分解整数A (A为质数)*/
		if(A!=1)
		{
			p[k]=A;
			n[k++]=1;
		}

		int ans=1;  //约数和
		for(i=0;i<k;i++)
			ans=(ans*(sum(p[i],n[i]*B)%mod))%mod;  //n[i]*B可能会超过int，因此用__int64

		cout<<ans<<endl;
	}
	return 0;
}

__int64 sum(__int64 p,__int64 n)  //递归二分求 (1 + p + p^2 + p^3 +...+ p^n)%mod
{                          //奇数二分式 (1 + p + p^2 +...+ p^(n/2)) * (1 + p^(n/2+1))
	if(n==0)               //偶数二分式 (1 + p + p^2 +...+ p^(n/2-1)) * (1+p^(n/2+1)) + p^(n/2)
		return 1;
	if(n%2)  //n为奇数,
		return (sum(p,n/2)*(1+power(p,n/2+1)))%mod;
	else     //n为偶数
		return (sum(p,n/2-1)*(1+power(p,n/2+1))+power(p,n/2))%mod;
}

__int64 power(__int64 p,__int64 n)  //反复平方法求(p^n)%mod
{
	__int64 sq=1;
	while(n>0)
	{
        if(n%2)
            sq=(sq*p)%mod;
        n/=2;
        p=p*p%mod;
    }
	return sq;
}