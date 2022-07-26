#include<iostream>
#include<string>
#include<vector>
#include"Header.h"
#include "Footer.h"
#include<sys/stat.h>
#include <direct.h>
#include"Page.h"



using namespace std;
class website {
private:
	string websiteName, backgroundColor;
	vector<string>pageName;
public:
	void createWebsite() {
		cout << "Website Name: ";
		cin >> websiteName;
		cout << "Number of pages: ";
		int NumOfPages;
		cin >> NumOfPages;
		cout << "Enter a background Color: ";
		cin >> backgroundColor;
		for (size_t i = 0; i < NumOfPages; i++)
		{
			cout << "Enter the name of page " <<i + 1<<": ";
			string NameOfPage;
			cin >> NameOfPage;
			pageName.push_back(NameOfPage);
		}
		Header h;
		h.ChooseHeader(pageName);
		Footer f;
		f.ChooseFooter(websiteName);
		_mkdir(websiteName.c_str());
		string cssFolder = websiteName;
		cssFolder += "//css";
		_mkdir(cssFolder.c_str());
		string cssFile = cssFolder;
		cssFile += "//header.css";
		ofstream headerCss(cssFile);
		headerCss << h.getCss();
		headerCss.close();
		cssFile = cssFolder;
		cssFile += "//Footer.css";
		ofstream FooterCss(cssFile);
		FooterCss << f.getCss();
		FooterCss.close();
		for (size_t i = 0; i < NumOfPages; i++)
		{
			Page p;
			cout << pageName[i] << " Details" << endl;
			p.ChoosePage(h.getHtml(), f.getHtml(), pageName[i], backgroundColor);
			string file = websiteName;
			if (i == 0) {
				file += "//index.html";
			}
			else
			{
				file +="//"+ pageName[i] + ".html";
			}
			ofstream Pagehtml(file);
			Pagehtml << p.getHtml();
			Pagehtml.close();
		}
	}
};


int main() {
	website w;
	w.createWebsite();
}