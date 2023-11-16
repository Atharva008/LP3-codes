#include<bits/stdc++.h>
using namespace std;


struct HuffmanNode{
    char data;
    int frequency;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char d , int f){
        data = d;
        frequency = f;
        left = NULL;
        right = NULL;
    }
};

struct CompareNodes{
    bool operator()(HuffmanNode* left , HuffmanNode* right){
        return left->frequency > right->frequency;
    }
};

HuffmanNode* buildHuffmanTree(map<char,int> &frequencies){
    priority_queue<HuffmanNode* , vector<HuffmanNode*> , CompareNodes> pq;
    for(auto pair : frequencies){
        pq.push(new HuffmanNode(pair.first , pair.second));
    }

    while(pq.size() > 1){
        HuffmanNode* left = pq.top();
        pq.pop();
        HuffmanNode* right = pq.top();
        pq.pop();

        HuffmanNode* newNode = new HuffmanNode('\0' , left->frequency + right->frequency);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    return pq.top();
}



void generateHuffmanCode(HuffmanNode* root , string code , map<char,string> &huffmanCode){
    if(root == NULL) return;

    if(!root->left and !root->right){
        huffmanCode[root->data] = code;
    }

    generateHuffmanCode(root->left , code + "0" , huffmanCode);
    generateHuffmanCode(root->right , code + "1" , huffmanCode);
}




int main(){

    string input;
    cin >> input;

    map<char,int> frequencies;

    for(auto it : input) frequencies[it]++;


    for(auto i : frequencies){
        cout << i.first << ' ' << i.second << endl;
    }
    cout << endl;


    HuffmanNode* root = buildHuffmanTree(frequencies);
    map<char,string> huffmanCode;
    generateHuffmanCode(root,"",huffmanCode);

    for(auto it : huffmanCode){
        cout << it.first << ':' << it.second << endl;
    }
    cout << endl;

    return 0;
}