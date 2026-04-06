// 16052025.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<thread>
#include<chrono>
#include<vector>
using namespace std;
void fun()
{
    int i;
    for (i = 0; i < 10; i++)
        cout << "so easy:"<< i << endl;
}
int main()
{
    cout << "start" << endl;
    vector<thread*>list;
    int n = 10;
    int i;
    for (i = 0; i < n; i++)
        list.push_back(new thread(fun));
    for(i=0;i<n;i++)
    cout << "end" << endl;
    return 0;
}

