#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200


typedef struct {
    int key;
} element;

typedef struct {
    element heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

HeapType* create() {
    return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h) {
    h->heap_size = 0;
}

void print_heap(HeapType* h) { //과정 출력
    for (int i = 1; i <= h->heap_size; i++) {
        printf("%d ", h->heap[i].key);
    }
    printf("\n");
}

void insert_max_heap(HeapType* h, element item) { //삽입
    int i;
    i = ++(h->heap_size);
    h->heap[i] = item;
    
    while ((i != 1) && (item.key > h->heap[i / 2].key)) {
        h->heap[i] = h->heap[i / 2];
        h->heap[i / 2] = item;
        i /= 2;
        
    }
    print_heap(h); // 중간 상태 출력

}


element delete_max_heap(HeapType* h) { //삭제
    int parent, child;
    element item;
    

    item = h->heap[1]; //최상위 노드
    h->heap[1] = h->heap[(h->heap_size)--]; //최상위 노드 삭제 -> 마지막 노드를 최상위 노드로 업데이트
    parent = 1;
    child = 2; //자식노드
   

    while (child <= h->heap_size) {
        if ((child < h->heap_size) && (h->heap[child].key < h->heap[child + 1].key)) {
            child++;
        } //왼쪽 자식보다 오른쪽 자식이 크면 자식 업데이트
        if (h->heap[parent].key >= h->heap[child].key) break; //부모가 자식노드보다 크거나 같으면 break

        element tmp = h->heap[parent]; //부모 노드 옮김
        h->heap[parent] = h->heap[child]; //자식노드가 더 크면 자식 노드랑 부모 노드 위치 바꿈
        h->heap[child] = tmp;
        parent = child;
        child *= 2;
        
    }
    print_heap(h); // 중간 상태 출력
    return item;
}



void print_level(HeapType* h) { //레벨별 출력
    int level = 1;
    int count = 0;
    for (int i = 1; i <= h->heap_size; i++) {
        if (i == level) {
            printf("\n[%d]: ", level);
            level *= 2;
        }
        printf("%d ", h->heap[i].key);
    }
    printf("\n");
}

int main(void) {
    HeapType* heap = create();
    init(heap);
    int elements[] = { 34, 12, 76,59, 32, 55, 88, 26, 16, 79, 34,85,29,78,41,56,86 };
    int size_element = sizeof(elements) / sizeof(elements[0]);
    element up_heap[sizeof(elements)] = 0;

    for (int i = 0; i < size_element; i++) {
        element e;
        e.key = elements[i];
        insert_max_heap(heap, e);
    }
    
    for (int i = 0; i < size_element; i++) {
        up_heap[i] = delete_max_heap(heap);
    }
    for (int i = 0; i < sizeof(up_heap)/sizeof(up_heap[0]); i++) {
        printf("%d ", up_heap[i].key);
    }
    

    return 0;
}