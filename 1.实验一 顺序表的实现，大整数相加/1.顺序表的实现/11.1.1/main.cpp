#include "Seq.h"
#include "Seq.cpp"
int main() {
    int flag=0,n,m,l,i=0,j=0,cj=0;
    //cj:��������λ���flag:��λ��ʶ����n,m��A��B����ĳ��ȣ�l���������Ľ϶�λ����i��j��ѭ��������
    char k='0';//k��Ϊ�����ַ�����ʱ�洢������
    char strA[Max]={0},strB[Max]={0};
    cout<<"���������A��"<<endl;
    cin>>strA;
    cout<<"���������B��"<<endl;
    cin>>strB;
    n=strlen(strA);
    m=strlen(strB);
    if(n<m) l=n,cj=m-n;else l=m,cj=n-m;//ȡ�϶̵�λ������l
    Seqlist <char> A(strA,n),B(strB,m),C;//��ģ�嶨�������࣬AB�������C����Ӻ�Ĵ���
    A.PrintList();
    B.PrintList();
    //�������غ�λ�������
    do
    {
        k=(A.Getdata(i+1)+B.Getdata(i+1)-96+flag)%10+48;//��ֹ���ҵ��Ƿ�λ�ã��Զ̵Ĵ���Ϊ�������Ĵ�������Ĳ������㡣
        C.Insert(i+1,k);//(�ڼ�λ���ַ�)
        flag=(A.Getdata(i+1)-48+B.Getdata(i+1)-48+flag)/10;
        i++;
    }while(i<l);
    //ͬλ������Ӻ���λ����
    if((flag==1)&&(cj==0)) {C.Insert(i+1,'1');}//����޲�λ�ҽ�λ��
    //����A��B�����һ���ִ���
    for(j=0;j<cj;j++)
    {
        if(n<m) {k=(B.Getdata(i+1)-48+flag)%10+48; C.Insert(i+1,k);flag=(B.Getdata(i+1)-48+flag)/10;i++;}
        else {k=(A.Getdata(i+1)-48+flag)%10+48; C.Insert(i+1,k);flag=(A.Getdata(i+1)-48+flag)/10;i++;}
    }
    //���λ������
    cout<<"λ��Ϊ��"<<C.Length()<<" λ�����Ϊ��"<<endl;
    C.PrintList();
    return 0;
}
