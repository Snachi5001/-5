#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>                  //указание прототипов
#include <stdlib.h>                 //библиотечных функций 
#include <windows.h>
#include <malloc.h>
#include <string.h>
#include <time.h>

struct node {
	int inf;  // приоритет
	struct node* next; // ссылка на следующий элемент 
};
struct node* head = NULL, * last = NULL;

struct node* get_struct(int t) {
	struct node* p = NULL;

	if ((p = (node*)malloc(sizeof(struct node))) == NULL)  // выделяем память под новый элемент списка
	{
		printf("Ошибка при распределении памяти\n");
		exit(1);
	}

	p->inf = t;
	p->next = NULL;

	return p;		// возвращаем указатель на созданный элемент
}
void spstore(int t) {
	struct node* p = NULL, * f = NULL;
	p = get_struct(t);
	if (head == NULL && p != NULL) {	// если списка нет, то устанавливаем голову списка
		head = p;
		last = p;
	}
	else if (head != NULL && p != NULL) { // список уже есть, то вставляем в конец
		f = head;
		if (f->inf > p->inf) {
			p->next = head;
			head = p;
		}
		if (last->inf <= p->inf) {
			last->next = p;
			last = p;
		}
		if (last->inf > p->inf && f->inf <= p->inf) {
			while (f->next->inf <= p->inf) {
				f = f->next;
			}
			p->next = f->next;
			f->next = p;
		}
	}
	return;
}
void review(void) {
	struct node* struc = head;
	if (head == NULL)
	{
		printf("Список пуст\n");
	}
	while (struc)
	{
		printf("%d  ", struc->inf);
		struc = struc->next;
	}
	printf("\n");
}
void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	struct node* p = NULL;
	
	int k = 6;
	int d[6][6], f[6], x = 0, y = 0, ii = 0, m = -1, u = 0, isolated = 0, terminaland = 0, dominant = 0;
	for (int i = 0; i < k; i++) {
		ii += i;
	}
	ii = rand() % (ii - 1) + 1;
	int *a = (int*)malloc(k * ii * sizeof(int));
	for (int i = 0; i < k; i++) {
		for (int l = 0; l < ii; l++) {
			a[i * ii + l] = 0;
		}
	}
	int ppp = 0;
	for (int l = 0; l < ii; l++) {
		do {
			do {
				x = rand() % 6;
				y = rand() % 6;
			} while (y == x);
		ppp = 0;
		for (int i = 0; i < l; i++) {
			if (a[x * ii + i] == 1 && a[y * ii + i] == 1)
				ppp = 1;
		}
		} while (ppp == 1);
		a[x * ii + l] = 1;
		a[y * ii + l] = 1;
	}
	for (int i = 0; i < k; i++) {
		x = 0;
		for (int l = 0; l < ii; l++) {
			if (a[i * ii + l] != 0) x += 1;
		}
		if (x == 0) isolated += 1;
		if (x == 1) terminaland += 1;
		if (x == ii) dominant += 1;
	}
	for (int i = 0; i < k; i++) {
		for (int l = 0; l < ii; l++) {
			printf("%2d", a[i * ii + l]);
		}
		printf("\n");
	}
	printf("size: %d\nisolated: %d   terminaland: %d   dominant: %d\n", ii, isolated, terminaland, dominant);
	
}

