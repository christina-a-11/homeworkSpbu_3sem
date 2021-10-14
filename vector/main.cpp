#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void enlarge(vector<int> &v)
{
    vector<int> new_v;
    for(int i = 0; i < v.size() - 1; i++)
    {
        new_v.push_back(v[i]);
        new_v.push_back((v[i] + v[i + 1])/2);
    }
    new_v.push_back(v[v.size() - 1]);
    v = new_v;
}
void del(vector<int> &v)
{
    vector<int> new_v;
    for(vector<int>::iterator i = v.begin() + 1; i < v.end(); i+=2)
    {
        new_v.push_back(*i);
    }
    v = new_v;
}
vector<int> concat(vector<int> v1, vector<int> v2)
{
    for(auto x : v2)
    {
        v1.push_back(x);
    }
    return v1;
}
vector<int> repeat(vector<int> v, int n)
{
    vector<int> new_v;
    for(int i = 0; i < n; i++)
    {
        for(auto x : v)
        {
            new_v.push_back(x);
        }
    }
    return new_v;
}
vector<int>::iterator find_second(vector<int> v, int d)
{
    vector<int>::iterator i = find(v.begin(), v.end(), d);
    if(i == v.end())
    {
        return i;
    }
    i++;
    i = find(i, v.end(), d);
    return i;
}
vector<int>::iterator find_last(vector<int> v, int d)
{
    vector<int>::iterator i = v.begin();
    while(find(i, v.end(), d) != v.end())
    {
        i = find(i, v.end(), d);
        i++;
    }
    if(i == v.begin() && *i != d)
    {
        return v.end();
    }
    return i;
}
bool subseq(vector<int> v1, vector<int> v2)
{
    int i = 0;
    for(auto x : v1)
    {
        if(x == v2[i])
        {
            i++;
        }
    }
    if(i == v2.size())
    {
        cout << "true\n";
        return true;
    }
    else
    {
        cout << "false\n";
        return false;
    }
}
vector<int>::iterator find_last_bound(vector<int> sort_v, int d)
{
    vector<int>::iterator i = sort_v.begin();
    i = upper_bound(sort_v.begin(), sort_v.end(), d);
    i--;
    if(*i != d)
    {
        return sort_v.end();
    }
    return i;
}
void find_index(vector<double> v, double x, int &i, int &j)
{
    vector<double>::iterator a, b, c = v.begin();
    a = upper_bound(v.begin(), v.end(), x);
    b = lower_bound(v.begin(), v.end(), x);
    if(a == b)
    {
        return; // число х не найдено
    }
    if(++b == a)
    {
        b--;
    }
    b--;
    i = 0; //v.begin() - b
    j = 0; //distance()
    while(c != a)
    {
        j++;
        c++;
    }
    c = v.begin();
    while(c != b)
    {
        i++;
        c++;
    }
}
void print(vector<int> v)
{
    if(v.size() == 0)
    {
        cout << "empy\n";
    }
    for(auto x : v)
    {
        cout << x << " ";
    }
    cout << '\n';
}
int main()
{
    /*enlarge() and del()
    vector<int> v {5, 7, 9, 11};
    print(v);
    enlarge(v);
    print(v);
    vector<int> v2 {1};
    print(v2);
    del(v2);
    print(v2);
    del(v);
    print(v);*/

    //copy()
    vector<int> v1{1, 3, 5, 7, 9};
    int arr[5]{0};
    copy(v1.begin(), v1.end(), arr);
    for(auto x: arr)
    {
        cout << x << " ";
    }
    cout << '\n';
    vector<int> v2{10, 12, 14};
    vector<int> v3 = concat(v1, v2);
    print(v1);
    print(v2);
    print(v3);
    v3 = repeat(v2, 4);
    print(v3);

    /*find()
    vector <int> v{3, 2, 5, 9, 4, 5, 7};
    cout << *find_second(v, 1) << '\n';
    cout << *find_second(v, 9) << '\n';
    cout << *find_second(v, 5) << '\n';
    vector<int> v2{3, 2, 5, 9, 4, 5, 7, 1, 5, 8};
    cout << *find_last(v2, 5) << '\n';
    vector<int> vv{1, 2, 3, 5, 6, 7, 8, 9};
    vector<int> vv1{3, 5, 7, 8};
    vector<int> vv2{5, 3, 7, 8};
    subseq(vv, vv1);
    subseq(vv, vv2); */

    /*upper_bound() and lower_bound() find
    vector<int> v1 {11,24,31,31,40,50,60,60,70,100,112};
    sort(v1.begin(), v1.end());
    cout << *(find_last_bound(v1, 40)) << '\n';
    vector<double> v {11,24.5,31.0f,31,40,50,60.05f, 70,100,112};
    int i = -1;
    int j = -1;
    sort(v.begin(), v.end());
    find_index(v, 66, i, j);
    cout << " i = " << i << '\n';
    cout << " j = " << j << '\n';
    find_index(v, 60.05f, i, j);
    cout << " i = " << i << '\n';
    cout << " j = " << j << '\n'; */
    return EXIT_SUCCESS;
}
