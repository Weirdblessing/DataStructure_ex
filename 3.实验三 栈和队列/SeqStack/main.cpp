#include "SeqStack.h"
#include "SeqStack.cpp"
int main()
{
    SeqStack<int>S;
    int n,m,x,n1,count=0;
    do{
    cout<<"������һ���Ǹ�ʮ������n(n>=0):"<<endl;
    cin>>n;}while(n<0);
    n1=n;
    while(m!=0)
        {
            n=n1;
            cout<<"\n��������Ҫת���Ľ���m(1<m<10,����0�˳�):"<<endl;
            cin>>m;
            if(m==0) break;
            else if(m<=1||m>=10) {cout<<"������涨���Ʒ�Χ!"<<endl;}
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
            cout<<"ת����"<<m<<"������Ϊ:"<<endl;
            while(count!=0)
                {
                    cout<<S.Pop();
                    count--;
                }
        }}
    cout<<"�˳��ɹ���"<<endl;
    return 0;
}
