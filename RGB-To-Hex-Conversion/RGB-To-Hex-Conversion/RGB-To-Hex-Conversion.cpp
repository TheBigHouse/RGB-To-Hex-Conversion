// RGB-To-Hex-Conversion.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <iomanip>

using namespace std;
class RGBToHex
{
public:
	static std::string rgb(int r, int g, int b);

};

class myRGBToHex : RGBToHex
{
public:
	static std::string rgb(int r, int g, int b) {
		std::string rsr, gsr, bsr;
		if (r < 0) rsr = "00";
		else if (r > 255) rsr = "FF";
		else rsr = decToHex(r).size() >= 2 ? decToHex(r) : '0' + decToHex(r);
		if (g < 0) gsr = "00";
		else if (g > 255) gsr = "FF";
		else gsr = decToHex(g).size() >= 2 ? decToHex(g) : '0' + decToHex(g);
		if (b < 0) bsr = "00";
		else if (b > 255) bsr = "FF";
		else bsr = decToHex(b).size() >= 2 ? decToHex(b) : '0' + decToHex(b);
		return rsr + gsr + bsr;
	}

public:
	static std::string decToHex(int n) {
		std::string hex;
		int left;
		left = n / 16;
		//hex = n % 16 > 10 ? 'A' + (n % 16 - 10) : n % 16;
		if (n % 16 >= 10) {
			hex = 'A' + (n % 16 - 10);
		}
		else {
			hex = addstring("", n % 16);
		}
		if (left > 0) {
			hex += decToHex(left);
		}
		reverse(hex.begin(), hex.end());
		return hex;
	}
public:
	static std::string addstring(std::string s, int n) {
		std::ostringstream ss;
		ss << s << n;
		return ss.str();
	}
};

std::string RGBToHex::rgb(int r, int g, int b) {
	std::stringstream ss;
	std::string res;
	ss << std::uppercase << std::setfill('0') << std::setw(2) << std::hex << (r < 0 ? 0 : r>255 ? 255 : r)
		<< std::uppercase << std::setfill('0') << std::setw(2) << std::hex << (g < 0 ? 0 : g>255 ? 255 : g)
		<< std::uppercase << std::setfill('0') << std::setw(2) << std::hex << (b < 0 ? 0 : b>255 ? 255 : b);
	ss >> res;
	return res;
}

int main()
{
	cout << RGBToHex::rgb(250, 250, 125) << endl;
	system("pause");
    return 0;
}

