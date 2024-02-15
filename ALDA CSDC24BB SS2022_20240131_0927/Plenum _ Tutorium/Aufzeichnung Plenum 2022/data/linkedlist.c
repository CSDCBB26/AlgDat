//
//  main.c
//  list
//
//  Created by Juergen Falb on 22.04.21.
//

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

struct element {
    int data;
    struct element *next;
    struct element *prev;
};

struct element *insert(int data, int p, struct element **list) {
    struct element *h = *list;
    struct element *n;
    
    n = (struct element *)malloc(sizeof(struct element));
    n->data = data;
    
    if (*list == NULL) {
        n->next = n;
        n->prev = n;
        return n;
    }

    for (int i = 0; i < p - 1; i++) {
        h = h->next;  // (*h).next;
    }
    
    n->prev = h;
    n->next = h->next;
    n->next->prev = n;
    n->prev->next = n;
    
    if (p == 0) {
        *list = n;
    }
    return n;
}


int main(int argc, const char * argv[]) {
    struct element *list = NULL;
    insert(10, 0, &list);
    insert(6, 0, &list);
    
    return 0;
}
