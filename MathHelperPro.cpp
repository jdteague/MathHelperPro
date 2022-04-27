/*/--------------- PROGRAM 1 ---------------\*\
PROGRAMMER: 
	Jarod Teague
PURPOSE:
	this  is  the  math  helper  that  I was  tasked to create.
	However,  this  is  the  PRO version,  with  above average 
	input validation. Hence my inclusion of the string library.
\*\-------------------------------------/*/

//g++ -c MathHelperPro.cpp <---------------------------|these are here for my benefit, I had alot of
//g++ -o MathHelperPro.exe MathHelperPro.o Random.o	<--|nasty errors, got tired of scrolling through them.

#include <iostream>
#include <iomanip>// necessary to create the equation
#include <string>// necessary to save large strings
#include <cmath>// necessary for the style of input validationcI am using
#include "Random.h"// the randomizer you supplied

using namespace std;

int main()
{	
	seedRandomizer();
	int num1 = generateRandomInt(0 , 1000); //<-----| these are the numbers used in the question,  the answer is kept for use later on
	int num2 = generateRandomInt(0 , 1000); //<-----|
	double ans = num1 + num2;//<-----|this is a double in order to make use of the pow() function
	
	string reply;//<------------|the user's input 
	
	cout << "Hello! welcome to Math \"Helper\" Pro, try to Answer the question below:\n" << endl;
	cout << setfill(' ') << setw(20) << num1 << endl;
	cout << setw(14) << "+" << setw(6) << num2 << endl;//<--|this makes sure that the + sign is always in the same spot.
	cout << setw(20) << "_______" << endl;//				|Also it turns out setw only includes the first object it recieves, 
	//														|hence why I needed to break it up
	cin >> reply;
	
	double cReply = 0;
	bool flag = false;
	
	if(reply == "heck")// a rudimentary profanity scanner. As you can see, it only hunt's for the most deragatory of phrases.
	{
		cout << "No swearing on Math Helper Pro!"<< endl;
		flag = true;
	}
	
	else// if the user's language is decent, they may recieve help.
	{
		for(int i = 0; i < reply.length(); ++i) 
		{
			if(reply[i] >= '0' && reply[i] <= '9')
			{
				cReply += (reply[i] - '0') * (pow(10.0 , (double)reply.length() - i - 1));//<------------|the magical line that converts the char's into values, 
			}//																							 |the whole gist of this loop is that it simultaneosly
//																										 |checks for only numerical characters and preserves the
			else// 																						 |number's position within the string. it then multiplies each
			{// 																						 |position with a power of ten and adds them all together.
				cout << "please enter a response with only numeric characters"<< endl;
				cReply = 0;
				flag = true;
				break;
			}
		}
	}
	
	if (cReply == ans)
	{
		cout << "Congradulations! " << reply << " was the correct answer!" << endl; // the end result if correct;
	}
	
	else if(cReply != ans && !flag)
	{
		cout << "Your answer was incorrect, " << ans << " was the correct answer" << endl; // the end result if incorrect;
	}
	
	return 0;
}
