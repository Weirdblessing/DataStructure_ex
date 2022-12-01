#include "LinkQueue.h"
#include "LinkQueue.cpp"

int main()
{
    LinkQueue <int> Q;
    int x=1,n=1,count=0;
    cout<<"请选择您的操作:\n1.取号\t2.叫号\t0.退出"<<endl;
    while(n!=0)
        {
            cout<<"输入您想选择的操作：";
            cin>>n;
            switch(n)
                {
                case 1:
                    if(count<M)
                        {
                            Q.EnQueue(x);count++;
                            cout<<"您的序号为:"<<x++<<"\n当前业务等候人数:"<<count<<endl;

                        }
                    else
                        cout<<"人数限制，请稍后再取号！"<<endl;
                    break;
                case 2:
                    if(Q.Empty())
                        cout<<"等待区无顾客，请稍候！"<<endl;
                    else
                        {cout<<"请"<<Q.DeQueue()<<"号客户办理业务！"<<"\n当前业务等候人数:"<<--count<<endl;}
                    break;
                case 0:
                    break;
                default:
                    cout<<"无此功能！请重新选择："<<endl;
                }
        }
    cout<<"退出成功！"<<endl;
    return 0;
}
