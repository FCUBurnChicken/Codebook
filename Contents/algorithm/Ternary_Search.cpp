int l = -10000;
int r = 10000;
int iterations = 100;
for (int i = 0; i < iterations; i++){
    double mr = (l + r) / 2.0;
    double ml = (l + mr) / 2.0;
    // f( ): 目標函數
    if (f(ml) < f(mr)) r = mr;
    else l = ml;
}