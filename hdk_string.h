/*
 * string.h
 * string.h is a local C++ header file that 
 * include a infinity digits char vector
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
#ifndef string_h
#define string_h 0
#endif
#include<string>
#include<map>
#include<string.h>
#include<iostream>
namespace hdk{
	const int siz=100001;
		class string{
			private:
				char s[siz];
				int lengtht=0;
				int start=0;
			public:
				void operator =(const std::string x){
					memset(s,0,sizeof s);
					for(int i=0;i<=(int)x.length()-1;++i){
						s[i]=x[i];
					}
					lengtht=x.length();
				}
				void operator =(const string x){
					memset(s,0,sizeof s);
					for(int i=0;i<=x.start+x.lengtht-1;++i){
						s[i]=x.s[i];
					}
					start=x.start;
					lengtht=x.lengtht;
				}
				inline int length(){
					return lengtht;
				}
				void check_start(){
					for(int i=0;i<=siz;++i){
						if(s[i]){
							start=i;
							break;
						}
					}
				}
				void print(char ending=0){
					std::cout<<s+start;
					if(ending!=0) std::cout<<ending;
				}
				void input(int start_pos=0){
					std::cin>>(s+start_pos);
					start=start_pos;
					lengtht=strlen(s+start_pos);
				}
				inline void push_back(char x){
					s[start+lengtht]=x;
					lengtht++;
				}
				string operator +(char x){
					string ans=*this;
					ans.push_back(x);
					return ans;
				}
				string operator +(string &x){
					string ans=*this;
					for(int i=x.start;i<=x.start+x.length()-1;++i){
						ans.push_back(x.s[i]);
					}
					return ans;
				}
				void operator +=(string &x){
					*this=*this+x;
				}
				void operator +=(char x){
					push_back(x);
				}
				char* begin(){
					return &s[start];
				}
				char* end(){
					return &s[start+lengtht];
				}
				char operator[](int x){
					return s[x];
				}
				string substr(int substart,int sublength=siz){
					string ans;
					for(int i=start+substart;i<=start+substart+sublength-1;++i){
						if(i>=start+lengtht) break;
						ans.push_back(s[i]);
					}
					return ans;
				}
				string operator *(int x){
					string ans;
					while(x--) ans+=*this;
					return ans;
				}
				void operator *=(int x){
					*this=(*this)*x;
				}
				unsigned long long hash(int l,int r,int num=233,unsigned long long mod=0){
					unsigned long long ans=0;
					for(int i=l;i<=r;++i){
						ans=ans*num+s[i];
						if(mod) ans%=mod;
					}
					return ans;
				}
				unsigned long long hashall(int num=233,unsigned long long mod=0){
					unsigned long long ans=0;
					for(int i=start;i<=start+lengtht-1;++i){
						ans=ans*num+s[i];
						if(mod) ans%=mod;
					}
					return ans;
				}
				inline bool empty(){
					if(s[start]) return false;
					return true;
				}
				inline void pop_back(){
					if(!empty()){
						s[start+lengtht-1]=0;
						lengtht--;
					}
				}
				inline void clear(){
					memset(s,0,sizeof s);
					start=0;
					lengtht=0;
				}
				string reverse(string x){
					string ans;
					for(int i=x.start+x.length()-1;i>=x.start;--i){
						ans.push_back(x[i]);
					}
					return ans;
				}
				void reverse(){
					*this=reverse(*this);
				}
				friend std::ostream& operator<<(std::ostream& output,string& inx){
					inx.print();
					return output;
				}
				friend std::istream& operator>>(std::istream& input,string& inx){
					inx.input();
					inx.check_start();
					return input;
				}
				bool check_mir(){
					int i=start,j=start+lengtht-1;
					while(i<=j){
						if(s[i]!=s[j]) return false;
						i++;j--;
					}
					return true;
				}
				int count(char x){
					int ans=0;
					for(int i=start;i<=start+lengtht-1;++i){
						if(s[i]==x) ans++;
					}
					return ans;
				}
				bool operator ==(string x){
					if(x.length()!=length()) return false;
					for(int i=0;i<=x.length()-1;++i){
						if(x[x.start+i]!=s[start+i]) return false;
					}
					return true;
				}
				bool operator <(string x){
					if(x.length()!=length()){
						return x.length()>length();
					}
					for(int i=0;i<=x.length()-1;++i){
						if(x[x.start+i]!=s[start+i]){
							return s[start+i]<x[x.start+i];
						}
					}
					return false;
				}
				bool operator >(string x){
					return ((!(*this==x)) and (!(*this<x)));
				}
				bool operator <=(string x){
					return ((*this<x) or (*this==x));
				}
				bool operator >=(string x){
					return ((*this>x) or (*this==x));
				}
				inline int size(){
					return length();
				}
				inline int start_pos(){
					return start;
				}
				inline void insert(int pos,string x){
					for(int i=start+length()-1;i>=start+pos;--i){
						s[i+x.length()]=s[i];
					}
					for(int i=start+pos;i<=start+pos+x.length()-1;++i){
						s[i]=x[x.start+i-start-pos];
					}
					lengtht+=x.lengtht;
				}
				inline void insert(int pos,std::string x){
					for(int i=start+length()-1;i>=start+pos;--i){
						s[i+x.length()]=s[i];
					}
					for(int i=start+pos;i<=(int)(start+pos+x.length()-1);++i){
						s[i]=x[i-start-pos];
					}
					lengtht+=x.length();
				}
				inline void insert(int pos,char x){
					for(int i=start+length()-1;i>=start+pos;--i){
						s[i+1]=s[i];
					}
					s[start+pos]=x;
					lengtht++;
				}
				inline void erase(int pos){
					for(int i=start+pos;i<=start+length()-2;++i){
						s[i]=s[i+1];
					}
					s[start+length()-1]=0;
					lengtht--;
				}
				inline void erase(int l,int r){
					for(int i=start+l;i<=start+length()-1-(r-l+1);++i){
						s[i]=s[i+r-l+1];
					}
					for(int i=start+length()-(r-l+1);i<=start+length()-1;++i){
						s[i]=0;
					}
					lengtht-=(r-l+1);
				}
				inline bool find(string x){
					int ppos=0;
					for(int i=start;i<=start+length()-1;++i){
						if(s[i]==x[x.start+ppos]){
							ppos++;
							if(ppos==x.length()){
								return true;
							}
						}
						else{
							ppos=0;
						}
					}
					return false;
				}
				inline bool find(std::string x){
					int ppos=0;
					for(int i=start;i<=start+length()-1;++i){
						if(s[i]==x[ppos]){
							ppos++;
							if(ppos==(int)x.length()){
								return true;
							}
						}
						else{
							ppos=0;
						}
					}
					return false;
				}
				void lowercase(){
					for(int i=start;i<=start+length()-1;++i){
						if(s[i]>='A' and s[i]<='Z'){
							s[i]-=('A'-'a');
						}
					}
				}
				void lowercase(int l,int r){
					for(int i=start+l;i<=start+r;++i){
						if(s[i]>='A' and s[i]<='Z'){
							s[i]-=('A'-'a');
						}
					}
				}
				void uppercase(){
					for(int i=start;i<=start+length()-1;++i){
						if(s[i]>='a' and s[i]<='z'){
							s[i]+=('A'-'a');
						}
					}
				}
				void uppercase(int l,int r){
					for(int i=start+l;i<=start+r;++i){
						if(s[i]>='a' and s[i]<='z'){
							s[i]+=('A'-'a');
						}
					}
				}
				void map_replace(std::map<char,char> mp){
					for(int i=start;i<=start+length()-1;++i){
						if(mp.count(s[i])){
							s[i]=mp[s[i]];
						}
					}
				}
				void map_replace(std::map<char,char> mp,int l,int r){
					for(int i=start+l;i<=start+r;++i){
						if(mp.count(s[i])){
							s[i]=mp[s[i]];
						}
					}
				}
		};
}
using namespace hdk;
/*--NAMESPACE HDK  STRING_H_--*/
