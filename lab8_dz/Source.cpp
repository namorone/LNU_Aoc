#include<iostream>
using namespace std;

int main()
{
	int number, sum = 0;
	cin >> number;
	__asm
	{
		mov eax, number// ����� �������� number � ������� eax
		cdq //���������� ������� eax �� eax:edx
		mov ecx, 10// ����� 10 � ������� ecx

		lo: //����
		cdq//���������� ������� eax �� eax:edx
			div ecx// ����� �� 10
			add edx, sum//edx=edx=sum
			mov sum, edx//�������� �������� edx � ������� eax(sum=edx)
			cmp eax, 0// ��������� eax � 0
			jz equalnull// ���� xf=0� ���������� �� ���� equalnull
			jmp lo//������� �� ���� lo
            equalnull ://����
	}
	cout << "the sum of 3 digits " << number << " = " << sum << endl;
	system("pause");
}