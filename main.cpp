#include <bits/stdc++.h>

using namespace std;
# define V 7
vector<int>adj[1000];
void addedge(int x,int y)
{
    adj[x].push_back(y);
    adj[y].push_back(x);
}
bool hamilton(bool *vis,vector<int>&p,int v)
{
    if(p.size()==V)
        return true;
    for(int av:adj[v])
    {
        if(!vis[av])
        {
            vis[av]=true;
            p.push_back(av);
            if(hamilton(vis,p,av))
                return true;
            vis[av]=false;
            p.pop_back();




        }


    }
    return false;
}



int main()
{
    addedge(0,1);
    addedge(0,3);
    addedge(0,4);
    addedge(0,5);
    addedge(1,5);
    addedge(1,4);
    addedge(1,2);
    addedge(2,6);
    addedge(2,3);
    addedge(2,4);
    addedge(3,6);
    addedge(3,4);
    bool vis[V]={0};
    vector<int>path;
    if(hamilton(vis,path,0))
    {

        for( int i=0; i<V; i++)
            cout<<path[i]<<" ";
            cout<<path[0];
    }
    else
    {
        cout<<"There is no hamilton  cycle exist"<<"\n";
    }









    return 0;
}
