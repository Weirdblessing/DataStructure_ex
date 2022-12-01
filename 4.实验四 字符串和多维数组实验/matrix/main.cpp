#include <iostream>

using namespace std;
const int N=5;
int main()
{
    int A[N][N],SA[N*(N+1)/2]={0};
    int i,j;
    for(i=0;i<N;i++)
        for(j=0;j<=i;j++)
        A[i][j]=A[j][i]=i+j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
            cout<<A[i][j]<<" ";
        cout<<endl;
    }
    for(i=0;i<N;i++)
        for(j=0;j<=i;j++)
            SA[i*(i+1)/2+j]=A[i][j];
        cout<<"请输入行号和列号：";
        cin>>i>>j;
        if(i>5||i<1||j>5||j<1) cout<<"请输入合法行列！"<<endl;
        else{
        cout<<i<<"行"<<j<<"列的元素值是：";
        if(i>=j)
            cout<<SA[i*(i-1)/2+j-1]<<endl;
        else
            cout<<SA[j*(j-1)/2+i-1]<<endl;}
    return 0;
}
