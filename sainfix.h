/*
 * sainfix.h
 * sainfix.h is a local C++ header file that 
 * include a infinity digits int vector that
 * just suggest operator +
 * 
 * Author : HaneDaniko
 * Create Time: 25/7/2024
 * 
 * To use this header, you must import this
 * file into you programme
**/
#if std::CLOCKS_PER_SEC==1000
#ifndef HDK
#define HDK 0
#endif
#ifndef sainfix_h
#define sainfix_h 0
#endif
#include<_mingw.h>
#include<string>
#include<iosfwd>
#include<iostream>
namespace hdk{
	const size_t fixsize=10000;
	class StringAddition_InFix{
		private:
			std::string x="00";
			inline void fixed(int size){
				if(size<=(int)x.length())return;
				std::string res;
				for(int i=1;i<=(int)size-(int)x.length();++i){
					res.push_back('0');
				}
				for(int i=0;i<=(int)x.length()-1;++i){
					res.push_back(x[i]);
				}
				x=res;
			}
			inline void refixed(){
				std::string res;bool is0=false;
				res.push_back('0');
				for(int i=0;i<=(int)x.length()-1;++i){
					if(x[i]!='0'||is0){
						is0=true;
						res.push_back(x[i]);
					}
				}
				x=res;
			}
		public:
			void operator =(std::string inx){
				x.push_back('0');
				for(int i=0;i<=(int)inx.length()-1;++i){
					x.push_back(inx[i]);
				}
			}
			void operator =(long long inx){
				x.clear();std::string ans;
				int r=inx;
				while(r){
					ans.push_back(r%10+'0');
					r/=10;
				}
				x.push_back('0');
				for(int i=ans.size()-1;i>=0;--i){
					x.push_back(ans[i]);
				}
			}
			std::string it(){
				std::string res;
				for(int i=1;i<=(int)x.length()-1;++i){
					res.push_back(x[i]);
				}
				if(res.empty()) res="0";
				return res;
			}
			StringAddition_InFix operator +(StringAddition_InFix a){
				StringAddition_InFix ans;ans=a;
				if(x.length()>ans.x.length()){
					ans.fixed(x.length());
				}
				else fixed(ans.x.length());
				for(int i=std::max(x.length(),ans.x.length())-1;i>=1;--i){
					int np=(ans.x[i]-'0'+x[i]-'0');
					if(np>=10) ans.x[i-1]+=np/10;
					ans.x[i]=np%10+'0';
				}
				ans.refixed();refixed();
				return ans;
			}
			StringAddition_InFix operator +(long long a){
				StringAddition_InFix r;r=a;
				return *this+r;
			}
			void operator +=(StringAddition_InFix a){
				*this=*this+a;
			}
			void operator +=(long long a){
				*this=*this+a;
			}
			friend std::ostream& operator<<(std::ostream& output,StringAddition_InFix& inx){
				output<<inx.it()<<std::endl;
				return output;
			}
			friend std::istream& operator>>(std::istream& input,StringAddition_InFix& inx){
			   input>>inx.x;
			   inx.fixed(inx.x.length()+1);
			   return input;
			}
	};
	typedef StringAddition_InFix Int;
	Int max(Int &la,Int &lb){
		if(la.it()>lb.it()) return la;
		else return lb;
	}
	Int min(Int &la,Int &lb){
		if(la.it()<lb.it()) return lb;
		else return la;
	}
}
#endif
/*--NAMESPACE HDK::SAI  SAINFIX_H_--*/
