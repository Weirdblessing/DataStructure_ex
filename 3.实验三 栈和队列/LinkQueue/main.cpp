#include "LinkQueue.h"
#include "LinkQueue.cpp"

int main()
{
    LinkQueue <int> Q;
    int x=1,n=1,count=0;
    cout<<"��ѡ�����Ĳ���:\n1.ȡ��\t2.�к�\t0.�˳�"<<endl;
    while(n!=0)
        {
            cout<<"��������ѡ��Ĳ�����";
            cin>>n;
            switch(n)
                {
                case 1:
                    if(count<M)
                        {
                            Q.EnQueue(x);count++;
                            cout<<"�������Ϊ:"<<x++<<"\n��ǰҵ��Ⱥ�����:"<<count<<endl;

                        }
                    else
                        cout<<"�������ƣ����Ժ���ȡ�ţ�"<<endl;
                    break;
                case 2:
                    if(Q.Empty())
                        cout<<"�ȴ����޹˿ͣ����Ժ�"<<endl;
                    else
                        {cout<<"��"<<Q.DeQueue()<<"�ſͻ�����ҵ��"<<"\n��ǰҵ��Ⱥ�����:"<<--count<<endl;}
                    break;
                case 0:
                    break;
                default:
                    cout<<"�޴˹��ܣ�������ѡ��"<<endl;
                }
        }
    cout<<"�˳��ɹ���"<<endl;
    return 0;
}
