#include<bits/stdc++.h>
#include "solvability.h"
#define n 4
using namespace std;

struct node{
    int **mat;
    int blankx;
    int blanky;
}initial;
int path[100];
int pos[n*n][2];
int solved,bound;
int dx[4]={0,-1,1,0};
int dy[4]={-1,0,0,1};
int hash_table[n][n][n*n];

int calc_heuristic()
{
    int res=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int num=(initial.mat)[i][j];
            if(num==0)
                continue;
            res+=abs(i-pos[num][0])+abs(j-pos[num][1]);
        }
    }
    return res;
}

void print_matrix(int save[][n])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<save[i][j]<<" ";
        cout<<endl;
    }
}

void print_path(int save[][n],int savex,int savey)
{
    int i=0;

    while(path[i]!=-1)
    {
        int x=savex,y=savey;
        int currx,curry;
        if(path[i]==0)
        {
            currx=x;
            curry=y-1;
            swap(save[x][y],save[currx][curry]);
            savex=currx;
            savey=curry;
            print_matrix(save);
        }
        else if(path[i]==1)
        {
            currx=x-1;
            curry=y;
            swap(save[x][y],save[currx][curry]);
            savex=currx;
            savey=curry;
            print_matrix(save);
        }
        else if(path[i]==2)
        {
            currx=x+1;
            curry=y;
            swap(save[x][y],save[currx][curry]);
            savex=currx;
            savey=curry;
            print_matrix(save);
        }
        else if(path[i]==3)
        {
            currx=x;
            curry=y+1;
            swap(save[x][y],save[currx][curry]);
            savex=currx;
            savey=curry;
            print_matrix(save);
        }
        cout<<endl;
        i++;
    }
}

int IDAS_rec(int depth,int heuri,int prev)
{
    if(heuri==0)
    {
        solved=depth;
        path[depth]=-1;
        return depth;
    }

    if(depth+5*heuri/3 > bound)
        return depth+5*heuri/3;

    int x=initial.blankx,y=initial.blanky;
    int next_bound=INT_MAX;

    for(int i=0;i<4;i++)
    {
        if(i+prev == 3)
            continue;
        int currx=x+dx[i],curry=y+dy[i];
        if(currx<0 || currx>=n || curry<0 || curry>=n)
            continue;

        int new_heuri=heuri;
        new_heuri-=hash_table[currx][curry][(initial.mat)[currx][curry]];
        new_heuri+=hash_table[x][y][(initial.mat)[currx][curry]];

        initial.blankx=currx;
        initial.blanky=curry;
        swap((initial.mat)[x][y],(initial.mat)[currx][curry]);

        path[depth]=i;

        int val=IDAS_rec(depth+1,new_heuri,i);
        swap((initial.mat)[x][y],(initial.mat)[currx][curry]);
        initial.blankx=x;
        initial.blanky=y;

        if(solved)
            return solved;

        next_bound=min(next_bound,val);
    }
    return next_bound;
}

int main()
{
    initial.mat=new int*[n];
    for(int i=0;i<n;i++)
    {
        initial.mat[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            cin>>(initial.mat)[i][j];
            if((initial.mat)[i][j]==0)
            {
                initial.blankx=i;
                initial.blanky=j;
            }
        }
    }

    clock_t start,e;
    start=clock();
    int k=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(k==n*n)
                continue;
            pos[k][0]=i;
            pos[k][1]=j;
            k++;
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(k=1;k<n*n;k++)
                hash_table[i][j][k]=abs(i-pos[k][0])+abs(j-pos[k][1]);
        }
    }

    if(!is_solvable(initial.mat,n))
    {
        cout<<endl;
        cout<<"This instance of sliding puzzle is not solvable"<<endl;
        return 0;
    }

    int save[n][n];
    int savex,savey;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            save[i][j]=(initial.mat)[i][j];
            if(save[i][j]==0)
            {
                savex=i;
                savey=j;
            }
        }
    }

    int ini_heuri;
    solved=0;
    ini_heuri=calc_heuristic();
    bound=ini_heuri;

    while(solved==0)
    bound=IDAS_rec(0,ini_heuri,-1);

    cout<<endl;
    print_path(save,savex,savey);
    cout<<endl;

    e=clock();

    cout<<"Time taken to execute "<<(double)(e-start)/CLOCKS_PER_SEC<<" seconds"<<endl;
    return 0;
}
