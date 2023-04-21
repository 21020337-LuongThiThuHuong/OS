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
// 2,3,2,1,5,2,4,5,3,2,3,5
char alphaByFIFO(map<char, int> mp, char frame[], int nOFrame){
	int distanceMin = INT_MAX;
	char tmp;
	for(int i = 0; i < nOFrame; i++){
		if(mp[frame[i]] < distanceMin){
			distanceMin = mp[frame[i]];
			tmp = frame[i];
		}
	}
	return tmp;
}
int indexByFIFODeAlpha(map<char, int> mp, char frame[], char alpha, int nOFrame){
	int distanceMin = INT_MAX;
	int index = 0;
	for(int i = 0; i < nOFrame; i++){
		if(frame[i] == alpha) continue;
		else{
			if(mp[frame[i]] < distanceMin){
				distanceMin = mp[frame[i]];
				index = i;
			}
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
	map<char, int> referenceBit;
	for(int i = 0; i < n; i++){
		referenceBit[pages[i]] = 0;
	}
	map<char, int> mp;
	int index = 0;
	vector<string> listFrame;
	for(int i = 0; i < n; i++){
			if(isSpace(frame, nOFrame) == true){
				if(find(pages[i], frame, nOFrame) == false){	
					frame[index++] = pages[i];
					pageFaults++;
					mp[pages[i]] = i;
					listFrame.push_back(frame); 
				}else{
					referenceBit[pages[i]] = 1;
				}
			}else{
				if(find(pages[i], frame, nOFrame) == false){
					char alpha = alphaByFIFO(mp, frame, nOFrame); // lấy được kí tự vào đầu tiên
					if(referenceBit[alpha] == 1){
						referenceBit[alpha] = 0;
						index = indexByFIFODeAlpha(mp, frame, alpha, nOFrame);
						frame[index] = pages[i];
						mp[pages[i]] = i;
						listFrame.push_back(frame);	
					}else{
						for(int k = 0; k < nOFrame; k++){
							if(frame[k] == alpha){
								index =  k;
								break;
							}
						}
						frame[index] = pages[i];
						mp[pages[i]] = i;
						listFrame.push_back(frame);
					}
					pageFaults++;
				}else{
					referenceBit[pages[i]] = 1;
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
for(int i = 1; i <= 10; i++){
		cout << i << " Frame: " << endl;
		cout << pageFaults(pages, n, nOFrame) << " Page faults" << endl;
		cout << endl;
	}
	return 0;
}		nOFrame = i;

