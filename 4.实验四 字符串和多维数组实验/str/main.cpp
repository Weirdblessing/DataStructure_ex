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
    cout<<"请输入需要匹配的模式T字符串：";
    cin>>src;
    strcpy(T,src.c_str());//将string转为字符串
    BF(S,T);
    return 0;
}
