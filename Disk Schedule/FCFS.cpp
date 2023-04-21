#include <bits/stdc++.h>
using namespace std;
void FCFS(int arr[], int head, int size)
{
    int tmp = head;
    int seek_count = 0;
    int distance, cur_track;
 
    for (int i = 0; i < size; i++) {
        cur_track = arr[i];

        distance = abs(cur_track - head);
 
        seek_count += distance;
 
  
        head = cur_track;
    }
 
    cout << "Total number of seek operations = "
         << seek_count << endl;
 
    cout << "Seek Sequence is" << endl;
    cout << tmp << endl;
 
    for (int i = 0; i < size; i++) {
        cout << arr[i] << endl;
    }
}
 
int mapStringToProc(string s, int proc[]){
    int j = 0;
    string tmp = "";
    for(int i = 0; i < s.size(); i++){
        if(isdigit(s[i])){
           tmp += s[i];
        }else if(isspace(s[i])){
            continue;
        }
        else{
            proc[j++] = stoi(tmp);
            tmp = "";
        }
    }
    proc[j++] = stoi(tmp);
    return j;
}
int main()
{
 
    string s;
    cout << "Enter the groove shaft: ";
    getline(cin, s);
    int proc[10001];
    int len = mapStringToProc(s, proc);
    int currentGroove;
    cout << "Enter the current groove: ";
    cin >> currentGroove;
    FCFS(proc, currentGroove, len);
 
    return 0;
}