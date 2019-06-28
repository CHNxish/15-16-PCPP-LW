//读 数字 程序
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#define ELEMENT_SIZE 11
#define DIGIT_SIZE 9 
#define ARRAY_SIZE 100
void numberToChinese(int number, wchar_t *array);
int bitToNumber(int number, wchar_t *array, wchar_t *element[], wchar_t *digit[], int exp);

int main(int argc, char *argv[]){
	int number;
	wchar_t array[ARRAY_SIZE];
	setlocale(LC_ALL, "en_US.utf8");
	
	scanf("%d", &number);
	numberToChinese(number, array);
	printf("%S\n", array);
	
	return 0;
}

void numberToChinese(int number, wchar_t *array){
	int exp;
	wchar_t *element[ELEMENT_SIZE]={L"零", L"一", L"二", L"三", L"四",
					L"五", L"六", L"七", L"八", L"九",
					L"负"};
	wchar_t *digit[DIGIT_SIZE]={L"", L"十", L"百", L"千", L"万",
				    L"十万", L"百万", L"千万", L"亿"};
	
	wcscpy(array, L"");
	if(number < 0){
		number *= -1;
		wcscat(array, element[ELEMENT_SIZE - 1]);
	}
	
	exp = 0;
	bitToNumber(number, array, element, digit, exp);
}
int bitToNumber(int number, wchar_t *array, wchar_t *element[], wchar_t *digit[], int exp){
	int previousBit, currentBit;
	if(number == 0)
		currentBit = 0;
	else{
		previousBit = bitToNumber(number / 10, array, element, digit, exp + 1);
		currentBit = number % 10;
		if(currentBit != 0){
			wcscat(array, element[currentBit]);
			wcscat(array, digit[exp]);
		}
		else{
			if(previousBit != 0){
				wcscat(array, element[currentBit]);
			}
		}
	}
	return currentBit;
}
