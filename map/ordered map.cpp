#include <iostream>
#include<map>
#include<string>
using namespace std;

int main() {
    map<string,int>m;

    //insert
    //way 1
    m.insert(make_pair("Apple", 10));

    //way 2
    pair<string, int>p;
    p.first = "Banana";
    p.second = 20;
    m.insert(p);

    //way 3
    m["Mango"] = 30;

    //search
    string fruit;
    cin>>fruit;

    auto it = m.find(fruit);
    if(it!=m.end()){
        cout<<"fruit is "<<fruit<<" of price "<<m[fruit]<<endl;
    }
    else{
        cout<<"not found"<<endl;
    }

    //another way to find a particular map
    //it store unique keys only once
    if(m.count(fruit)){
        cout<<"price is "<<m[fruit]<<endl;
    }
    else{
        cout<<"couldn't fount"<<endl;
    }

    //erase
    m.erase(fruit);

    //iterate over the all key value pairs
    for(auto it=m.begin(); it!=m.end(); it++){
        cout<<it->first<<" -> "<<it->second<<endl;
    }

    //for each loop
    for(auto p: m){
        cout<<p.first<<" : "<<p.second<<endl;
    }
return 0;
}

/*
Input
Apple

Output
fruit is Apple of price 10
price is 10
Banana -> 20
Mango -> 30
Banana : 20
Mango : 30
*/