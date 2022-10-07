//
//  dsatrial1.cpp
//
//
//  Created by Vansh Vatsal on 30/08/22.
//

#include <bits/stdc++.h>
using namespace std;

class SEIT
{
    string name;
    int roll;
    float sgpa;

public:
    void getdata()
    {
        string a;
        int b;
        float c;
        cout << "Enter Name : " << endl;
        cin >> a;
        cout << "Enter Roll No. : " << endl;
        cin >> b;
        cout << "Enter SGPA : " << endl;
        cin >> c;
        name = a;
        roll = b;
        sgpa = c;
    }
    void putdata()
    {
        cout << name << endl;
        cout << roll << endl;
        cout << sgpa << endl;
    }
    void linearsearch(SEIT s[], int n, float key)
    {
        bool flag = 1;
        for (int i = 0; i < n; i++)
        {
            if (s[i].sgpa == key)
            {
                cout << "Object is present at " << i << " index." << endl;
                s[i].putdata();
                flag = 0;
            }
        }
        if (flag)
        {
            cout << "No record found" << endl;
        }
    }

    void binarysearch(SEIT s[], int n, string nm)
    {

        int start = 0;
        int end = n - 1;
        int mid = (start + end) / 2;
        bool flag = 1;
        while (start <= end)
        {
            if (s[mid].name == nm)
            {
                s[mid].putdata();
                flag = 0;
                break;
            }
            else if (s[mid].name < nm)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
            mid = (start + end) / 2;
        }
        if (flag)
        {
            cout << "No record found." << endl;
        }
    }
    void bubblesort(SEIT s[], int n)
    {

        for (int l = 0; l < n; ++l)
        {

            for (int i = 0; i < n -l-1; ++i)
            {

                if ( s[i].roll > s[i+1].roll)
                {
                    swap(s[i],s[i+1]);
                }
            }
        }
    }
    void insertionSort( SEIT s[], int size) {
  for (int step = 1; step < size; step++) {
    int key = s[step];
    int j = step - 1;

    // Compare key with each element on the left of it until an element smaller than
    // it is found.
    // For descending order, change key<array[j] to key>array[j].
    while (key < s[j] && j >= 0) {
      s[j + 1] = s[j];
      --j;
    }
    s[j + 1] = key;
  }
}
    void printArray(SEIT s[], int n)
    {
        for (int i = 0; i < n; ++i)
        {
            cout << "roll  " <<  s[i].roll<<endl;
            cout << "name  " << s[i].name<<endl;
            cout << "sgpa  " << s[i].sgpa<<endl;
        }
        cout << "\n";
    }
};

int
menu()
{
    int a;
    cout << " 1 for linear search" << endl;
    cout << " 2 for binary search" << endl;
    cout << " 3 to display details of all students" << endl;
    cout << " 4 to exit" << endl;
    cout << " 5 to do Bubble Sort" << endl;
    cout << " 6 to do Insertion Sort" << endl;

    cout << "enter your choice = ";
    cin >> a;
    cout << endl;
    return a;
}
int main()
{
    cout << "enter number of students" << endl;
    int n;
    cin >> n;
    SEIT s[n];
    for (int i = 0; i < n; i++)
    {
        s[i].getdata();
    }
    int status;
    status = menu();
    while (true)
    {
        SEIT task;

        if (status == 4)
        {
            break;
        }
        else if (status == 1)
        {
            float key;
            cout << "Enter SGPA of the student : " << endl;
            cin >> key;

            task.linearsearch(s, n, key);
        }
        else if (status == 2)
        {
            string nm;
            cout << "Enter the name of the student : " << endl;
            cin >> nm;
            task.binarysearch(s, n, nm);
        }
        else if (status == 3)
        {
            for (int i = 0; i < n; i++)
            {
                s[i].getdata();
            }
        }
        else if (status == 5)
        {
            
            task.bubblesort(s, n);
            cout << "Sorted Array in Ascending Order:\n";
            task.printArray(s,n);
            
        }
        else if (status==6){
            task.insertionSort(s,size);
            cout<<"Insertion Sort"<<endl;
            task.printArray(s,size);
        }

        else
        {
            cout << "invalid input pls enter another choice" << endl;
        }

        status = menu();
    }
    return 0;
}
