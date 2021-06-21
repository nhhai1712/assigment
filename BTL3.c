#include <stdio.h>
#include <string.h>

void hienThiTenCot();

struct HoTen {
	char ho[20];
	char dem[20];
	char ten[20];
};

struct DiemMH {
	float gt2;
	float trr;
	float cpro;
	float gpa;
};

struct SinhVien {
	int mssv;
	struct HoTen hoVaTen;
	int tuoi;
	char gioiTinh[10];
	struct DiemMH diem;
};

void nhapDiem(struct DiemMH* diem) {
	printf("Giai tich 2: ");
	scanf("%f", &diem->gt2);
	printf("Toan roi rac: ");
	scanf("%f", &diem->trr);
	printf("C programming: ");
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
	printf("Nhap ma so sinh vien: ");
	scanf("%d", &sv.mssv);
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
	sv.mssv, sv.hoVaTen.ho, sv.hoVaTen.dem, sv.hoVaTen.ten, sv.tuoi, sv.gioiTinh,
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
		}
	}
	if(timSV == 0) {
		printf("Khong co sinh vien %s trong danh sach!\n", ten);
	}
}

void ghiFile(struct SinhVien* ds, int slsv) {
	FILE* fOut = fopen("SV.txt", "a");
	int i;
	for(i = 0; i < slsv; i++) {
		struct SinhVien sv = ds[i];
		fprintf(fOut, "%-10d %-10s %-20s %-10s %-10d %-10s %-10.2f %-10.2f %-10.2f %-10.2f\n",
		sv.mssv, sv.hoVaTen.ho, sv.hoVaTen.dem, sv.hoVaTen.ten, sv.tuoi, sv.gioiTinh,
		sv.diem.gt2, sv.diem.trr, sv.diem.cpro, sv.diem.gpa);
	}
	fclose(fOut);
}

void hienThiTenCot() {
	printf("%-10s %-10s %-20s %-10s %-10s %-10s %-10s %-10s %-10s %-10s\n", 
		"Ma so SV", "Ho", "Dem", "Ten", "Tuoi", "Gioi Tinh", 
		"Diem Giai tich 2", "Diem Toan roi rac", "Diem C programming", "Diem GPA");
}

int main() {
	struct SinhVien dssv[100];
	int slsv = 0;
	int luaChon;
	
	do {
		printf("=============== MENU ===============");
		printf("\n1. Hien thi danh sach sinh vien.");
		printf("\n2. Nhap them Sinh vien vao danh sach.");
		printf("\n3. Tim sinh vien theo ten.");
		printf("\n4. Thoat chuong trinh.");
		printf("\nBan chon ? ");
		
		scanf("%d", &luaChon);
		struct SinhVien sv;
		int i;
		switch(luaChon) {
			case 4:
				break;
				
			case 2:
				sv = nhapSV();
				dssv[slsv++] = sv;
				break;
				
			case 1:
				hienThiTenCot();
				for(i = 0; i < slsv; i++) {
					hienThiTTSV(dssv[i]);
				}
				break;	
				
			case 3:
				timTheoTen(dssv, slsv);
				break;
				
			default:
				printf("Sai chuc nang, vui long chon lai!\n");
				break;
		}
		
	} while(luaChon);
	
	return 0;
}
