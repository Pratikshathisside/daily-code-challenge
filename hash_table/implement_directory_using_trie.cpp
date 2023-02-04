#include <iostream>
using namespace std;
#include<vector>

class Trienode{
    public:
    char data;
    Trienode* children[26];
    bool isterminal;

    //constructor
    Trienode(char ch){
        data = ch;
        for(int i = 0; i<26; i++){
            children[i] = NULL;
        }
        isterminal = false;
    }

};
class Trie{
    public: Trienode* root;
    //initialize
    Trie(){
root =new Trienode('\0');
    }
    void insertutil(Trienode* root,string word) {
        //base case
        if(word.length()==0){
            root->isterminal = true;
            return;
        }
        Trienode* child;
int index = word[0]-'a';
        //if present
        if(root->children[index]!=NULL){
            child = root->children[index];
        }
        else{
            child = new Trienode(word[0]);
            root->children[index] = child;

        }
        return insertutil(child,word.substr(1));
        
    }
    void insertword(string word){
        return insertutil(root, word);
    }
    void printsuggestions(Trienode* curr, vector<string> &temp, string prefix){
        if(curr->isterminal){
            temp.push_back(prefix);
            // return ;
        }
        for(char ch ='a';ch<='z';ch++){
            Trienode* next = curr->children[ch-'a'];
            if(next!=NULL){
                prefix.push_back(ch);
                printsuggestions(next, temp, prefix);
                //backtracking purpose k lie

                prefix.pop_back();

            }
        }

    }
    vector<vector<string>> getsuggestions(string str){
        Trienode* prev  = root;
        vector<vector<string>> output;
        string prefix = "";
        for(int i = 0; i<str.size();i++){
            char lastch = str[i];
            prefix.push_back(lastch);
            //chech either that charcter exix=st or not
            Trienode* curr = prev->children[lastch -'a'];
            //if not found
            if(curr == NULL){
                break;
            }
            //if found
            vector<string> temp;
            printsuggestions(curr, temp, prefix);
            output.push_back(temp);
            temp.clear();
            prev = curr;
        }
        return output;
    }

};

vector<vector<string>>phoneDirectory(vector<string> &contactList, string &queryStr) {
  //    Write your code here.
  //creation of trie
  Trie* t = new Trie();
  //inserting all the contact lists
  for(int i = 0; i<contactList.size();i++){
      string str = contactList[i];
      t->insertword(str);
  }
  //returning ans 
  return t->getsuggestions(queryStr);
}
