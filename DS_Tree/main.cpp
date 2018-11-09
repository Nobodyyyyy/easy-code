#include <iostream>
#include <stdio.h>
#include "Tree.h"
using namespace std;

void init(vector<ElemType>& vec, vector<vector<int>>& table)
{
    int nodenum;
    string s;
    cout << "������ڵ���: ";
    cin >> nodenum;
    cout << endl << "��һ���ڵ�Ϊͷ�ڵ㣡" << endl;
    for(int i = 0; i < nodenum; i++)
    {
        cout << "�������" << i+1 << "���ڵ������: ";
        cin >> s;
        ElemType p; p.name = s;
        vec.push_back(p);
    }
    int tmp;
    table = vector<vector<int>>(nodenum);
    for(int i = 0; i < nodenum; i++)
    {
        cout << "�������" << i+1 << "���ڵ���ӽڵ����: ";
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
    vector<ElemType> vec;// = {{"a"}, {"b"}, {"c"}, {"d"}, {"e"}, {"f"}, {"g"}, {"h"}, {"i"}, {"j"}};
    vector<vector<int>> table;// = {{1,2,3}, {}, {4, 6}, {5}, {7}, {9}, {}, {8}, {}, {}};
    init(vec, table);
    TreeInit(tree, vec, table);
    preorderTraverse(tree, print);
    preorderTraverse_(tree, print);
    postorderTraverse(tree, print);
    postorderTraverse_(tree, print);
    return 0;
}
