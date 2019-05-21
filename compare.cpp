#include<iostream>
#include<vector>
#include<cstring>
#include<math.h>
#include"counter.h"
using namespace std;
bool Counter::compare(string opA,string opB)
{
	if(opA=="."&&opB!="(")
	{return true;}
	else
	{
		if(opB==".")
		{return false;}
	    else
	    {
		    if((opA=="&"||opA == "*" || opA == "/") && opB != "*" && opB != "/" && opB!= "("&&opB!="&")
		        {return true;}
	        else
		        {return false;}
	    }
	}
}
