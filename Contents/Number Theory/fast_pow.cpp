constexpr int mod = 1e9 + 7;
ll fpow(ll i, int j) {
    ll ret = 1, tmp = i;
    for (; j; j >>= 1, tmp = tmp * tmp % mod)
        if (j & 1) ret = ret * tmp % mod;
    return ret;
}