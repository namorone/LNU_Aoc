#include <iostream>
#include <bitset>
using namespace std;

void main()
{
	__int32 res = 0;
	static __int32 arr[2];
	cin >> arr[0] >> arr[1];
	cout << std::bitset<32>(arr[0]).to_string();
	cout << endl;
	cout << std::bitset<32>(arr[1]).to_string();
	cout << endl;
	__int32 mask = 1;//�����(0001)
	cin.clear();
	__asm
	{
		mov esi, 2				 // �������� � ������ �������� 2
		mov eax, arr			 // �������� � ������ ��������
		array_cicle:
		mov cx, 32				 // ������� ������� �����
			start_1:			 // ������� �����
			mov ebx, eax		 // ��� �����
			and ebx, mask		 // ��������� �� 1
			jz false1			 // ���� 0 �� ���������� �� ����
			inc res
			jmp end_			 // ������� � �����
			false1:
	end_:
		shl mask, 1				 // �������� ��� ����� ���� �� ����

			loop start_1
			mov eax, offset arr // �������� � ������� ������ ������
			add eax, 4			// ���������� �� ���������� �������� ������
			mov eax, [eax]		// �������� �����
			dec esi				// �������� �������� �� 1
			mov mask, 1			// �������� � ����� 1
			test esi, esi		// ���������� �� ������� �� 0
			jnz array_cicle		// ���� �� 0 �� ���������� ����
	}
	cout << "Result: " << res << endl;
}