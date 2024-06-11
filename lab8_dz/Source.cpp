#include<iostream>
using namespace std;

int main()
{
	int number, sum = 0;
	cin >> number;
	__asm
	{
		mov eax, number// запис значення number в регістир eax
		cdq //розширення регістра eax на eax:edx
		mov ecx, 10// запис 10 в регістир ecx

		lo: //мітка
		cdq//розширення регістра eax на eax:edx
			div ecx// ділимо на 10
			add edx, sum//edx=edx=sum
			mov sum, edx//записуємо значення edx в регістир eax(sum=edx)
			cmp eax, 0// порівнюємо eax з 0
			jz equalnull// якщо xf=0б переходимо до мітки equalnull
			jmp lo//перехід до мітки lo
            equalnull ://мітка
	}
	cout << "the sum of 3 digits " << number << " = " << sum << endl;
	system("pause");
}