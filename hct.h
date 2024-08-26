#include<bits/stdc++.h>
using namespace std;
char filein[21],fileout[21];
char in[11]="0.in",out[11]="0.out";
void create();
#define Rand() (rand()*65536+rand())
#define mrand(a,b) (rand()%((b)-1))+(a)
#define mRand(a,b) ((rand()*65536+rand())%((b)-1))+(a)
#if std::CLOCKS_PER_SEC==1000
void make_in(){
	struct _timeb T;
	_ftime(&T);
	srand(T.millitm);
	create();
}
#else
void make_in(){
	random_device rd;
	std::uniform_int_distribution<unsigned long long> dist(0,ULLONG_MAX);
	srand(dist(rd));
	create();
}
#endif
void solve();

void make(){
	cout<<"HCT is a TestData Creation Tool. Made by HaneDaniko at its version 1.0."<<endl<<endl;
	cout<<"file name >>";
	cin>>filein;
	int len=strlen(filein);
	for(int i=0;i<=len-1;++i){
		fileout[i]=filein[i];
	}
	for(int i=len;i<=len+4;++i){
		filein[i]=in[i-len];
		fileout[i]=out[i-len];
	}
	cout<<"amount of tests (max is 10)>>";
	int test;
	cin>>test;
	for(int i=0;i<=test-1;++i){
		filein[len]=i+'0';
		fileout[len]=i+'0';
		cout<<"Creating : "<<filein<<" "<<fileout<<endl;
		freopen(filein,"w",stdout);
		make_in();
		fclose(stdout);
		cout.clear();
		freopen("CON","w",stdout);
		cout<<"Input Finished."<<endl;
		freopen(fileout,"w",stdout);
		freopen(filein,"r",stdin);
		solve();
		fclose(stdout);
		cout.clear();
		fclose(stdin);
		cin.clear();
		freopen("CON","w",stdout);
		cout<<"Output Finished."<<endl<<endl;
	}
}
int main(){
	make();
}
/*--NAMESPACE HDK::HCT   HCT_H_--*/
