#include <stdio.h>
#include <string.h>
#include "student.h" 

struct SinhVien;
void hienThiDSSV(struct SinhVien*, int);
void hienThiTenCot();


void nhapDiem(struct DiemMH* diem) {
	printf("Gt2: ");
	scanf("%f", &diem->gt2);
	printf("Trr: ");
	scanf("%f", &diem->trr);
	printf("Cpro: ");
	scanf("%f", &diem->cpro);
	diem->gpa = (diem->gt2 + diem->trr + diem->cpro) / 3;
}

void nhapHoTen(struct HoTen* ten) {
	printf("Ho: ");
	scanf("%s", ten->ho);
	printf("Dem: ");
	getchar();
	gets(ten->dem);
	printf("Ten: ");
	scanf("%s", ten->ten);
}

struct SinhVien nhapSV() {
	struct SinhVien sv;
	printf("Nhap ma: ");
	scanf("%d", &sv.ma);
	nhapHoTen(&sv.hoVaTen);
	printf("Tuoi: ");
	scanf("%d", &sv.tuoi);
	printf("Gioi tinh: ");
	scanf("%s", sv.gioiTinh);
	nhapDiem(&sv.diem);
	return sv;
}

void hienThiTTSV(struct SinhVien sv) {
	printf("%-10d %-10s %-20s %-10s %-10d %-10s %-10.2f %-10.2f %-10.2f %-10.2f\n",
	sv.ma, sv.hoVaTen.ho, sv.hoVaTen.dem, sv.hoVaTen.ten, sv.tuoi, sv.gioiTinh,
	sv.diem.gt2, sv.diem.trr, sv.diem.cpro, sv.diem.gpa);
}

void timTheoTen(struct SinhVien* ds, int slsv) {
	char ten[20];
	printf("Nhap ten: ");
	scanf("%s", ten);
	hienThiTenCot();
	int i, timSV = 0;
	for(i = 0; i < slsv; i++) {
		if(strcmp(ten, ds[i].hoVaTen.ten) == 0) {
			hienThiTTSV(ds[i]);
			timSV = 1;
			ghiFile(ds[i], slsv);
		}
	}
	if(timSV == 0) {
		printf("Khong co sinh vien %s trong danh sach!\n", ten);
	}
}

void ghiFile(struct SinhVien* ds, int slsv) {
	getchar();
	char fName[26];
	printf("Nhap ten file: ");
	gets(fName);
	FILE* fOut = fopen(fName, "w");
	int i;
	for(i = 0; i < slsv; i++) {
		struct SinhVien sv = ds[i];
		fprintf(fOut, "%-10d %-10s %-20s %-10s %-10d %-10s %-10.2f %-10.2f %-10.2f %-10.2f\n",
		sv.ma, sv.hoVaTen.ho, sv.hoVaTen.dem, sv.hoVaTen.ten, sv.tuoi, sv.gioiTinh,
		sv.diem.gt2, sv.diem.trr, sv.diem.cpro, sv.diem.gpa);
	}
	fclose(fOut);
}

void docFile(struct SinhVien* ds, int* slsv) {
	FILE* fOut = fopen("D:\\SV2021.DAT", "a+");
	int i = 0;
	if(fOut) {
		for(;;) {
			struct SinhVien sv;
			fscanf(fOut, "%10d %10s %20[^\n] %10s %10d %10s %10f %10f %10f %10f\n",
			&sv.ma, sv.hoVaTen.ho, sv.hoVaTen.dem, sv.hoVaTen.ten, &sv.tuoi, sv.gioiTinh,
			&sv.diem.gt2, &sv.diem.trr, &sv.diem.cpro, &sv.diem.gpa);
			
			ds[i++] = sv;
			if(feof(fOut)) { // thoat chuong trinh
				break;
			}
		}
	}
	
	fclose(fOut);
	*slsv = i;
}

void hienThiTenCot() {
	printf("%-10s %-10s %-20s %-10s %-10s %-10s %-10s %-10s %-10s %-10s\n", 
		"Ma SV", "Ho", "Dem", "Ten", "Tuoi", "Gioi Tinh", 
		"Diem Gt2", "Diem Trr", "Diem Cpro", "Diem GPA");
}

void hienThiDSSV(struct SinhVien* ds, int slsv) {
	hienThiTenCot();
	int i;
	for(i = 0; i < slsv; i++) {
		hienThiTTSV(ds[i]);
	}
}

int main() {
	struct SinhVien dssv[100];
	int slsv = 0;
	int luaChon;
	
	docFile(dssv, &slsv);
	int i;
				
	do {
		printf("=============== MENU ===============");
		printf("\n1. Xem danh sach sinh vien.");
		printf("\n2. Nhap them sinh vien.");
		printf("\n3. Tim sinh vien theo ten.");
// cho them cho do bi loi
		printf("\n4. Ghi file.");
		printf("\n5. Thoat.");
		printf("\nBan chon ? ");
		
		scanf("%d", &luaChon);
		struct SinhVien sv;
		
		switch(luaChon) {				
			case 1:
				hienThiDSSV(dssv, slsv);
				break;
				
			case 2:
				sv = nhapSV();
				dssv[slsv++] = sv;
				break;
				
			case 3:
				timTheoTen(dssv, slsv);
				break;
			
			case 4:
				ghiFile(dssv, slsv);
				break;
				
			case 5:
				break;
				
			default:
				printf("Sai chuc nang, vui long chon lai!\n");
				break;
		}
		
	} while(luaChon);
	
	return 0;
}
