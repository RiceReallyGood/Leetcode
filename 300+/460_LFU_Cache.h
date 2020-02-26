#include <unordered_map>
#include <vector>
#include <climits>
using namespace std;

class LFUCache {
public:
    LFUCache(int capacity) : cap(capacity), sz(0) {
        dumhead = new ListNode(0, 0);
        dumhead->freq = INT_MAX;
        dumhead->next = dumhead;
        dumhead->prev = dumhead;
    }
    
    int get(int key) {
        if(nodemap.find(key) == nodemap.end())
            return -1;
        ListNode* node = nodemap[key];
        node->freq++;
        move(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(cap == 0)
            return;
        ListNode *node;
        if(nodemap.find(key) != nodemap.end()){
            node = nodemap[key];
            node->val = value;
            node->freq++;
            move(node);
        }
        else{
            if(cap == sz){
                node = dumhead->next;
                nodemap.erase(node->key);
                node->key = key;
                node->val = value;
                node->freq = 0;
                move(node);
            }
            else{
                node = new ListNode(key, value);
                ListNode* p = dumhead->next;
                while(p->freq == 0)
                    p = p->next;
                node->next = p;
                node->prev = p->prev;
                node->prev->next = node;
                p->prev = node;
                sz++;
            }
            nodemap[key] = node;
        }
    }

private:
    class ListNode{
    public:
        int key;
        int val;
        int freq;
        ListNode* next;
        ListNode* prev;
        ListNode(int k, int v): key(k), val(v), freq(0), next(nullptr), prev(nullptr){}
    };
    void move(ListNode* node){
        ListNode* p = node->next;
        while(p->freq <= node->freq)
            p = p->next;
        node->next->prev = node->prev;
        node->prev->next = node->next;
        node->prev = p->prev;
        node->prev->next = node;
        node->next = p;
        p->prev = node;
    }

    ListNode* dumhead;
    unordered_map<int, ListNode*> nodemap;
    int cap;
    int sz;
};

class LFUCache {
public:
    LFUCache(int capacity): cap(capacity), sz(0){}
    ~LFUCache(){
        for(auto p : lists)
            delete p;
    }
    
    int get(int key) {
        if(nodemap.find(key) == nodemap.end())
            return -1;
        else{
            DoubleLinkedList::ListNode* node = nodemap[key];
            lists[node->freq]->del(node);
            node->freq++;
            insert(node);
            return node->val;
        }
    }
    
    void put(int key, int value) {
        if(cap == 0)
            return;
        DoubleLinkedList::ListNode* node;
        if(nodemap.find(key) != nodemap.end()){
            node = nodemap[key];
            lists[node->freq]->del(node);
            node->val = value;
            node->freq++;
        }
        else{
            if(cap == sz){
                int minfreq = 0;
                while(lists[minfreq]->empty())
                    minfreq++;
                node = lists[minfreq]->last();
                lists[minfreq]->dellast();
                nodemap.erase(node->key);
                node->key = key;
                node->val = value;
                node->freq = 0;
                nodemap[key] = node;   
            }
            else{
                node = new DoubleLinkedList::ListNode(key,value);
                nodemap[key] = node;
                sz++;
            }
        }
        insert(node);
    }

private:
    class DoubleLinkedList{
    public:
        class ListNode{
        public:
            int key;
            int val;
            int freq;
            ListNode* next;
            ListNode* prev;
            ListNode(int k, int v) : key(k), val(v), freq(0), next(nullptr), prev(nullptr) {}
            ListNode(int k, int v, ListNode *next_, ListNode *prev_) :
                    key(k), val(v), freq(0), next(next_), prev(prev_) {}
        };

        DoubleLinkedList(){
            dumhead = new ListNode(0, 0);
            dumhead->next = dumhead;
            dumhead->prev = dumhead;
        }
        ~DoubleLinkedList(){
            ListNode* tmp1 = dumhead->next;
            ListNode* tmp2;
            while(tmp1 != dumhead){
                tmp2 = tmp1->next;
                delete tmp1;
                tmp1 = tmp2;
            }
            delete dumhead;
        }

        void del(ListNode* node){
            node->next->prev = node->prev;
            node->prev->next = node->next;
        }

        void dellast(){ del(dumhead->prev); }
        void addfirst(ListNode* node){
            node->next = dumhead->next;
            node->next->prev = node;
            dumhead->next = node;
            node->prev = dumhead;
        }

        bool empty(){ return dumhead->next == dumhead; }
        ListNode* last(){ return dumhead->prev; }
    private:
        ListNode* dumhead;
    };
    void insert(DoubleLinkedList::ListNode* node){
        if(lists.size() < node->freq + 1)
            lists.push_back(new DoubleLinkedList());
        lists[node->freq]->addfirst(node);
    }
    vector<DoubleLinkedList*> lists;
    unordered_map<int, DoubleLinkedList::ListNode*> nodemap;
    int sz;
    int cap;
};