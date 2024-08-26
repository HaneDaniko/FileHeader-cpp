/*
 * ordered_vector.h
 * ordered_vector.h is a local C++ header file that 
 * include a ordered int vector
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
#ifndef ordered_vector_h
#define ordered_vector_h 0
#endif
#include<vector>
#include<iostream>
#include<algorithm>
namespace hdk{
	template<typename T>
	class ordered_vector{
		private:
			std::vector<T>v;
			inline void push_back(T x){
				v.push_back(x);
			}
		public:
			ordered_vector(std::vector<T> x={}){
				v=x;
			}
			inline void clear(){
				v.clear();
			}
			inline int lower_bound(T x){
				int loc=std::lower_bound(v.begin(),v.end(),x)-v.begin();
				return loc;
			}
			inline int upper_bound(T x){
				int loc=std::upper_bound(v.begin(),v.end(),x)-v.begin();
				return loc;
			}
			inline void insert(T x){
				v.insert(v.begin()+lower_bound(x),x);
			}
			inline void remove(T x){
				int pos=lower_bound(x);
				if(pos!=v.size() and v[pos]==x) v.erase(v.begin()+pos);
			}
			inline void remove_all(T x){
				while(1){
					int pos=lower_bound(x);
					if(pos==v.size()) break;
					if(v[pos]!=x) break;
					v.erase(v.begin()+pos);
				}
			}
			inline std::vector<T> it(){
				return v;
			}
			T operator [](int x){
				if(x==-1) return -1;
				return v[x];
			}
			inline void remove_larger(int x,bool include_this=false){
				int pos=upper_bound(x);
				for(int i=v.size()-1;i>=pos;--i){
					v.erase(v.begin()+i);
				}
				if(include_this) remove_all(x);
			}
			inline void print(char devide=' ',char ending='\n'){
				for(T i:v) std::cout<<i<<devide;
				std::cout<<ending;
			}
			inline void remove_smaller(int x,bool include_this=false){
				int pos=lower_bound(x);
				for(int i=pos-1;i>=0;--i){
					v.erase(v.begin()+i);
				}
				if(include_this) remove_all(x);
			}
			inline int findpre(T x){
				int pos=lower_bound(x)-1;
				if(pos<0) return -1;
				return pos;
			}
			inline int findnext(T x){
				int pos=upper_bound(x);
				if(pos>=v.size()) return -1;
				return pos;
			}
			inline T nearestabs(T x){
				int p=findpre(x),n=findnext(x),ans=0x7fffffff;
				if(p>=0) ans=min(ans,x-v[p]);
				if(n>=0) ans=min(ans,v[n]-x);
				return ans;
			}
			inline T remove_nearestabs(T x){
				if(v.empty()) return 0;
				int p=findpre(x),n=findnext(x),ans=0x7fffffff;bool isp=0;
				if(p>=0) if(x-v[p]<ans) ans=x-v[p],isp=1;
				if(n>=0) if(v[n]-x<ans) ans=v[n]-x,isp=0;
				if(isp) v.erase(v.begin()+p);
				else v.erase(v.begin()+n);
				return ans;
			}
			inline int locate_nearestabs(T x){
				if(v.empty()) return -1;
				int p=findpre(x),n=findnext(x),ans=0x7fffffff;bool isp=0;
				if(p>=0) if(x-v[p]<ans) ans=x-v[p],isp=1;
				if(n>=0) if(v[n]-x<ans) ans=v[n]-x,isp=0;
				if(isp) return p;
				else return n;
			}
			inline int count(T x){
				int b=lower_bound(x),e=upper_bound(x);
				return e-b;
			}
			inline bool find(T x){
				return count(x);
			}
			inline bool empty(){
				return v.empty();
			}
			inline int size(){
				return v.size();
			}
			inline int find_maxnum(int rank){
				if(rank>v.size() or rank<1) return -1;
				return v[v.size()-rank];
			}
			inline int find_minnum(int rank){
				if(rank>v.size() or rank<1) return -1;
				return v[rank-1];
			}
			ordered_vector<T> operator +(ordered_vector<T> x){
				ordered_vector<T> ans;
				int i=0,j=0;
				while(i<size() and j<x.size()){
					if(v[i]<x[j]){
						ans.push_back(v[i]);
						i++;
					}
					else{
						ans.push_back(x[j]);
						j++;
					}
				}
				while(i<size()){
					ans.push_back(v[i]);
					i++;
				}
				while(j<x.size()){
					ans.push_back(x[j]);
					j++;
				}
				return ans;
			}
			void operator +=(ordered_vector<T> x){
				*this=(*this)+x;
			}
	};
}
using namespace hdk;
/*--NAMESPACE HDK  ORDERED_VECTOR_H_--*/
