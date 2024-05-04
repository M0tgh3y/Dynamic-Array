#include <iostream>
using namespace std;
template <typename T>

class nemidanam
{
public:
    T* arr;
    int sz;

    nemidanam()
    {
        arr = nullptr;
    }

    nemidanam(int a)
    {
        arr = new T[a];
        this->sz = a;
    }

    ~nemidanam()
    {
        delete []arr;
    }

    void print()
    {
        for (int i = 0; i < sz; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void read(int a)
    {
        this->sz = a;
        for (int i = 0; i < sz; i++)
        {
            cin >> arr[i];
        }
    }

    void resiz(int m)
    {
        T* temp = new T[m];
        if (m > sz)
        {
            for (int i = 0; i < sz; i++)
            {
                temp[i] = arr[i];
            }
            for (int i = sz; i < m; i++)
            {
                temp[i] = {0};
            }
            delete []arr;
            this->sz= m;
            this->arr = temp;
        }
        else
        {
            for (int i = 0; i < sz; i++)
            {
                temp[i] = arr[i];
            }
            delete []arr;
            this->sz= m;
            this->arr = temp;
        }

    }

    double miang()
    {
        double sum;
        for (int i = 0; i < sz; i++)
        {
            sum = arr[i] + sum;
        }
        return (sum / sz);
    }

    void soort()
    {
        for (int i = 0; i < sz - 1; i++)
        {
            for (int j = 0; j < sz - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    bool operator==(nemidanam a2)
    {
        if (sz != a2.sz)
        {
            return false;
        }

        for (int i = 0; i < sz; i++)
        {
            if (arr[i] != a2.arr[i])
            {
                return 0;
                break;
            }
            return 1;
        }
    }

    void operator=(nemidanam a2)
    {
        for (int i = 0; i < (*this).a; i++)
        {
            a2.arr[i] = arr[i];
        }
    }
};

//**********************

int main()
{
    nemidanam<double> arr1(100);
    int tedadarr = 0;

    while (tedadarr < 4)
    {
        cout << "1.sakht array" << endl;
        cout << "2.resize array" << endl;
        cout << "3.mohasebe miangin" << endl;
        cout << "4.moratab kardan array" << endl;
        cout << "5.check mosavi boodan" << endl;
        cout << endl << "**********************" << endl;
        int chose;
        cout << endl <<"entekhab ra vared konid: ";
        cin >> chose;
        switch (chose)
        {
        case 1:
            {
                tedadarr++;
                cout << "***sakht array***" << endl;
                cout << "size ra vared konid:";
                int n;
                cin >> n;
                arr1.read(n);
                cout << endl << "**********************" << endl;
                break;
            }

        case 2:
            {
                cout << "***resize array***" << endl;
                int m;
                cout << "size jadid ravared konid:";
                cin >> m;
                arr1.resiz(m);
                arr1.print();
                cout << endl << "**********************" << endl;
                break;
            }

        case 3:
            {
                cout << "***mohasebe miangin***" << endl;
                cout << "miangin mosavi ast ba: " << arr1.miang() << endl;
                cout << endl << "**********************" << endl;
                break;
            }

        case 4:
            {
                cout << "***moratab kardan array***" << endl;
                cout << "moratam mosavi ast ba: ";
                arr1.soort();
                arr1.print();
                cout << endl << "**********************" << endl;
                break;
            }

        case 5:
            {
                cout << "***check mosavi boodan***" << endl;
                int n2;
                cout << "size array 2 ra vared konid: ";
                cin >> n2;
                nemidanam<double> arr2(n2);
                arr2.read(n2);
                if (arr1 == arr2)
                {
                    cout << "mosavi";
                }
                else
                {
                    cout << "mosavi nist";
                }
                cout << endl << "**********************" << endl;
                break;
            }
        }
    }
}
