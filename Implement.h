#ifndef IMPLEMENT_H
#define IMPLEMENT_H

#include "readonly/GraphOperations.h"

class Implement : public GraphOperations{
public:
    const char* getStudentID(){
        return "103062334";
    }

    void addEdge(const int label_1, const int label_2);

    //----------------------------------------------------------------------
    //delete an edge between the vertex_1 and the vertex_2
    //----------------------------------------------------------------------
    void deleteEdge(const int label_1, const int label_2);

    //----------------------------------------------------------------------
    //delete the vertex of the graph
    //----------------------------------------------------------------------
    void deleteVertex(const int label);

    //----------------------------------------------------------------------
    //calc the degree of the vertex
    //----------------------------------------------------------------------
    int degree(const int label);

    //----------------------------------------------------------------------
    //check if it exists a path between the vertex_1 and the vertex_2
    //----------------------------------------------------------------------
    bool isExistPath(const int label_1, const int label_2);

};

#endif
