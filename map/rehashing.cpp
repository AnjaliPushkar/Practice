/*Rehashing: to avoid collision we increase the size of table
table size increase on the basis of load factor = current size/ table size
step 1: load factor
step 2: create a new table with size 2x
step 3: shift element from old to new table
step 4: delete old table
*/ 
#include<iostream>
#include<cstring>
using namespace std;

template<typename T>
class Node{
public:
    string key;
    T value;
    Node<T>*next;

    Node(string key, T value){
        this->key = key;
        T val = value;
        next = NULL;
    }
    ~Node(){
        if(next!=NULL){
            delete next;
        }
    }
};

template<typename T>
class Hashtable{
    Node<T>**table; //pointer to an arrays of pointer
    int table_size;
    int current_size;
    
    int hashfucn(string key){
        int idx =0;
        int p =1;
        for(int j=0; j<key.length(); j++){
            idx = idx + (key[j]*p)%table_size;
            idx = idx%table_size;
            p = (p*27)%table_size;
        }
        return idx;
    }
    void rehash(){
        Node<T>**oldtable = table;
        int oldtable_size = table_size;
        table_size = 2*table_size;//approximation find the next prime no.
        table = new Node<T>*[table_size];

        for(int i=0; i<table_size; i++){
            table[i] = NULL;
        }
        current_size = 0;
        
        //shift elements from old to new table
        for(int i=0; i<oldtable_size; i++){
            Node<T>*temp = oldtable[i];
            while(temp!= NULL){
                insert(temp->key, temp->value);
                temp = temp->next;
            }
            if(oldtable[i] != NULL){
                delete oldtable[i];
            }
        }
    delete [] oldtable;
    }

public:
    Hashtable(int ts=7){
        table_size = 7;
        table = new Node<T>*[table_size];
        current_size = 0;
        for(int i=0; i<table_size; i++){
            table[i] = NULL;
        }
    }

    
    void insert(string key, T value){
        int idx = hashfucn(key);
        Node<T>*n = new Node<T>(key, value);
        //insert at the head of linked list with id = idx
        n->next = table[idx];
        table[idx] = n;
        current_size++;
        //rehash
        float load_factor = current_size/(1.0*table_size);
        if(load_factor > 0.7){
            rehash();
        }
    }

    void print(){
        for(int i=0; i<table_size; i++){
            cout<<"Bucket"<<i<<"->";
            Node<T>*temp = table[i];
            while(temp != NULL){
                cout<<temp->key<<"->";
                temp = temp->next;
            }
            cout<<endl;
        }
    }

    // T search(string key){

    // }

    // void erase(string erase){

    // }
};
/*Rehashing: to avoid collision we increase the size of table
table size increase on the basis of load factor = current size/ table size
step 1: load factor
step 2: create a new table with size 2x
step 3: shift element from old to new table
step 4: delete old table
*/ 
#include<iostream>
#include<cstring>
using namespace std;

template<typename T>
class Node{
public:
    string key;
    T value;
    Node<T>*next;

    Node(string key, T value){
        this->key = key;
        T val = value;
        next = NULL;
    }
    ~Node(){
        if(next!=NULL){
            delete next;
        }
    }
};

template<typename T>
class Hashtable{
    Node<T>**table; //pointer to an arrays of pointer
    int table_size;
    int current_size;
    
    int hashfucn(string key){
        int idx =0;
        int p =1;
        for(int j=0; j<key.length(); j++){
            idx = idx + (key[j]*p)%table_size;
            idx = idx%table_size;
            p = (p*27)%table_size;
        }
        return idx;
    }
    void rehash(){
        Node<T>**oldtable = table;
        int oldtable_size = table_size;
        table_size = 2*table_size;//approximation find the next prime no.
        table = new Node<T>*[table_size];

        for(int i=0; i<table_size; i++){
            table[i] = NULL;
        }
        current_size = 0;
        
        //shift elements from old to new table
        for(int i=0; i<oldtable_size; i++){
            Node<T>*temp = oldtable[i];
            while(temp!= NULL){
                insert(temp->key, temp->value);
                temp = temp->next;
            }
            if(oldtable[i] != NULL){
                delete oldtable[i];
            }
        }
    delete [] oldtable;
    }

public:
    Hashtable(int ts=7){
        table_size = 7;
        table = new Node<T>*[table_size];
        current_size = 0;
        for(int i=0; i<table_size; i++){
            table[i] = NULL;
        }
    }

    
    void insert(string key, T value){
        int idx = hashfucn(key);
        Node<T>*n = new Node<T>(key, value);
        //insert at the head of linked list with id = idx
        n->next = table[idx];
        table[idx] = n;
        current_size++;
        //rehash
        float load_factor = current_size/(1.0*table_size);
        if(load_factor > 0.7){
            rehash();
        }
    }

    void print(){
        for(int i=0; i<table_size; i++){
            cout<<"Bucket"<<i<<"->";
            Node<T>*temp = table[i];
            while(temp != NULL){
                cout<<temp->key<<"->";
                temp = temp->next;
            }
            cout<<endl;
        }
    }

    T* search(string key){
        int idx = hashfucn(key);
        Node<T>*temp = table[idx];
        while(temp!=NULL){
            if(temp->key == key){
                return &temp->value; // if present return the address
            }
            temp = temp->next;
        }
        return NULL;//if not present return null
    }

    // void erase(string erase){

    // }
};

int main(){
    Hashtable<int>price_menu;
    price_menu.insert("burger",120);
    price_menu.insert("pepsi",20);
    price_menu.insert("lays",7);
    price_menu.insert("kurkure",90);
    price_menu.insert("oyes",66);

    price_menu.print();

    int *price = price_menu.search("oyes");
    if(price == NULL){
        cout<<"not found";
    }
    else{
        cout<<"price is "<<*price<<endl;
    }
    return 0;
}
/*
Output
Bucket0->
Bucket1->pepsi->
Bucket2->
Bucket3->lays->kurkure->
Bucket4->oyes->
Bucket5->
Bucket6->
Bucket7->burger->
Bucket8->
Bucket9->
Bucket10->
Bucket11->
Bucket12->
Bucket13->
price is 0
/*

int main(){
    Hashtable<int>price_menu;
    price_menu.insert("burger",120);
    price_menu.insert("pepsi",20);
    price_menu.insert("lays",70);
    price_menu.insert("kurkure",90);
    price_menu.insert("oyes",66);

    price_menu.print();
}