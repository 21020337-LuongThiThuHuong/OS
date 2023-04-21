#include<bits/stdc++.h>
using namespace std;
bool find(char digit, char frame[], int nOFrame){
	for(int i = 0; i < nOFrame; i++){
		if(frame[i] == digit){
			return true;
		}
	}
	return false;
}
bool isSpace(char frame[], int nOFrame){
	for(int i = 0; i < nOFrame; i++){
		if(frame[i] == ' '){
			return true;
		}
	}
	return false;
}
int pageFaults(char pages[], int n, int nOFrame){
	int pageFaults = 0;
	char frame[nOFrame];
	for(int i = 0; i < nOFrame; i++){
		frame[i] = ' ';
	}
	int j = 0;
	vector<string> listFrame;
	for(int i = 0; i < n; i++){
			if(isSpace(frame, nOFrame) == true){
				if(find(pages[i], frame, nOFrame) == false){
					frame[j] = pages[i];
					j++;
					j %= nOFrame;
					pageFaults++;
					listFrame.push_back(frame);
				}
			}else{
				if(find(pages[i], frame, nOFrame) == false){
					pageFaults++;
					frame[j] = pages[i];
					j++;
					j %= nOFrame;
					listFrame.push_back(frame);
				}
			}	
	}
	for(int j = 0; j < nOFrame; j++){
		for(int i = 0; i < pageFaults; i++){
			cout << listFrame[i][j] << " ";
		}
		cout << endl;
	}
	return pageFaults;
}	

int mapStringToPage(string referenceString,char pages[]){
	int j = 0;
	for(int i = 0; i < referenceString.size(); i++){
		if(isdigit(referenceString[i]))
			pages[j++] = referenceString[i];
	}
	return j;
}
int main()
{
	string referenceString;
	getline(cin, referenceString);
	char pages[1001];
	int n = mapStringToPage(referenceString, pages);
	int nOFrame;
for(int i = 1; i <= 7; i++){
		nOFrame = i;
		cout << i << " Frame: " << endl;
		cout << pageFaults(pages, n, nOFrame) << " Page faults" << endl;
		cout << endl;
	}
	return 0;
}
