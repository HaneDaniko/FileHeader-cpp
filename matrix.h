/*
 * matrix.h
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
#ifndef matrix_h
#define matrix_h 0
#endif
#include<iostream>
template<typename T,int maxlen>
class matrix{
	private:
		int n,m,mod;
		bool ifmod;
		T mat[maxlen+1][maxlen+1];
	public:
		int get_n(){
			return n;
		}
		int get_m(){
			return m;
		}
		int get_mod(){
			return mod;
		}
		T& get_matrix(int x,int y){
			return mat[x][y];
		}
		T* operator[](int x){
			return mat[x];
		}
		void clear(){
			for(int i=1;i<=n;++i){
				for(int j=1;j<=m;++j){
					mat[i][j]=0;
				}
			}
			n=0;
			m=0;
			ifmod=false;
			mod=0;
		}
		void setmod(int x){
			if(x==0){
				ifmod=false;
			}
			else{
				ifmod=true;
			}
			mod=x;
		}
		void resize(int nsize,int msize){
			n=nsize;
			m=msize;
		}
		void fillmain(int x){
			for(int i=1;i<=n;++i){
				mat[i][i]=x;
			}
		}
		void fillsec(int x){
			for(int i=1;i<=n;++i){
				mat[i][n-i+1]=x;
			}
		}
		void fill(int x){
			for(int i=1;i<=n;++i){
				for(int j=1;j<=m;++j){
					mat[i][j]=x;
				}
			}
		}
		void fill(int x,int startn,int endn,int startm,int endm){
			for(int i=startn;i<=endn;++i){
				for(int j=startm;j<=endm;++j){
					mat[i][j]=x;
				}
			}
		}
		void opposite(){
			for(int i=1;i<=n;++i){
				for(int j=1;j<=m;++j){
					mat[i][j]*=-1;
				}
			}
		}
		void packed_clear(int nsize,int msize,int filln,int mod){
			clear();
			resize(nsize,msize);
			setmod(mod);
			fill(filln);
		}
		void input(){
			std::cin>>n>>m;
			for(int i=1;i<=n;++i){
				for(int j=1;j<=m;++j){
					std::cin>>mat[i][j];
				}
			}
		}
		void inputn(int nsize){
			n=nsize;
			std::cin>>m;
			for(int i=1;i<=n;++i){
				for(int j=1;j<=m;++j){
					std::cin>>mat[i][j];
				}
			}
		}
		void inputm(int msize){
			m=msize;
			std::cin>>n;
			for(int i=1;i<=n;++i){
				for(int j=1;j<=m;++j){
					std::cin>>mat[i][j];
				}
			}
		}
		void input(int nsize,int msize){
			n=nsize;
			m=msize;
			for(int i=1;i<=n;++i){
				for(int j=1;j<=m;++j){
					std::cin>>mat[i][j];
				}
			}
		}
		void print(){
			for(int i=1;i<=n;++i){
				for(int j=1;j<=m;++j){
					std::cout<<mat[i][j]<<" ";
				}
				std::cout<<std::endl;
			}
		}
		matrix operator *(const matrix &A)const{
			matrix p;
			p.packed_clear(n,A.m,0,mod);
			for(int i=1;i<=n;++i){
				for(int j=1;j<=A.m;++j){
					for(int k=1;k<=m;++k){
						if(ifmod){
							p.mat[i][j]+=(mat[i][k]*A.mat[k][j])%mod;
							p.mat[i][j]%=mod;
						}
						else{
							p.mat[i][j]+=mat[i][k]*A.mat[k][j];
						}
					}
				}
			}
			return p;
		}
		matrix operator +(const matrix &A)const{
			matrix p;
			p.packed_clear(n,m,0,mod);
			for(int i=1;i<=n;++i){
				for(int j=1;j<=m;++j){
					if(ifmod){
						p.mat[i][j]=(mat[i][j]+A.mat[i][j])%mod;
					}
					else{
						p.mat[i][j]=mat[i][j]+A.mat[i][j];
					}
				}
			}
			return p;
		}
		matrix operator -(const matrix &A)const{
			matrix p;
			p.packed_clear(n,m,0,mod);
			for(int i=1;i<=n;++i){
				for(int j=1;j<=m;++j){
					if(ifmod){
						p.mat[i][j]=(mat[i][j]-A.mat[i][j])%mod;
					}
					else{
						p.mat[i][j]=mat[i][j]-A.mat[i][j];
					}
				}
			}
			return p;
		}
		matrix operator ^(const long long times)const{
			matrix p;
			p.packed_clear(n,m,1,mod);
			for(int i=1;i<=times;++i){
				p=p*(*this);
			}
			return p;
		}
		matrix operator |(long long times)const{
			matrix base,p;
			p.packed_clear(n,m,0,mod);
			base.packed_clear(n,m,0,mod);
			base=(*this);
			p.fillmain(1);
			if(times<=0){
				return p;
			}
			while(times){
				if(times&1){
					p=p*base;
				}
				base=base*base;
				times>>=1;
			}
			return p;
		}
		matrix operator *(const int x)const{
			matrix p;
			p.packed_clear(n,m,0,mod);
			for(int i=1;i<=n;++i){
				for(int j=1;j<=m;++j){
					if(ifmod){
						p.mat[i][j]=(mat[i][j]*x)%mod;
					}
					else{
						p.mat[i][j]=mat[i][j]*x;
					}
				}
			}
			return p;
		}
};
/*--NAMESPACE HDK::MATRIX  MATRIX_H_--*/
