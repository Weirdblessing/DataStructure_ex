#include "str.h"

int main()
{
    char S[Max];
    int i=0;
    ifstream in("input.txt");
    if(!in) cout<<"open file error!"<<endl;
    while(in)
    {
        in.get(S[i]);
        i++;
    }
    in.close();
    S[i]='\0';
    string src;
    char T[]={0};
    cout<<"��������Ҫƥ���ģʽT�ַ�����";
    cin>>src;
    strcpy(T,src.c_str());//��stringתΪ�ַ���
    BF(S,T);
    return 0;
}
