from core_func import is_odd
print("Mời nhập vào n: ")
while True:
    try:
        n = int(input())
        break
    except ValueError:
        print("Vui lòng nhập số nguyên dương.")
try:
    if(is_odd(n)):
        print("Số bạn nhập là số lẻ.")
    else:
        print("Số của bạn nhập là số chẵn")
except Exception as e:
    print(f"Chương trình chưa thể tính toán được tính chất của {n}.")
    print(f"Lỗi: {e}")