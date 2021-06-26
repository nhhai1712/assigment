#include <stdio.h>
#include <math.h>

long long gt(long n){
	if(n == 0){
		return 1;
	}else{
		return n * gt(n - 1);
	}
}
int main(){
	int n, k;
	int i, r;
	FILE *fin;
	fin = fopen("C:\\Users\\Admin\\OneDrive\\Máy tính\\TOHOP.INP", "r");
	FILE *fout;
	fout = fopen("C:\\Users\\Admin\\OneDrive\\Máy tính\\TOHOP.OUT", "w");
/*in ra du lieu tu input
	printf("Doc file TOHOP.INP\n");
	while(fscanf(fin,"%d \t %d\n", &n, &k) != EOF){
		printf("%d \t %d\t\n", n, k);
	}
*/
	printf("Ket qua\n");
	while(fscanf(fin,"%d \t %d\n", &n, &k) != EOF){
		r =  gt(n) / (gt(k) * gt(n-k));
		printf("%lld\n", r);
		fprintf(fout, "%lld\n", r);
	}	
	
	fclose(fin);
	return 0;
}
