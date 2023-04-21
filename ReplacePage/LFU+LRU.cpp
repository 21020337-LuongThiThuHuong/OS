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
bool check(int currentItemPosition, int newItemPosition){
	return newItemPosition < currentItemPosition ? true: false; // thỏa mãn LRU
}
int indexCurrentByFrequency(char frame[], map<char, pair<int, int>> mp, int nOFrame){
	int leastFrequency = INT_MAX;
	int index = 0;
	int currentItemPosition = 0;
	for(int i = 0; i < nOFrame; i++){
		if(mp[frame[i]].first < leastFrequency){
			leastFrequency = mp[frame[i]].first;
			index = i;
			currentItemPosition = mp[frame[i]].second;
		}else if (mp[frame[i]].first == leastFrequency){
			bool flag = check(currentItemPosition, mp[frame[i]].second);
			if(flag == true){
				index = i;
				currentItemPosition = mp[frame[i]].second;
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
	int index = 0;
	map<char, pair<int, int>> mp;
	vector<string> listFrame;
	for(int i = 0; i < n; i++){
			if(i < nOFrame){
				if(find(pages[i], frame, nOFrame) == false){
					frame[index] = pages[i];
					index++;
					pageFaults++;
					listFrame.push_back(frame);
					mp[pages[i]].first++; 
					mp[pages[i]].second = i;
					} 
			}else{
				if(find(pages[i], frame, nOFrame) == false){
					pageFaults++;
					index = indexCurrentByFrequency(frame, mp, nOFrame);
					frame[index] = pages[i];
					mp[pages[i]].first++; 
					mp[pages[i]].second = i; 
					listFrame.push_back(frame);
				}else{
						mp[pages[i]].first++; 
						mp[pages[i]].second = i; 
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
		cout << i << " Frame: " << endl;
		cout << pageFaults(pages, n, nOFrame) << " Page faults" << endl;
		cout << endl;
	}
	return 0;
}
