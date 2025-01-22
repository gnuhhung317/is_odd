import files.check_403
def check_404(n):
    return not files.check_403.check_403(n-1)
