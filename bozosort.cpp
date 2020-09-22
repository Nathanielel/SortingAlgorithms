/*
    Nathaniel Larsen - bozosort implementation - Jan. 2020
    Just for fun. Works, but sometimes has to give up.
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <climits>

const int LIMIT = INT_MAX;

void print_vector(std::vector<int>& v){
  for (int i = 0; i < v.size(); i++)
    std::cout << v[i] << std::endl;
  std::cout << "=========================\n" ;
}

void swap(int& num1, int& num2){
  int temp = num1;
  num1 = num2;
  num2 = temp;
}

//iterate through list to check if it's sorted - O(n)
bool is_sorted(std::vector<int>& v){
  for (unsigned i = 0; i < v.size() - 1; i++)
    if (v[i] > v[i+1]) return false;
  return true;

}

//pick 2 random numbers from the vector and swap them - O(1)
void bozo_swap(std::vector<int>& unsorted){
  unsigned index1 = rand() % unsorted.size(); //generate a number from 0 to size - 1
  unsigned index2 = rand() % unsorted.size(); //generate a number from 0 to size - 1
  swap(unsorted[index1], unsorted[index2]);
}

int bozo_sort(std::vector<int>& v){
  unsigned int iteration = 0;
  while (!is_sorted(v)){
    bozo_swap(v);
    print_vector(v);
    if (iteration >= LIMIT) return -1;
    iteration++;
  }
  return iteration;
}

main(){
  srand(time(0));
  std::vector<int> v;
  for (int i = 0; i < 10; i++)
    v.push_back(rand() % 840);
  //  print_vector(v);
  int attempts = bozo_sort(v);
  if(attempts >= 0)  
    std::cout << "sorting completed after " << attempts << " swaps\n";
  else
    std::cout << "Failed to sort data after " << attempts << " swaps\n";
}

