/* 
 * topass.h
 * topass.h is a local C++ header file used
 * to lock and unlock password through
 * topass method
 *
 * Author : HaneDaniko
 * Create Time: 27/7/2024
 *
 * To use this header, you must import this
 * file into you programe
**/
#ifndef HDK
#define HDK 0
#endif
#ifndef topass_h
#define topass_h 0
#endif
#include<string>
class topass{public:int h=0;std::string version="1.0";}topass;
std::string lock(int public_key,int private_key,std::string word){
	int now=public_key;
	for(int i=0;i<=(int)word.length()-1;++i){
		if(!now) now=public_key;
		if(now&1){
			word[i]^=(private_key+now%8);
		}
		now>>=1;
	}
	std::string ans;
	for(int i=0;i<=(int)word.length()-1;++i){
		if(word[i]<100){
			ans.push_back('0');
			ans.push_back(word[i]/10+'0');
			ans.push_back(word[i]%10+'0');
		}
		else{
			ans.push_back(word[i]/100+'0');
			ans.push_back((word[i]%100)/10+'0');
			ans.push_back(word[i]%10+'0');
		}
	}
	for(int i=1;i<=3;++i)
	ans.push_back('0');
	return ans;
}
std::string unlock(int public_key,int private_key,std::string password){
	int now=public_key;std::string ans;
	for(int i=0;i+2<=(int)password.length()-1;i+=3){
		int a=(password[i]-'0')*100+(password[i+1]-'0')*10+(password[i+2]-'0');
		if(a){
			if(!now) now=public_key;
			if(now&1) ans.push_back(a^(private_key+now%8));
			else ans.push_back(a);
			now>>=1;
		}
	}
	return ans;
}
/*--NAMESPACE HDK::TOPASS  TOPASS_H_--*/
