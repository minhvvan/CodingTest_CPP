#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Node
{
    int num;
    pair<int,int> coord;
    Node* left;
    Node* right;
    
    Node(): num(0)
    {
        left = nullptr;
        right = nullptr;
        coord = {0,0};
    }
    
    void insert(Node* newNode)
    {
        int newX = newNode->coord.first;
        int newY = newNode->coord.second;
        
        if(newX < coord.first)
        {
            //left
            if(left == nullptr)
            {
                left = newNode;
                return;
            }
            
            left->insert(newNode);
        }
        else
        {
            //right
            if(right == nullptr)
            {
                right = newNode;
                return;
            }
            
            right->insert(newNode);
        }
    }
};

bool cmp(Node* A, Node* B)
{
    if(A->coord.second == B->coord.second)
    {
        return A->coord.first < B->coord.first;
    }
    
    return A->coord.second > B->coord.second;
}


void PreSearch(Node* current, vector<int>& temp)
{
    temp.push_back(current->num);
    
    if(current->left) PreSearch(current->left, temp);
    if(current->right) PreSearch(current->right, temp);
}

void PostSearch(Node* current, vector<int>& temp)
{
    if(current->left) PostSearch(current->left, temp);
    if(current->right) PostSearch(current->right, temp);
    
    temp.push_back(current->num);
}


vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    
    vector<Node*> Tree;
    
    for(int i = 0; i < nodeinfo.size(); i++)
    {
        Node* newNode = new Node();
        newNode->num = i+1;
        newNode->coord = {nodeinfo[i][0], nodeinfo[i][1]};
        
        Tree.push_back(newNode);
    }
    
    sort(Tree.begin(), Tree.end(), cmp);
    
    Node* root = new Node();
    root->num = Tree[0]->num;
    root->coord = Tree[0]->coord;
    
    for(int i = 1; i < Tree.size(); i++)
    {
        // cout << node->num << ": {" << node->coord.first << "," << node->coord.second << "}" << "\n";
        Node* newNode = new Node();
        newNode->num = Tree[i]->num;
        newNode->coord = Tree[i]->coord;
        
        root->insert(newNode);
    }
    
    {
        vector<int> temp;
        PreSearch(root, temp);
        answer.push_back(temp);
    }

    {
        vector<int> temp;
        PostSearch(root, temp);
        answer.push_back(temp);
    }

    
    return answer;
}