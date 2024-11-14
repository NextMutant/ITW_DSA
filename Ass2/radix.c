#include <stdio.h>
#include <stdlib.h>
//Time and space complexity
//Time: n*d
//space: 
void display(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d, ", a[i]);
    }
    printf("\n");
}

int main() {
    printf("Enter the number of totaldigits: ");
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the %d number: ", i + 1);
        scanf("%d", &a[i]);
    }

    int temp = a[0];
    for (int i = 1; i < n; i++) {
        if (temp < a[i]) {
            temp = a[i];
        }
    }

    int totaldigits = 0;
    while (temp != 0) {
        totaldigits++;
        temp /= 10;
    }

    int newa[n];
    int count[10] = {0}; 

    int exp = 1;
    for (int i = 0; i < totaldigits; i++) {
        for (int j = 0; j < n; j++) {
            int digit = (a[j] / exp) % 10;
            count[digit]++;
        }
        for (int j = 1; j < 10; j++) {
            count[j] = count[j] + count[j - 1];
        }
        for (int j = n - 1; j >= 0; j--) {
            int digit = (a[j] / exp) % 10;
            newa[count[digit] - 1] = a[j];
            count[digit]--;
        }
        for (int j = 0; j < n; j++) {
            a[j] = newa[j];
        }
        for (int j = 0; j < 10; j++) {
            count[j] = 0;
        }
        exp *= 10;
        display(a, n);
    }
    return 0;
}