#include<string>
#include<iostream>
// properly space a string

using namespace std;

bool compareString(string const &str1, const char &str2)
{
	string temp(&str2, str1.length());
	cout<<"comparing "<<str1<<" and "<<temp<<endl;
	if(str1 == temp)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

bool SpaceTheString(string s, int start, int len, string dict[], int dictLen, string &output)
{
	if(len == 0)
	{
		cout<<"done \n";
		return true;
	}
	for(int i = 0; i< dictLen; i++)
	{
		if(len>= dict[i].length())
		{
			if(true == compareString(dict[i], s[start]))
			{
				if(true ==SpaceTheString(s, start+dict[i].length(), len - dict[i].length(), dict, dictLen, output))
				{
					output+= dict[i] + ' ';
					return true;
				}
			}
		}
	}
	return false;
}

int main()
{
	string str = "thisworldisacrazyworld";
	string dict[] = {"this", "is", "a", "crazy", "world"};
	string output;
	SpaceTheString(str, 0, str.length(), dict, 5, output);
	cout<<output;
}
