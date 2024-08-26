/*
 * direct_vector.h
 * direct_vector.h is a local C++ header file that 
 * include directed_vector and its cal method
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
#ifndef direct_vector_h
#define direct_vector_h 0
#endif
#include<bits/stdc++.h>
namespace hdk{
	using namespace std;
	#define xl direct_vector
	const long double pi=acos(-1);
	const long double eps=1e-5;
	inline double arcalpha(double _anglealpha){
		return _anglealpha*pi/180;
	}
	inline double anglealpha(double _arcalpha){
		return _arcalpha*180/pi;
	}
	template<int degree>
	class direct_vector{
		private:
			double d[degree+1];
		public:
			direct_vector<degree>(vector<double> x={}){
				for(int i=1;i<=degree;++i){
					if(i>(int)x.size()) d[i]=0;
					else d[i]=x[i-1];
				}
			}
			inline double *_get(int d_id){
				return &d[d_id];
			}
			inline void clear(){
				for(int i=1;i<=degree;++i){
					d[i]=0;
				}
			}
			template<bool alphatype=1>
			inline void set_basevector(double alpha){
				if(degree!=2) exit(3);
				if(alphatype==2){
					alpha=arcalpha(alpha);
				}
				d[1]=cos(alpha);
				d[2]=sin(alpha);
			}
			inline double get(int d_id){return (abs(d[d_id])<=eps?0:d[d_id]);}
			inline void set_vector(vector<double>a){
				if(a.size()<degree) exit(3);
				for(int i=1;i<=degree;++i){
					d[i]=a[i-1];
				}
			}
			void operator =(const vector<double> &A){
				if(A.size()<degree) exit(3);
				for(int i=1;i<=degree;++i){
					d[i]=A[i-1];
				}
			}
			void operator =(const direct_vector<degree> &A){
				for(int i=1;i<=degree;++i){
					d[i]=A.d[i];
				}
			}
			direct_vector<degree> operator +(const direct_vector<degree> &A)const{
				direct_vector<degree> ans;
				for(int i=1;i<=degree;++i){
					ans.d[i]=d[i]+A.d[i];
				}
				return ans;
			}
			void operator +=(const direct_vector<degree> &A){
				*this=*this+A;
			}
			direct_vector<degree> operator -()const{
				direct_vector<degree> ans;
				for(int i=1;i<=degree;++i){
					ans.d[i]=-d[i];
				}
				return ans;
			}
			direct_vector<degree> operator -(const direct_vector<degree> &A)const{
				return *this+-A;
			}
			void operator -=(const direct_vector<degree> &A){
				*this=*this+-A;
			}
			double operator *(const direct_vector<degree> &A)const{
				double ans=0;
				for(int i=1;i<=degree;++i){
					ans+=d[i]*A.d[i];
				}
				return ans;
			}
			inline vector<double> get_all(){
				vector<double> v;
				for(int i=1;i<=degree;++i){
					v.push_back(d[i]);
				}
				return v;
			}
			inline void print(char devide=' ',char end='\n'){
				for(int i=1;i<=degree;++i){
					cout<<(abs(d[i])<eps?0:d[i])<<devide;
				}
				cout<<end;
			}
			double& operator [](int x){
				return d[x];
			}
			inline double length(){
				double ans=0;
				for(int i=1;i<=degree;++i){
					ans+=d[i]*d[i];
				}
				return sqrt(ans);
			}
			inline void set_basevector(){
				double len=length();
				for(int i=1;i<=degree;++i){
					d[i]/=len;
				}
			}
			direct_vector<degree> operator *(double x)const{
				direct_vector<degree> ans;
				for(int i=1;i<=degree;++i){
					ans.d[i]=x*d[i];
				}
				return ans;
			}
			void operator *=(double x){
				*this=*this*x;
			}
			template<int equaltype=1>
			bool operator ==(direct_vector<degree> A){
				if(equaltype==1){
					for(int i=1;i<=degree;++i){
						if(abs(d[i]-A.d[i])>eps) return false;
					}
					return true;
				}
				else{
					if(abs(length()-A.length())<=eps) return true;
					return false;
				}
			}
			bool operator !=(direct_vector<degree> A){
				return not(*this==A);
			}
			bool operator <(direct_vector<degree> A){
				return length()<A.length();
			}
			bool operator >(direct_vector<degree> A){
				return not((*this.operator==<2>(A)) or (*this<A));
			}
			bool operator <=(direct_vector<degree> A){
				return not(*this>A);
			}
			bool operator >=(direct_vector<degree> A){
				return not(*this<A);
			}
			template<int todegree>
			direct_vector<todegree> upper_degree(){
				direct_vector<todegree> ans;
				for(int i=1;i<=degree;++i){
					*ans._get(i)=d[i];
				}
				return ans;
			}
			template<int todegree>
			direct_vector<todegree> lower_degree(){
				direct_vector<todegree> ans;
				for(int i=1;i<=todegree;++i){
					*ans._get(i)=d[i];
				}
				return ans;
			}
			double alpha(){
				direct_vector<degree> res;
				res=*this;
				res.set_basevector();
				return acos(res[1]);
			}
			double vectoralpha_cos(direct_vector<degree> A){
				double ans=abs(*this*A)/(length()*A.length());
				return ans;
			}
			double vectoralpha(direct_vector<degree> A){
				double res=acos(vectoralpha_cos(A));
				if(abs(res)<=eps){
					return 0;
				}
				else{
					return res;
				}
			}
			bool length_eq(direct_vector<degree> A){
				return *this.operator==<2>(A);
			}
	};
}
using namespace hdk;
/*--NAMESPACE HDK  DIRECT_VECTOR_H_--*/
