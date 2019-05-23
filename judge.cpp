#include<iostream>
#include<vector>
#include<cstring>
#include<math.h>
#include"counter.h"
using namespace std;
bool Counter::judge(string tr)
{
	int i;
    for(i=0;i<=tr.size()-1;i++)
	{
	    if(tr[i]=='>'||tr[i]=='<'||tr[i]=='='||tr[i]=='!')
	    {return false;}
	}
	return true;
}
bool Counter::if_judge(char c)
{
	int i;
	if(c=='>'||c=='<'||c=='='||c=='!')
	{return true;}
	else {return false;}
}
string Counter::judge_fail1(string tr)
{
	string str;
	for(int i=0;!if_judge(tr[i]);i++)
	{
		str+=tr[i];
	}
	return str;
}
string Counter::judge_fail2(string tr)
{
	string str;
	int i=0;
	for(i=0;!if_judge(tr[i]);i++);
	i++;
	if(if_judge(tr[i])){i++;}
	for( ;i<=tr.size()-1;i++)
	{str+=tr[i];}
	return str;
}
int Counter::get_relation(string tr)
{
	int i;
	for(i=0;!if_judge(tr[i]);i++);
	if(tr[i]=='<')
	{if(tr[i+1]=='=')
	    {return 1;}
	    else {return 2;}
	}
	if(tr[i]=='>')
	{
		if(tr[i+1]=='=')
		{return 3;}
		else{return 4;}
	}
	if(tr[i]=='=')
	{
		if(tr[i+1]!='=')
		{cout<<"erro"<<endl;exit(0);}
		return 5;
	}
	if(tr[i]=='!')
	{
		if(tr[i+1]!='=')
		{cout<<"erro."<<endl;exit(0);}
		return 6;
	}
	cout<<"erro"<<endl;exit(0);
}
bool Counter::if_true(int i,int a,int b)
{
	switch(i)
	{
		case 1 :
			return a<=b;
			break;
		case 2:
			return a<b;
			break;
		case 3:
			return a>=b;
			break;
		case 4:
			return a>b;
			break;
		case 5:
			return a==b;
			break;
		case 6:
			return !(a==b);
			break;
		default:
			cout<<"error"<<endl;
			exit(0);
		}

}
