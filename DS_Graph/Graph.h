#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <vector>
#inlcude <string>
using namespace std;

#define MAX_SIZE 50
#define MAX_NAME 3
#define MAX_INFO 20
typedef char InfoType;
typedef struct {
    string courseNo;
    int credit;
    int preCourse;
}VertexType;

typedef struct ArcBox {
    int tailVex, headVex;
    struct ArcBox *hlink, *tlink;
    InfoType *info;
}ArcBox;

typedef struct VexNode {
    VertexType data;
    ArcBox *firstin, *firstout;

    VexNode(VertexType d) : data(d), firstin(nullptr), firstout(nullptr) {}
}VexNode;

typedef struct {
    VexNode xlist[MAX_SIZE];
    int vexnum, arcnum;
}OLGraph;

void GraphInit(OLGraph& graph, vector<VertexType>& vec)
{
    for(int i = 0; i < vec.size(); i++)
    {
        VexNode v = new VexNode(vec[i]);
        graph.xlist[i] = v;
    }
    vexnum = vec.size();

}
#endif // GRAPH_H_INCLUDED
