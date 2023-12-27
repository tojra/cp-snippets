vector<int> parent, sz;
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

inline void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
}

// to find size of set containing 'a'
inline int set_size(int a){
  return sz[find_set(a)];
}

// union of sets containing 'a' and 'b'
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

// to initialise DSU with single elements 
void init(int n){
    parent.resize(n+1);
    sz.resize(n+1);

    for(int i=1;i<=n;i++)make_set(i);
}
