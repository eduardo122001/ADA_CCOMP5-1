#include <iostream>

int gVect[100]; // Buffer to save the elements
int gnCount; // Counter to know the number of elements used


void Insert(int elem)
{
if( gnCount < 100 ) // we can only insert if there is space
gVect[gnCount++] = elem; // Insert the element at the end
}

int main() {
  Insert(1);
  Insert(2);
  Insert(3);
  Insert(4);

  for(int i=0;i<gnCount;i++) std::cout<<gVect[i]<<" ";
  
}