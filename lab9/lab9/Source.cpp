#include <iostream> 
using namespace std;
int a, b, c, d, x;
int values[5]; // ����� ��� ���������� �(�)
void main() {
	a = -6;	b = 4;	c = 8;	d = 2;
	__asm { 
		mov eax, offset values
	    push eax 	// ���������� � ���� ������ ������� ������
		mov cx, 5 	// ������� ������� ����� 
	start: 	// ������� �����
	    mov ax, 3 	// ��� ���������� x = 3 - �� 
		sub ax, cx 	// �������� ������� �������� �
			cwde 	// ���������� ax �� eax
			mov ebx, eax 	// �������� x � ebx
			mov eax, a 	// ����� �
			cmp ebx, 1 	// ��������� � � ��������
			jl lesst 	// ���� � ����� 1, ���������� �� ���� less
			je equals 	// ���� � ������� 1, ���������� �� equals
			// ���� � > 1:
			imul eax 	// a^2
			sub eax, ebx 	// a^2-x
			cdq 	// ���������� a^2-x �� ��������� �����
			mov ebx, c 	// ����� c
			idiv ebx 	// (a^2-x)/c
			jmp result 	// ���������� �� ���� result
		lesst :
		mov edx, 2
			imul edx 	// a*2
			imul ebx 	// a*2*x
			add eax, 5 	// a*2*x+5
			jmp result  // ���������� �� ���� result
			equals :	
		mov ebx, b 	// ����� b
			sub eax, ebx 	// a-b
			cdq 	// ���������� a-b �� ��������� �����
			mov ebx, d 	// ����� d
			idiv ebx 	// (a-b)/d
			jmp result
			result :	// ���������� �� ���� result
		pop ebx 	// ���������� � ����� ������ ������
			mov[ebx], eax // �������� ��������� �� �������� ������� 
			add ebx, 4 	// ������� �������� ������ 
			push ebx 	// ���������� � ���� ���� ������ 
			loop start 	// ����� �����
	}
	for (int i = 0; i < 5; i++) {
		cout << values[i] << endl;
	} system("pause");
}
