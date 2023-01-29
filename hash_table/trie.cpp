#include<bits/stdc++.h>

using namespace std;

 

class TrieNode

{

    public:

    char data;

    TrieNode* children[26];

    bool isTerminal;

    TrieNode(char data)

    {

        this->data=data;

        for(int i=0; i<26; i++)

        {

            children[i]=NULL;

        }

        isTerminal=false;

    }

};

class Trie {

 TrieNode* root;

public:

 

    /** Initialize your data structure here. */

    

    Trie() {

       root=new TrieNode('\0');

       

    }

 

    /** Inserts a word into the trie. */

    void insertutil(string word , TrieNode*root)

    {

       

       if(word.length()==0)

        {

            root->isTerminal=true;

        }

        int index=word[0]-'a';

        TrieNode*child;

        if(root->children[index]!=NULL)

        {

            child=root->children[index];

        }

        else

        {

            child=new TrieNode(word[0]);

             root->children[index]=child;

        }

        insertutil(word.substr(1),child);

    }

    void insert(string word) {

        // int n=word.size();

        insertutil(word ,root);

    }

 

    /** Returns if the word is in the trie. */

    bool searchutil(string word,TrieNode* root)

    {

        if(word.length()==0)

        {

            return root->isTerminal;

        }

        int index=word[0]-'a';

        TrieNode*child;

        if(root->children[index]!=NULL)

        {

           child=root->children[index];

        }

        else

        {

            return false;

        }

        searchutil(word.substr(1),child);

    }

    bool search(string word) {

       return searchutil(word,root);

    }

 

    /** Returns if there is any word in the trie that starts with the given prefix. */

    bool startWithUtil(TrieNode* root,string prefix)

    {

        if(prefix.length()==0)

        {

            return true;

        }

        TrieNode*child;

        int index=prefix[0]-'a';

        if(root->children[index]!=NULL)

        {

            root->children[index]=child;

        }

        else

        {    

           return 0;

        }

        return startWithUtil(child,prefix.substr(1));

    }

    bool startsWith(string prefix) {

         return startWithUtil(root,prefix);

    }

};

