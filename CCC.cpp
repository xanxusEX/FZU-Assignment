#include <iostream>
#include <string.h>
#include <fstream>
#include <cassert>
using namespace std;
const char jia[]="����";
const char jian[]="����";
const char check[]="����";
const char wallet[]="Ǯ��";
const char num[11][3]={"��","һ","��","��","��","��","��","��","��","��","ʮ"};//��������ĳ������ֹؼ���
int w,*p=&w;//ͨ��ָ��ʹ��Ǯ�������ۼ�ֵ�ں����ڸ���
int CHECK(char N[100])//����������ݺϷ��Ժ��� 
{
	int flag=0;
	if(strlen(N)>2) flag=-1;
	else{
	for(int i=0;i<=10;i++)
    {
        if(strcmp(num[i],N)==0) flag=1;
    }	
	}
	return flag;
}
void defin()
{
    char type[10],wa[10],op[10],start[10]; int i;
    cin>>type>>wa>>op>>start;//�����ʼֵ
    i=CHECK(start);
    if(i==1){
    for(int i=0;i<=10;i++)
    {
        if(strcmp(num[i],start)==0) *p=i;//���뺺���ڳ����ڲ�ת��Ϊ����������
    }
    }
    else {
    	cout<<"Input Error"<<endl; defin();
	}
}
void up(char number[10])
{
	int a; a=CHECK(number);
	if(a==1){
    for(int i=0;i<=10;i++)
    {
        if(strcmp(num[i],number)==0) *p=*p+i;//Ѱ�Һ��ֶ�Ӧ���������֣����ԡ�Ǯ�������ۼ�ֵ���ӷ�����
    }
    } 
	else  cout<<"Input Error"<<endl; 
}
void down(char number[10])
{
	int a; a=CHECK(number);
	if(a==1){
    for(int i=0;i<=10;i++)
    {
        if(strcmp(num[i],number)==0) *p=*p-i;//Ѱ�Һ��ֶ�Ӧ���������֣����ԡ�Ǯ�������ۼ�ֵ����������
    }
    }
    else cout<<"Input Error"<<endl;
} 
void output()
{
    if(w<=10){
        cout<<num[w];
    }//��10���ڵ���ֱֵ�����
    else if(w>=11&&w<20){
        int ge;
        ge=w%10;
        cout<<"ʮ"<<num[ge];
    }//���11��19֮�����ֵ
    else{
        int ge,shi;
        ge=w%10; shi=w/10;
        if(ge) cout<<num[shi]<<"ʮ"<<num[ge];
        else cout<<num[shi]<<"ʮ";
    }//��������20����ֵ
}
int main() 
{
	 cout<<"�������ļ���"<<endl; 
     string file;
     cin>>file;
     ofstream ofs;
     ofs.open(file,ios::in);
     defin();//���ó�ʼ����ģ�麯��
     char object[10],order[10],number[10];
     while(1)//��ָ����������
     {
        cin>>object;//����ָ����׸��ؼ���
        if(strcmp(object,wallet)==0){
            cin>>order>>number;
            if(strcmp(order,jia)==0) up(number);
            else down(number);
         }//�ԼӼ���ָ���ж�
         else{
            cin>>order;
            output();
            break;
         }//�����ָ���жϲ�����ѭ��
    }
    return 0; 
}
