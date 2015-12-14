#include "Implement.h"
#include <queue>
using namespace std;
//----------------------------------------------------------------------
// add your code here
//----------------------------------------------------------------------

void Implement::addEdge(const int label_1, const int label_2)
{
    Vertex *cur1,*cur2;
    bool found1 = false, found2 = false;
    cur1 = this->adjacencyList[label_1].head;
    cur2 = this->adjacencyList[label_2].head;
    if(label_1==label_2){}       ///no loop
    else{
        if(cur1==NULL){
            cur1 = new Vertex;
            cur1->label = label_2;
            cur1->next = NULL;
            this->adjacencyList[label_1].head = cur1;
        }else{
            while(cur1->next!=NULL){        /// no multiple
                if(cur1->label==label_2) found1 = true;
                cur1 = cur1->next;
            }
            if(cur1->label==label_2) found1 = true;
            if(!found1){
                cur1->next = new Vertex;
                cur1->next->label = label_2;
                cur1->next->next = NULL;
            }
        }

        if(cur2==NULL){
            cur2 = new Vertex;
            cur2->label = label_1;
            cur2->next = NULL;
            this->adjacencyList[label_2].head = cur2;
        }else{
            while(cur2->next!=NULL){
                if(cur2->label==label_1) found2 = true;
                cur2 = cur2->next;
            }
            if(cur2->label==label_1) found2 = true;
            if(!found2){
                cur2->next = new Vertex;
                cur2->next->label = label_1;
                cur2->next->next = NULL;
            }
        }
    }
}
void Implement::deleteEdge(const int label_1, const int label_2)
{
    Vertex* p;

    Vertex *cur;
    if(isExistPath(label_1,label_2)){
        cur = this->adjacencyList[label_1].head;
        if(cur->label==label_2){    /// head->label = label_2
            this->adjacencyList[label_1].head = cur->next;
            cur->next = NULL;
            delete cur;
        }else{
            while(cur->next!=NULL){
                if(cur->next->label==label_2) break;
                cur = cur->next;
            }
            Vertex *tmp;
            tmp = cur->next;
            cur->next = tmp->next;
            tmp->next = NULL;
            delete tmp;
        }

        cur = this->adjacencyList[label_2].head;
        if(cur->label==label_1){    /// head->label = label_2
            this->adjacencyList[label_2].head = cur->next;
            cur->next = NULL;
            delete cur;
        }else{
            while(cur->next!=NULL){
                if(cur->next->label==label_1) break;
                cur = cur->next;
            }
            Vertex *tmp;
            tmp = cur->next;
            cur->next = tmp->next;
            tmp->next = NULL;
            delete tmp;
        }
    }else{}
}
void Implement::deleteVertex(const int label)
{
    Vertex *cur;
    queue<int> q;
    cur = this->adjacencyList[label].head;
    while(cur!=NULL){
        q.push(cur->label);
        cur = cur->next;
    }
    while(q.size()){
        deleteEdge(label,q.front());
        q.pop();
    }

}
int Implement::degree(const int label)
{
    Vertex *cur = this->adjacencyList[label].head;
    int ct = 0;

    while(cur!=NULL){
        ct ++;
        cur = cur->next;
    }
    return ct;
}

bool Implement::isExistPath(const int label_1, const int label_2)
{
    queue<int> q;
    Vertex *cur;
    int x;
    bool visit[100]={0};

    if(label_1==label_2) return false;
    else{
        for(int i=0;i<100;i++) visit[i] = false;
        q.push(label_1);
        while(q.size()){
            x = q.front(); q.pop();
            visit[x] = true;

            cur = this->adjacencyList[x].head;
            while(cur!=NULL){
                if(!visit[cur->label]) q.push(cur->label);
                if(cur->label==label_2) return true;

                cur = cur->next;
            }
        }
        return false;
    }
}
