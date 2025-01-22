import files.check_404
def check_405(n):
    return not files.check_404.check_404(n-1)
