/*
 * io.h
 * io.h is a local C++ header file that 
 * include fast read
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
#ifndef io_h
#define io_h 0
#endif
#include<iostream>
namespace fastio{
	void rule(bool setting=false){std::ios::sync_with_stdio(setting);}
	inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-'){f=-1;}ch=getchar();}while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}return x*f;}
	inline int read(int &A){A=read();return A;}
    inline char read(char &A){A=getchar();return A;}
	inline void write(int A){if(A<0){putchar('-');A=-A;}if(A>9){write(A/10);}putchar(A%10+'0');}
    inline void write(long long A){if(A<0){putchar('-');A=-A;}if(A>9){write(A/10);}putchar(A%10+'0');}
	inline void write(char A){putchar(A);}
	inline void space(){putchar(' ');}
	inline void endl(){putchar('\n');}
	#define w(a) write(a)
	#define we(a) write(a);endl()
	#define ws(a) write(a);space()
}
namespace reader{
	template<typename T>
	inline void read(T& x){
		x=0;bool sym=0;char c=getchar();
		while(!isdigit(c)){sym^=(c=='-');c=getchar();}
		while(isdigit(c)){x=x*10+c-48;c=getchar();}
		if(sym)x=-x;
	}
	template<size_t N>
	inline void read(char (&str)[N]){
		size_t n=0;char c=getchar();
		while(n<N-1&&!isspace(c)){str[n]=c;c=getchar();++n;}
		str[n]=0;
	}
	template<typename T,size_t N>
	inline void read(T (&a)[N],int range=N){
		for(int i=1;i<=range-1;++i){read(a[i]);}
	}
	template<typename T,typename... Args>
	inline void read(T& x,Args&... args){
		read(x);read(args...);
	}
	template<typename T,typename T2>
	inline void readarray(T& x,T2& args){
		read(x);read(args,x);
	}
	#if std::CLOCKS_PER_SEC==1000
	template<typename func,typename... Args>
	inline void readact(int x,std::function<func>fu,Args&... args){
		for(int i=1;i<=x;++i){
			read(args...);
			fu(args...);
		}
	}
	#endif
}

/*--NAMESPACE HDK::DASTIO  IO_H_--*/
