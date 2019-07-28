#include <iostream>
#include <fstream>

using namespace std;
char v[101][101];
int st[101]={0},n,nu_e_nb;bool m[101][101]={{0},{0}};
ifstream f("nume.in");
ifstream incom("incompatibil.in");
ofstream g("submultimi.out");
ofstream h("catan.out");
void tipar(int p)
{int i;
for(i=1;i<=p;i++)
 {g<<st[i]<<" ";h<<v[st[i]];if(i<p)h<<" +";}
 g<<'\n',h<<'\n';

}
int valid(int p)
{int i,j,nb=0;
 for(i=1;i<=p;i++)
   if(st[i]>nu_e_nb){nb++;if(nb>2)return 0;}
 for(i=1;i<p;i++)
   for(j=i+1;j<=p;j++)
     if(m[st[i]][st[j]]==1)return 0;
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
int main()
{   int y,x;
    n=0;nu_e_nb=24;
    while(f>>x)
      {n++;f.getline(v[n],100);}
    while(incom>>x)
      {incom>>y;
       while(y!=0)
         {m[x][y]=1;m[y][x]=1;incom>>y;
         }
      }
    backs();
    return 0;
}
