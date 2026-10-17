for (int i = 1; i <= n; i++) cnt[a[i]]++;

// Normal DP SOS Submask
for (int mask = 0; mask < (1 << 20); mask++) sosSub[mask] = cnt[mask];
for (int lg = 0; lg < 20; lg++) {
    for (int mask = 0; mask < (1 << 20); mask++) {
        if (getBit(mask, lg)) sosSub[mask] += sosSub[mask ^ (1 << lg)];
    }
}

// Normal DP SOS Supermask
for (int mask = 0; mask < (1 << 20); mask++) sosSup[mask] = cnt[mask];
for (int lg = 0; lg < 20; lg++) {
    for (int mask = 0; mask < (1 << 20); mask++) {
        if (!getBit(mask, lg)) sosSup[mask] += sosSup[mask ^ (1 << lg)];
    }
}

// Reverse DP SOS Submask
for (int mask = 0; mask < (1 << 20); mask++) revSub[mask] = sosSub[mask];
for (int lg = 0; lg < 20; lg++) {
    for (int mask = 0; mask < (1 << 20); mask++) {
        if (getBit(mask, lg)) revSub[mask] -= revSub[mask ^ (1 << lg)];
    }
}

// Reverse DP SOS Supermask
for (int mask = 0; mask < (1 << 20); mask++) revSup[mask] = sosSup[mask];
for (int lg = 0; lg < 20; lg++) {
    for (int mask = 0; mask < (1 << 20); mask++) {
        if (!getBit(mask, lg)) revSup[mask] -= revSup[mask ^ (1 << lg)];
    }
}
