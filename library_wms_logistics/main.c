#include <stdio.h>
#include <string.h>

int main() {

    char maPhieu[100][20];
    char maSach[100][20];
    int soNgayMuon[100];

    int soLuong = 0;
    int luaChon;

    do {
        printf("\n");
        printf("==============================================================\n");
        printf("       HE THONG QUAN LY MUON TRA SACH (LOGISTICS)\n");
        printf("==============================================================\n");
        printf("1. Them moi phieu muon sach (Create)\n");
        printf("2. Hien thi danh sach phieu muon & Tien phat (Read)\n");
        printf("3. Cap nhat so ngay muon sach (Update)\n");
        printf("4. Xac nhan tra sach / Xoa phieu muon (Delete)\n");
        printf("5. Thoat chuong trinh\n");
        printf("==============================================================\n");
        printf("Lua chon cua ban (1-5): ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1: {
                if (soLuong >= 100) {
                    printf("Bo nho danh sach da day, khong the them moi!\n");
                    break;
                }

                printf("\n--- THEM MOI PHIEU MUON ---\n");

                char maNhap[20];
                int trungMa = 0;

                printf("Nhap ma phieu: ");
                scanf("%19s", maNhap);

                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], maNhap) == 0) {
                        trungMa = 1;
                        break;
                    }
                }

                if (trungMa == 1) {
                    printf("Ma phieu da ton tai trong he thong!\n");
                    break;
                }

                strcpy(maPhieu[soLuong], maNhap);

                printf("Nhap ma sach: ");
                scanf("%19s", maSach[soLuong]);
                do {
                    printf("Nhap so ngay muon: ");
                    scanf("%d", &soNgayMuon[soLuong]);

                    if (soNgayMuon[soLuong] <= 0) {
                        printf("So ngay muon phai lon hon 0! Vui long nhap lai.\n");
                    }

                } while (soNgayMuon[soLuong] <= 0);
                soLuong++;
                printf("Them moi phieu muon thanh cong!\n");

                while (getchar() != '\n');
                break;
            }

            case 2: {
                if (soLuong == 0) {
                    printf("\nDanh sach phieu muon hien dang rong!\n");
                    break;
                }

                printf("\n");
                printf("========================= DANH SACH PHIEU MUON =========================\n");

                printf("%-5s | %-12s | %-15s | %-12s | %-15s | %-15s\n","STT", "Ma Phieu", "Ma Sach", "So Ngay", "Trang Thai", "Tien Phat");

                printf("-------------------------------------------------------------------------------\n");

                for (int i = 0; i < soLuong; i++) {
                    int ngayQuaHan;
                    int tienPhat;

                    if (soNgayMuon[i] > 14) {
                        ngayQuaHan = soNgayMuon[i] - 14;
                        tienPhat = ngayQuaHan * 5000;

                        printf("%-5d | %-12s | %-15s | %-12d | %-15s | %-15d\n",i + 1, maPhieu[i], maSach[i], soNgayMuon[i], "QUA HAN", tienPhat);
                    } else {
                        tienPhat = 0;
                        printf("%-5d | %-12s | %-15s | %-12d | %-15s | %-15d\n",i + 1, maPhieu[i], maSach[i], soNgayMuon[i], "DUNG HAN", tienPhat);
                    }
                }

                printf("-------------------------------------------------------------------------------\n");
                break;
            }
            case 3: {
                if (soLuong == 0) {
                    printf("\nDanh sach phieu muon hien dang rong!\n");
                    break;
                }

                char maNhap[20];
                int pos = -1;
                printf("\n--- CAP NHAT SO NGAY MUON ---\n");
                printf("Nhap ma phieu can cap nhat: ");
                scanf("%19s", maNhap);

                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], maNhap) == 0) {
                        pos = i;
                        break;
                    }
                }

                if (pos == -1) {
                    printf("Khong tim thay ma phieu trong he thong!\n");
                } else {
                    printf("So ngay muon hien tai cua phieu %s la: %d\n", maPhieu[pos], soNgayMuon[pos]);
                    do {
                        printf("Nhap so ngay muon moi: ");
                        scanf("%d", &soNgayMuon[pos]);
                        if (soNgayMuon[pos] <= 0) {
                            printf("So ngay muon phai lon hon 0! Vui long nhap lai.\n");
                        }

                    } while (soNgayMuon[pos] <= 0);
                    printf("Cap nhat so ngay muon thanh cong!\n");
                }
                while (getchar() != '\n');
                break;
            }

            case 4: {
                if (soLuong == 0) {
                    printf("\nDanh sach phieu muon hien dang rong!\n");
                    break;
                }
                char maNhap[20];
                int pos = -1;
                printf("\n--- XAC NHAN TRA SACH / XOA PHIEU ---\n");
                printf("Nhap ma phieu xac nhan tra/xoa: ");
                scanf("%19s", maNhap);

                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], maNhap) == 0) {
                        pos = i;
                        break;
                    }
                }
                if (pos == -1) {
                    printf("Khong tim thay ma phieu can xoa!\n");
                } else {
                    for (int i = pos; i < soLuong - 1; i++) {
                        strcpy(maPhieu[i], maPhieu[i + 1]);
                        strcpy(maSach[i], maSach[i + 1]);
                        soNgayMuon[i] = soNgayMuon[i + 1];
                    }
                    soLuong--;
                    printf("Xac nhan tra sach va xoa phieu muon thanh cong!\n");
                }
                while (getchar() != '\n');
                break;
            }

            case 5: {
                printf("\nCam on ban da su dung LIBRARY_WMS Logistics!\n");
                printf("Thoat chuong trinh...\n");
                break;
            }

            default: {
                printf("Lua chon khong hop le, vui long chon lai!\n");
                break;
            }
        }

    } while (luaChon != 5);
    return 0;
}