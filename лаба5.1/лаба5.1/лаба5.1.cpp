#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>                  //указание прототипов
#include <stdlib.h>                 //библиотечных функций 
#include <windows.h>
#include <malloc.h>
#include <string.h>
#include <time.h>

struct node{
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
	int d[6][6], f[6], t = 0, ii = 0, x = 0, m = -1, u = 0, isolated = 0, terminaland = 0;
	for (int i = 0; i < k; i++) {
		f[i] = 0;
		for (int l = i; l < k; l++) {
			d[i][l] = (rand() % 5 + 7) / 10;
			d[l][i] = d[i][l];
			if (l == i) d[i][l] = 0;
		}
	}
	for (int i = 0; i < k; i++) {
		for (int l = i; l < k; l++) {
			if (d[l][i] == 1) t += 1;
		}
	}

	for (int i = 0; i < k; i++) {
		x = 0;
		for (int l = 0; l < k; l++) {
			if (d[l][i] == 1) x += 1;
		}
		if (x == 0) {
			isolated += 1;
			f[i] = -1;
		}
		if (x == 1) terminaland += 1;
		if (x > m) {
			m = x;
			ii = i;
		}
	}
	f[ii] = 1;
	spstore(ii + 1);
	for (int l = 0; l < k; l++) {
		if (f[l] == 0) f[l] = d[ii][l];
		if (f[l] != 0) u += 1;
	}
	
	while (u != k){
		m = 0;
		u = 0;
		for (int i = 0; i < k; i++) {
			x = 0;
			for (int l = 0; l < k; l++) {
				if (d[l][i] == 1 && f[l] == 0) x += 1;
				if (l == i && f[l] == 0) x += 1;
			}
			if (x > m) {
				m = x;
				ii = i;
			}
		}
		for (int l = 0; l < k; l++) {
			if (f[l] != -1) f[l] += 1;
			if (f[l] != 0) u += 1;
		}
		f[ii] = 1;
		spstore(ii + 1);

	}


	for (int i = 0; i < k; i++) {
		for (int l = 0; l < k; l++) {
			printf("%-3d", d[i][l]);
		}
		printf("\n");
	}

	printf("size: %d\nisolated: %d   terminaland: %d\ndominant: ", t, isolated, terminaland);
	review();
}

