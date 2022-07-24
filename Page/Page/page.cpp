#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

using namespace std;

class Page {
private:
	string htmlCode, CssCode;
public:
	void ChoosePage(string HeaderHtml, string FooterHtml ,string pagename, string BackgroundColor) {
		cout << "Page 1\n"
			<< "------------------------------------------------\n"
			<< "|     Youtube video    |     Youtube Video      |\n"
			<< "------------------------------------------------\n"
			<< "Page 2\n"
			<< "------------------------------------------------\n"
			<< "|     Youtube video    |     Youtube Video      |\n"
			<< "Choose Number: ";
		int pageNum;
		cin >> pageNum;
		generateCode(HeaderHtml, FooterHtml, pagename, pageNum,BackgroundColor);

	}
	void generateCode(string Headerhtml,string Footerhtml, string pageName, int pageNumber,string backgroundColor){
		htmlCode = "<html><head><title>";
		htmlCode += pageName + "</title>";
		htmlCode += "<link rel=\"stylesheet\" href=\"css\\header.css\">";
		htmlCode += "<link rel=\"stylesheet\" href=\"css\\footer.css\">";
		CssCode += "body{background-color: " + backgroundColor + "; } table.pagetable{margin-right: auto; margin-left: auto; width:100%; } td.pagetd{color:white; text-align: center; } iframe {width:100%;}";
		htmlCode += "<body><br>" + Headerhtml + "<br><br>";
		htmlCode += "<table class=\"pagetable\">";
		cout << "Enter NUMBER OF Rows: ";
		int rows;
		cin >> rows;
		for (size_t i = 0; i < rows; i++)
		{
			htmlCode += "<tr><td class= \"pagetd\">";
			cout << "Enter a video Link: ";
			string videoLink;
			cin >> videoLink;
			htmlCode += "<iframe width=\"560\" height=\"315\" src=\"https://www.youtube.com/embed/" + videoLink+ "\" title=\"YouTube video player\" frameborder=\"0\" allow=\"accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture\" allowfullscreen></iframe>";
			if (pageNumber == 1) {
				cout << "Enter a video Link: ";
				cin >> videoLink;
				htmlCode += "<iframe width=\"560\" height=\"315\" src=\"https://www.youtube.com/embed/" + videoLink + "\" title=\"YouTube video player\" frameborder=\"0\" allow=\"accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture\" allowfullscreen></iframe>";
			}
			else if (pageNumber == 2) {
				string text;
				cout << "Enter Text: ";
				getchar();
				getline(cin, text);
				htmlCode += text;

			}
			htmlCode += "</td></tr>";

		}
		htmlCode += "</table>" + Footerhtml + "</body></html>";
		htmlCode += "<style>" + CssCode + "</syle><head>";
	}
	string getHtml() { return htmlCode;	 }
};