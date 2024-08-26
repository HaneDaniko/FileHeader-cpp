/*
 * demap.h
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
#ifndef demap_h
#define demap_h 0
#endif
#include<map>
template<typename F,typename S>
class demap{
	private:
		std::map<F,S> f;
		std::map<S,F> s;
	public:
		void add(F Key,S Text){f[Key]=Text;s[Text]=Key;}
		S find_text(F Key){return f[Key];}
		F find_key(S Text){return s[Text];}
		bool count_key(F Key){return f.count(Key);}
		bool count_text(S Text){return s.count(Text);}
		void clear(){s.clear();f.clear();}
		bool empty(){return s.empty();}
};
/*--NAMESPACE HDK::DEMAP   DEMAP_H_--*/
