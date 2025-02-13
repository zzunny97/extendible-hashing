#pragma once
#include <vector>
#include <set>
#include "bucket.h"

class Directory {
        int global_depth, bucket_size;
        std::vector<Bucket*> buckets;
        int hash(int n);
        int pairIndex(int bucket_no, int depth);
        void grow(void);
        void shrink(void);
        void split(int bucket_no);
        void merge(int bucket_no);
		std::string bucket_id(int n);
    public:
        Directory(int depth, int bucket_size);
        void insert(int key, std::string value,bool reinserted);
        void remove(int key,int mode);
        void update(int key, std::string value);
        void search(int key);
        void display(bool duplicates);
};

