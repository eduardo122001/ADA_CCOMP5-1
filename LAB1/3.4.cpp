#include <iostream>
#include <cstdlib>

// Class CVector definition
template <typename Type> class CVector
{
  private:
    Type*m_pVect; // Pointer to the buffer
    int m_nCount, // Control how many elements are actually used
    m_nMax, // Control the number of allocated elements
    m_nDelta; // To control the growing
    void Init(int delta); // Init our private variables, etc
    void Resize(); // Resize the vector when occurs an overflow
  public:
    CVector(int delta = 10); // Constructor
    void Insert(Type elem); // Insert a new element
    // ...
    int Size() ;
    Type Get(int index) ; 
};

template <typename Type>
CVector<Type>::CVector(int delta)
{
    Init(delta);
}

template <typename Type>
void CVector<Type>::Init(int delta)
{
    m_nCount = 0;
    m_nMax = delta;
    m_nDelta = delta;
    m_pVect = new Type[m_nMax];
}

template <typename Type>
void CVector<Type>::Insert(Type elem)
{
    if (m_nCount == m_nMax)
        Resize();
    m_pVect[m_nCount++] = elem;
}

template <typename Type>
void CVector<Type>::Resize()
{
    Type* temp = new Type[m_nMax + m_nDelta];
    for (int i = 0; i < m_nCount; ++i)
    {
        temp[i] = m_pVect[i];
    }
    delete[] m_pVect;
    m_pVect = temp;
    m_nMax += m_nDelta;
}

template <typename Type>
int CVector<Type>::Size()
{
    return m_nCount;
}

template <typename Type>
Type CVector<Type>::Get(int index) 
{
    if (index >= 0 && index < m_nCount)
        return m_pVect[index];
    else
        std::cout<<"empty";
}

int main() {
  CVector <int>m;
  m.Insert(1);
  m.Insert(2);
  m.Insert(3);
  m.Insert(4);

  for (int i = 0; i <m.Size(); ++i)
    {
        std::cout << m.Get(i) << " ";
    }

  
}