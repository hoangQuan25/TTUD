#include <windows.h>
#include <stdio.h>

// Khai b�o bi?n to�n c?c

int W,X1,X2, Y, Z, Ans;
HANDLE sem1, sem2;

// Ch?c nang cho P1
void process1() {
    Y = W * X1;
    ReleaseSemaphore(sem1, 1, NULL); // Signal semaphore 1
}

// Ch?c nang cho P2
void process2() {
    Z = W * X2;
    ReleaseSemaphore(sem2, 1, NULL); // Signal semaphore 2
}

// Ch?c nang cho P3
void process3() {
    // �?i c? hai semaphore
    WaitForSingleObject(sem1, INFINITE); // �?i P1 ho�n th�nh
    WaitForSingleObject(sem2, INFINITE); // �?i P2 ho�n th�nh

    Ans = Y + Z;
    printf("Ket qua: %d\n", Ans);
}

int main() {
    // Kh?i t?o semaphore
    sem1 = CreateSemaphore(NULL, 0, 1, NULL);
    sem2 = CreateSemaphore(NULL, 0, 1, NULL);

    HANDLE threads[3];

    // �?c gi� tr? d?u v�o cho W, X1, X2
    printf("Nhap W, X1, X2: ");
    scanf("%d %d %d", &W, &X1, &X2);

    // T?o thread
    threads[0] = CreateThread(NULL, 0,(LPTHREAD_START_ROUTINE)process1, NULL, 0, NULL);
    threads[1] = CreateThread(NULL, 0,(LPTHREAD_START_ROUTINE)process2, NULL, 0, NULL);
    threads[2] = CreateThread(NULL, 0,(LPTHREAD_START_ROUTINE)process3, NULL, 0, NULL);

    // Ch? c�c thread ho�n th�nh
    WaitForMultipleObjects(3, threads, TRUE, INFINITE);

    // ��ng handle c?a c�c semaphore v� thread
    CloseHandle(sem1);
    CloseHandle(sem2);
    for (int i = 0; i < 3; i++) {
        CloseHandle(threads[i]);
    }

    return 0;
}

