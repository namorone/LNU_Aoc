#include <iostream>
using namespace std;
char FORMAT[] = "%s %s\n"
;char HELLO[] = "Design by";
char WORLD[] = "Borovets Roman 2022...|";
void main() 
{
	
	__asm 
	{ // ������� ������������ ����
		mov  eax, offset WORLD
		push eax
		mov  eax, offset HELLO
		push eax
		mov  eax, offset FORMAT
		push eax
		mov edi, printf
		call edi          
		// �������� ����� ��� ���������� ���������� ��������� main
		pop  ebx
		pop  ebx
		pop  ebx 
	} // ����� ������������ ����
	system("pause");
}