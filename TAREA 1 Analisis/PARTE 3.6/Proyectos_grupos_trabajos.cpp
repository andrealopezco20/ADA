#include<iostream>
#include<vector>
using namespace std;

class CMyComplexDataStructure
{
    vector<float> m_container;

    public:
    void Insert(float fVal) { m_container.push_back(fVal); }
    template <typename objclass>
    void sumone(objclass funobj)
    {
        vector<float>::iterator iter = m_container.begin();
        for (; iter != m_container.end() ; iter++)
        funobj(*iter);

    }
};

template <typename objclass>
class funcobjclass
{
    public:
    void operator ()(objclass& objinstance)
    {
        objinstance++;
    }
};

int main(int argc, char* argv[])
{
    CMyComplexDataStructure ds;
    ds.Insert(5.5);
    ds.Insert(6.6);
    ds.Insert(7.7);
    ds.Insert(8.9);
    funcobjclass<float> x;
    ds.sumone(x);
    return 0;
}
