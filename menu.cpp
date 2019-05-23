#include<iostream>
#include<vector>
#include<cstring>
#include<math.h>
#include"counter.h"
using namespace std;
void Counter::EXECUTE(){
        string str1,str3,str4;
        cout<<"please input the formula:";cin>>str2;
	    if(judge(str2))
	    {
	        fun1();
	        //cout<<str2<<endl;
	        parseFormula();
	        //cout<<str2<<endl;
	        result();
	        cout<<"result is:";cout<<t<<endl;

	    }
	    else
	    {
	    	str1=judge_fail1(str2);
	    	str3=judge_fail2(str2);
	    	str4=str2;
	    	str2=str1;
	    	fun1();
	        parseFormula();
	        str1=str2;
	        str2=str3;
	        fun1();
	        parseFormula();
	        str3=str2;
	        str2=str4;
	        if(if_true((get_relation(str2)),result(str1),result(str3)))
	        {cout<<"yes"<<endl;}
	        else
	        {cout<<"no"<<endl;}
	    }
            cout<<"*******************"<<endl;
        }
void Counter::MAINEXECUTE(){
        int i;
        cout<<"Welcome to use our calculator\n";
        cout<<"inter '1' to calculate   inter '2' to exit:";cin>>i;
       if(i==1){EXECUTE();Counter the_next;the_next.MAINEXECUTE();}
       else if(i==2){cout<<"Thank you for using our calculator\n";}
}
