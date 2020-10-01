// luogu/P1104.cpp
// https://www.luogu.com.cn/problem/P1104
// Created by learntocode1024 on 2020/8/6.
// AC

#include <cstring>
#include <iostream>

struct ID {
    int key;
    std::string name;
};

ID id[105];
int cnt = -1;
int size = 0;

inline int left(int a) {
    return (a << 1) + 1;
}
inline int right(int a) {
    return (a << 1) + 2;
}
inline int parent(int a) {
    return (a - 1) >> 1;
}

inline void heap_insert(std::string name, int key) {
    id[size].key = key;
    id[size].name = name;
    int i = size;
    ++size;
    while (i && id[parent(i)].key > id[i].key) {
        ID temp = id[i];
        id[i] = id[parent(i)];
        id[parent(i)] = temp;
        i = parent(i);
    }
}

void min_heapify(int a) {
    int l, r;
    int min = -1;
    while (a < size) {
        l = left(a);
        r = right(a);
        min = a;
        if (l < size && id[l].key < id[a].key) min = l;
        if (r < size && id[r].key < id[min].key) min = r;
        if (min != a) {
            ID temp = id[a];
            id[a] = id[min];
            id[min] = temp;
            a = min;
        } else break;
    }
}

void heap_extract() {
    if (size) {
        std::cout << id[0].name << std::endl;
        --size;
        id[0] = id[size];
        min_heapify(0);
    }
}

int main() {
    int a, b, c, N;
    std::string name;
    std::cin >> N;
    while (std::cin >> name >> a >> b >> c) {
        ++cnt;
        int t = (a*1000000 + b*10000 + c*100 + cnt);
        heap_insert(name, t);
    }

    while (size) {
        heap_extract();
    }
    return 0;
}