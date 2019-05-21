#include<iostream>
#include"counter.h"
using namespace std;
void Counter::fun2()//处理负数
{
    string str;
	int i;
	for(i=0;i<=str2.size()-1;i++)
	{
	    str+=str2[i];
		if(str2[i]=='('&&str2[i+1]=='-')
		{str+='0';}
	}
	str2=str;
	return;
}
void Counter::fun1()//处理大于10的数
{
	int i,j,k;
	string temp;
	string str;
	fun2();
	for(i=0;i<=str2.size()-1;i++)
	{
		int l=0;
		if(str2[i]=='+'||str2[i]=='-'||str2[i]=='*'||str2[i]=='/'||str2[i]=='('||str2[i]==')'||str2[i]=='.')
		{str+=str2[i];}
		else
		{
		    for(l=0;str2[i+l]<='9'&&str2[i+l]>='0';l++)
		    {
			    temp+=str2[i+l];
		    }
		    if(l==0)
		    {cout<<"erro"<<endl;exit(0);}
		    if(l==1)
		    {
		    	str+=str2[i];
		    	temp.clear();
		    }
		    else
		    {
		    	i+=(l-1);//cout<<l<<endl;
		    	str+='(';
		    	for(j=0;l>=1;l--,j++)
		    	{
		    		char c=char(l+48-1);
		    		str+=temp[j];
		    		str+='&';
		    		str+=c;
		    		if(l!=1)
		    		{str+='+';}
		    		else{str+=')';}//cout<<"flag"<<endl;
		    	}
		    	temp.clear();
		    }
		    //i+=(l-1);
		    l=0;
		}
	}
	str2=str;
	return;
}
