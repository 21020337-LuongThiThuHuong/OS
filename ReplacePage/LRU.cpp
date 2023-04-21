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
int indexCurrent(char frame[], map<char, int> mp, int currentIndex, int nOFrame){
	int distance = 0;
	int index = 0;
	for(int i = 0; i < nOFrame; i++){
		if(currentIndex - mp[frame[i]] > distance){
			distance = currentIndex - mp[frame[i]];
			index = i;
		}
	}
	return index;
}
int pageFaults(char pages[], int n, int nOFrame){
	int pageFaults = 0;
	char frame[nOFrame];
	for(int i = 0; i < nOFrame; i++){
		frame[i] = ' ';
	}
	int index = 0;
	map<char, int> mp;
	vector<string> listFrame;
	for(int i = 0; i < n; i++){
			if(i < nOFrame){
				if(find(pages[i], frame, nOFrame) == false){
					frame[index] = pages[i];
					index++;
					pageFaults++;
					listFrame.push_back(frame);
					mp[pages[i]] = i; // lấy vị trí xuất hiện của nó
				}
			}else{
				if(find(pages[i], frame, nOFrame) == false){
					pageFaults++;
					index = indexCurrent(frame, mp, i, nOFrame);
					frame[index] = pages[i];
					mp[pages[i]] = i;
					listFrame.push_back(frame);
				}else{
					mp[pages[i]] = i;
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
	cin >> referenceString;
	char pages[1001];
	int n = mapStringToPage(referenceString, pages);
	int nOFrame;
	for(int i = 1; i <= 10; i++){
		nOFrame = i;
		cout << pageFaults(pages, n, nOFrame) << " Page faults" << endl;
		cout << endl;
	}
	return 0;
}
