/*
1. divide the file into runs such that the size of a run
is small enough to fit into main memory.
2. sort each run in main memory using merge sort sorting algorithm
3. merge the resulting runs together into successively bigger runs
-----------
Merge k sorted arrays (of different length), merge them into a single
array such that the merged array is also sorted.
Input: {1, 4}, {2, 5}, {3, 6, 7}
Output: {1,2,3,4,5,6,7}
1. take pairs of arrays at each step
2. merge the pairs using merge sort algorithm
3. after merging all the pairs, the number of arrays will reduce by half
4. continue this till the number of remaining arrays does not become 1
// the number of steps need is O(log(k))
//at each step, taking O(N) time to perform the merge operations
// total time complexity is O(N*log(k))
*/
#include <iostream>
#include <vector>
using namespace std;


//Function to merge two arrays
vector<int> mergeTwoArrays(vector<int>& left, vector<int>& right)
{   //array to store the result after merging left and right
    vector<int> ret = {};

    //variables to store the current pointers for left and right
    int i = 0, j=0;

    // store the sizes of left array and right array
    int n1 = left.size();
    int n2 = right.size();

    //loop to merge left and right using two pointers

    while (i+ j < n1 + n2){
        if (i != n1 && (j == n2 || left[i] < right[j])){
            ret.push_back(left[i++]);
        }
        else {
            ret.push_back(right[j++]);
        }
    }

    return ret;

}
//O(n1+n2)

//Function to sort using merge sort algorithm
vector<int> mergeSort(vector<int> arr)
{
   if (arr.size() <= 1)
      return arr;

   vector<int> left, right, result;
   int mid = arr.size() / 2;
   //int middle = ((int)m.size()+ 1) / 2;

   for (int i = 0; i < mid; i++) {
      left.push_back(arr[i]);
   }

   for (int i = mid; i < arr.size(); i++) {
      right.push_back(arr[i]);
   }

   left = mergeSort(left);
   right = mergeSort(right);
   result = mergeTwoArrays(left, right);

   return result;

}





//Function to merge all the arrays
vector<int> mergeArrays(vector<vector<int>>& arr, bool sorted)
{
  vector<vector<int>> temp;

  if(!sorted){ // sort the unsorted arrays before merging arrays
    for(int i=0; i<arr.size(); i++){
       temp.push_back(mergeSort(arr[i]));
    }
    arr = temp;
    temp.clear();
    sorted=true;
  }

  int K = arr.size(); //number of files

 //loop when the number of remaining arrays does not become 1
  while(K != 1){
     temp.clear();

     for(int i=0; i<K; i+=2){
        if(i == K-1)
             temp.push_back(arr[i]);
        else
             temp.push_back(mergeTwoArrays(arr[i], arr[i+1]));
      }
      arr = temp; // new arrays with size reduced by half
      K = arr.size();
  }
  return arr[0];
}
//O(NlogK)

int main()
{
  cout<<"Input Arrays: {1, 4}, {5, 2, 9}, {3, 6, 7}"<<endl;
  vector<vector<int>> arr = {{1,4},{5, 2, 9},{3,6,7}};
  bool sorted=false;
  //Merge unsorted arrays
  vector<int> output = mergeArrays(arr, sorted);

  cout<<"Output sorted Arrays: "<<endl;
  for(int i = 0; i < output.size(); i++)
       cout<<output[i]<<" ";

  return 0;
}
