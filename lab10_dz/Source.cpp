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
	__int32 mask = 1;//маска(0001)
	cin.clear();
	__asm
	{
		mov esi, 2				 // заносимо у регістр лічильник 2
		mov eax, arr			 // заносимо у регістр значення
		array_cicle:
		mov cx, 32				 // кількість проходів циклу
			start_1:			 // початок циклу
			mov ebx, eax		 // наш масив
			and ebx, mask		 // порівнюємо чи 1
			jz false1			 // якщо 0 то переходимо до мітки
			inc res
			jmp end_			 // перехід в кінець
			false1:
	end_:
		shl mask, 1				 // побітовий сув маски вліво на один

			loop start_1
			mov eax, offset arr // заносимо у регістир адресу масиву
			add eax, 4			// переходимо до наступного значення масиву
			mov eax, [eax]		// отримуємо кінець
			dec esi				// зменшуємо лічильник на 1
			mov mask, 1			// заносимо у маску 1
			test esi, esi		// перевіряємо чи регістир не 0
			jnz array_cicle		// якщо не 0 то повторюємо цикл
	}
	cout << "Result: " << res << endl;
}