#include <iostream>
#include <fstream>

using namespace std;
struct joculetze{char n[101];int id_joc;}v[101];
int st[101]={0},n,nu_e_nb;bool m[101][101]={{0},{0}},OsC,NAV,LHO,NsB;
ifstream f("nume.in");
ifstream incom("incompatibil.in");
ofstream g("submultimi.out");
ofstream h("catan.out");
void tipar(int p)
{int i;
for(i=1;i<=p;i++)
 {g<<st[i]<<" ";h<<v[st[i]].n;if(i<p)h<<" +";}
 g<<'\n',h<<'\n';
}
int valid(int p)
{int i,j,nb=0;
 for(i=1;i<=p;i++)
   if(v[st[i]].id_joc>nu_e_nb){nb++;if(nb>2)return 0;}
 for(i=1;i<p;i++)
   for(j=i+1;j<=p;j++)
     if(m[v[st[i]].id_joc][v[st[j]].id_joc]==1)return 0;
 return 1;
}
void backs()//submultimile unei multimi
{int p=1;
 st[p]=0;
 while(p>0)///cu && am eliminat combinatiile are incep cu altceva decat cu 1-Jocul de baza
 { if(st[p]<n && !(p==1 && st[2]==n))
    { st[p]++;
      if(valid(p))
       {tipar(p);p++;st[p]=st[p-1];}
    }
    else p--;
 }
}
int joc_valid(int x)
{if(OsC==0 && 17<=x && x<=20)return 0;
 else if(NAV==0 && 2<=x && x<=19)return 0;
   else if(LHO==0 && 11<=x && x<=19)return 0;
     else if(NsB==0 && 21<=x && x<=29)return 0;
 return 1;
}
int main()
{   int y,x;
    n=0;nu_e_nb=24;
    OsC=1;
    NAV=1;
    LHO=1;
    NsB=1;
    while(f>>x)
      {if(joc_valid(x)){n++;f.getline(v[n].n,100);v[n].id_joc=x;}
         else f.getline(v[0].n,100);
      }
    while(incom>>x)
      {incom>>y;
       while(y!=0)
         {m[x][y]=1;m[y][x]=1;incom>>y;
         }
      }
    backs();
    return 0;
}
