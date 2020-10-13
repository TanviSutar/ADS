//Trie data structure
#include<iostream>
#include<unordered_map>
using namespace std;

class tnode{
    public:
        unordered_map<char,tnode*> map;
        bool endofword;
        tnode(){
            endofword = false;
        }
};

void trieinsert(tnode *root,string carr,int size,int curr){
    if(curr >= size) return;
    unordered_map<char,tnode*>::iterator itr = root->map.find(carr.at(curr));
    if(itr == root->map.end()){//character not found
        tnode *next = new tnode();
        if(curr == size-1)  next->endofword = true;   
        root->map.insert(make_pair(carr.at(curr),next));
        trieinsert(next,carr,size,curr+1);
    }   
    else{//character found
        trieinsert(itr->second,carr,size,curr+1);
    }
}

bool queryPrefix(tnode *root,string s){
    int i=0;
    unordered_map<char,tnode*>::iterator itr = root->map.find(s.at(i));
    while(itr != root->map.end()){
        i++;
        if(i == s.size()) break;
        root = itr->second;
        itr = root->map.find(s.at(i));
    }
    if(i == s.size()) return true;
    return false; 
}

bool queryWord(tnode* root,string s){
    int i=0;
    unordered_map<char,tnode*>::iterator itr = root->map.find(s.at(i));
    while(itr != root->map.end()){
        i++;
        if(i == s.size()) break;
        root = itr->second;
        itr = root->map.find(s.at(i));
    }
    if(i == s.size()){
        root = itr->second;
        if(root->endofword == true) return true;
        else return false; 
    }
    return false;
}

bool deleteWord(tnode *root,string s,int curr){
    if(curr == s.size()){
        if(root->map.empty()) return true;
        else{
            root->endofword = false;
            return false;
        }
    }
    unordered_map<char,tnode*>::iterator itr = root->map.find(s.at(curr));
    bool flag = deleteWord(itr->second,s,curr+1);
    if(flag){
        tnode *tmp = itr->second;
        delete tmp;//here every child node is explicitly deleted
        root->map.erase(s.at(curr));
        if(root->map.empty()) return true;
    }
    return false;
}

void deleteAll(tnode *root){
    if(root->map.empty()) return;
    unordered_map<char,tnode*>::iterator itr = root->map.begin();
    while(itr != root->map.end()){
        deleteAll(itr->second);
        delete itr->second;
        itr++;
    }
}

bool deletePrefix(tnode *root,string s,int curr){
    if(curr == s.size()){
        deleteAll(root);
        return true;
    }
    unordered_map<char,tnode*>::iterator itr = root->map.find(s.at(curr));
    bool flag = deletePrefix(itr->second,s,curr+1);
    if(flag){
        delete itr->second;
        root->map.erase(s.at(curr));
        if(root->map.empty()) return true;
    }
    return false;
}

int main(){
    tnode *root = new tnode();
    string s;
    int ch;
    while(true){
        cout<<"1.Insert string\n2.Query for prefix\n3.Query for word\n4.Delete words with prefix\n5.Delete a word\n6.exit\n\nEnter your choice: ";
        cin>>ch;
        switch(ch){
        case 1:
            cout<<"Enter the word: ";
            cin>>s;
            trieinsert(root,s,s.size(),0);
            cout<<"Inserted successfully.\n\n";
            break;
        case 2:
            cout<<"Enter the prefix: ";
            cin>>s;
            if(queryPrefix(root,s)) cout<<"Word/words with given prefix exists.\n\n";
            else cout<<"No word with given prefix exists.\n\n";
            break;
        case 3:
            cout<<"Enter the word: ";
            cin>>s;
            if(queryWord(root,s)) cout<<"Given word exists.\n\n";
            else cout<<"Given word does not exist.\n\n";
            break;
        case 4:
            cout<<"Enter the prefix to be deleted: ";
            cin>>s;
            if(!queryPrefix(root,s)) cout<<"No word with given prefix exists.\n\n";
            else{
                bool flag = deletePrefix(root,s,0);
                cout<<"Words with given prefix deleted successfully.\n\n";
            }
            break;
        case 5:
            cout<<"Enter the word to be deleted: ";
            cin>>s;
            if(!queryWord(root,s)) cout<<"Word does not exists.\n\n";
            else{
                bool flag = deleteWord(root,s,0);
                cout<<"Given word deleted successfully.\n\n";
            }
            break;
        case 6:
            exit(0);
            break;
        default:
            cout<<"Invalid choice.\n";
        }
    }
    return 0;
}