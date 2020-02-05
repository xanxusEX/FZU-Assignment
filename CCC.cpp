#include <iostream>
#include <string.h>
#include <fstream>
#include <cassert>
using namespace std;
const char jia[]="增加";
const char jian[]="减少";
const char check[]="看看";
const char wallet[]="钱包";
const char num[11][3]={"零","一","二","三","四","五","六","七","八","九","十"};//定义题设的常量汉字关键词
int w,*p=&w;//通过指针使“钱包”内累计值在函数内更新
int CHECK(char N[100])//新增检测数据合法性函数 
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
    cin>>type>>wa>>op>>start;//输入初始值
    i=CHECK(start);
    if(i==1){
    for(int i=0;i<=10;i++)
    {
        if(strcmp(num[i],start)==0) *p=i;//输入汉字在程序内部转化为阿拉伯数字
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
        if(strcmp(num[i],number)==0) *p=*p+i;//寻找汉字对应阿拉伯数字，并对“钱包”内累计值做加法更新
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
        if(strcmp(num[i],number)==0) *p=*p-i;//寻找汉字对应阿拉伯数字，并对“钱包”内累计值做减法更新
    }
    }
    else cout<<"Input Error"<<endl;
} 
void output()
{
    if(w<=10){
        cout<<num[w];
    }//对10以内的数值直接输出
    else if(w>=11&&w<20){
        int ge;
        ge=w%10;
        cout<<"十"<<num[ge];
    }//输出11至19之间的数值
    else{
        int ge,shi;
        ge=w%10; shi=w/10;
        if(ge) cout<<num[shi]<<"十"<<num[ge];
        else cout<<num[shi]<<"十";
    }//输出大等于20的数值
}
int main() 
{
	 cout<<"请输入文件名"<<endl; 
     string file;
     cin>>file;
     ofstream ofs;
     ofs.open(file,ios::in);
     defin();//调用初始定义模块函数
     char object[10],order[10],number[10];
     while(1)//对指令逐条处理
     {
        cin>>object;//接收指令的首个关键词
        if(strcmp(object,wallet)==0){
            cin>>order>>number;
            if(strcmp(order,jia)==0) up(number);
            else down(number);
         }//对加减法指令判断
         else{
            cin>>order;
            output();
            break;
         }//对输出指令判断并跳出循环
    }
    return 0; 
}
