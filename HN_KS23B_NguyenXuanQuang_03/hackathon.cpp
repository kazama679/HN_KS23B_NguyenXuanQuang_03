#include<stdio.h>
#include<stdlib.h>
#define MAX 5 

typedef struct {
    int array[MAX];
    int top; 
} Stack; 

void inital(Stack* stack) {
    stack->top = -1; 
}

int isEmpty(Stack* stack) {
    if (stack->top == -1) {
        return 1; 
    }
    return 0;
} 

int isFull(Stack* stack) {
    if (stack->top >= MAX - 1) {
        return 1; 
    }
    return 0; 
} 

void push(Stack* stack, int value) {
    if (isFull(stack) == 1){
        printf("Ngan xep da day, khong them dc!\n"); 
        return; 
    }
    stack->array[++(stack->top)] = value; 
} 

void pop(Stack* stack){
	if (isEmpty(stack) == 1){
        printf("Ngan xep rong, khong xoa dc!\n"); 
        return; 
    }
    stack->array[(stack->top)--];
} 

void clear(Stack* stack){
	if (isEmpty(stack) == 1){
        printf("Ngan xep rong, khong can xoa!\n");
        return; 
    }
    stack->top = -1; 
    printf("Da xoa toan bo ngan xep thanh cong!\n");
}

void peek(Stack* stack){
	if (isEmpty(stack) == 1) {
        printf("Ngan xep rong, khong lay dc!\n"); 
        return; 
    }
    printf("Phan tu tren cung la: %d", stack->array[(stack->top)]);
} 

void size(Stack* stack){
	printf("Kich thuoc ngan xep = ");
    if (isEmpty(stack)) {
        printf("0\n");
        return;
    }
    int count;
    for (int i = stack->top; i >= 0; i--) { 
    	count++;
    }
    printf("%d\n", count);
}

void display(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Ngan xep rong!\n");
        return;
    }
    printf("Danh sach ngan xep: ");
    for (int i = stack->top; i >= 0; i--) { 
        printf("\n| %d |", stack->array[i]);
    }
    printf("\n");
}

void reverse(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Ngan xep rong!\n");
        return;
    }
    printf("Danh sach ngan xep nguoc lai: ");
    for (int i = 0; i <= stack->top; i++) { 
        printf("\n| %d |", stack->array[i]);
    }
    printf("\n");
}

int main(){
    int value, choice;
    Stack stack;
    inital(&stack);
	do{
		printf("\n==========MENU============\n");
		printf("1. Them phan tu vao ngan xep\n");
		printf("2. Lay phan tu khoi ngan xep\n");
		printf("3. Kiem tra phan tu tren cung ngan xep\n");
		printf("4. Kiem tra ngan xep có rong khong\n");
		printf("5. Lay kich thuoc ngan xep\n");
		printf("6. In toan bo ngan xep\n");
		printf("7. Xoa toan bo ngan xep\n");
		printf("8. In cac phan tu theo thu tu nguoc lai\n");
		printf("9. Thoat\n");
		printf("Moi ban chon: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
                printf("Nhap gia tri cho phan tu them moi: ");
                scanf("%d", &value);
                push(&stack, value);
                display(&stack);
				break; 
			case 2:
                pop(&stack);
                printf("Da lay phan tu thay cong khoi ngan xep!");
                display(&stack);
				break;
			case 3:
				peek(&stack);
				break; 
			case 4:
				if (isEmpty(&stack) == 1) {
			        printf("Ngan xep rong!\n");
			    } else{
			        printf("Ngan xep khong rong!\n");
				}
				break; 
			case 5:
				size(&stack);
				break; 
			case 6:
                display(&stack);
				break; 
			case 7:
				clear(&stack);
				break; 
			case 8:
				reverse(&stack);
				break; 
			case 9:
				printf("Thoat!");
				break;
			default:
				printf("Moi nhap lai\n");
		}
	} while(choice!=9);
	return 0;
}
