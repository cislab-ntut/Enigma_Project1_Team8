#include <iostream>
#include <string.h>
#include <string>
using namespace std;

//A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y  Z
//1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26
/*範例:
1.(III)  : BDFHJLCPRTXVZNYEIWGAKMUSQO
2.(II)   : AJDKSIRUXBLHWTMCQGZNPYFVOE
3.(I)    : EKMFLGDQVZNTOWYHXUSPAIBRCJ
reflector: YRUHQSLDPXNGOKMIEBFZCWVJAT
plugboard: ABCDEFGHIJKLMNOPQRSTUVWXYZ
CBADEFGHIJKLMNOPQRSTUVWXYZ
KEY:
轉盤一設定:(III)
開始位置: X
指標位置: W (指標位置在轉盤哪一顆時決定時候就決定了唷)
轉盤二設定:(II)
開始位置: D
指標位置: F
轉盤三設定:(I)
開始位置: H
指標位置: R
明文: ABCDEFGHIJKLMNOPQRSTUVWXYZ
祕文: KQGJALNNGTESJCXFSWEYLSNCIW
*/
//#remember the number cauclate and the range cauclate will get the more 1 than the accurate one#

int relativedirfun(int, int);
int findalphabet(int, int[]);
int ctrlrange(int);
int LRmove, location;
int main(){
	int incir1[26];
	int incir2[26];
	int incir3[26];
	int refcir[26];
	int plug[26];
	int start1 = 24, start2 = 4, start3 = 8;
	int index1 = 23, index2 = 6, index3 = 18;
	int location;
	int input;
	int output;
	int counter = 0;
	char scir[26];

	cout << "ENTER THE TURNTABLE (III): " << endl;
	cin >> scir;
	for (int g = 0; g<26; g++)
		incir1[g] = scir[g] - 64;
	cout << endl;

	cout << "ENTER THE START(III):" << endl;
	cin >> scir;
	start1 = scir[0]-64;
	cout << endl;

	cout << "ENTER THE TURNTABLE (II): " << endl;
	cin >> scir;
	for (int h = 0; h<26; h++)
		incir2[h] = scir[h] - 64;
	cout << endl;

	cout << "ENTER THE START(II):" << endl;
	cin >> scir;
	start2 = scir[0] - 64;
	cout << endl;

	cout << "ENTER THE TURNTABLE (I): " << endl;
	cin >> scir;
	for (int j = 0; j<26; j++)
		incir3[j] = scir[j] - 64;
	cout << endl;

	cout << "ENTER THE START(I):" << endl;
	cin >> scir;
	start3 = scir[0] - 64;
	cout << endl;

	cout << "ENTER THE REFLECTOR: " << endl;
	cin >> scir;
	for (int k = 0; k<26; k++)
		refcir[k] = scir[k] - 64;
	cout << endl;

	cout << "ENTER THE PLUGBOARD: " << endl;
	cin >> scir;
	for (int M = 0; M<26; M++)
		plug[M] = scir[M] - 64;
	cout << endl;

	cout << "#####_INPUT: " << endl;
	char s[300];
	cin >> s;
	string stemp(s);
	cout << stemp.length();
	int tt = stemp.length();
	int * arr;
	arr =new int[tt];
	

	while (counter<tt){
		counter++;
		input = s[counter - 1] - 64;
		//cout<<"#input :"<<input<<endl;
		input = plug[input - 1];
		//cout<<"plugboard:"<<input<<endl;
		input = input - 1;//a->y=>0+stat1,so that's why -1
		start1++;
		start1 = ctrlrange(start1);
		if (start1 == index1 || start2 == index2 - 1)
		{
			start2++;
			if (start2 == index2)//it must trigger by start2++
				start3++;
		}
		start2 = ctrlrange(start2);
		if (start3 == index3 - 1)
			start3++;
		start3 = ctrlrange(start3);
		input = start1 + input;
		input = ctrlrange(input);
		//cout<<"start1 "<<start1<<endl;
		//cout<<"start2 "<<start2<<endl;
		//cout<<"start3 "<<start3<<endl;
		//cout<<"the first number in circle.1: "<<input<<endl;
		input = incir1[input - 1];//array start from 0
		//cout<<" confirm.2 :"<<input<<endl;
		LRmove = relativedirfun(start1, input);
		//cout<<"##start2#"<<start2<<endl;
		//cout<<"##LRmove#"<<LRmove<<endl;
		input = start2 + LRmove;
		input = ctrlrange(input);
		//cout<<" confirm.3 :"<<input<<endl;
		input = incir2[input - 1];
		//cout<<" confirm.4 :"<<input<<endl;
		LRmove = relativedirfun(start2, input);
		//cout<<"LRmove"<<LRmove<<endl;
		input = start3 + LRmove;
		input = ctrlrange(input);
		//cout<<" confirm.5 :"<<input<<endl;
		input = incir3[input - 1];
		//cout<<" confirm.6 :"<<input<<endl;
		LRmove = relativedirfun(start3, input);
		input = LRmove + 1;//start from A
		input = ctrlrange(input);
		//cout<<" confirm.7 :"<<input<<endl;
		input = refcir[input - 1];//array start form 0
		//cout<<" confirm.8 :"<<input<<endl;
		//=====output reflec header - the input to get the move range=====//
		output = input + start3 - 1;
		output = ctrlrange(output);
		//cout<<" confirmO.9 :"<<output<<endl;
		//find the array location to get the number
		location = findalphabet(output, incir3);
		output = location;
		//cout<<" confirmO.10 :"<<output<<endl;
		//location equal number of the alphabet
		LRmove = relativedirfun(start3, output);
		//#cout<<" confirm LR:"<<LRmove<<endl;
		output = start2 + LRmove;
		output = ctrlrange(output);
		//cout<<" confirmO.11 :"<<output<<endl;
		location = findalphabet(output, incir2);
		output = location;
		//cout<<" confirmO.12 :"<<output<<endl;
		LRmove = relativedirfun(start2, output);
		output = start1 + LRmove;
		output = ctrlrange(output);
		//cout<<" confirmO.13 :"<<output<<endl;
		output = findalphabet(output, incir1);
		//cout<<" confirmO.14 :"<<output<<endl;
		LRmove = relativedirfun(start1, output);
		//cout<<" confirmO.15 move :"<<output<<endl;
		if (LRmove<0)
			LRmove = 26 + LRmove;//to avoid the wrong answer by the last code line

		output = 1 + LRmove;//A start from 1
		//cout<<"output: "<<output<<endl;
		arr[counter - 1] = plug[output - 1];
	}
	cout << "###########ANSWER#############" << endl;
	for (int j = 0; j<counter; j++)
		cout << (char)(arr[j] + 64) << " ";
	system("pause");
	return 0;
}

//algorithm of the know the devide the two side of circule,
//right side => +
//left side  => -
//we use the peak to move right or left to get the relative direction
int relativedirfun(int start, int input)
{
	int x, LRmove;
	x = 26 - start + 1;
	x = x + (input - 1);// (input-1) the number to the head's(A) range
	if (x>26)
		x = x - 26;
	if (x>13)
	{
		//left
		LRmove = 26 - x;
		LRmove = LRmove*(-1);
	}
	else if (x == 13)
	{
		LRmove = 13;
		//acorss
	}
	else
	{
		//right
		LRmove = x;
		LRmove = LRmove*(1);
	}
	//cout<<LRmove<<endl;
	return LRmove;
}

int findalphabet(int output, int circle[])
{
	int i;
	for (i = 0; i<26; i++)
	if (output == circle[i])
		break;
	location = i + 1;//location start from 1
	return location;
}

int ctrlrange(int input)
{
	if (input <= 0)
		input = 26 + input;

	if (input>26)
		input = input % 26;
	return input;
}

