#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void create_check_file(int k, int next_k) {
    char filename[50];
    sprintf(filename, "files/check_%d.py", next_k);

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Failed to create file %s\n", filename);
        return;
    }

    fprintf(file, "import files.check_%d\n", k);
    fprintf(file, "def check_%d(n):\n", next_k);
    fprintf(file, "    return not files.check_%d.check_%d(n-1)\n", k, k);

    fclose(file);
    printf("File %s created successfully.\n", filename);
}
void create_is_odd_file(int x) {
    FILE *pyFile = fopen("core_func.py", "w");

    // Kiểm tra nếu file không mở được
    if (pyFile == NULL) {
        printf("Failed to create is_odd.py\n");
        return;
    }

    // Thêm các import theo thứ tự từ 1 đến x
    for (int k = 1; k <= x; k++) {
        fprintf(pyFile, "import files.check_%d\n", k);
    }

    // Thêm hàm is_odd với các điều kiện
    fprintf(pyFile, "\n");
    fprintf(pyFile, "def is_odd(n):\n");

    for (int k = 1; k <= x; k++) {
        fprintf(pyFile, "    if n == %d:\n", k);
        fprintf(pyFile, "        return files.check_%d.check_%d(n)\n", k, k);
    }

    // Thêm phần xử lý exception
    fprintf(pyFile, "    else:\n");
    fprintf(pyFile, "        raise Exception('Invalid input')\n");

    // Đóng file sau khi ghi xong
    fclose(pyFile);

    printf("File 'core_func.py' has been created successfully.\n");
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Đọc giá trị k từ file "db.txt"
    FILE *dbFile = fopen("db.txt", "r");
    if (dbFile == NULL) {
        printf("Failed to open db.txt\n");
        return 1;
    }

    int k, n;
    fscanf(dbFile, "%d", &k); // Lấy giá trị k từ dòng đầu
    fclose(dbFile);

    // Đặt số lượng file n (ví dụ: 5 file)
    n = rand() % 1000 + 1;
    if(n<500) n += 500;

    int current_k = k;
    for (int i = 0; i < k+n; i++) {
        int next_k = current_k + 1; // Tăng dần 1000 lần
        create_check_file(current_k, next_k);
        current_k = next_k; // Cập nhật current_k
    }

    // Cập nhật file core_func.py
    create_is_odd_file( k+n);
    dbFile = fopen("db.txt", "w");
    if (dbFile == NULL) {
        printf("Failed to open db.txt for writing\n");
        return 1;
    }
    fprintf(dbFile, "%d", k+n); // Ghi giá trị k mới vào file "db.txt"
    // Đóng file sau khi ghi xong
    fclose(dbFile);


    printf("All files and core_func.py updated successfully.\n");
    return 0;
}

// int main() {
    
// }
