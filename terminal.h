#if std::CLOCKS_PER_SEC==1000
#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
using namespace std;
string version="3.1";
namespace randt{
    namespace rander{
        vector<long long> list;
        int it,ssize;
        int reset(int size){if(size<=0)return -1;int seed=std::rand();mt19937 Rand(seed);ssize=size;it=0;list.clear();for(int i=1;i<=size;++i){list.push_back(rand());}return seed;}
        int reset(){srand(time(0));return rander::reset(10000);}
        vector<long long> randlist(int size){int seed=ssize;reset(size);vector<long long> ret=list;reset(seed);return ret;}
        int rand(){if(ssize<=0)reset();int ret=list[it];it++;if(it>=ssize)reset();return ret;}
        int rand(int mod){int ret=rander::rand()%mod;return ret;}
        long long randabs(int mod){long long ret=abs(rander::rand());if(mod)ret%=mod;return ret;}
        long long rand(int l,int r){if(l<0)return rander::rand(0,r);long ret=rander::randabs(r-l+1)+l;return ret;}
        template<typename _T>_T from(vector<_T>p){long long ret=rander::randabs(p.size());return p[ret];}
        template<typename _T>void randsort(vector<_T>&p){for(int i=1;i<=5*(int)p.size();++i){int x=rander::rand(0,p.size()-1),y=rander::rand(0,p.size()-1);swap(p[x],p[y]);}}
        template<typename _T>void randsort(_T &p,int from,int to){for(int i=1;i<=to-from+1;++i){int x=rander::rand(from,to),y=rander::rand(from,to);swap(p[x],p[y]);}}
    };
    map<int,bool> mp;
    bool vis[100000001];
    string version="2.4";
    void input();
    void clear(){
        mp.clear();
    }
    void start(){
        cout<<"[Randtool ("<<version<<" Version)]"<<endl<<endl;
        cout<<"֮ǰ�ļ�¼�ѻ�ԭ"<<endl;
        cout<<"���� /help ���鿴����"<<endl<<endl;
    }
    void input(){
        cout<<">> ";
        string com;
        cin>>com;
        if(com[0]=='/'){
        if(com=="/help"){
            cout<<endl;
            cout<<"ָ���б����б��ڵ� [] ����Ҫ����ı�����"<<endl;
            cout<<"/help �鿴����"<<endl;
            cout<<"/copyright �鿴���������Ϣ"<<endl;
            cout<<"/example �鿴һЩ����ʾ��"<<endl;
            cout<<"/rand [x] [y] [z] �� x �� y ����� z ������"<<endl;
            cout<<"/randun [x] [y] [z] �� x �� y �в��ظ������ z ������"<<endl;
            cout<<"/ban [x] ������ x ������б���ɾ��"<<endl;
            cout<<"/banlist [x] {list} ���б��ڵ����ִ�����б���ɾ��"<<endl;
            cout<<"/unban [x] ���������� x ��ɾ������"<<endl;
            cout<<"/allunban ����ȫ��ɾ������"<<endl;
			cout<<"/randfrom [x] {list} [y]���� x ��Ԫ�أ�������� y ��"<<endl;
            cout<<"/randfromun [x] {list} [y]���� x ��Ԫ�أ����в��ظ������ y ��"<<endl;
            cout<<"/sort [x] {list} ���� x ��Ԫ�أ����Һ����˳��"<<endl;
            cout<<"/clear ����"<<endl;
            cout<<"/reset ��������"<<endl;
            cout<<"/exit �˳�����"<<endl;
        }
        else if(com=="/clear"){
            system("cls");
            cout<<"Terminal Version "<<version<<endl<<endl;
			cout<<"[System Mode] Using 'exit' to exit"<<endl;
            start();
        }
        else if(com=="/reset"){
            system("cls");
			cout<<"Terminal Version "<<version<<endl<<endl;
			cout<<"[System Mode] Using 'exit' to exit"<<endl;
            clear();
            start();
            input();
            return;
        }
        else if(com=="/rand"){
                int x,y,z;
                cin>>x>>y>>z; 
                for(int i=1;i<=z;++i){
                    int res=rander::rand(x,y);
                    while(mp.count(res)&&mp[res]==true) res=rander::rand(x,y);
                    cout<<"[Rand "<<i<<"] "<<res<<endl;
                }
                cout<<endl;
        }
        else if(com=="/randun"){
            int x,y,z;
            cin>>x>>y>>z;
            if(z>y-x+1){
                cout<<"��������ֹ���"<<endl;
            }
            else if(y>10000000){
                cout<<y<<" ̫����"<<endl;
            }
            else{
                memset(vis,0,sizeof vis);
                for(int i=1;i<=z;++i){
                    int res=rander::rand(x,y);
                    while((mp.count(res)&&mp[res]==true)||vis[res]){
                        res=rander::rand(x,y);
                    }
                    vis[res]=true;
                    cout<<"[Rand "<<i<<"] "<<res<<endl;
                }
                cout<<endl;
            }
        }
        else if(com=="/ban"){
                int x;cin>>x;
                mp[x]=true;
                cout<<"�ɹ�ɾ�� "<<x<<endl;
            }
            else if(com=="/banlist"){
                int x;cin>>x;int ge=x;
                while(x--){
                    int y;cin>>y;
                    mp[y]=true;
                }
                cout<<"�ɹ�ɾ�� "<<ge<<" ��Ԫ��"<<endl;
            }
        else if(com=="/unban"){
                int x;cin>>x;
                if(!mp.count(x)){
                    cout<<"��Ч����";
                }
                else{
                    mp[x]=false;
                    cout<<"�ɹ����� "<<x<<endl;
                }
            }
        else if(com=="/allunban"){
        	mp.clear();
        	cout<<"��ȫ�����"<<endl;
		}
        else if(com=="/randfrom"){
            int x;cin>>x;vector<string> xd;
            for(int i=1;i<=x;++i){
                string a;cin>>a;xd.push_back(a);
            }
            int t;cin>>t;
            for(int i=1;i<=t;++i){
                cout<<"[Rand "<<i<<"] "<<rander::from(xd)<<endl;
            }
        }
        else if(com=="/randfromun"){
            int x;cin>>x;vector<string> xd;
            for(int i=1;i<=x;++i){
                string a;cin>>a;xd.push_back(a);
            }
            int t;cin>>t;
            if(t>x){
                cout<<"��������ֹ���"<<endl;
            }
            else{
                map<string,bool> rn;
                for(int i=1;i<=t;++i){
                    string res=rander::from(xd);
                    while(rn.count(res)){
                        res=rander::from(xd);
                    }
                    rn[res]=true;
                    cout<<"[Rand "<<i<<"] "<<res<<endl;
                }
            }
        }
        else if(com=="/sort"){
            int x;cin>>x;vector<string> xd;
            for(int i=1;i<=x;++i){
                string a;cin>>a;xd.push_back(a);
            }
            rander::randsort(xd);
            int t=0;
            for(string i:xd){
                t++;
                cout<<"["<<t<<"] "<<i<<endl; 
            }
        }
        else if(com=="/exit"){
            return;
        }
        else if(com=="/example"){
            cout<<endl;
            cout<<"[Example 1]"<<endl;
            cout<<"/rand 1 10 3 �� 1 �� 10 ��Χ����� 3 ������"<<endl<<endl;
            cout<<"[Example 2]"<<endl;
            cout<<"/randfrom 3 a b c 4 �� {a,b,c} ����Ԫ�������ѡ���ĸ����أ�3 ��Ԫ�صĸ�����"<<endl<<endl;
            cout<<"[Example 3]"<<endl;
            cout<<"/sort 3 a b c �� {a,b,c} ����б�������ң�3 ��Ԫ�صĸ�����"<<endl<<endl;
        }
        else if(com=="/copyright"){
            cout<<"[COPYRIGHT] 2024/5/31- ; HaneDaniko"<<endl;
            cout<<"All Right Served"<<endl;
        } 
        else{
            cout<<"��Чָ��"<<endl;
        }
        }
        cout<<endl;
        input();
    }
    void scbc(char put,int color,char devide){
        HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(handle,color);
        cout<<put<<devide;
        SetConsoleTextAttribute(handle,0x0F);
    }
}
namespace wordle{
	#define Kw "114514"
	#define Save "0"
	int len;
	int ansid,times;
	vector<string> wst;
	string in;
	char rea[201];
	int jg[6][8];
	bool zc[8];
	string ans[6];
	int guessed['z'+1];
	void clear(){  //reset the game
		len=0;
		ansid=0;
		times=0;
		for(int i=0;i<=5;++i){
			for(int j=0;j<=7;++j){
				jg[i][j]=0;
			}
			ans[i].clear();
		}
		for(int i=0;i<=7;++i){
			zc[i]=false;
		}
		for(int i='a';i<='z';++i){
			guessed[i]=0;
		}
	}
	void scbc(char put,int type){  //colorful change the word result
		HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
		if(type==1){
			SetConsoleTextAttribute(handle,0xE0);
			cout<<put<<" ";
			SetConsoleTextAttribute(handle,0x0F);
		}
		if(type==2){
			SetConsoleTextAttribute(handle,0xA0);
			cout<<put<<" ";
			SetConsoleTextAttribute(handle,0x0F);
		}
		if(type==0){
			cout<<put<<" ";
		}
	}
	void scbc(string put,int color){  //colorful change the word result
		HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(handle,color);
		cout<<put<<" ";
		SetConsoleTextAttribute(handle,0x0F);
	}
	int check(int time,string x){  //check the input changes what
		bool flag=false;
		if(x.length()!=wst[ansid].length()){
			return -1;
		}
		for(int i=0;i<=x.length()-1;++i){
			guessed[x[i]]=1;
		}
		for(int i=0;i<=x.length()-1;++i){
			if(x[i]!=wst[ansid][i]){
				flag=true;
				break;
			}
			jg[time][i]=2;
			zc[i]=true;
		}
		if(flag==false){
			return 2;
		}
		for(int i=0;i<=x.length()-1;++i){
			for(int j=0;j<=x.length()-1;++j){
				if(x[j]==wst[ansid][i]){
					if(jg[time][j]==0){
						guessed[x[j]]=2;
						jg[time][j]=1;
					}
					if(i==j){
						guessed[x[j]]=3;
						jg[time][j]=2;
						zc[j]=true;
					}
				}
			}
		}
		return 1;
	}
	void sc(int times){    //print the result
		system("cls");
		cout<<"Terminal Version "<<version<<endl<<endl;
		cout<<"[Wordle Mode]"<<endl;
		cout<<"Use 'exit' to exit" <<endl;
		cout<<"Rule"<<endl;
		scbc(' ',1);
		cout<<" Yellow means the string has this letter,but it isn't in the correct place."<<endl;
		scbc(' ',2);
		cout<<" Green means the string has this letter,and it is in the correct place."<<endl;
		cout<<"There's a string has "<<len<<" letters."<<endl<<"Answer : ";
		for(int i=0;i<=len-1;++i){
			if(zc[i]){
				scbc(wst[ansid][i],2);
			}
			else{
				cout<<"* ";
			}
		}
		cout<<endl<<endl;
		for(int i=0;i<=times;++i){
			for(int j=0;j<=len-1;++j){
				scbc(ans[i][j],jg[i][j]);
			}
			cout<<endl;
		}
		cout<<endl;
		cout<<"Remain Letters"<<endl;
		for(int i='a';i<='z';++i){
			string x;x.push_back(i);
			if(guessed[i]==0){
				scbc(x,0x0F);
			}
			if(guessed[i]==1){
				scbc(x,0x08);
			}
			if(guessed[i]==2){
				scbc(x,0xE0);
			}
			if(guessed[i]==3){
				scbc(x,0xA0);
			}
			x.clear();
		}
		cout<<endl<<endl;
	}
	void rd(){
		cout<<"Read Mode"<<endl<<"Please open a file (Putin 0 to read 'StandardVocabulary.wordle') >>";
		cin>>rea;
		if(rea[0]!='0'){
			freopen(rea,"r",stdin);
		}
		else{
			freopen("StandardVocabulary.wordle","r",stdin);
		}
		while(1){
			cin>>in;
			if(in=="0"){
				break;
			}
			wst.push_back(in);
		}
		cout<<"Read "<<wst.size()<<" Words."<<endl;
		cin.clear();
		freopen("CON","r",stdin);
		cout<<endl;
		system("pause");
		system("cls");
		cout<<"Terminal Version "<<version<<endl<<endl;
		cout<<"[Wordle Mode]"<<endl;
	}
	int start(){
		system("title Read // WordleGame 1.2.0 version // Made By HaneDaniko");
		rd();
		srand(time(NULL));
		bool ingame=true;
		while(1){
			ansid=rand()%wst.size();
			len=wst[ansid].length();
			cout<<"There's a string has "<<len<<" letters."<<endl<<"Answer : ";
			for(int i=0;i<=len-1;++i){
				cout<<"* ";
			}
			cout<<endl<<endl;
			system("title Guess // WordleGame 1.2.0 version // Made By HaneDaniko");
			while(1){
				cout<<"You have 5 chance in totle to guess."<<endl;
				cout<<"Guess a word >>";
				cin>>ans[times];
				if(ans[times]=="exit"){
					ingame=false;
					break;
				}
				if(ans[times]==Kw){
					ans[times].clear();
					system("cls");
					cout<<"Creator Mode"<<endl;
					string com;
					while(1){
						cout<<"Command >>";
						cin>>com;
						if(com=="/exit"){
							system("cls");
							break;
						}
						else if(com=="/answer"){
							cout<<wst[ansid];
						}
						else if(com=="/system"){
							char sys[101];
							cout<<"System >>";
							cin>>sys;
							system(sys);
							cout<<"Has Done it.";
						}
						else{
							cout<<"Wrong Command.";
						}
						cout<<endl;
					}
					continue;
				}
				else if(ans[times]==Save){
					int sav;
					ans[times].clear();
					system("cls");
					system("color 07");
					system("title C:/Users/hzoi/Desktop/Untitled1.cpp");
					cout<<"100 7 1 "<<endl<<"101 1 2"<<endl<<"1 2 2 "<<endl<<"2 3 2 "<<endl<<"3 3 1 "<<endl<<"1 3 2 "<<endl<<"3 1 1 "<<endl<<"5 5 0"<<endl<<"Yes"<<endl<<"No"<<endl;
					cout<<"--------------------------------"<<endl<<"Process exited after 2.797 seconds with return value 0"<<endl<<"�밴���������. . .";
					cin>>sav;
					system("cls");
					cout<<"Terminal Version "<<version<<endl<<endl;
					cout<<"[Wordle Mode]"<<endl;
					system("title Guess // WordleGame 1.2.0 version // Made By HaneDaniko");
					continue;
				}
				else{
					int a=check(times,ans[times]);
					if(a==-1){
						cout<<"Wrong Length."<<endl<<endl;
						continue;
					}
					else if(a==1){
						for(int i=0;i<=len-1;++i){
							cout<<jg[times][i]<<" ";
						}
						cout<<endl;
						sc(times);
						times++;
						if(times==5){
							system("title Just SO EASY! Are you CLEVER ?");
							cout<<"You lost."<<endl;
							cout<<"The Answer is '"<<wst[ansid]<<"'."<<endl;
							break;
						}
						cout<<"You have "<<5-times<<" times remain."<<endl;
					}
					else{
						system("title Win // WordleGame 1.2.0 version // Made By HaneDaniko");
						sc(times);
						times++;
						cout<<"You Win."<<endl;
						cout<<"Total Times : "<<times<<endl;
						break;
					}
				}
			}
			system("pause");
			system("cls");
			clear();
			if(!ingame) break;
		}
		return 0;
	}
}
namespace abcg{
	int n;
	char m[21][21];
	bool can[21][21][3];
	int tot[21][21];
	int remain;
	void sc(int x,int y){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(x==i&&y==j){
					HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(handle,0xF0);
					cout<<m[i][j]<<" ";
					SetConsoleTextAttribute(handle,0x0F);
				}
				else{
					cout<<m[i][j]<<" ";
				}
			}
			cout<<endl;
		}
		cout<<"Remain Places : "<<remain<<endl;
	}
	bool go(int x,int y,char z){
		if(m[x][y]!='_') return false;
		if(x+1<=n&&m[x+1][y]==z) return false;
		if(y+1<=n&&m[x][y+1]==z) return false;
		if(x-1>=1&&m[x-1][y]==z) return false;
		if(y-1>=1&&m[x][y-1]==z) return false;
		m[x][y]=z;
		if(x+1<=n&&!can[x+1][y][z-'A']){
			can[x+1][y][z-'A']=1;
			tot[x+1][y]++;
			if(tot[x+1][y]==3){
				remain--;
			}
		}
		if(x-1>=1&&!can[x-1][y][z-'A']){
			can[x-1][y][z-'A']=1;
			tot[x-1][y]++;
			if(tot[x-1][y]==3){
				remain--;
			}
		}
		if(y+1<=n&&!can[x][y+1][z-'A']){
			can[x][y+1][z-'A']=1;
			tot[x][y+1]++;
			if(tot[x][y+1]==3){
				remain--;
			}
		}
		if(y-1>=1&&!can[x][y-1][z-'A']){
			can[x][y-1][z-'A']=1;
			tot[x][y-1]++;
			if(tot[x][y-1]==3){
				remain--;
			}
		}
		return true;
	}
	void prefork(){
		system("cls");
		cout<<"Terminal Version "<<version<<endl<<endl;
		cout<<"[ABCG Mode]"<<endl;
		cout<<"Please Read Before You Play"<<endl<<endl;
		cout<<"This game is made by HaneDaniko. While you play, please be careful to be caught."<<endl;
		cout<<"Otherwise, if necessary, please press a 'SPACE' any time, this will help hide the game."<<endl;
		cout<<"And if you want to go back to game, please press 'ESC'"<<endl;
		cout<<"Please close the folder while you play."<<endl;
		cout<<"If you clear, then press 'S' to start"<<endl;
		while(1){
			if(kbhit()){
				int ch=getch();
				if(ch=='s'){
					return;
				}
			}
		}
	}
	int start(){
		system("title ABCG");
		prefork();
		system("cls");
		cout<<"Terminal Version "<<version<<endl<<endl;
		cout<<"[ABCG Mode]"<<endl;
		cout<<"Map Size >>";
		cin>>n;
		remain=n*n;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				m[i][j]='_';
			}
		}
		int i=1,j=1;
		system("cls");
		cout<<"Terminal Version "<<version<<endl<<endl;
		cout<<"[ABCG Mode]"<<endl;
		sc(i,j);
		while(1){
			if(remain==0){
				system("cls");
				cout<<"Terminal Version "<<version<<endl<<endl;
				cout<<"[ABCG Mode]"<<endl;
				sc(i,j);
				break;
			}
			if(kbhit()){
				int ch=getch();
				if(ch==72&&i!=1){i--;system("cls");cout<<"Terminal Version "<<version<<endl<<endl;
								cout<<"[ABCG Mode]"<<endl;sc(i,j);}
				if(ch==80&&i!=n){i++;system("cls");cout<<"Terminal Version "<<version<<endl<<endl;
								cout<<"[ABCG Mode]"<<endl;sc(i,j);}
				if(ch==75&&j!=1){j--;system("cls");cout<<"Terminal Version "<<version<<endl<<endl;
								cout<<"[ABCG Mode]"<<endl;sc(i,j);}
				if(ch==77&&j!=n){j++;system("cls");cout<<"Terminal Version "<<version<<endl<<endl;
								cout<<"[ABCG Mode]"<<endl;sc(i,j);}
				if(ch==97){
					if(go(i,j,'A')){system("cls");cout<<"Terminal Version "<<version<<endl<<endl;
								cout<<"[ABCG Mode]"<<endl;remain--;sc(i,j);}
					else cout<<"Error"<<endl;
				}
				if(ch==98){
					if(go(i,j,'B')){system("cls");cout<<"Terminal Version "<<version<<endl<<endl;
								cout<<"[ABCG Mode]"<<endl;remain--;sc(i,j);}
					else cout<<"Error"<<endl;
				}
				if(ch==99){
					if(go(i,j,'C')){system("cls");cout<<"Terminal Version "<<version<<endl<<endl;
								cout<<"[ABCG Mode]"<<endl;remain--;sc(i,j);}
					else cout<<"Error"<<endl;
				}
				if(ch==32){
					system("cls");
					cout<<"ababcababababcabab\nact 0\nact 1\nactin 1 : 0\nact 2\nact 3\nact 4\nactin 4 : 2\nactin 4 : 0act 5\nact 6\nact 7\nact 8\nact 9\nactin 9 : 4\nact 10\nact 11\nactin 11 : 4\nact 12\nact 13\nact 14\nact 15\nact 16\nact 17\n2 4 9 18\naaaaa\nact 0\nact 1\nact 2\nact 3\nact 4\n1 2 3 4 5\n--------------------------------\nProcess exited after 0.5747 seconds with return value 0\n�밴���������. . .";
					while(1){
						if(kbhit()){
							int ch=getch();
							if(ch==27){
								system("cls");
								cout<<"Terminal Version "<<version<<endl<<endl;
								cout<<"[ABCG Mode]"<<endl;
								sc(i,j);
								break;
							}
						}
					}
				}
			}
		}
		cout<<endl<<"GameOver"<<endl;
		system("pause");
		system("title Terminal");
		system("cls");
	} 
} 
void input();
void start(){
	system("title Terminal");
	cout<<"Terminal Version "<<version<<endl<<endl;
	cout<<"[Terminal Mode]"<<endl;
	input();
}
map<string,string>filepath;
void readpath(){
	freopen("FastPath.txt","r",stdin);
	int fcnt=0;
	while(1){
		char fo[1001];
		string xa,xb;
		cin>>xa;
		if(xa=="end") break;
		fcnt++;
		cin.getline(fo,1001);
		int len=strlen(fo);
		for(int i=0;i<=len-1;++i){
			xb.push_back(fo[i]);
		}
		filepath[xa]=("explorer "+xb);
	}
	cout<<"[FastPath] Read "<<fcnt<<" path"<<endl;
	freopen("CON","r",stdin);
	cin.clear();
}
void input(){
	cout<<">> ";
	string com;
    cin>>com;
    if(com=="help"){
    	cout<<endl;
    	cout<<"'system' open the System Mode (cmd)"<<endl;
    	cout<<"'rand' open the Randtool"<<endl;
    	cout<<"'sleep' sleep the exe several times"<<endl;
    	cout<<"'open [name]' open a folder using fastpathname"<<endl;
    	cout<<"'show[path]' show a file"<<endl;
    	cout<<"'wordle' start a wordle"<<endl;
    	cout<<"'abcg' start a ABCG"<<endl;
		cout<<"'exit' exit the exe"<<endl;
    	cout<<"'reset' reset the exe"<<endl;
    	cout<<endl;
	}
	else if(com=="abcg"){
		cout<<endl<<"[ABCG 1.0]"<<endl;
		abcg::start();
		cout<<"Terminal Version "<<version<<endl<<endl;
		cout<<"[Terminal Mode]"<<endl;
	}
	else if(com=="wordle"){
		cout<<endl<<"[Wordle 2.0]"<<endl;
		wordle::start();
		cout<<"Terminal Version "<<version<<endl<<endl;
		cout<<"[Terminal Mode]"<<endl;
	}
	else if(com=="open"){
		string fstn;cin>>fstn;
		if(filepath.count(fstn)){
			string po=filepath[fstn];char pa[1001];
			for(int i=0;i<=po.length()-1;++i){
				pa[i]=po[i];
			}
			system(pa);
		}
		else{
			cout<<"[FastPath] Name not found"<<endl;
		}
	}
    else if(com=="system"){
    	cout<<"[System Mode] Using 'exit' to exit"<<endl;
    	getchar();
        char sys[1001];
        while(1){
        	cout<<" >> ";
        	cin.getline(sys,1000);
        	if(sys[0]=='e'&&sys[1]=='x'&&sys[2]=='i'&&sys[3]=='t'){
        		cout<<"[Terminal Mode]"<<endl;
        		break;
			}
			else if(sys[0]=='c'&&sys[1]=='l'&&sys[2]=='s'){
				system("cls");
				cout<<"Terminal Version "<<version<<endl<<endl;
				cout<<"[System Mode] Using 'exit' to exit"<<endl;
			}
            else{
                system(sys);
            }
        }
    }
    else if(com=="rand"){
        randt::start();
        randt::input();
        cout<<"[Terminal Mode]"<<endl;
    }
    else if(com=="sleep"){
        cout<<"Sleep time (ms) >>";
        int tme;cin>>tme;
        Sleep(tme);
    }
    else if(com=="exit") return;
    else if(com=="reset"){
        system("cls");
		cout<<"Terminal Version "<<version<<endl<<endl;
		cout<<"[Terminal Mode]"<<endl;
    }
    else if(com=="show"){
    	char sx[1001];char sc[1001]="type ";
    	cin.getline(sx,1000);
    	int len=strlen(sx);
    	for(int i=0;i<=len-1;++i){
    		sc[i+4]=sx[i];
		}
		system(sc);
	}
    else{
    	cout<<"Unused Commend"<<endl;
	}
    input();
}
int main(){
	readpath();
	start();
}

#endif