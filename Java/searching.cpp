#include<iostream>
#include<vector>
using namespace std;
void binarySearch(vector<int> &v, int key)
{
    int low = 0;
    int high = v.size() - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (v[mid] == key)
        {
            cout << "Found " << key << " at index " << mid << endl;
            return;
        }
        else if (v[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << "Not found " << key << endl;
}
int main()
{
    vector<int> v ;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int key;
    cout << "Enter the key to search: ";
    cin >> key;
    binarySearch(v, key);
    return 0;
}
