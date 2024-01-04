#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 


// use this for ordered_set of int
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

// or this for ordered_set of pair<int,int>
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update> 


/**
  USAGE
  */

ordered_set o_set; 

o_set.insert(5); 
o_set.insert(1); 
o_set.insert(2); 

// find element at index k in sorted set (0-indexed)
cout << *(o_set.find_by_order(k)) << endl;

// find no. of elements strictly less than k
cout << o_set.order_of_key(k)  << endl;
