#include <iostream>
#include <string.h>
using namespace std;
const char num[11][3]={"��","һ","��","��","��","��","��","��","��","��","ʮ"};
const char tst[7][3]={"��","��","��","ѧ","F","Z","U"};
int w,*p=&w;
int CHECK(char N[100])
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
void output()
{
    if(w<=10){
        cout<<num[w];
    }
    else if(w>=11&&w<20){
        int ge;
        ge=w%10;
        cout<<"ʮ"<<num[ge];
    }
    else{
        int ge,shi;
        ge=w%10; shi=w/10;
        if(ge) cout<<num[shi]<<"ʮ"<<num[ge];
        else cout<<num[shi]<<"ʮ";
    }
}
int main()
{
	cout<<"��ʼ���Ծ�����"<<endl;
	int a; char dammy[10];
	for(int i=0;i<=10;i++){
		cout<<"����"<<' '<<num[i]<<' '; 
		strcpy(dammy,num[i]);
		a=CHECK(dammy);
		if(a==1) cout<<"PASS";
		else cout<<"ERROR";
		cout<<endl; 
	} 
	for(int i=0;i<=6;i++){
		cout<<"����"<<' '<<tst[i]<<' '; 
		strcpy(dammy,tst[i]);
		a=CHECK(dammy);
		if(a==1) cout<<"PASS";
		else cout<<"ERROR"; 
		cout<<endl;
	} 
	cout<<"��ʼ�����������"<<endl;
	for(int i=0;i<21;i++){
		cout<<"����"<<' '<<i<<' '; 
		*p=i;
		output();
		cout<<' '<<endl;
	} 
	cout<<"���Խ���";
	return 0; 
}
