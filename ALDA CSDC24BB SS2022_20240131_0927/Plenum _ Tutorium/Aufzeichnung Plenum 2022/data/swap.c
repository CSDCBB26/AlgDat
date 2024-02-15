//
//  main.c
//  pointer
//
//  Created by Juergen Falb on 08.03.21.
//

#include <stdio.h>
void swap(int *ptrX, int *ptrY);

int main() {
    int x;
    int y;

    scanf("%i %i", &x, &y);
    printf("x = %i, y = %i\n", x, y);
    swap(&x, &y);
    printf("x = %i, y = %i\n", x, y);
    return 0;
}

void swap(int *ptrX, int *ptrY) {
    int tmp;
    tmp = *ptrX;
    *ptrX = *ptrY;
    *ptrY = tmp;
}
