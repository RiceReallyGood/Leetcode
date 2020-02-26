#include <unordered_map>
using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) :cap(capacity){
        dumhead = new ListNode(0 , 0);
        dumhead->next = dumhead;
        dumhead->prev = dumhead;
    }
    
    int get(int key) {
        if(nodemap.find(key) == nodemap.end())
            return -1;
        move2end(nodemap[key]);
        return nodemap[key]->val;
    }
    
    void put(int key, int value) {
        if(nodemap.find(key) != nodemap.end()){
            move2end(nodemap[key]);
            nodemap[key]->val = value;
            return ;
        }
        ListNode *node;
        if(cap == 0){  
            node = dumhead->next;  
            del(node);
            nodemap.erase(node->key);
            node->key = key;
            node->val = value;
        }
        else{
            node = new ListNode(key, value);
            cap--;
        }
        nodemap[key] = node;
        add(node);
    }

    ~LRUCache(){
        ListNode *node = dumhead;
        ListNode *nextnode;
        do{
            nextnode = node->next;
            delete node;
            node = nextnode;
        }while(node != dumhead);
    }

private:
    class ListNode{
    public:
        int key;
        int val;
        ListNode *next;
        ListNode *prev;

        ListNode(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {}
        ListNode(int k, int v, ListNode *next_, ListNode *prev_) :
                    key(k), val(v), next(next_), prev(prev_) {}
    };

    void move2end(ListNode *node){
        if(node->next != dumhead){
            del(node);
            add(node);
        }
    }

    void del(ListNode *node){
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

    void add(ListNode *node){
        dumhead->prev->next = node;
        node->next = dumhead;
        node->prev = dumhead->prev;
        dumhead->prev = node;
    }

    unordered_map<int, ListNode *> nodemap;
    ListNode *dumhead;

    int cap;
};