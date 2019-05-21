#include<iostream>
#include<vector>
#include<cstring>
#include<math.h>
#include"counter.h"
using namespace std;
void Counter::EXECUTE(){
            cout<<"please input the formula:";(cin>>str2).get();
            fun1();
            parseFormula();
            result();
            cout<<"result is:";
            cout<<t<<std::endl;
            cout<<"*******************"<<endl;
        }
void Counter::MAINEXECUTE(){
        int i;
        cout<<"Welcome to use our calculator\n";
        cout<<"inter '1' to calculate   inter '2' to exit:";cin>>i;
       if(i==1){EXECUTE();Counter the_next;the_next.MAINEXECUTE();}
       else if(i==2){cout<<"Thank you for using our calculator\n";}
}
