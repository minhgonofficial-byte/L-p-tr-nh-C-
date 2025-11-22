#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

// ================= CHỨC NĂNG 1 =================
void chucNang1() {
    int x;
    printf("Nhap so nguyen x: ");
    scanf("%d", &x);

    printf("- %d la so nguyen.\n", x);

    // kiểm tra số nguyên tố
    int isPrime = 1;
    if (x < 2) isPrime = 0;
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) {
            isPrime = 0;
            break;
        }
    }
    printf("- %d %s so nguyen to.\n", x, isPrime ? "la" : "khong la");

    // kiểm tra số chính phương
    int sq = sqrt(x);
    printf("- %d %s so chinh phuong.\n", x, (sq * sq == x) ? "la" : "khong la");
}

// ================= CHỨC NĂNG 2 =================
int gcd(int a, int b) {
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void chucNang2() {
    int x, y;
    printf("Nhap x: ");
    scanf("%d", &x);
    printf("Nhap y: ");
    scanf("%d", &y);

    int u = gcd(x, y);
    int bcnn = (x * y) / u;

    printf("Uoc so chung lon nhat: %d\n", u);
    printf("Boi so chung nho nhat: %d\n", bcnn);
}

// ================= CHỨC NĂNG 3 =================
void chucNang3() {
    int begin, end;
    printf("Nhap gio bat dau (12-23): ");
    scanf("%d", &begin);
    printf("Nhap gio ket thuc (12-23): ");
    scanf("%d", &end);

    if (begin < 12 || end > 23 || begin >= end) {
        printf("Gio khong hop le!\n");
        return;
    }

    int gio = end - begin;
    float tien;

    if (gio <= 3) {
        tien = gio * 150000;
    } else {
        tien = 3 * 150000 + (gio - 3) * 150000 * 0.7;
    }

    if (begin >= 14 && begin <= 17) {
        tien *= 0.9;
    }

    printf("Tien thanh toan: %.0f VND\n", tien);
}

// ================= CHỨC NĂNG 4 =================
void chucNang4() {
    int kwh;
    printf("Nhap so kWh: ");
    scanf("%d", &kwh);

    long tien = 0;

    if (kwh <= 50) tien = kwh * 1678;
    else if (kwh <= 100) tien = 50*1678 + (kwh-50)*1734;
    else if (kwh <= 200) tien = 50*1678 + 50*1734 + (kwh-100)*2014;
    else if (kwh <= 300) tien = 50*1678 + 50*1734 + 100*2014 + (kwh-200)*2536;
    else if (kwh <= 400) tien = 50*1678 + 50*1734 + 100*2014 + 100*2536 + (kwh-300)*2834;
    else tien = 50*1678 + 50*1734 + 100*2014 + 100*2536 + 100*2834 + (kwh-400)*2927;

    printf("Tien dien: %ld VND\n", tien);
}

// ================= CHỨC NĂNG 5 =================
void chucNang5() {
    int money, menhgia[] = {500,200,100,50,20,10,5,2,1};
    printf("Nhap so tien: ");
    scanf("%d", &money);

    for (int i = 0; i < 9; i++) {
        int count = money / menhgia[i];
        money %= menhgia[i];
        if (count > 0)
            printf("%d to %d\n", count, menhgia[i]);
    }
}

// ================= CHỨC NĂNG 6 =================
void chucNang6() {
    float tien;
    printf("Nhap so tien muon vay: ");
    scanf("%f", &tien);

    float laithang = 0.05 * tien;
    float traThang = (tien / 12) + laithang;

    printf("Tien phai tra moi thang: %.0f VND\n", traThang);
    printf("Tong sau 12 thang: %.0f VND\n", traThang * 12);
}

// ================= CHỨC NĂNG 7 =================
void chucNang7() {
    float phanTram;
    printf("Nhap phan tram can vay (vd 80): ");
    scanf("%f", &phanTram);

    float giatri = 500000000;
    float vay = giatri * phanTram / 100;
    float traTruoc = giatri - vay;

    float laiNam = 0.072;
    float traThang = (vay / (24*12)) + (vay * laiNam / 12);

    printf("Tra truoc: %.0f VND\n", traTruoc);
    printf("Tra hang thang: %.0f VND\n", traThang);
}

// ================= CHỨC NĂNG 8 =================
struct SV {
    char ten[50];
    float diem;
};

void chucNang8() {
    int n;
    printf("Nhap so sinh vien: ");
    scanf("%d", &n);

    struct SV a[n];

    for (int i = 0; i < n; i++) {
        printf("Nhap ten: ");
        fflush(stdin);
        gets(a[i].ten);
        printf("Nhap diem: ");
        scanf("%f", &a[i].diem);
    }

    // sắp xếp giảm dần
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if (a[i].diem < a[j].diem) {
                struct SV t = a[i];
                a[i] = a[j];
                a[j] = t;
            }

    // xuất
    for (int i = 0; i < n; i++) {
        printf("%s - %.2f - ", a[i].ten, a[i].diem);
        if (a[i].diem >= 9) printf("Xuat sac");
        else if (a[i].diem >= 8) printf("Gioi");
        else if (a[i].diem >= 6.5) printf("Kha");
        else if (a[i].diem >= 5) printf("Trung binh");
        else printf("Yeu");
        printf("\n");
    }
}

// ================= CHỨC NĂNG 9 =================
void chucNang9() {
    int a, b;
    printf("Nhap so thu 1 (1-15): ");
    scanf("%d", &a);
    printf("Nhap so thu 2 (1-15): ");
    scanf("%d", &b);

    srand(time(NULL));
    int r1 = rand()%15 + 1;
    int r2 = rand()%15 + 1;

    int match = 0;
    if (a == r1 || a == r2) match++;
    if (b == r1 || b == r2) match++;

    printf("So may man: %d - %d\n", r1, r2);

    if (match == 2) printf("Chuc mung! Ban trung giai nhat\n");
    else if (match == 1) printf("Ban trung giai nhi\n");
    else printf("Chuc ban may man lan sau\n");
}

// ================= CHỨC NĂNG 10 =================
void chucNang10() {
    int tu1, mau1, tu2, mau2;
    printf("Nhap phan so 1 (tu mau): ");
    scanf("%d %d", &tu1, &mau1);
    printf("Nhap phan so 2 (tu mau): ");
    scanf("%d %d", &tu2, &mau2);

    printf("Tong = %d/%d\n", tu1*mau2 + tu2*mau1, mau1*mau2);
    printf("Hieu = %d/%d\n", tu1*mau2 - tu2*mau1, mau1*mau2);
    printf("Tich = %d/%d\n", tu1*tu2, mau1*mau2);
    printf("Thuong = %d/%d\n", tu1*mau2, mau1*tu2);
}

// ================= MAIN MENU =================
int main() {
    int chon;

    do {
        printf("\n===== MENU ASSIGNMENT =====\n");
        printf("1. Kiem tra so nguyen\n");
        printf("2. UCLN & BCNN\n");
        printf("3. Tinh tien Karaoke\n");
        printf("4. Tinh tien dien\n");
        printf("5. Doi tien\n");
        printf("6. Tinh lai vay ngan hang\n");
        printf("7. Vay tien mua xe\n");
        printf("8. Sinh vien\n");
        printf("9. Game FPOLY-LOTT\n");
        printf("10. Phan so\n");
        printf("11. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &chon);

        switch(chon) {
            case 1: chucNang1(); break;
            case 2: chucNang2(); break;
            case 3: chucNang3(); break;
            case 4: chucNang4(); break;
            case 5: chucNang5(); break;
            case 6: chucNang6(); break;
            case 7: chucNang7(); break;
            case 8: chucNang8(); break;
            case 9: chucNang9(); break;
            case 10: chucNang10(); break;
            case 11: printf("Thoat chuong trinh.\n"); break;
            default: printf("Lua chon sai! Moi nhap lai.\n");
        }
    } while(chon != 11);

    return 0;
}