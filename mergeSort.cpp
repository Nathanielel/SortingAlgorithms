/*
  Nathaniel Larsen - mergesort implementation - Sept. 2020
  Started this at the begining of Data Structures & Algorithms..
  Decided to try and come around and code merge in-place
*/

#include <cstdlib>
#include <ctime>
#include <iostream>

void sort(int *A, int left, int right);

int main() {
  srand(time(0));
  int arr[43] = {0};

  // populate
  for (int i = 0; i < 43; ++i) {
    arr[i] = rand() % 43;
  }

  // print
  for (int i = 0; i < 42; ++i) {
    std::cout << arr[i] << ", ";
  }
  std::cout << arr[42] << std::endl;

  // sort
  sort(arr, 0, 42);

  // print
  for (int i = 0; i < 42; ++i) {
    std::cout << arr[i] << ", ";
  }
  std::cout << arr[42] << std::endl;
}

// IN-PLACE merging algorithm, sacrifices time complexity for space
//   O(n^2)time, O(1) space
void merge_tight(int *arr, int left, int mid, int right) {
  int left2 = mid + 1;                 // second half's starting pt
  if (arr[mid] <= arr[left2]) return;  // already in order

  while (left <= mid && left2 <= right) {
    // subarrays have more elementts to process / iterate through
    if (arr[left] <= arr[left2])  // first element is already in position
      ++left;
    else {
      // put arr[left2] on the left of first element (linear shift)
      int val = arr[left2], at = left2;
      while (at != left) {
        arr[at] = arr[at - 1];
        --at;
      }
      arr[left] = val;

      ++left;
      ++mid;
      ++left2;
    }
  }
}

// traditional merging algorithm. takes O(n lg n) time and uses O(n) space
void merge_fast(int *arr, int left, int mid, int right) {
  int len1 = mid - left + 1;  // length of subarray [left..mid]
  int len2 = right - mid;     // subarray (mid..right]
  int i, j, k;                // cursors

  // make working arrays & deep copy data into them
  int L[len1], R[len2];
  for (i = 0; i < len1; ++i) {
    L[i] = arr[i + left];
  }
  for (j = 0; j < len2; ++j) {
    R[j] = arr[j + mid + 1];
  }

  // put elts of subarrays back in their proper position
  i = j = 0;
  k = left;
  while (i < len1 && j < len2) {  // not done merging comparable elts
    // put the lesser of current elts into arr[k]
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      ++i;
    } else {
      arr[k] = R[j];
      ++j;
    }
    ++k;
  }

  // copy any leftovers from longer subarray
  while (i < len1) {
    arr[k] = L[i];
    ++k;
    ++i;
  }
  while (j < len2) {
    arr[k] = R[j];
    ++k;
    ++j;
  }
}

void sort(int *A, int left, int right) {
  if (left < right) {  // can further divide
    // find midpoint by going halfway to R from L (avoids overflow for very
    // large L+R)
    int mid = left + (right - left) / 2;
    sort(A, left, mid);
    sort(A, mid + 1, right);

    // switch function calls for time vs space
    // merge_tight(A, left, mid, right);
    merge_fast(A, left, mid, right);
  }
}
