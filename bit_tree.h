/*
 * bit.h
 * 
 * 
 * Author : HaneDaniko
 * Create Time: 25/7/2024
 * 
 * To use this header, you must import this
 * file into you programme
**/
#ifndef HDK
#define HDK 0
#endif
#ifndef bit_h
#define bit_h 0
#endif
#if std::CLOCKS_PER_SEC==1000
#include<hdk_string.h>
#else
#include"./hdk_string.h"
#endif
class BIT{
	private:
		long long d[100001],di[100001],s[100001];
		inline int lowbit(int x){
			return x&-x;
		}
		void change(long long *c,int x,int y){
			while(x<=n){
				c[x]+=y;
				x+=lowbit(x);
			}
		}
		long long sum(long long *c,int x){
			long long ans=0;
			while(x>0){
				ans+=c[x];
				x-=lowbit(x);
			}
			return ans;
		}
		long long sum_(int end){
			return s[end]+(end+1)*sum(d,end)-sum(di,end);
		}
	public:
		int n;
		void clear(){
			memset(d,0,sizeof(d));
			memset(di,0,sizeof(di));
			memset(s,0,sizeof(s));
		}
		long long sum(int l,int r){
			return sum_(r)-sum_(l-1);
		}
		void change(int x,int y,int changevalue){
			change(d,x,changevalue);
			change(d,y+1,-changevalue);
			change(di,x,changevalue*x);
			change(di,y+1,-changevalue*(y+1));
		}
		void make_sum(int id,int x){
			s[id]=s[id-1]+x;
		}
		long long sum(int id){
			return sum(id,id);
		}
		void change(int id,int changevalue){
			change(id,id,changevalue);
		}
};
/*-- NAMESPACE HDK::BIT  BIT_H_--*/
