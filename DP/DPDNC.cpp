void dnc(int i, int l, int r, int optl, int optr) {
    if (l > r) return;
    int mid = (l + r) >> 1;
    pair <long long, int> best = {inf, l};
    for (int j = optl; j < min(mid, optr + 1); j++) {
        long long s = sum[mid] - sum[j];
        best = min(best, {s * s + f[i - 1][j], j});
    } 
    f[i][mid] = best.first;
    int opt = best.second;
    dnc(i, l, mid - 1, optl, opt);
    dnc(i, mid + 1, r, opt, optr);
}