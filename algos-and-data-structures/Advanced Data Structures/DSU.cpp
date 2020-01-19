struct DSU
{
    vector<int> rnk,prnt;// rank , parent
    int forests;

    DSU(int n){//n = number of nodes
        rnk=vector<int>(n),prnt=vector<int>(n);
        forests=n;
        for(int i=0;i<n;i++){
            rnk[i]=1;
            prnt[i]=i;
        }
    }

    int find_set(int x){
        if(x==prnt[x])return x;
        return prnt[x]=find_set(prnt[x]);
    }

    void link(int x,int y){
        if(rnk[x]>rnk[y])swap(x,y);
        prnt[x]=y;
        if(rnk[x]==rnk[y])rnk[y]++;
    }

    bool union_sets(int x,int y){
        x=find_set(x), y=find_set(y);
        if(x!=y){
            link(x,y);
            forests++;
        }
        return x!=y;
    }

};
