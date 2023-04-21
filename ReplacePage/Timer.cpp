#include<iostream>
#include<iomanip>
#include<time.h>   // Thư viện thời gian
const int MAXN = 720;
using namespace std;
int main(){
    clock_t start, end;   
    long double time_use;     
   
     int data[MAXN][MAXN];  
     start = clock();    
  	for(int j = 0; j < MAXN; j++){
   		for(int i = 0; i < MAXN; i++){
   			data[i][j] = 0;
   		}

   	}
    end = clock(); 
    time_use = (double)(end - start)*1.00000000 / CLOCKS_PER_SEC;  
    cout <<"Thoi gian chay: "<<time_use << endl;


     start = clock();    
   	for(int i = 0; i < MAXN; i++){
   		for(int j = 0; j < MAXN; j++){
   			data[i][j] = 0;
   		}

   	}
    end = clock(); 
    time_use = (double)(end - start) / CLOCKS_PER_SEC;  
    cout <<"Thoi gian chay: "<<time_use;
}