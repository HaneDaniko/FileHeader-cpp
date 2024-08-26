/*
 * diff.h
 * diff.h is a local C++ header file that 
 * used to compare and find the difference
 * of two file
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
#ifndef diff_h
#define diff_h 0
#endif
#include<string>
#include<cstring>
#include<cstdio>
#include<fstream>
#include<vector>
	class diff{public:int h=0;std::string version="1.2";}diff;
	std::string a,b;
	/*
		this fuction compare two file file_A,file_B
		if not equal,then returns true,else false.
	*/
	bool fc(char file_A[],char file_B[],bool display=false,bool debug_mode=false){
		if(display){printf("fc %s and %s\n",file_A,file_B);}
		bool eofA=false,eofB=false;std::ifstream f1,f2;f1.open(file_A);f2.open(file_B);
		while(1){
			if(f1.eof()){eofA=true;}
			else{f1>>a;}
			if(f2.eof()){eofB=true;}
			if(eofA and eofB){if(display) printf("File is equal.\n"); return false;}
			else if(eofA or eofB){if(display) printf("Length is not equal.\n");return true;}
			else{f2>>b;}
			if(debug_mode){printf("Compare: '%s' '%s'\n",a.c_str(),b.c_str());}
			if(a!=b){if(display){
			printf("Find Difference: \n");
			printf("%s: %s\n",file_A,a.c_str());
			printf("%s: %s\n",file_B,b.c_str());}
			return true;
			}
		}
	}
	bool fc(std::string file_A,std::string file_B,bool display=false,bool debug_mode=false){
		char A[200001],B[200001];
		strcpy(A,file_A.c_str());
		strcpy(B,file_B.c_str());
		return fc(A,B,display,debug_mode);
	}
	/*
		this function provide a read function
		used in read_out(*read)(std::ifstream) below
		using read<T> to use it, and it returns a
		vector<T>
	*/
	template<typename T>
	std::vector<T>read(std::ifstream x){
		std::vector<T>an;T re;
		while(!x.eof()){x>>re;an.push_back(re);}
		return an;
	}
	/*
		this function compares to file using
		specific fuction.
		before use it, please make sure the
		type func_out has operator == 
	*/
	template<typename read_out,typename func_out>
	bool fc(char file_A[],char file_B[],read_out(*read_t)(std::ifstream),func_out(*func)(read_out)){
		std::ifstream f1,f2;f1.open(file_A);f2.open(file_B);
		read_out A=read_t(f1);read_out B=read_t(f2);
		func_out x=func(A);func_out y=func(B);
		if(x==y) return false;else return true;
	}
/*--NAMESPACE HDK::DIFF  DIFF_H_--*/
