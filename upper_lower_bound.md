# Lower Bound
 The `lower_bound()` method in `C++` is used to return an iterator pointing to the first element in the range [first, last) which has a value not less than val.
 This means that the function returns the index of the next smallest number just greater than or equal to that number. If there are multiple values that are equal to val, `lower_bound()` returns the index of the first such value.
 The elements in the range should be sorted.
 
## Example:
```
vector<int> v{1, 3, 6, 6, 8};
vector<int>::iterator lower1, lower2, lower3;
lower1 = lower_bound(v.begin(), v.end(), 4); // Index will be 2
lower2 = lower_bound(v.begin(), v.end(), 1); // Index will be 0
lower3 = lower_bound(v.begin(), v.end(), 9); // Index will be 5
// To get the index do: lower1 - v.begin();
cout<<"lower_bound for element 4 at position : "<<lower1 - v.begin()<<endl; // 2
```

# Upper Bound
upper_bound() is a standard library function in C++ defined in the header. It returns an iterator pointing to the first element in the range [first, last) that is greater than value, or last if no such element is found. The elements in the range shall already be sorted or at least partitioned with respect to val.

## Example:
```
vector<int> v{1, 3, 6, 6, 8};
vector<int>::iterator upper1, upper2, upper3;
upper1 = upper_bound(v.begin(), v.end(), 6); // 4
upper2 = upper_bound(v.begin(), v.end(), 1); // 1
upper3 = upper_bound(v.begin(), v.end(), 4); // 2
// To get the index do: upper1 - v.begin(); 
cout<<"upper_bound for element 6 at position : "<<upper1 - v.begin()<<endl; //4
```
