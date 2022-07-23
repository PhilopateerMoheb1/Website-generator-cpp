#include<iostream>
#include<string>
using namespace std;

class Footer {
private:
	string htmlCode, CssCode;
	int FooterNum;
public:
	void ChooseFooter(string websiteName) {
		cout << "Footer 1\n"
			<< "----------------------------------\n"
			<< "(website name) All rights reserved\n"
			<< "-----------------------------------\n"
			<< "Footer 2\n"
			<< "------------------------------------\n"
			<< "       (Footer Background Color)     \n"
			<< "(website name) All rights reserved\n"
			<< "Choose Footer Number: ";
		while (1) {
			cin >> FooterNum;
			if (FooterNum == 1 || FooterNum == 2) {
				break;
			}
		}
		GenerateCode(websiteName);

	}
	void GenerateCode(string websitename) {
		htmlCode = "<footer><div class=\"footerdiv\">";
		htmlCode += websitename;
		htmlCode += "all rights reserved</div></footer>";
		CssCode = "footer{margin-left:auto; margin-right:auto; div.footerdiv{position: fixed; left:0; bottom:0; width:100%;";
		if (FooterNum == 2) {
			cout << "Footer Color: ";
			string footerBackgroundColor;
			cin >> footerBackgroundColor;
			CssCode += "background-color: ";
			CssCode += footerBackgroundColor + ";";
			cout << "Footer Text Color: ";
			string footerTextColor;
			CssCode += "color: " + footerTextColor + ";";
		}
		CssCode += "}";
	}
	string getHtml() { return htmlCode; }
	string getCss() { return CssCode; }
};