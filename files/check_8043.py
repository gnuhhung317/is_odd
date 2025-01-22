import files.check_8042
def check_8043(n):
    return not files.check_8042.check_8042(n-1)
