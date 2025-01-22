import files.check_6379
def check_6380(n):
    return not files.check_6379.check_6379(n-1)
