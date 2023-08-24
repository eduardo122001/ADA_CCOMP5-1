#include <iostream>
#include <cstdlib>


struct Vector
{
int*m_pVect, // Pointer to the buffer
m_nCount, // Control how many elements are actually used
m_nMax, // Control how many are allocated as maximum
m_nDelta; // To control the growing
};

void Resize(Vector *pThis)
{
pThis->m_pVect = (int *)realloc(pThis->m_pVect, sizeof(int) *
(pThis->m_nMax + pThis->m_nDelta));
// The Max has to be increased by delta
pThis->m_nMax += pThis->m_nDelta;
}
void Insert(Vector *pThis, int elem)
{
if( pThis->m_nCount == pThis->m_nMax ) // Verify the overflow
Resize(pThis); // Resize the vector before inserting elem
// Insert the element at the end of the sequence
pThis->m_pVect[pThis->m_nCount++] = elem;
}






int main() {
  Vector m;
  m.m_nCount=0;
  m.m_nMax=4;
  m.m_nDelta=4;
  m.m_pVect=(int*)malloc(sizeof(int) * m.m_nMax);
  
  
  Insert(&m, 1);
  Insert(&m, 2);
  Insert(&m, 3);
  Insert(&m, 4);

  for(int i=0;i<4;i++) std::cout<<*(m.m_pVect+i)<<" ";
  
}