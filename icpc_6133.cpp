#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
#include <set>
#include <bits/stdc++.h>

using namespace std;
#define EPS 1e-6

typedef vector<string> vs;
const int ALPHABET_SIZE = 26;
int calcuate_temp;

struct TrieNode
{
    struct TrieNode* children[ALPHABET_SIZE];
    int num_children;
    bool isEndOfWord;
};


struct TrieNode* getNode(void) {
    struct TrieNode *pNode =  new TrieNode;
    pNode->isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++){
        pNode->children[i] = NULL;
        pNode->num_children=0;
    }
    return pNode;
}


void insert(struct TrieNode* root, string word) {
    struct TrieNode *pCrawl = root;
    for (int i = 0; i < word.length(); i++) {
        int index = word[i] - 'a';
        if (!pCrawl->children[index]){
            pCrawl->children[index] = getNode();
            pCrawl->num_children++;
        }
        pCrawl = pCrawl->children[index];
    }
    pCrawl->isEndOfWord = true;
}

bool search(struct TrieNode* root, string word) {
    struct TrieNode* pCrawl = root;
    for (int i = 0; i < word.length(); i++) {
        int index = word[i] - 'a';
        if (!pCrawl->children[index]){
            return false;
        }else{
            if(pCrawl->num_children>1){
                calcuate_temp++;
            }else if(pCrawl->num_children==1 && pCrawl->isEndOfWord){
                calcuate_temp++;
            }else if(pCrawl->num_children==1 && pCrawl==root){
                calcuate_temp++;
            }
            pCrawl = pCrawl->children[index];
        }
    }
    return (pCrawl != NULL && pCrawl->isEndOfWord);
}

void printAnswer(TrieNode* root,int num_words){
    float answer=0;
    answer=calcuate_temp/double(num_words);
    answer= roundf(answer * 100) / 100;
    printf("%.2f", answer);
    cout<<endl;
}

int calculateLeaves (TrieNode* root,vs& words){
    int size=words.size();
    for (int i=0;i<size;i++){
        search(root,words[i]);
    }
}


int main() {
    int num_words;
    string temp;
    TrieNode* root;
    while(cin >> num_words) {
        vs words;
        root=getNode();
        calcuate_temp=0;
        for(int i=0;i<num_words;i++){
            cin>>temp;
            words.push_back(temp);
            insert(root,temp);
        }
        calculateLeaves(root,words);
        printAnswer(root,num_words);
    }
    return 0;
}