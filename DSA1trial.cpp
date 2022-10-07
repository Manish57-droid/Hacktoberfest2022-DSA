//Created by Vansh Vatsal on 30/08/22
//
//



#include <iostream>
using namespace std;
class student{
    private:
        string name;
        int rollno;
        float sgpa;
    public:
        void putdata(string a,int b , float c){
            name = a;
            rollno  = b;
            sgpa = c;
            }
        void displaydata(){
            cout << "Name : " << name << endl;
            cout << "Roll No. : " << rollno << endl;
            cout << "Sgpa : " << sgpa << endl;
        }
        float getsgpa(){
            return sgpa;
        }
        string getname(){
            return name;
        }
        void linearsearch(student s[], int n, float x)
            {
            int i;
            int c=0;
            for (i = 0; i < n; i++){
                if (s[i].sgpa == x){
                    c+=1;
                    cout << "SGPA found at -> " << i << endl;
                    s[i].displaydata(); }}
            if (c==0) cout << "Not Found" << endl;
        }
        int binarysearch(student s[], int n, string x)
            {
            int low = 0;
            int high = n-1;
            int mid = (high+low)/2;
            while (low<=high){
                mid = (high+low)/2;
                if (s[mid].name == x){
                    return mid;
                }
                else if (s[mid].name < x){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
                }
            return -1;
            }
        void insertionsortname(student s[] ,int n){
            int i,j;
            string ky;
            for (int i = 1 ; i<n;i++){
                ky = s[i].name;
                j= i-1;
                while(j>-1 && s[j].name>ky){
                    swap(s[j+1],s[j]);
                    j=j-1;
                }
            }
        }

        void bubblesortroll(student s[] ,int n){
            for (int  i = 0 ; i < n-1 ; i++){
                for ( int j = 0; j < n-i-1 ; j++){
                    if (s[j].rollno>s[j+1].rollno){
                        swap(s[j],s[j+1]);

                    }}}}

int partition(student s[], int low, int high)
    {
        int i = low;
        int j = high;
        float pivot = s[low].getsgpa();
        while (i < j)
        {
            while (pivot <= s[i].getsgpa())
                i++;
            while (pivot > s[j].getsgpa())
                j--;
            if (i < j)
                swap(s[i], s[j]);
        }
        swap(s[low], s[j]);
        return j;
    }

void quickSort(student s[], int low, int high)
    {
    if (low < high)
        {
        int pivot = partition(s, low, high);
        quickSort(s, low, pivot - 1);
        quickSort(s, pivot + 1, high);
        }}


        };



int main()
    {

    int ans;
    float key;
    string keyname;
    int n;
    string a;
    int b;
    float c;
    cout << "enter no. of students : " ;
    cin >> n;
    student s[n];
    student t;


    do {
        cout << "Choose Any One : - >" << endl;
        cout << "1.Enter Record\n2.Display\n3.Linear Search\n4.Binary Search\n5.Bubble Sort\n6.Insertion Sort\n7.Quick Sort" << endl;
        int choice;
        cin >> choice;
    switch(choice){
            case 1:
                    for(int i = 0 ; i < n ; i++){
                        cout << "enter name : " ;
                        cin >> a ;
                        cout << "enter roll no : ";
                        cin >> b;
                        cout << "enter SGPA : ";
                        cin >> c;
                        cout << endl;
                        s[i].putdata(a,b,c);
                    }
                break;
            case 2:
                    for(int i = 0 ; i < n ; i++){
                        s[i].displaydata();
                        }
                break;
            case 3:
                cout << "enter SGPA to be searched - > " << endl;
                cin >> key;
                cout << "SGPAs found at : -> " << endl ;
                
                t.linearsearch(s,n,key);
                break;
            case 4:
                t.insertionsortname(s,n);
                for(int i = 0 ; i < n ; i++){
                        s[i].displaydata();
                        }
                cout << "Enter Name to be searched - >" << endl;
                cin >> keyname;
                if(t.binarysearch(s,n,keyname)==-1){
                    cout<<"Name not Found"<<endl;
                }
                else{
                cout << "Name found at : -> " << t.binarysearch(s,n,keyname)<<endl;
                s[t.binarysearch(s,n,keyname)].displaydata();}
                break;
            case 5:
                cout << "Bubble Sort Acc. to roll no. -> " << endl;
                    t.bubblesortroll(s,n);
                    for(int i = 0 ; i < n ; i++){
                        s[i].displaydata();
                        }
                break;
            case 6:
                cout << "Insertion Sort Acc. to name -> " << endl;
                    t.insertionsortname(s,n);
                    for(int i = 0 ; i < n ; i++){
                        s[i].displaydata();
                        }
                break;
            case 7:
                cout << "Quick Sort Acc. to SGPA" << endl;
                    t.quickSort(s, 0, n - 1);
                    cout<<"How Many Student do you want?"<<endl;
                    int k;
                    cin>>k;
                    for(int i = 0 ; i < k; i++)
                        {
                        s[i].displaydata();
                        }

        }
            cout << "Do you want to continue {0/1} : - >" << endl;
            cin >> ans;}

    while(ans);
    return 0;
}



