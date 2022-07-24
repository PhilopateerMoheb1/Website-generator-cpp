#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>


using namespace std;

class Header {
private:
	string htmlCode, CssCode;
	int HeaderNum;
	string intTostring(int num) {
		switch (num) {
		case 1:
			return "1";
		case 2:
			return "2";
		case 3:
			return "3";
		case 4:
			return "4";
}
	}
public:
	void ChooseHeader(vector<string>pageName){
		cout << "Header 1\n"
			<< "----------------------------------------\n"
			<<" |                Picture               |\n" 
			<< "|   Home    |   Contact   |    About   |\n"
			<< "----------------------------------------\n"
			<< "Header 2\n"
			<< "----------------------------------------\n"
			<< "|   Home    |   Contact   |    About   |\n"
			<< "----------------------------------------\n"
			<< "Please Enter Your choice: ";
		cin >> HeaderNum;
		while (HeaderNum != 1 && HeaderNum != 2) {
			cout << "Enter correct Choice: ";
			cin >> HeaderNum;
		}
		GenerateCode(pageName);
	}
	void GenerateCode(vector<string>pageName) {
		htmlCode = "<table class=\" headertable\">";
		CssCode = "table.headertable{ width:100%; margin-left: auto; margin-right: auto; }";
		CssCode += "td.headertd{border: 1px solid black; color: black; text-align: center; font-size: 20px;}a.headera{text-decoration: none; color: black;}";
		if (HeaderNum == 1) {
			CssCode += "img.headerimg{ width: 100%; height: auto; }";
			string PictureFileName;
			cout << "Picture File Name: ";
			cin >> PictureFileName;
			htmlCode += "<tr><td class=\"headertd\" colspan= \""+intTostring(pageName.size()) +"\"><img class =\"headerimg\"src = \"" + PictureFileName;
			htmlCode += "\" /></td></tr>";
		}
		htmlCode += "<tr>";
		htmlCode += "<td class= \"headertd\"><a class=\"headera\" href=\"index.html\">" + pageName[0] + "</a> </td>";
		for (size_t i = 1; i < pageName.size(); i++)
		{
			htmlCode += "<td class= \"headertd\"><a class=\"headera\" href=\"" + pageName[i]+".html\">" +pageName[i]+ "</a> </td>";
		}
		htmlCode += "</tr></table>";
	}
	string getHtml() { return htmlCode; }
	string getCss() { return CssCode; }
};
int main() {
	FILE* htmlfile=fopen("index.html", "w");
	Header h;
	vector<string>pageName = { "Home","Contact","About" ,"Courses"};
	h.ChooseHeader(pageName);
	fprintf(htmlfile,"<html><head><title>Test</title><style>");
	fprintf(htmlfile, h.getCss().c_str());
	fprintf(htmlfile, "</style></head><body>%s",h.getHtml().c_str());
	fprintf(htmlfile, "</body></html>");
	return 0;

}