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

void print_heap(HeapType* h) { //���� ���
    for (int i = 1; i <= h->heap_size; i++) {
        printf("%d ", h->heap[i].key);
    }
    printf("\n");
}

void insert_max_heap(HeapType* h, element item) { //����
    int i;
    i = ++(h->heap_size);
    h->heap[i] = item;
    
    while ((i != 1) && (item.key > h->heap[i / 2].key)) {
        h->heap[i] = h->heap[i / 2];
        h->heap[i / 2] = item;
        i /= 2;
        
    }
    print_heap(h); // �߰� ���� ���

}


element delete_max_heap(HeapType* h) { //����
    int parent, child;
    element item;
    

    item = h->heap[1]; //�ֻ��� ���
    h->heap[1] = h->heap[(h->heap_size)--]; //�ֻ��� ��� ���� -> ������ ��带 �ֻ��� ���� ������Ʈ
    parent = 1;
    child = 2; //�ڽĳ��
   

    while (child <= h->heap_size) {
        if ((child < h->heap_size) && (h->heap[child].key < h->heap[child + 1].key)) {
            child++;
        } //���� �ڽĺ��� ������ �ڽ��� ũ�� �ڽ� ������Ʈ
        if (h->heap[parent].key >= h->heap[child].key) break; //�θ� �ڽĳ�庸�� ũ�ų� ������ break

        element tmp = h->heap[parent]; //�θ� ��� �ű�
        h->heap[parent] = h->heap[child]; //�ڽĳ�尡 �� ũ�� �ڽ� ���� �θ� ��� ��ġ �ٲ�
        h->heap[child] = tmp;
        parent = child;
        child *= 2;
        
    }
    print_heap(h); // �߰� ���� ���
    return item;
}



void print_level(HeapType* h) { //������ ���
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