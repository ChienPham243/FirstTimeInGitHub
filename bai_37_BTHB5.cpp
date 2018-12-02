#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

struct TB
{
    char stb[10];
    char hoTen[25];
    int cp; //cước phí
    char nl[10]; //ngày lập

};
//===========================================================================================================
void nhapDSTB(TB d[], int &n)
{
    int i = 0;
    int x;
    const char *h = "0";
    printf("\n ---------NHAP THONG TIN KHACH HANG---------");
    while(1){
        printf("\n Nhap thong tin cua khach hang thu %d: ",i+1);
        printf("\n Nhap so thue bao: "); // lỗi lặp Họ tên khách hàng
        fflush(stdin);
        gets(d[i].stb);
//        fflush(stdin);
//        x = atoi(d[i].stb);
//        if( x == 0 )
        if( strcmp(d[i].stb,h) == 0 )
        {
            break;
        }
        printf("\n Nhap ho ten: ");
        fflush(stdin);
        gets(d[i].hoTen);
        printf("\n Nhap cuoc phi: ");
        scanf("%d",&d[i].cp);
        printf("\n Nhap ngay lap: ");
        fflush(stdin);
        gets(d[i].nl);
        i++;
    }
    n = i;
}
//===========================================================================================================
void hienDSTB(TB d[], int n)
{
    printf("\n ---------DANH SACH KHACH HANG---------");
    printf("\n STT \t So thue bao \t Ho ten \t \t Cuoc phi \t Ngay lap ");
    for(int i = 0; i < n; i++)
    {
        printf("\n %-3d \t %-12s \t %-20s \t %-10d \t %-15s",i + 1,d[i].stb,d[i].hoTen,d[i].cp,d[i].nl);
    printf("\n%-3d",i+1);
    printf("\n%-12s",d[i].stb);
    printf("\n%-20s",d[i].hoTen);
    printf("\n%-10d",d[i].cp);
    printf("\n%-15s",d[i].nl);

    }

}
//===========================================================================================================
void sapxepDSTB(TB d[], int n)
{
    int i,j;
    TB tg;
    printf("\n ---------DANH SACH KHACH HANG SAU KHI SAP XEP---------");
    for(i = 0; i < n - 1; i++)
        for(j = i+1; j < n; j++)
            if(d[i].cp < d[j].cp)
            {
                tg = d[i];
                d[i] = d[j];
                d[j] = tg;
            }
}
//===========================================================================================================
void CPCN(TB d[], int n) //cước phí cao nhât
{
    int m = 0; //m = max
    int i,vt; // vị trí
    for( i = 0; i < n; ++i)
        if(d[i].cp >= m)
        {
            m = d[i].cp;
            vt = i;
        }
    for( i = 0; i < n; ++i)
        if(d[i].cp == m)
        {
            printf("\n So thue bao co cuoc phi cao nhat: ");
            printf("\n STT \t So thue bao \t Ho ten \t \t Cuoc phi \t Ngay lap ");
            printf("\n %-3d \t %-12s \t %-20s \t %-10d \t %-15s",i + 1, d[i].stb, d[i].hoTen, d[i].cp, d[i].nl);
        }
}
//===========================================================================================================
void themDSTB(TB d[], int &n)
{
    int i = n;
    printf("\n ---------NHAP THONG TIN KHACH HANG---------");
    printf("\n Nhap thong tin cua khach hang thu %d: ",i+1);
    printf("\n Nhap so thue bao: ");
    fflush(stdin);
    gets(d[i].stb);
    printf("\n Nhap ho ten: ");
    fflush(stdin);
    gets(d[i].hoTen);
    printf("\n Nhap cuoc phi: ");
    scanf("%d",&d[i].cp);
    printf("\n Nhap ngay lap: ");
    fflush(stdin);
    gets(d[i].nl);
    n = i + 1;
}
//===========================================================================================================
void xoaTB(TB d[], int &n)
{
    for( int i = 0; i < n; i++ )
    {
        if( d[i].cp < 10000)
        {
            for( int j = i; j < n; j++ )
            {
                d[j] = d[j+1];
            }
        }
    }n--;
    printf("\n ---------DANH SACH THUE BAO SAU KHI XOA---------");

}
//===========================================================================================================
int main()
{
    int n,i;
    TB d[100];
    nhapDSTB(d,n);
    hienDSTB(d,n);
    sapxepDSTB(d,n);
    hienDSTB(d,n);
    CPCN(d,n);
    themDSTB(d,n);
    hienDSTB(d,n);
    xoaTB(d,n);
    hienDSTB(d,n);
    getch();
    return 0;
}
