#include<bits/stdc++.h>
#include<iostream>
using namespace std;
// map in stl
// STL container which store key value pair
// the ele are store in accesnding or descending order
// maps cant have duplicate key
// implemented through BST;
int main(){
// map<string,int,greater<string>>m;
// m["gaurav"]=2134;
// m["ashish"]=34324;
// m["saurabh"]=4848;
// m["jayant"]=77228;
// m["ashish"]=77228;
// m.insert(make_pair("ballu",3234)); 
// m.insert({"dh",9879});
// for(auto ele:m){// data type of ele is key value pair 
//     cout<<"name - "<<ele.first<<endl;
//     cout<<"no - "<<ele.second<<endl;
// }
// map<string,int>:: reverse_iterator itr;
// for(itr=m.rbegin();itr!=m.rend();itr++){
// cout<<itr->first<<endl;
// cout<<itr->second<<endl;
// }
// insert--O(logN);
// erase()
// size()
// max_size()
// find() if find then returns result else return  end itr
// count();
// empty();
// upper_bound() -- returns next greater ele
// lower_bound()-- return ele if present else return next greater ele
// begin()
// end()
// rbegin()
// rend()

// Q---find the sum of repetitive ele in given arr
// 1 1 1 2 3 3  output 1+3=4
// time-O(N) space-O(n);

// int n;
// cin>>n;
// vector<int>v(n);

// for(int i=0;i<n;i++){
//     cin>>v[i];
// }
// map<int, int>m ;
// for(int i=0;i<n;i++){
//     m[v[i]]++;
// }
// int sum = 0;
// for(auto pair:m){
//     if(pair.second>1){
//         sum+=pair.first;
//     }
// }
// cout<<sum<<endl;




//                                 *******************unordered_map***********************
//                                  ele are not ordered
//                                  keys will be unique



// unordered_map<int,string>record;
// map<int,string>record;
// record.insert(make_pair(3,"ria"));
// record[1]="hans";
// record[2]="you";
// record[3]="divya";

// insert,erase,find all have O(1) time in avg case and O(n) in worst case
// count-if key present return 1 else 0;
// record.erase(3); 
// record.erase(record.find(1));
// record.erase(record.find(1),record.end());
// for(auto pair:record){
//     cout<<pair.first<<" "<<pair.second<<endl;
// }



//                                    ***************multimap*****************
//                                      ele are store in an order ascending or descending
//                                      duplicate keys are allowed 


// insert()
// delete()
// search()   O(logn) time for all


// multimap<string,int>directory;
// directory.insert(make_pair("urvi",54322));
// directory.insert(make_pair("mohan",54322));
// directory.insert(make_pair("mohan",54322));
// for(auto pair:directory){
//     cout<<pair.first<<" "<<pair.second<<endl;
// }

//                     **********unordered multimap*******
// insert,delete,search O(1) time for avg case and O(n) for worst case

// unordered_multimap<string,int>map;
// map.insert(make_pair("urvi",54322));
// map.insert(make_pair("mohan",54322));
// map.insert(make_pair("same",53322));
// for(auto pair:map){
//     cout<<pair.first<<" "<<pair.second<<endl;
// }
 


return 0;
} 