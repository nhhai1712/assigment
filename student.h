#include <stdio.h>
#include <string.h>
struct HoTen {
	char ho[20];
	char dem[21];
	char ten[20];
};

struct DiemMH {
	float gt2;
	float trr;
	float cpro;
	float gpa;
};

struct SinhVien {
	int ma;
	struct HoTen hoVaTen;
	int tuoi;
	char gioiTinh[10];
	struct DiemMH diem;
};
