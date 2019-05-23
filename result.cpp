#include<iostream>
#include<vector>
#include<cstring>
#include<math.h>
#include"counter.h"
using namespace std;
void Counter::parseFormula() {
	vector<string> rpn_; // 总输出
	vector<string> rpn_stack; // 符号堆栈
	string sign_; // 临时保存操作数
	for (int i = 0; i < str2.size(); ++i) {
		if (str2[i] != '+'&&str2[i] != '-'&&str2[i] != '*'&&str2[i] != '/' && str2[i] != '(' &&str2[i] != ')'&&str2[i]!='&'&&str2[i]!='.') { // 如果是操作数的话就保存起来等待输出
			sign_ += str2[i];
		} else {
			string t_formula;
			t_formula += str2[i];
			// 操作数输出
			if (!sign_.empty()) {
				rpn_.push_back(sign_);
				sign_.clear(); // 清空，保存下一个操作数
			}
			//操作符入栈
			if (t_formula == ")") {
				while (rpn_stack[rpn_stack.size() - 1] != "(") {
					if (rpn_stack.empty())
						{cout<<"failed 1"<<endl;exit(0);};
					rpn_.push_back(rpn_stack[rpn_stack.size() - 1]);
					rpn_stack.pop_back();
				}
				rpn_stack.pop_back();
			} else if (rpn_stack.empty())
				rpn_stack.push_back(t_formula);
			else if (t_formula == "(" || rpn_stack[rpn_stack.size() - 1] == "(")
				rpn_stack.push_back(t_formula);
			else if (compare(t_formula, rpn_stack[rpn_stack.size() - 1]))
				rpn_stack.push_back(t_formula);
			else {
				while (!compare(t_formula, rpn_stack[rpn_stack.size() - 1]) && rpn_stack[rpn_stack.size() - 1]!="(") {
					rpn_.push_back(rpn_stack[rpn_stack.size() - 1]);
					rpn_stack.pop_back();
					if (rpn_stack.empty())
						break;
				}
				rpn_stack.push_back(t_formula);
			}
		} // end else
	} // end for
	// 处理最后的还留在暂存区的操作数和操作符
	if (!sign_.empty())
		rpn_.push_back(sign_);
	if(!rpn_stack.empty()) {
		for(int i = rpn_stack.size()-1; i>=0; --i)
			rpn_.push_back(rpn_stack[i]);
	}
	// 输出测试
	string rpn;
	for (int i = 0; i < rpn_.size(); ++i) {
		rpn += rpn_[i];
	}
	str2=rpn;
	return;
}
double Counter::result_function1(double t1,double t2)
{
	while(t2>=1)
	{t2=t2/10.0;}
	return t1+t2;
}
double Counter::result_function2(double t1,double t2)
{
	int i=int(t2);
	return pow(10,i)*t1;
}
void Counter::result(){
        int i;
        vector<double> sign;
        for(i=0;i<=str2.size()-1;i++)
        {
                    if(str2[i]>='0'&&str2[i]<='9')
                    {sign.push_back(double (str2[i]-48));}
                    else
                    {
                        //double temp=sign[sign.size()-1];
                        //double temp2;
                        //for(double i=1;(temp2=temp/i)<1;i=i*10);//
                        if(sign.size()-2<0){cout<<"erro"<<endl;exit(0);}
                        switch (str2[i])
                        {
                            case '+':
                                t=sign[sign.size()-1]+sign[sign.size()-2];
                                sign.pop_back();
                                sign.pop_back();
                                sign.push_back(t);
                                break;
                            case '-':
                                t=sign[sign.size()-2]-sign[sign.size()-1];
                                sign.pop_back();
                                sign.pop_back();
                                sign.push_back(t);
                                break;
                            case '*':
                                t=sign[sign.size()-1]*sign[sign.size()-2];
                                sign.pop_back();
                                sign.pop_back();
                                sign.push_back(t);
                                break;
                            case '/':
                                t=sign[sign.size()-2]/sign[sign.size()-1];
                                sign.pop_back();
                                sign.pop_back();
                                sign.push_back(t);
                                break;
                            case '.':
                                t=result_function1(sign[sign.size()-2],sign[sign.size()-1]);
                                sign.pop_back();
                                sign.pop_back();
                                sign.push_back(t);
                                break;
                            case '&':
                                t=result_function2(sign[sign.size()-2],sign[sign.size()-1]);
                                sign.pop_back();
                                sign.pop_back();
                                sign.push_back(t);
                                break;
                            default :
                                cout<<"erro"<<endl;
                                exit(0);
                        }
                    }
                        //for(int j=0;j<=sign.size()-1;j++)
                        //{cout<<sign[j]<<' ';}cout<<endl;

                }
                t=sign[0];
                }
double Counter::result(string tr){
        int i;
        vector<double> sign;
        for(i=0;i<=tr.size()-1;i++)
        {
                    if(tr[i]>='0'&&tr[i]<='9')
                    {sign.push_back(double (tr[i]-48));}
                    else
                    {
                        //double temp=sign[sign.size()-1];
                        //double temp2;
                        //for(double i=1;(temp2=temp/i)<1;i=i*10);//
                        if(sign.size()-2<0){cout<<"erro"<<endl;exit(0);}
                        switch (tr[i])
                        {
                            case '+':
                                t=sign[sign.size()-1]+sign[sign.size()-2];
                                sign.pop_back();
                                sign.pop_back();
                                sign.push_back(t);
                                break;
                            case '-':
                                t=sign[sign.size()-2]-sign[sign.size()-1];
                                sign.pop_back();
                                sign.pop_back();
                                sign.push_back(t);
                                break;
                            case '*':
                                t=sign[sign.size()-1]*sign[sign.size()-2];
                                sign.pop_back();
                                sign.pop_back();
                                sign.push_back(t);
                                break;
                            case '/':
                                t=sign[sign.size()-2]/sign[sign.size()-1];
                                sign.pop_back();
                                sign.pop_back();
                                sign.push_back(t);
                                break;
                            case '.':
                                t=result_function1(sign[sign.size()-2],sign[sign.size()-1]);
                                sign.pop_back();
                                sign.pop_back();
                                sign.push_back(t);
                                break;
                            case '&':
                                t=result_function2(sign[sign.size()-2],sign[sign.size()-1]);
                                sign.pop_back();
                                sign.pop_back();
                                sign.push_back(t);
                                break;
                            default:
                                cout<<"erro"<<endl;
                                exit(0);
                        }
                    }
                        //for(int j=0;j<=sign.size()-1;j++)
                        //{cout<<sign[j]<<' ';}cout<<endl;

                }
                t=sign[0];
                return t;
                }
