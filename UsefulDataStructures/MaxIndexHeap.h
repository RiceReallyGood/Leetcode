#ifndef MAXINDEXHEAP_H
#define MAXINDEXHEAP_H

#include <vector>
#include <cassert>

class MaxIndexHeap{
public:
    MaxIndexHeap(std::vector<int>& data_) : data(data_), indices(data_.size()),
                                            reverse(data_.size()), count(data_.size()),
                                            cap(data_.size())
    {
        for(int i = 0; i < count; i++){
            indices[i] = i;
            reverse[i] = i;
        }
        heapify();
    }

    MaxIndexHeap(int capacity_){
        count = 0;
        cap = capacity_;
        for(int i = 0; i < cap; i++)
            reverse[i] = -1;
    }

    ~MaxIndexHeap() {}

    int size(){
        return count;
    }

    bool empty(){
        return count == 0;
    }

    int capacity(){
        return cap;
    }

    int top(){
        assert(count > 0);
        return data[indices[0]];
    }

    int topindex(){
        assert(count > 0);
        return indices[0];
    }

    void pop(){
        assert(count > 0);
        count--;
        reverse[indices[0]] = -1;
        indices[0] = indices[count];
        shiftDown(0);
    }

    bool contain( int index ){
        assert(index >= 0 && index < cap);
        return reverse[index] != -1;
    }

    int get(int index){
        assert(contain(index));
        return data[index];
    }

    void change(int index, int newval){
        assert(contain(index));
        data[index] = newval;
        shiftDown(reverse[index]);
        shiftUp(reverse[index]);
    }

    void increase(int index, int diff){
        change(index, data[index] + diff);
    }

    void insert(int index, int val){
        if(!contain(index)){
            assert(count < cap);
            count++;
            data[index] = val;
            indices[count - 1] = index;
            reverse[index] = count - 1;
            shiftUp(count - 1);
        }
        else
            change(index, val);
    }

private:
    std::vector<int> indices;
    std::vector<int> reverse;
    std::vector<int> data;

    int count;
    int cap;

    void shiftDown(int k){
        int j = 0;
        while((j = 2 * k + 1) < count){
            if(j < count - 1 && data[indices[j]] < data[indices[j + 1]])
                j = j + 1;
            
            if(data[indices[k]] >= data[indices[j]]) break;

            std::swap(indices[j], indices[k]);
            reverse[indices[j]] = j;
            reverse[indices[k]] = k;
            k = j;
        }
    }

    void shiftUp(int k){
        int j = 0;
        while(k > 0){
            j = (k - 1) / 2;
            if(data[indices[j]] >= data[indices[k]]) break;
            std::swap(indices[j], indices[k]);
            reverse[indices[j]] = j;
            reverse[indices[k]] = k;
            k = j;
        }
    }

    void heapify(){
        for(int k = (count - 1 - 1) / 2; k >= 0; k--)
            shiftDown(k);
    }
};

#endif