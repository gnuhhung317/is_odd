import files.check_8259
def check_8260(n):
    return not files.check_8259.check_8259(n-1)
