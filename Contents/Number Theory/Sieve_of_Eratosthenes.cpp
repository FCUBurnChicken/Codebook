bool a[46342];
vector <int> v;
for (int j = 2; j < 46342; j++){
    if (!a[j]){
        v.push_back(j);
        for (int i = j * j; i < 46342; i += j){
            a[i] = true;
        }
    }
}