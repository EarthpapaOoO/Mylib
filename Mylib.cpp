#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string upper_to_lower(string str)
{

	auto length = (str.length());
	for (size_t i = 0; i < length; i++)
	{
		char temp = str[i];
		if ('A' <= temp && temp <= 'Z')
			str[i] = char(temp + 32);
	}
	return str;
}
string lower_to_upper(string str)
{

	auto length = size_t(str.length());
	for (size_t i = 0; i < length; i++)
	{
		char temp = str[i];
		if ('a' <= temp && temp <= 'z')
			str[i] = char(temp - 32);
	}
	return str;
}
int char_to_num(char c)
{
	int result = 0;
	if (48 <= c && c <= 57)
	{
		result = int(c - 48);
	}
	else if (65 <= c && c <= 90)
	{
		result = int(c - 55);
	}
	else if (97 <= c && c <= 122)
	{
		result = int(c - 87);
	}
	return result;

}
char num_to_char(int num)
{
	char result = '\0';
	if (0 <= num && num <= 9)
	{
		result =  to_string(num).at(0);
	}
	else if (10 <= num && num <= 35)
	{
		result =  char('a' + num - 10);
	}
	return result;
}
string baseConversion(int sourceBase, int targetBase, string baseString)
{
	int decimal = 0;
	string targetString;
	size_t length = baseString.length();
	for (size_t i = 0; i < length; i++)
	{
		size_t index = length - i - 1;
		decimal += int(pow(double(sourceBase), double(i)) * char_to_num(baseString.at(index)));
	}
	//test here
	cout << "demical = " << decimal << endl;
	while (decimal > 0)
	{
		char temp;
		temp = num_to_char(decimal % targetBase);
		targetString.insert(targetString.end(), temp);
		decimal /= targetBase;
	}
	reverse(targetString.begin(), targetString.end());
	return targetString;
}
