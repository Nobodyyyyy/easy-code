#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

struct ElemType
{
    string name;
};

struct childNode
{
    int pos;
    childNode* next;
};

struct parentNode
{
    ElemType data;
    childNode *fir;
};

struct Tree
{
    vector<parentNode*> nodes;
    int nodenum = 0;
};

void TreeInit(Tree& tree, vector<ElemType>& vec, vector<vector<int>>& table)
{
    parentNode *p;
    for(int i = 0; i < int(vec.size()); i++)
    {
        p = new parentNode;
        p->data = vec[i]; p->fir = nullptr;
        for(int j = 0; j < int(table[i].size()); j++)
        {
            childNode* cnode = new childNode;
            cnode->pos = table[i][j];
            cnode->next = p->fir;
            p->fir = cnode;
        }
        tree.nodes.push_back(p);
    }
    tree.nodenum = vec.size();
}

void preorderTraverse(Tree& t, void(*visit)(parentNode* n))
{
    cout << "非递归方式先序遍历结果:" << endl;
    //辅助栈s_help 使子节点输出顺序反向
    stack<parentNode*> s, s_help;
    s.push(t.nodes[0]);
    parentNode *pnode;
    childNode *cnode;
    while(!s.empty())
    {
        pnode = s.top();
        s.pop();
        visit(pnode);
        cnode = pnode->fir;
        while(cnode){
            s_help.push(t.nodes[cnode->pos]);

            cnode = cnode->next;
        }
        while(!s_help.empty())
        {
            s.push(s_help.top());
            s_help.pop();
        }
    }
}

//递归
void preorderTraverse_help(Tree& t, parentNode* pnode, void(*visit)(parentNode* n))
{
    if(!pnode) return;
    visit(pnode);
    childNode *cnode = pnode->fir;
    while(cnode)
    {
        preorderTraverse_help(t, t.nodes[cnode->pos], visit);
        cnode = cnode->next;
    }
}

void preorderTraverse_(Tree& t, void(*visit)(parentNode* n))
{
    cout << "递归方式先序遍历结果:" << endl;
    preorderTraverse_help(t, t.nodes[0], visit);
}

void postorderTraverse(Tree& t, void(*visit)(parentNode* n))
{
    cout << "非递归方式后序遍历结果:" << endl;
    stack<parentNode*> s, s_help;
    s.push(t.nodes[0]);
    parentNode *pnode;
    childNode *cnode;
    while(!s.empty())
    {
        pnode = s.top();
        s.pop();
        s_help.push(pnode);
        cnode = pnode->fir;
        while(cnode){
            s.push(t.nodes[cnode->pos]);
            cnode = cnode->next;
        }
    }
    while(!s_help.empty())
    {
        visit(s_help.top());
        s_help.pop();
    }
}

//递归
void postorderTraverse_help(Tree& t, parentNode* pnode, void(*visit)(parentNode* n))
{
    if(!pnode) return;
    childNode *cnode = pnode->fir;
    while(cnode)
    {
        postorderTraverse_help(t, t.nodes[cnode->pos], visit);
        cnode = cnode->next;
    }
    visit(pnode);
}

void postorderTraverse_(Tree& t, void(*visit)(parentNode* n))
{
    cout << "递归方式后序遍历结果:" << endl;
    postorderTraverse_help(t, t.nodes[0], visit);
}
#endif // TREE_H_INCLUDED
