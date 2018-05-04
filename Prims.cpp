/// God Help Me
#include<bits/stdc++.h>
using namespace std;
vector<int>List[100];
int G[100][100];
bool Check[100][100];
int Node,Edge;
vector<int>Vect;
queue<int>Q;
int MST=0;
 bool NodeCk[100];
 string StringHome[100];
 int StrCount=0;
 int Search_Index(string s)
{
    for(int I=1; I<=StrCount; I++)
    {
        if(StringHome[I]==s)
        {
            return I;
        }
    }
    StrCount = StrCount +1;
    StringHome[StrCount] = s;
    return StrCount;
}
void Prims(int Src)
{
  Vect.clear();
  Vect.push_back(Src);
  int Count =0;
  int U,V,Min=100000000,Loc1,Loc2;
  NodeCk[Src] =true;
  while(Vect.size()<=Node)
  {

      Min=100000000;
      for(int I=0; I<Vect.size(); I++)
      {
          U= Vect[I];

          for(int J=0; J<List[U].size(); J++)
          {
             V = List[U][J];
             if(G[U][V]<=Min && Check[U][V]==false && NodeCk[V]==false)
             {
                 Min=G[U][V];
                 Loc1=U;
                 Loc2=V;
             }
          }
      }
      cout<<Loc1<<" "<<Loc2<<endl;
      Vect.push_back(Loc2);
      NodeCk[Loc1]=true; NodeCk[Loc2]=true;
      Check[Loc1][Loc2]=true;
      Check[Loc2][Loc1]=true;
      MST+=G[Loc1][Loc2];
      if(Vect.size()==Node) break;

  }


}
int main()
{
  freopen("Prims.txt","r",stdin);
    cin>>Node>>Edge;
    int Node_Index1, Node_Index2,Cost;
     string s1,s2;
    for(int I=1; I<=Edge; I++)
    {
        cin>>s1>>s2>>Cost;
        Node_Index1=Search_Index(s1);
        Node_Index2=Search_Index(s2);

        if(Node_Index1!=Node_Index2){
        List[Node_Index1].push_back(Node_Index2);
        List[Node_Index2].push_back(Node_Index1);
          G[Node_Index1][Node_Index2] = Cost;
          G[Node_Index2][Node_Index1] = Cost;
          Check[Node_Index1][Node_Index2]= false;
          Check[Node_Index2][Node_Index1]= false;
        }

    }
   for(int I =1; I<=Node; I++)
   {
       if(NodeCk[I]==false)
       {
            Prims(I);
       }
   }

    cout<<"MST = "<<MST<<endl;



    return 0;
}

