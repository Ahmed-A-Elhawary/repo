/*
    PROBLEM 1
    - Accepts the number of steps taken each day in the month as numbers separated by spaces.
    - Calculates the highest and lowest step counts.
    - Calculates the average daily step count.
    - Sorts the step counts in descending order.

test numbers :
11044 3343 12489 11976 7233 7815 9067 8223 5165 6741 11589 6275 13581 7050 2673 11416 14974 10045 8237 11723 14297 4311 3981 1245 5421 1962 3459 9547 5032 14733

*/

#include<iostream>
#include<algorithm>

#define days 30

using namespace std;


int main(){ 
  int steps[days];
  
  // to accept 'steps' number form the user;
  cout<<endl<<"Enter the number of steps taken each day separated by spaces: ";
  for(int i = 0; i < days; i++){
    cin>>steps[i];
  }

  // in order to determine the 'highest' step counts
  int highest = 0;
  for(int i = 0; i < days; i++){
    if(steps[i] > highest)
      highest = steps[i];
  }

  // in order to determine lowest step counts
  int lowest = highest;
  for(int i = 0; i < days; i++){
    if(steps[i] < lowest)
      lowest = steps[i];
  }
  
  // find average
  long avg = 0;
  for(int i = 0; i < days; i++){
    avg += steps[i];
  }
  avg /= days;

  cout<<endl;
  cout<<"Highest Day: "<<highest<<endl;
  cout<<"Lowest Day: "<<lowest<<endl;
  cout<<"Average: "<< avg <<endl;

  // Sort the step counts in descending order.
  sort(steps,steps + days);
  cout<<endl;
  for(int i = 0; i < days; i++){
    cout<<steps[i]<<endl;
}

  return 0;
}
