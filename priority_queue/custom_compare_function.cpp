#include <bits/stdc++.h>
using namespace std;

class Student{
    public:
        string name;
        int roll;
        int num;

        Student(string name, int roll, int num)
        {
            this->name = name;
            this->roll = roll;
            this->num = num;
        }
};

class cmp{
    public:
        bool operator()(Student l, Student r)
        {
            if(l.num > r.num)
            {
                return true;
            }
            else if(l.num < r.num)
            {
                return false;
            }
            else
            {
                return l.roll > r.roll;
            }
        }
};

int main()
{
    priority_queue<Student, vector<Student>, cmp> pq;
    int n ; 
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string name;
        int roll, num;

        cin >> name >> roll >> num;
        Student obj(name, roll, num);
        pq.push(obj);
    }
    
    while (!pq.empty())
    {
        cout << pq.top().name << " " << pq.top().roll << " " << pq.top().num << endl;
        pq.pop();
    }
    
    return 0;
}