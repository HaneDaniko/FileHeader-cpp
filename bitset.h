/*
 * bitset.h
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
#ifndef bitset_h
#define bitset_h 0
#endif
#include<bits/stdc++.h>
using namespace std;
namespace hdk{
	unsigned long long maxull=(1ull<<63)-1+(1ull<<63);
	template<int siz>
	class bitset{
		private:
			unsigned long long s[int(ceil(siz/64.0))]={};
		public:
			inline int size(){
				return siz;
			}
			inline int array_size(){
				return int(ceil(siz/64.0));
			}
			inline void clear(){
				for(int i=0;i<=array_size()-1;++i){
					s[i]=0;
				}
			}
			bool operator [](int x){
				int pos=x/64;
				return ((s[pos]>>(x%64))&1);
			}
			inline unsigned long long &at(int pos){
				return s[pos];
			}
			inline void upset_down(int pos){
				int x=pos/64;
				s[x]^=(1ull<<(pos%64));
			}
			inline void upset_down(int l,int r){
				int pos1=l/64,pos2=r/64;
				if(pos1==pos2){
					for(int i=l;i<=r;++i){
						upset_down(i);
					}
					return;
				}
				for(int i=pos1+1;i<=pos2-1;++i){
					if(s[i]==0){
						s[i]=maxull;
					}
					else if(s[i]==maxull){
						s[i]=0;
					}
					else{
						for(int j=i*64;j<=(i+1)*64-1;++j){
							upset_down(j);
						}
					}
				}
				for(int i=l;i<=(pos1+1)*64-1;++i){
					upset_down(i);
				}
				for(int i=pos2*64;i<=r;++i){
					upset_down(i);
				}
			}
			inline void set(unsigned long long x){
				*this=x;
			}
			inline void set(int pos,bool value){
				if((*this)[pos]!=value){
					this->upset_down(pos);
				}
			}
			inline void set(int l,int r,bool value){
				int pos1=l/64,pos2=r/64;
				if(pos1==pos2){
					for(int i=l;i<=r;++i){
						set(i,value);
					}
					return;
				}
				if(value){
					for(int i=pos1+1;i<=pos2-1;++i){
						s[i]=maxull;
					}
				}
				else{
					for(int i=pos1+1;i<=pos2-1;++i){
						s[i]&=0;
					}
				}
				for(int i=l;i<=(pos1+1)*64-1;++i){
					set(i,value);
				}
				for(int i=pos2*64;i<=r;++i){
					set(i,value);
				}
			}
			hdk::bitset<siz> operator ~(){
				hdk::bitset<siz>ans;
				ans=*this;
				ans.upset_down(0,siz-1);
				return ans;
			}
			void operator =(unsigned long long x){
				s[0]=x;
			}
			void operator =(string x){
				for(int i=(int)x.length()-1;i>=0;--i){
					this->set(x.length()-1-i,x[i]-'0');
				}
			}
			hdk::bitset<siz> operator +(hdk::bitset<siz>A){
				hdk::bitset<siz>ans;
				int x=0;
				for(int i=0;i<=siz-1;++i){
					x+=(*this)[i]+A[i];
					ans.set(i,x&1);
					x>>=1;
				}
				return ans;
			}
			void operator +=(hdk::bitset<siz>A){
				*this=*this+A;
			}
			void print(bool iscomplete_print){
				bool iszero=iscomplete_print;
				for(int i=siz;i>=0;--i){
					bool res=(*this)[i];
					if(res==1){
						iszero=true;
					}
					if(iszero){
						putchar(res+'0');
					}
				}
				if(!iszero) putchar('0');
				putchar('\n');
			}
			void print(char devide=0,char end='\n',bool iscomplete_print=false){
				bool iszero=iscomplete_print;
				for(int i=siz;i>=0;--i){
					bool res=(*this)[i];
					if(res==1){
						iszero=true;
					}
					if(iszero){
						putchar(res+'0');
						if(devide!=0) putchar(devide);
					}
				}
				if(!iszero) putchar('0');
				if(end!=0) putchar(end);
			}
			hdk::bitset<siz> operator &(hdk::bitset<siz>A){
				hdk::bitset<siz> ans;
				for(int i=0;i<=siz-1;++i){
					ans.set(i,(*this)[i]&A[i]);
				}
				return ans;
			}
			hdk::bitset<siz> operator &(unsigned long long x){
				hdk::bitset<siz> A,ans;A.set(x);
				for(int i=0;i<=siz-1;++i){
					ans.set(i,(*this)[i]&A[i]);
				}
				return ans;
			}
			void operator &=(hdk::bitset<siz>A){
				*this=*this&A;
			}
			void operator &=(unsigned long long x){
				*this=*this&x;
			}
			hdk::bitset<siz> operator |(hdk::bitset<siz>A){
				hdk::bitset<siz> ans;
				for(int i=0;i<=siz-1;++i){
					ans.set(i,(*this)[i]|A[i]);
				}
				return ans;
			}
			hdk::bitset<siz> operator |(unsigned long long x){
				hdk::bitset<siz> A,ans;A.set(x);
				for(int i=0;i<=siz-1;++i){
					ans.set(i,(*this)[i]|A[i]);
				}
				return ans;
			}
			void operator |=(hdk::bitset<siz>A){
				*this=*this|A;
			}
			void operator |=(unsigned long long x){
				*this=*this|x;
			}
			hdk::bitset<siz> operator ^(hdk::bitset<siz>A){
				hdk::bitset<siz> ans;
				for(int i=0;i<=siz-1;++i){
					ans.set(i,(*this)[i]^A[i]);
				}
				return ans;
			}
			hdk::bitset<siz> operator ^(unsigned long long x){
				hdk::bitset<siz> A,ans;A.set(x);
				for(int i=0;i<=siz-1;++i){
					ans.set(i,(*this)[i]^A[i]);
				}
				return ans;
			}
			void operator ^=(hdk::bitset<siz>A){
				*this=*this^A;
			}
			void operator ^=(unsigned long long x){
				*this=*this^x;
			}
			inline bool empty(){
				bool x=0;
				for(int i=0;i<=array_size()-1;++i){
					x+=s[i];
				}
				return !x;
			}
			bool operator !(){
				return !empty();
			}
			inline unsigned long long it(){
				return s[0];
			}
			inline void set(){
				for(int i=0;i<=array_size()-1;++i){
					s[i]=maxull;
				}
			}
			inline void reset(){
				clear();
			}
			inline int count(){
				int ans=0;
				for(int i=0;i<=siz-1;++i){
					if((*this)[i]==1) ans++;
				}
				return ans;
			}
			bool operator <(hdk::bitset<siz> A){
				for(int i=array_size()-1;i>=0;--i){
					if(s[i]!=A.s[i]){
						return s[i]<A.s[i];
					}
				}
				return false;
			}
			bool operator <(unsigned long long x){
				hdk::bitset<siz>A;A=x;
				for(int i=array_size()-1;i>=0;--i){
					if(s[i]!=A.s[i]){
						return s[i]<A.s[i];
					}
				}
				return false;
			}
			bool operator ==(hdk::bitset<siz> A){
				for(int i=array_size()-1;i>=0;--i){
					if(s[i]!=A.s[i]){
						return false;
					}
				}
				return true;
			}
			bool operator ==(unsigned long long x){
				hdk::bitset<siz>A;A=x;
				for(int i=array_size()-1;i>=0;--i){
					if(s[i]!=A.s[i]){
						return false;
					}
				}
				return true;
			}
			inline bool test(int pos){
				return (*this)[pos];
			}
			inline string to_string(bool complete_print=false){
				string ans;
				if(complete_print){
					for(int i=siz-1;i>=0;--i){
						ans.push_back((*this)[i]+'0');
					}
					return ans;
				}
				else{
					bool iszero=false;
					for(int i=siz-1;i>=0;--i){
						bool res=(*this)[i];
						if(res==1) iszero=true;
						if(iszero) ans.push_back(res+'0');
					}
					if(!iszero) ans.push_back('0');
					return ans;
				}
			}
			bool operator !=(hdk::bitset<siz> A){
				return !(*this==A);
			}
			bool operator !=(unsigned long long x){
				return !(*this==x);
			}
			bool operator >(hdk::bitset<siz> A){
				return !(*this<A or *this==A);
			}
			bool operator >(unsigned long long x){
				return !(*this<x or *this==x);
			}
			bool operator >=(hdk::bitset<siz> A){
				return (*this>A or *this==A);
			}
			bool operator >=(unsigned long long x){
				return (*this>x or *this==x);
			}
			bool operator <=(hdk::bitset<siz> A){
				return (*this<A or *this==A);
			}
			bool operator <=(unsigned long long x){
				return (*this<x or *this==x);
			}
			inline bool all(){
				for(int i=0;i<=siz-1;++i){
					if((*this)[i]==0) return false;
				}
				return true;
			}
			inline bool any(){
				for(int i=0;i<=siz-1;++i){
					if((*this)[i]==1) return true;
				}
				return false;
			}
			inline bool none(){
				return !any();
			}
			inline void flip(){
				*this=~*this;
			}
			friend ostream& operator<<(ostream& output,hdk::bitset<siz> inx){
				inx.print(0,0);
				return output;
			}
			friend istream& operator>>(istream& input,hdk::bitset<siz> inx){
				unsigned long long x;
			   	input>>x;inx=x;
			   	return input;
			}
			friend hdk::bitset<siz> max(hdk::bitset<siz>A,hdk::bitset<siz>B){
				if(A>B) return A;
				else return B;
			}
			friend hdk::bitset<siz> min(hdk::bitset<siz>A,hdk::bitset<siz>B){
				if(A<B) return A;
				else return B;
			}
			hdk::bitset<siz> operator <<(int x){
				hdk::bitset<siz> ans;
				for(int i=siz-1;i>=x;--i){
					ans.set(i,(*this)[i-x]);
				}
				return ans;
			}
			hdk::bitset<siz> operator >>(int x){
				hdk::bitset<siz> ans;
				for(int i=siz-1-x;i>=0;--i){
					ans.set(i,(*this)[i+x]);
				}
				return ans;
			}
	};
}
using namespace hdk;
/*--NAMESPACE HDK  BITSET_H_--*/
