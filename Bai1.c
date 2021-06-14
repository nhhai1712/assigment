#include <stdio.h>
#include <math.h>

long long giaithua(long n){
	if(n == 0){
		return 1;
	}else{
		return n * giaithua(n - 1);
	}
}
int main(){
	int n, k;
	printf("Nhap n = ");
	scanf("%d", &n);
	while(n < 2 || n > 30){
		printf("Khong trong pham vi input. Hay nhap lai ...\n");
		printf("Nhap n = ");
		scanf("%d", &n);
	}
	printf("Nhap k = ");
	scanf("%d", &k);
	while(k < 0 || k > n){
		printf("Khong tinh duoc to hop chap %d cua %d\n", k , n);
		printf("Nhap k = ");
		scanf("%d", &k);
	}
	long long tohop;
	tohop = giaithua(n) / (giaithua(k) * giaithua(n - k));
	printf("To hop chap %d cua %d la %dC%d = %ld", k, n, n, k, tohop);
}
