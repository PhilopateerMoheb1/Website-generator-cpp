#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Footer {
private:
	string htmlCode, CssCode;
	int FooterNum;
public:
	void ChooseFooter(string websiteName) {
		cout << "Footer 1\n"
			<< "----------------------------------\n"
			<< "(website name)  All rights reserved\n"
			<< "-----------------------------------\n"
			<< "Footer 2\n"
			<< "------------------------------------\n"
			<< "       (Footer Background Color)     \n"
			<< "(website name)  All rights reserved\n"
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
		htmlCode = "<br><br><footer><div class=\"footerdiv\">";
		htmlCode += websitename;
		htmlCode += " All rights reserved</div></footer>";
		CssCode = "footer{margin-left:auto; margin-right:auto;} div.footerdiv{ text-align: center; left:0; bottom:0; width:100%; ";
		if (FooterNum == 2) {
			cout << "Footer Color: ";
			string footerBackgroundColor;
			cin >> footerBackgroundColor;
			CssCode += "background-color: ";
			CssCode += footerBackgroundColor + ";";
			cout << "Footer Text Color: ";
			string footerTextColor;
			cin >> footerTextColor;
			CssCode += "color: " + footerTextColor + ";";
			CssCode += "position: fixed;";
		}
		CssCode += "}";
	}
	string getHtml() { return htmlCode; }
	string getCss() { return CssCode; }
};
int main() {
	Footer f;
	f.ChooseFooter("Phalphilooo");
	FILE* html = fopen("index.html","w");
	fprintf(html, "<html><head><title>Philopateer Moheb</title>");
	fprintf(html, "<style>%s</style><body>", f.getCss().c_str());

	for (size_t i = 0; i < 100; i++)
	{
		fprintf(html, "philo<br>");
	}
	fprintf(html, "%s</body></html>", f.getHtml().c_str());

	return 0;
}
