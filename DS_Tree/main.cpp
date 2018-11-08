#include <iostream>
#include <stdio.h>
#include "Tree.h"
using namespace std;

void init(vector<ElemType>& vec, vector<vector<int>>& table)
{
    int nodenum;
    string s;
    cout << "请输入节点数: ";
    cin >> nodenum;
    cout << endl << "第一个节点为头节点！" << endl;
    for(int i = 0; i < nodenum; i++)
    {
        cout << "请输入第" << i+1 << "个节点的名称: ";
        cin >> s;
        ElemType p; p.name = s;
        vec.push_back(p);
    }
    int tmp;
    table = vector<vector<int>>(nodenum);
    for(int i = 0; i < nodenum; i++)
    {
        cout << "请输入第" << i+1 << "个节点的子节点序号: ";
        while(scanf("%d", &tmp) != EOF)
            table[i].push_back(tmp-1);
    }
}

void print(parentNode* node)
{
    cout << node->data.name << endl;
}

int main()
{
    Tree tree;
    vector<ElemType> vec; vector<vector<int>> table;
    init(vec, table);
    TreeInit(tree, vec, table);
    preorderTraverse(tree, print);
    preorderTraverse_(tree, print);
    postorderTraverse(tree, print);
    postorderTraverse_(tree, print);
    return 0;
}
