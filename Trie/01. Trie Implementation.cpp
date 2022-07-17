#include <bits/stdc++.h>
using namespace std;


class Node{
public:
    // We can add more member variables as per our need. For example see below question -
    // https://www.codingninjas.com/codestudio/test-series/amazon-online-test-series/offering/2409857/problem/14688

    Node* links[26];
    int pre;
    int end;
    
    Node(int pre, int end){
        for(int i = 0; i<26; i++){
            links[i] = NULL;
        }
        this->pre = pre;
        this->end = end;
    }
};


class Trie{
public:
    Node* root;
    Trie(){
        root = new Node(0, 0);
    }

    void insert(string &word){
        Node* temp = root;
        for(int i = 0; i < word.size(); i++){
            if(temp->links[word[i]-'a'] == NULL){
                temp->links[word[i]-'a'] = new Node(1,0);
            }
            else{
                temp->links[word[i]-'a']->pre += 1;
            }
            temp = temp->links[word[i]-'a'];
        }
        temp->end += 1;
    }

    int countWordsEqualTo(string &word){
        Node* temp = root;
        for(int i = 0; i < word.size(); i++){
            if(temp->links[word[i]-'a'] == NULL){
                return 0;
            }
            temp = temp->links[word[i]-'a'];
        }
        return temp->end;
    }

    int countWordsStartingWith(string &word){
        Node* temp = root;
        for(int i = 0; i < word.size(); i++){
            if(temp->links[word[i]-'a'] == NULL){
                return 0;
            }
            temp = temp->links[word[i]-'a'];
        }
        return temp->pre;
    }

    void erase(string &word){
        Node* temp = root;
        for(int i = 0; i < word.size(); i++){
            if(temp->links[word[i]-'a'] == NULL){
                return;
            }
            temp = temp->links[word[i]-'a'];
            temp->pre -= 1;
        }
        temp->end -= 1;
    }
};

int main(){
    
}    