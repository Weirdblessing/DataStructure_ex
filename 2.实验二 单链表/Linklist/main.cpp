#include "Linklist.h"
#include "Linklist.cpp"
int main() {
    Linklist <int> L;
    int choice=1,flag=0;;
    cout<<"请您选择操作:"<<'\n'<<"1.存包"<<'\n'<<"2.取包"<<'\n'<<"3.清空"<<'\n'<<"4.管理"<<'\n'<<"0.退出"<<endl;
    while(choice>0) {
        cout<<"输入你想选择的操作： "<<endl;
        cin >>choice;
        switch(choice) {
        case 1:
        Store(L);//存包;
        break;
        case 2:
        Get(L);//取包;
        break;
        case 3:
        Clearlist(L);//清空;
        flag=1;
        break;
        case 4:
        Dispaylist(L,flag);//管理;
        break;
        case 0:
            cout<<"退出成功！";
            break;
        default:
            cout<<"无此功能！"<<endl;
        }
    }
    return 0;
}
