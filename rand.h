/*
 * rand.h
 * rand.h is a local C++ header file that 
 * used to create rand number
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
#ifndef rand_h
#define rand_h 0
#endif
#include<random>
namespace rander{
	std::vector<long long> list;
	int it,ssize;
	int reset(int size){if(size<=0)return -1;int seed=std::rand();std::mt19937 Rand(seed);ssize=size;it=0;list.clear();for(int i=1;i<=size;++i){list.push_back(Rand());}return seed;}
	#if std::CLOCKS_PER_SEC==1000
	int reset(){struct _timeb T;_ftime(&T);srand(T.millitm);return rander::reset(1000);}
	#else
	int reset(){std::random_device rd;std::uniform_int_distribution<unsigned long long> dist(0,2147483647);srand(dist(rd));return rander::reset(1000);}
	#endif
	std::vector<long long> randlist(int size){int seed=ssize;reset(size);std::vector<long long> ret=list;reset(seed);return ret;}
	int randabs(){if(ssize<=0)reset();int ret=list[it];it++;if(it>=ssize)reset(ssize);return abs(ret);}
	int rand(){if(ssize<=0)reset();int ret=list[it];it++;if(it>=ssize)reset(ssize);return ret;}
	int rand(int mod){int ret=rander::rand()%mod;return ret;}
	long long randabs(int mod){long long ret=abs(rander::rand());if(mod)ret%=mod;return ret;}
	long long rand(int l,int r){if(l<0)return rander::rand(0,r);long ret=rander::randabs(r-l+1)+l;return ret;}
	template<typename _T>_T from(std::vector<_T>p){long long ret=rander::randabs(p.size());return p[ret];}
	template<typename _T>void randsort(std::vector<_T>&p){for(int i=1;i<=p.size();++i){int x=rander::rand(0,p.size()-1),y=rander::rand(0,p.size()-1);swap(p[x],p[y]);}}
	template<typename _T>void randsort(_T &p,int from,int to){for(int i=1;i<=to-from+1;++i){int x=rander::rand(from,to),y=rander::rand(from,to);swap(p[x],p[y]);}}
};
/*--NAMESPACE HDK::RAND  RAND_H_--*/
