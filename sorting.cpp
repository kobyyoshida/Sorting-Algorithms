#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

void insertSort(double array[], int size){
  for(int j = 1; j < size; ++j){
    double temp = array[j];
    int k = j;
    while (k>0 && array[k-1]>=temp){
      array[k]=array[k-1];
      --k;
    }
    array[k] = temp;
  }
}

void selectionSort (double array[], int size){
  int i, j, minIndex, tmp;
  for(int i = 0; i < size; i++){
    minIndex = i;
    for(int j = 0; j < size; j++){
      if(array[j]<array[minIndex]){
        minIndex = j;
      }
    }
    if(minIndex != i){
      tmp = array[i];
      array[i] = array[minIndex];
      array[minIndex] = tmp;
    }
  }
}

void bubbleSort(double myArray[], int size){
  for(int i = 0; i < size; ++i){
    double temp = 0;
    for(int j = 0; j < size-1; ++j){
      if(myArray[j] > myArray[j+1]){
        temp = myArray[j+1];
        myArray[j+1] = myArray[j];
        myArray[j] = temp;
      }
    }
  }
}


int partition(double array[], int low, int high) {
  double pivot = array[high];
  int i = low-1;
  double temp = 0;
  for(int j = low; j <= high-1; j++) {

    if(array[j] <= pivot) {
      i++;
      temp = array[j];
      array[j] = array[i];
      array[i] = temp;
    }
  }
  temp = array[high];
  array[high] = array[i+1];
  array[i+1] = temp;
  return i+1;
}

void quickSort(double array[], int low, int high) {
  if(low < high) {
    int index = partition(array, low, high);
    quickSort(array, low, index-1);
    quickSort(array, index+1, high);
  }
}

int main (int argc, char ** argv){
  string filePath;

  if (argc != 2) { //Checks for valid command line arguments and saves argument to filePath variable
    cerr << "Incorrect number of arguments. " << endl;
    return 0;
  }
  else {
    filePath = argv[1];
  }

  ifstream file;
  file.open(filePath);
  if(!file) {
    cerr << "File not found." << endl;
    return 0;
  }

  string line;

double *nums;
double *nums1;
double *nums2;
double *nums3;
int i = 0;
int size;



if(getline(file,line)) { //this will get the first line of the file and create arrays that are that size

  size = stoi(line);
  nums = new double[size];
  nums1 = new double[size];
  nums2 = new double[size];
  nums3 = new double[size];
}

while(getline(file, line)) { //this will read the file and set each element as a double in the array
  nums[i] = stod(line);
  nums1[i] = stod(line);
  nums2[i] = stod(line);
  nums3[i] = stod(line);
  i++;
}


  auto startTime = high_resolution_clock::now();
  insertSort(nums, size);
  auto stopTime = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stopTime - startTime);
  cout << "Insertion Sort finished in " << duration.count() << " microseconds. " << endl;

  startTime = high_resolution_clock::now();
  selectionSort(nums1, size);
  stopTime = high_resolution_clock::now();
  duration = duration_cast<microseconds>(stopTime - startTime);
  cout << "Selection Sort finished in " << duration.count() << " microseconds. " << endl;

  startTime = high_resolution_clock::now();
  bubbleSort(nums2, size);
  stopTime = high_resolution_clock::now();
  duration = duration_cast<microseconds>(stopTime - startTime);
  cout << "Bubble Sort finished in " << duration.count() << " microseconds. " << endl;

  startTime = high_resolution_clock::now();
  quickSort(nums3, 0, size);
  stopTime = high_resolution_clock::now();
  duration = duration_cast<microseconds>(stopTime - startTime);
  cout << "Quick Sort finished in " << duration.count() << " microseconds. " << endl;

  return 0;
}
