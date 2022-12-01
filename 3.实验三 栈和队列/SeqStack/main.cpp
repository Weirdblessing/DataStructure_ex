#include "SeqStack.h"
#include "SeqStack.cpp"
int main()
{
    SeqStack<int>S;
    int n,m,x,n1,count=0;
    do{
    cout<<"请输入一个非负十进制数n(n>=0):"<<endl;
    cin>>n;}while(n<0);
    n1=n;
    while(m!=0)
        {
            n=n1;
            cout<<"\n请输入您要转换的进制m(1<m<10,输入0退出):"<<endl;
            cin>>m;
            if(m==0) break;
            else if(m<=1||m>=10) {cout<<"请输入规定进制范围!"<<endl;}
            else{
            while(m<=n)
                {
                    x=n%m;
                    S.Push(x);
                    n/=m;
                    count++;
                }
            S.Push(n);
            count++;
            cout<<"转换成"<<m<<"进制数为:"<<endl;
            while(count!=0)
                {
                    cout<<S.Pop();
                    count--;
                }
        }}
    cout<<"退出成功！"<<endl;
    return 0;
}
