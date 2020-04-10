#include <iostream>
#include <unistd.h> 
#include <assert.h>

//Using linked lists to create a sequential allocator

using word_t = intptr_t;

struct Block {
    size_t size;
    bool used;
    Block *next;
    word_t data[1];
};

inline size_t align(size_t n) {
  return (n + sizeof(word_t) - 1) & ~(sizeof(word_t) - 1);
}

static Block *heapStart = nullptr;
static auto top = heapStart;


inline size_t allocSize(size_t size){
    return size + sizeof(Block) - sizeof(std::declval<Block>().data);
}

Block *requestFromOs(size_t size){
    auto block = (Block *)sbrk(0);
    if (sbrk(allocSize(size)) == (void *)-1){
        return nullptr;
    }
    return block;
}

Block *getHeader(word_t *data){
    return (Block *)((char *)data + sizeof(std::declval<Block>().data)-sizeof(Block));
}

word_t *alloc(size_t size){
    size = align(size);
    auto block = requestFromOs(size);

    block->size = size;
    block->used = true;

    if (heapStart==nullptr){
        heapStart = block;

    }
    if (top!=nullptr){
        top->next = block;
    }
    top = block;

    return block->data;
    
    }

int main(int argc, char const *argv[]){ 
    auto p1 = alloc(3);
    auto p1b = getHeader(p1);
    assert(p1b->size == sizeof(word_t));

    auto p2 = alloc(8);
    auto p2b = getHeader(p2);
    assert(p2b->size ==8);

    puts("\nAll assertions passed!\n");
    return 0;
}