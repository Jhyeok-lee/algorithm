#include<iostream>
using namespace std;
int inf=123456789;
int sgtree[2049][2049];
int t_size=1;
int min(int x,int y){
    return x<y ? x : y;
}
void inii(int i, int j){
    if (i<t_size){
        inii(i*2,j);
        inii(i*2+1,j);
        sgtree[i][j]=min(sgtree[i*2][j],sgtree[i*2+1][j]);
    }
}
void inij(int i, int j){
    if (j<t_size){
        inij(i,j*2);
        inij(i,j*2+1);
        sgtree[i][j]=min(sgtree[i][j*2],sgtree[i][j*2+1]);
    }
}
void update(int i, int j, int v)
{
    i+=t_size-1;
    j+=t_size-1;
    sgtree[i][j]+=v;
    while(j>1){
        int ii=i;
        while(ii>1){
            ii/=2;
            sgtree[ii][j]=min(sgtree[ii*2][j],sgtree[ii*2+1][j]);
        }
        j/=2;
        sgtree[i][j]=min(sgtree[i][j*2],sgtree[i][j*2+1]);
    }     
}
int find(int i, int j, int x,int y,int z,int w,int a,int b,int c,int d){
//    cout << i << ' '<< j<<' ' <<x << ' ' << y << ' ' << z << ' ' << w << ' ' << a << ' ' << b << ' ' << c << ' ' << d <<  endl;
    if(b<x || y<a || d<z || w<c) return inf;
    else if(a<=x && y<=b)
    {
        if(c<=z&&w<=d)
            return sgtree[i][j];
        else
            return min(find(i,j*2,x,y,z,(z+w)/2,a,b,c,d),find(i,j*2+1,x,y,min(w,(z+w)/2+1),w,a,b,c,d));
    }
    else
        return min(find(i*2,j,x,(x+y)/2,z,w,a,b,c,d),find(i*2+1,j,min(y,(x+y)/2+1),y,z,w,a,b,c,d));
}
int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        for(int i=0;i<2049;i++)
            for(int j=0;j<2049;j++)
                sgtree[i][j]=inf;
        int r=0;
        t_size=1;
        int n,m,k;
        cin >>n >> m>>k;
         
        while(t_size<n) t_size*=2;
        for(int i=0;i<n;i++) for(int j=0;j<n;j++)
                cin >> sgtree[i+t_size][j+t_size];
        for(int i=t_size;i<n+t_size;i++)
            inij(i,1);
        for(int j=1;j<n+t_size;j++){
            inii(1,j);}
        for(int i=0; i<m; i++){
            for(int j=0;j<k;j++)
            {
                int x,y,p;
                cin >> x >> y >> p;
                update(x,y,p);
            }
            int a,b,c,d;
            cin >> a >> b >> c >> d;
            r+=find(1,1,1,t_size,1,t_size,a,c,b,d);
        }
        cout << '#' << test_case << ' '<<  r << endl;
    }
    return 0;
}