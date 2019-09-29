#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
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

string match_txt = "match0.txt";
string plugpart1_txt = "plugboard_part1.txt";

string plugb(string n) {
	string AZ = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char t[7] = "000000", temp;
	int tn[6];
	int tt = 0;
	for (int i = 0; i < 26; i++) {
		if (n[i] != '0') {
			if (t[(int)n[i] - 49] == '0') {
				t[(int)n[i] - 49] = AZ[i];
				tn[(int)n[i] - 49] = i;
			}
			else {
				temp = AZ[tn[(int)n[i] - 49]];
				AZ[tn[(int)n[i] - 49]] = AZ[i];
				AZ[i] = temp;
			}
			tt++;
		}
		if (tt == 12)break;
	}
	return AZ;
}


int main() {
	int incir1[26] = { 1, 10, 4, 11, 19, 9, 18, 21, 24, 2, 12, 8, 23, 20, 13, 3, 17, 7, 26, 14, 16, 25, 6, 22, 15, 5 };
	int incir2[26] = { 5, 19, 15, 22, 16, 26, 10, 1, 25, 17, 21, 9, 18, 8, 24, 12, 14, 6, 20, 7, 11, 4, 3, 13, 23, 2 };
	int incir3[26] = { 2, 4, 6, 8, 10, 12, 3, 16, 18, 20, 24, 22, 26, 14, 25, 5, 9, 23, 7, 1, 11, 13, 21, 19, 17, 15 };
	int refcir[26] = { 25, 18, 21, 8, 17, 19, 12, 4, 16, 24, 14, 7, 15, 11, 13, 9, 5, 2, 6, 26, 3, 23, 22, 10, 1, 20 };
	int plug[26];
	int start1 = 24, start2 = 4, start3 = 8;
	int index1 = 23, index2 = 6, index3 = 18;
	int location;
	int input = 0;
	int output = 0;
	int g = 1, h = 1, j = 0;//start1, start2, start3
	string scir;
	int check[10] = { 8, 5, 9, 12, 8, 9, 20, 12, 5, 18 };//HITLER//Heil Hitler
	int similartimes = 0;
	//int checkroop = 0;
	int flag = 0;
	char filename[] = "findkey.txt";
	fstream fp;
	fp.open(filename, ios::out);
	if (!fp)
		cout << "Fail to open the file: " << filename << endl;

	while (g <= 26) {
		int counter = 0;
		int similartimes = 0;
		j++;
		if (j > 26)
		{
			h++;
			j = 1;
		}

		if (h > 26)
		{
			g++;
			h = 1;
		}
		if (g == 27)
			break;
		start1 = g, start2 = h, start3 = j;//output all start possibility
		cout << "start1 " << start1 << endl;
		cout << "start2 " << start2 << endl;
		cout << "start3 " << start3 << endl;
		//cout << "ENTER THE PLUGBOARD: " << endl;
		//cin >> scir;

		////////////////////////////////////////////////////////
		fstream file1;
		fstream match0;
		file1.open(plugpart1_txt, ios::in);
		string buffer1, buffer, t, sst, plugboardn, str[13], table2;
		int tt, is, st, w[13], ttt;
		while (getline(file1, buffer1)) {
			tt = 0;
			match0.open(match_txt, ios::in);
			while (getline(match0, buffer)) {
				ttt = 0;
				st = 0;
				for (int i = 0; i < 13; i++) {
					w[i] = 0;
					str[i] = "0";
				}
				stringstream ss(buffer);
				while (getline(ss, sst, ',')) {
					w[ttt] = atoi(sst.c_str());
					str[ttt] = sst;
					//cout << w[tt] << "_";
					ttt++;
					//cout <<tt<< endl;
				}

				string *num;
				num = new string[ttt + 1];
				for (int i = 0; i < ttt; i++) {
					//cout << str[i];
					num[i] = str[i];
				}
				num[ttt] = "0";
				/*for (int i = 0; i < tt+1; i++) {
				cout << num[i];
				}*/
				vector<int> vec(13);
				int te = 0;
				for (int i = 0; i < vec.size(); i++) {
					if (i == 0) {
						vec[i] = 0;
					}
					else {
						if (num[te] != "0") {
							te++;
						}
						vec[i] = te;
					}
				}
				/*for (int i = 0; i < vec.size(); i++) {
				cout << vec[i];
				}*/
				int aa = 0;
				do {
					for (auto& i : vec) {
						//cout << num[i];
						//output.write(num[i].c_str(), num[i].length());
						table2 += num[i];
						aa++;
						if (aa % 13 != 0) {
							//cout << ",";
							//output.write(",", 1);
							table2 += ',';
						}
					}
					if (aa > 1000)aa = 0;
					//cout << endl;
					//output.write("\n", 1);

					stringstream ss(table2);
					for (int i = 0; i < 13; i++) {
						getline(ss, t, ',');
						if (i == 0)plugboardn = "";
						is = atoi(t.c_str());
						while (is) {
							//cout << 0;
							plugboardn += "0";
							is--;
						}
						if (i < 12) {
							//cout << buffer1[i];
							plugboardn += buffer1[i];
						}
					}
					//cout << plugboardn << endl;
					scir = plugb(plugboardn);
					for (int M = 0; M < 26; M++)
						plug[M] = scir[M] - 64;
					//cout << endl;

					char s[10] = { 9, 16, 17, 8, 21, 7, 3, 24, 26, 13 };//INPUT:UGCXZM//IPQHUGCXZM

					counter = 0;
					similartimes = 0;
					while (counter < 10) {
						//checkroop++;
						//cout<<"start1 "<<start1<<endl;
						//cout<<"start2 "<<start2<<endl;
						//cout<<"start3 "<<start3<<endl;
						counter++;
						input = s[counter - 1];
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
						start3 = ctrlrange(start3);
						input = start1 + input;
						input = ctrlrange(input);
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
						if (LRmove < 0)
							LRmove = 26 + LRmove;//to avoid the wrong answer by the last code line

						output = 1 + LRmove;//A start from 1
											//cout<<"output: "<<output<<endl;
						if (check[counter - 1] != plug[output - 1])
							break;
						else
							similartimes++;

						if (similartimes == 10)
						{
							//output the information of the Enigma's situation
							fp << "start1: " << g << endl;
							fp << "start2: " << h << endl;
							fp << "start3: " << j << endl;
							fp << scir << endl;
							cout << scir << endl;
						}

					}

					table2.clear();
				} while (next_permutation(vec.begin(), vec.end()));

				delete[] num;
			}
			match0.close();
		}
		file1.close();
		///////////////////////////////////////////////////////
	}
	fp.close();
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
	if (x > 26)
		x = x - 26;
	if (x > 13)
	{
		//left
		LRmove = 26 - x;
		LRmove = LRmove * (-1);
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
		LRmove = LRmove * (1);
	}
	//cout<<LRmove<<endl;
	return LRmove;
}

int findalphabet(int output, int circle[])
{
	int i;
	for (i = 0; i < 26; i++)
		if (output == circle[i])
			break;
	location = i + 1;//location start from 1
	return location;
}

int ctrlrange(int input)
{
	if (input <= 0)
		input = 26 + input;

	if (input > 26)
		input = input % 26;
	return input;
}
