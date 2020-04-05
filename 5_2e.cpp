
#include <iostream>
#define M 3
using namespace std;
int main()
{
	
	long long i, j, mas[M][M], t = 0, k, tmp, smesh;

	cout << " A \n";

	for (i = 0; i < M; i++)
	{
		for (j = 0; j < M; j++)
			cin >> mas[i][j];
	}
	cout << " A \n";
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < M; j++)
			cout << mas[i][j] << "\t";
		cout << endl;
	}
	k = M - 2;
	smesh = M * 8;
	long long* arr = &mas[0][0];
    asm
	(
		"xorq %%rax,%%rax;"
		"movq %0,%%rbx;"
		"movq %%rbx,%%rsi;"
		"movq %1,%%rdx;"
		"movq $0x0,%%rcx;"
		"addq %2,%%rbx;"
		"addq $0x8,%%rsi;"
		"push %%rbx;"
		"jmp perestanovka;"

		"smeshh :"
		"addq %2,%%rbx;"
		"addq $0x8,%%rsi;"
		"incq %%rcx;"

		"perestanovka :"
		"movq (%%rsi) ,%%rax;"
		"movq (%%rbx) ,%%rdi;"
		"movq %%rdi, (%%rsi);"
		"movq %%rax, (%%rbx);"
		"cmp %%rdx, %%rcx;"
		"je perestanovka2;"
		"jmp smeshh;"

		"perestanovka2 :"
		"pop %%rbx;"
		"addq %2,%%rbx;"
		"addq $0x8,%%rbx;"
		"push %%rbx;"
		"movq %%rbx, %%rsi;"
		"subq %2,%%rsi;"
		"addq $0x8,%%rsi;"
		"decq %%rdx;"
		"cmp $0x0,%%rdx;"
		"jl konec;"
		"movq $0x0,%%rcx;"
		"jmp perestanovka;"

		"konec :"
		:
	    : "g"(arr), "g"(k), "g"(smesh)
		:
		);
		cout << "A \n";
		for (i = 0; i < M; i++)
		{
			for (j = 0; j < M; j++)
			cout << mas[i][j] << "\t";
			cout << endl;
		}
		
		return 0;
}

