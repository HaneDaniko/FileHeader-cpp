/*
 * balanced_tree.h
 * balanced_tree.h is a local C++ header file that 
 * include three type of balanced tree
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
#ifndef balanced_tree_h
#define balanced_tree_h 0
#endif
#include<bits/stdc++.h>
namespace hdk{
	namespace balanced_tree{
		using namespace std;
		const int N=2000001,inf=114514191;
		class splay{
			private:
				int root,tot;
				struct tree{
					int w;
					int cnt,size;
					int fa,son[2];
				}t[N];
			public:
				tree *operator [](int x){
					return &t[x];
				}
				inline int getroot(){
					return root;
				}
				inline void clear(int x){
					t[x]={0,0,0,0,{0,0}};
				}
				inline bool judgeson(int x){
					return t[t[x].fa].son[1]==x;
				}
				inline void update(int x){
					if(x){
						t[x].size=t[x].cnt;
						if(t[x].son[0]) t[x].size+=t[t[x].son[0]].size;
						if(t[x].son[1]) t[x].size+=t[t[x].son[1]].size;
					}
				}
				inline void rotate(int x){
					int f=t[x].fa,gf=t[f].fa;
					int k=judgeson(x);
					t[f].son[k]=t[x].son[k^1];
					t[t[f].son[k]].fa=f;
					t[x].son[k^1]=f;
					t[f].fa=x;
					t[x].fa=gf;
					if(gf){
						t[gf].son[t[gf].son[1]==f]=x;
					}
					update(f);update(x);
				} 
				inline void sply(int x){
					for(int f;(f=t[x].fa);rotate(x)){
						if(t[f].fa){
							if(judgeson(x)==judgeson(f)){
								rotate(f);
							}
							else rotate(x);
						}
					}
					root=x;
				}
				inline void insert(int x){
					if(!root){
						tot++;
						t[tot]={x,1,1,0,{0,0}};
						root=tot;
						return;
					}
					int now=root,fa=0;
					while(1){
						if(x==t[now].w){
							t[now].cnt++;
							update(now);update(fa);
							sply(now);
							break;
						}
						fa=now;
						now=t[now].son[t[now].w<x];
						if(!now){
							tot++;
							t[tot]={x,1,1,fa,{0,0}};
							t[fa].son[t[fa].w<x]=tot;
							update(fa);
							sply(tot);
							break;
						}
					}
				}
				inline int findnum(int x){
					int now=root;
					while(now){
						if(t[now].son[0] and x<=t[t[now].son[0]].size){
							now=t[now].son[0];
						}
						else{
							int temp=t[now].cnt;
							if(t[now].son[0]){
								temp+=t[t[now].son[0]].size;
							}
							if(x<=temp) return t[now].w;
							x-=temp;
							now=t[now].son[1];
						}
					}
					return t[now].w;
				}
				inline int findrank(int x){
					int now=root,ans=0;
					while(now){
						if(x<t[now].w){
							now=t[now].son[0];
						}
						else{
							if(t[now].son[0]){
								ans+=t[t[now].son[0]].size;
							}
							if(x==t[now].w){
								sply(now);
								return ans+1;
							}
							ans+=t[now].cnt;
							now=t[now].son[1]; 
						}
					}
					return ans+1;
				}
				inline int findpre(){
					int now=t[root].son[0];
					while(t[now].son[1]) now=t[now].son[1];
					return now;
				}
				inline int findnext(){
					int now=t[root].son[1];
					while(t[now].son[0]) now=t[now].son[0];
					return now;
				}
				inline void remove(int x){
					findrank(x);
					if(t[root].cnt>1){
						t[root].cnt--;
						update(root);
						return;
					}
					if(!t[root].son[0] and !t[root].son[1]){
						clear(root);
						root=0;
						return;
					}
					if(!t[root].son[0]){
						int oroot=root;
						root=t[root].son[1];
						t[root].fa=0;
						clear(oroot);
						return;
					}
					else if(!t[root].son[1]){
						int oroot=root;
						root=t[root].son[0];
						t[root].fa=0;
						clear(oroot);
						return;
					}
					int left=findpre(),oroot=root;
					sply(left);
					t[root].son[1]=t[oroot].son[1];
					t[t[oroot].son[1]].fa=root;
					clear(oroot);
					update(root);
				}
				inline int findpre(int x){
					insert(x);
					int ans=t[findpre()].w;
					remove(x);
					return ans;
				}
				inline int findnext(int x){
					insert(x);
					int ans=t[findnext()].w;
					remove(x);
					return ans;
				}
				inline tree* get(int id){
					return &t[id];
				}
		};
		class treap{
			private:
				int tot;
				struct tree{
					int w,data,size,cnt,son[2];
				}t[N];
				int root;
			public:
				tree *operator [](int x){
					return &t[x];
				}
				inline int getroot(){
					return root;
				}
				inline int size(){
					return tot;
				}
				inline void update(int x){
					t[x].size=t[t[x].son[0]].size+t[t[x].son[1]].size+t[x].cnt;
				}
				inline int newnode(int val){
					t[++tot]={val,rand(),1,1,{0,0}};
					return tot;
				}
				inline tree* get(int id){
					return &t[id];
				}
				inline void rotate(int &id,int isrignt){
					bool k=isrignt;
					int temp=t[id].son[k^1];
					t[id].son[k^1]=t[temp].son[k];
					t[temp].son[k]=id;
					id=temp;
					update(t[id].son[k]);
					update(id);
				}
				inline void insert(int &id,int x){
					if(!id){
						id=newnode(x);
						return;
					}
					if(x==t[id].w) t[id].cnt++;
					else{
						bool k=(x>=t[id].w);
						insert(t[id].son[k],x);
						if(t[id].data<t[t[id].son[k]].data){
							rotate(id,k^1);
						}
					}
					update(id);
				}
				inline void remove(int &id,int x){
					if(!id) return;
					if(t[id].w==x){
						if(t[id].cnt>1){
							t[id].cnt--;
							update(id);
							return;
						}
						if(t[id].son[0] or t[id].son[1]){
							if(!t[id].son[1] or t[t[id].son[0]].data>t[t[id].son[1]].data){
								rotate(id,1);
								remove(t[id].son[1],x);
							}
							else{
								rotate(id,0);
								remove(t[id].son[0],x);
							}
							update(id);
						}
						else{
							id=0;
						}
						return;
					}
					(x<t[id].w)?remove(t[id].son[0],x):remove(t[id].son[1],x);
					update(id);
				}
				inline int getrank(int id,int x){
					if(!id){
						return 1;
					}
					if(x==t[id].w){
						return t[t[id].son[0]].size+1;
					}
					else if(x<t[id].w){
						return getrank(t[id].son[0],x);
					}
					else{
						return t[t[id].son[0]].size+t[id].cnt+getrank(t[id].son[1],x);
					}
				}
				inline int getval(int id,int rank){
					if(!id) return inf;
					if(rank<=t[t[id].son[0]].size){
						return getval(t[id].son[0],rank);
					}
					else if(rank<=t[t[id].son[0]].size+t[id].cnt){
						return t[id].w;
					}
					else{
						return getval(t[id].son[1],rank-t[t[id].son[0]].size-t[id].cnt);
					}
				}
				inline int findpre(int x){
					int id=root,pre=0;
					while(id){
						if(t[id].w<x){
							pre=t[id].w;
							id=t[id].son[1];
						}
						else{
							id=t[id].son[0];
						}
					}
					return pre;
				}
				inline int findnext(int x){
					int id=root,next=0;
					while(id){
						if(t[id].w>x){
							next=t[id].w;
							id=t[id].son[0];
						}
						else{
							id=t[id].son[1];
						}
					}
					return next;
				}
				inline void insert(int x){
					insert(root,x);
				}
				inline void remove(int x){
					remove(root,x);
				}
				inline int findrank(int x){
					return getrank(root,x);
				}
				inline int findnum(int rank){
					return getval(root,rank);
				}
		};
		class fhq_treap{
			private:
				int tot,removed;
				struct tree{
					int w,data,size,cnt,son[2];
				}t[N];
				int root;
			public:
				tree *operator [](int x){
					return &t[x];
				}
				inline int getroot(){
					return root;
				}
				inline int size(){
					return tot;
				}
				tree *get(int id){
					return &t[id];
				}
				inline void update(int x){
					t[x].size=1+t[t[x].son[0]].size+t[t[x].son[1]].size;
				}
				inline int newnode(int val){
					t[++tot]={val,rand(),1,1,{0,0}};
					return tot;
				}
				inline int merge(int x,int y){
					if(!x or !y) return x+y;
					if(t[x].data<t[y].data){
						t[x].son[1]=merge(t[x].son[1],y);
						update(x);
						return x;
					}
					else{
						t[y].son[0]=merge(x,t[y].son[0]);
						update(y);
						return y;
					}
				}
				inline void split(int now,int k,int &x,int &y){
					if(!now) x=y=0;
					else{
						if(t[now].w<=k){
							x=now;
							split(t[now].son[1],k,t[now].son[1],y);
						}
						else{
							y=now;
							split(t[now].son[0],k,x,t[now].son[0]);
						}
						update(now);
					}
				}
				inline int find(int now,int rank){
					while(1){
						if(rank<=t[t[now].son[0]].size){
							now=t[now].son[0];
						}
						else if(rank==t[t[now].son[0]].size+1){
							return now;
						}
						else{
							rank-=t[t[now].son[0]].size+1;
							now=t[now].son[1];
						}
					}
				}
				inline void insert(int x){
					int a,b;
					split(root,x,a,b);
					root=merge(merge(a,newnode(x)),b);
				}
				inline void remove(int a){
					int x,y,z;
					split(root,a,x,z);
					split(x,a-1,x,y);
					y=merge(t[y].son[0],t[y].son[1]);
					root=merge(merge(x,y),z);
				}
				inline int findrank(int a){
					int x,y;
					split(root,a-1,x,y);
					int ans=t[x].size+1;
					root=merge(x,y);
					return ans;
				}
				inline int findnum(int rank){
					return t[find(root,rank)].w;
				}
				inline int findpre(int a){
					int x,y;
					split(root,a-1,x,y);
					int ans=t[find(x,t[x].size)].w;
					root=merge(x,y);
					return ans;
				}
				inline int findnext(int a){
					int x,y;
					split(root,a,x,y);
					int ans=t[find(y,1)].w;
					root=merge(x,y);
					return ans;
				}
		};
	}
}
/*--NAMESPACE HDK::BALANCED_TREE  BALANCED_TREE_H_--*/
