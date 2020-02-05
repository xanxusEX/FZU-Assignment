#include <iostream>
#include <string.h>
using namespace std;
const char num[11][3]={"零","一","二","三","四","五","六","七","八","九","十"};
const char tst[7][3]={"福","州","大","学","F","Z","U"};
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
        cout<<"十"<<num[ge];
    }
    else{
        int ge,shi;
        ge=w%10; shi=w/10;
        if(ge) cout<<num[shi]<<"十"<<num[ge];
        else cout<<num[shi]<<"十";
    }
}
int main()
{
	cout<<"开始测试纠错函数"<<endl;
	int a; char dammy[10];
	for(int i=0;i<=10;i++){
		cout<<"试数"<<' '<<num[i]<<' '; 
		strcpy(dammy,num[i]);
		a=CHECK(dammy);
		if(a==1) cout<<"PASS";
		else cout<<"ERROR";
		cout<<endl; 
	} 
	for(int i=0;i<=6;i++){
		cout<<"试数"<<' '<<tst[i]<<' '; 
		strcpy(dammy,tst[i]);
		a=CHECK(dammy);
		if(a==1) cout<<"PASS";
		else cout<<"ERROR"; 
		cout<<endl;
	} 
	cout<<"开始测试输出函数"<<endl;
	for(int i=0;i<21;i++){
		cout<<"试数"<<' '<<i<<' '; 
		*p=i;
		output();
		cout<<' '<<endl;
	} 
	cout<<"测试结束";
	return 0; 
}
