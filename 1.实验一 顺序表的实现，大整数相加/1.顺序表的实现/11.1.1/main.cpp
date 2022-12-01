#include "Seq.h"
#include "Seq.cpp"
int main() {
    int flag=0,n,m,l,i=0,j=0,cj=0;
    //cj:两大数的位数差；flag:进位标识符；n,m：A，B数组的长度；l：两大数的较短位数；i，j：循环变量。
    char k='0';//k作为插入字符的临时存储变量。
    char strA[Max]={0},strB[Max]={0};
    cout<<"输入大整数A："<<endl;
    cin>>strA;
    cout<<"输入大整数B："<<endl;
    cin>>strB;
    n=strlen(strA);
    m=strlen(strB);
    if(n<m) l=n,cj=m-n;else l=m,cj=n-m;//取较短的位数赋给l
    Seqlist <char> A(strA,n),B(strB,m),C;//类模板定义三个类，AB存大数，C存相加后的大数
    A.PrintList();
    B.PrintList();
    //两大数重合位数的相加
    do
    {
        k=(A.Getdata(i+1)+B.Getdata(i+1)-96+flag)%10+48;//防止查找到非法位置，以短的大数为主，长的大数多余的部分另算。
        C.Insert(i+1,k);//(第几位，字符)
        flag=(A.Getdata(i+1)-48+B.Getdata(i+1)-48+flag)/10;
        i++;
    }while(i<l);
    //同位数且相加后会进位处理
    if((flag==1)&&(cj==0)) {C.Insert(i+1,'1');}//解决无差位且进位数
    //大数A或B多余的一部分处理
    for(j=0;j<cj;j++)
    {
        if(n<m) {k=(B.Getdata(i+1)-48+flag)%10+48; C.Insert(i+1,k);flag=(B.Getdata(i+1)-48+flag)/10;i++;}
        else {k=(A.Getdata(i+1)-48+flag)%10+48; C.Insert(i+1,k);flag=(A.Getdata(i+1)-48+flag)/10;i++;}
    }
    //输出位数与结果
    cout<<"位数为："<<C.Length()<<" 位，结果为："<<endl;
    C.PrintList();
    return 0;
}
