#include <bits/stdc++.h>
using namespace std;
 
void LOOK(int arr[], int head, int size, string direction)
{
    int tmp = head;
    int seek_count = 0;
    int distance, cur_track;
    vector<int> left, right;
    vector<int> seek_sequence;
 
    for (int i = 0; i < size; i++) {
        if (arr[i] < head)
            left.push_back(arr[i]);
        if (arr[i] > head)
            right.push_back(arr[i]);
    }
 
    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    int run = 2;
    while (run--) {
        if (direction == "left") {
            for (int i = left.size() - 1; i >= 0; i--) {
                cur_track = left[i];
 
                seek_sequence.push_back(cur_track);
 
                distance = abs(cur_track - head);
 
                seek_count += distance;
 
                head = cur_track;
            }
            direction = "right";
        }
        else if (direction == "right") {
            for (int i = 0; i < right.size(); i++) {
                cur_track = right[i];
                seek_sequence.push_back(cur_track);

                distance = abs(cur_track - head);
 
                seek_count += distance;
 
                head = cur_track;
            }
            direction = "left";
        }
    }
 
    cout << "Total number of seek operations = "
         << seek_count << endl;
 
    cout << "Seek Sequence is" << endl;
    cout << tmp << endl;
 
    for (int i = 0; i < seek_sequence.size(); i++) {
        cout << seek_sequence[i] << endl;
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
    string direction;
    cout << "Enter the direction(left or right): ";
    getline(cin, direction);
    int currentGroove;
    cout << "Enter the current groove: ";
    cin >> currentGroove;
    LOOK(proc, currentGroove, len, direction);
    return 0;

}