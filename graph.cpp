//////////////////////////////
/// to find all vertices on a cycle
/// for undirected graph with n edges (1 cycle)
/////////////////////////////

vector<int> par;
vector<bool> vis;
int src, last;
void dfs(int u, int p){
    if(vis[u]){
        if(src==-1){
            src=u;
            last=p;
        }
        return;
    }
    vis[u]=1;
    par[u]=p;
    for(auto t:adj[u]){
        if(t!=p)dfs(t,u);
    }
}

int main(){
  vis.assign(n,0);
  par.assign(n,-1);
  src=-1;
  dfs(0,-1);
  vector<int> cyc;
  cyc.push_back(last);
  while(1){
      cyc.push_back(par[cyc.back()]);
      if(cyc.back()==src)break;
  }
}

//////////////////////////////////
