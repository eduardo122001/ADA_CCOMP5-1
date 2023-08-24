#include <iostream>
#include <cstdlib>

// Class CVector definition
class CVector
{
  private:

    int *m_pVect, // Pointer to the buffer
    m_nCount, // Control how many elements are actually used
    m_nMax, // Control how many are allocated as maximum
    m_nDelta; // To control the growing
    void Init(int delta); // Init our private variables, etc
    void Resize(); // Resize the vector when occurs an overflow

  public:

    CVector(int delta = 10); // Constructor
    void Insert(int elem); // Insert a new element
    // More methods go here
    int Get(int index);
     int Size();  
};

void CVector::Insert(int elem)
{
  if( m_nCount == m_nMax ) // Verify the overflow
  Resize(); // Resize the vector before inserting elem
  m_pVect[m_nCount++] = elem; // Insert the element at the end
}

CVector::CVector(int delta)
{
    Init(delta);
}

void CVector::Init(int delta)
{
    m_nCount = 0;
    m_nMax = delta;
    m_nDelta = delta;
    m_pVect = new int[m_nMax];
}

void CVector::Resize()
{
    int* temp = new int[m_nMax + m_nDelta];
    for (int i = 0; i < m_nCount; ++i)
    {
        temp[i] = m_pVect[i];
    }
    delete[] m_pVect; 
    m_pVect = temp;
    m_nMax += m_nDelta;
}

int CVector::Get(int index) 
{
    if (index >= 0 && index < m_nCount)
        return m_pVect[index];
    else
        std::cout<<"empty";
}

int CVector::Size() 
{
    return m_nCount;
}

int main() {
  CVector m;
  m.Insert(1);
  m.Insert(2);
  m.Insert(3);
  m.Insert(4);

  for (int i = 0; i <m.Size(); ++i)
    {
        std::cout << m.Get(i) << " ";
    }

  
}