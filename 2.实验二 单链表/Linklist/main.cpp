#include "Linklist.h"
#include "Linklist.cpp"
int main() {
    Linklist <int> L;
    int choice=1,flag=0;;
    cout<<"����ѡ�����:"<<'\n'<<"1.���"<<'\n'<<"2.ȡ��"<<'\n'<<"3.���"<<'\n'<<"4.����"<<'\n'<<"0.�˳�"<<endl;
    while(choice>0) {
        cout<<"��������ѡ��Ĳ����� "<<endl;
        cin >>choice;
        switch(choice) {
        case 1:
        Store(L);//���;
        break;
        case 2:
        Get(L);//ȡ��;
        break;
        case 3:
        Clearlist(L);//���;
        flag=1;
        break;
        case 4:
        Dispaylist(L,flag);//����;
        break;
        case 0:
            cout<<"�˳��ɹ���";
            break;
        default:
            cout<<"�޴˹��ܣ�"<<endl;
        }
    }
    return 0;
}
