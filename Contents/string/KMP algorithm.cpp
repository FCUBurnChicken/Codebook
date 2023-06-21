vector<int> NEXT;
void getNext(string p){
    int i = 1, j = i - 1;
    while(i < p.size()){
        if(p[i] == p[j]){
            NEXT[i++] = ++j;
        }
        else if(j <= 0){
            NEXT[i++] = 0;
        }
        else{
            j = NEXT[j - 1];
        }
    }
}

int KMP(string s, string p){
	int i = 0, j = 0;
	while(i < s.size() && j < p.size()){
		if(s[i] == p[j]){
			++i;
			++j;
		}else if(j <= 0){
			++i;
		}else{
			j = NEXT[j - 1];
		}
	}
	
	if(j >= p.size()) return i - p.size();
	else return -1;
}