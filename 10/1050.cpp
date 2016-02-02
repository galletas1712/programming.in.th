#include <cstdio>
using namespace std;

int n, p;
typedef struct Chemical{
    int prop[10];  
} chem;

chem chems[100001]; // array ที่ใช้หลักๆ หลัง sort แล้ว
chem org[100001]; // original array
chem add; // อสารตั้งต้นที่ต้องการมาผสมเพื่อได้ผลลัพธ์ที่ต้องการ

//UTIL
bool equal(chem a, chem b){
	for(int i = 0; i < p; i++){
		if(a.prop[i] != b.prop[i]) return false;
	}
	return true;
}

bool less(chem a, chem b){
    for(int i = 0; i < p; i++){
        if(a.prop[i] < b.prop[i]) return true;
        else if(a.prop[i] > b.prop[i]) return false;
    }
    return false;
}

void exch(int a, int b){
	chem holder = chems[a];
	chems[a] = chems[b];
	chems[b] = holder;
}

void printChem(chem c){
	for(int i = 0; i < p; i++){
		printf("%d ", c.prop[i]);
	}
}

//QUICKSORT
int partition(int lo, int hi){
	chem k = chems[lo];
	int i = lo;
	int j = hi+1;
	while(true){
		while(less(chems[++i], k))
			if(i == hi) break;
		while(less(k, chems[--j]))
			if(j == lo) break;
		if(i >= j) break;
		exch(i, j);
	}
	exch(lo, j);
	return j;
}

void sort(int lo, int hi){
	if(hi <= lo) return;
	int j = partition(lo, hi);
	sort(lo, j-1);
	sort(j+1, hi); // skip j because we want it to stay in place. 
}

//BINARY SEARCH
int search(int lo,int hi, chem a){
    int mid = lo+(hi-lo)/2;//printf("%d\n", mid);
    if(lo == hi){
        if(equal(chems[lo], a)) return lo;
        else return -1;
    }else if(hi-lo == 1 || lo-hi == 1){
        if(equal(chems[lo], a)) return lo;
        else if(equal(chems[hi], a)) return hi;
        else return -1;
    }
    if(less(a, chems[mid])) return search(lo, mid-1, a);
    else if(less(chems[mid], a)) return search(mid+1, hi, a);
    else if(equal(chems[mid], a)) return mid;
}

int main(){
	// รับค่า
    scanf("%d %d", &n, &p);
    chem target;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < p; j++){
            int a;
            scanf("%d", &a);
            chems[i].prop[j] = a;
            org[i].prop[j] = a;
        }
    }
    sort(0, n-1);
    for(int i = 0; i < p; i++){
    	scanf("%d", &target.prop[i]);
    }
    // check ว่ามีสารตั้งต้นที่เหมือนกับที่ระขุไว้เหรือเปล่า
    int res = search(0, n-1, target);
    if(res != -1){
    	for(int i = 0; i < n; i++){
    		if(equal(chems[res], org[i])){
    			printf("%d", i+1);
    			return 0;
    		}
    	}
    }
    
    // check คู่
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < p; j++) add.prop[j]  = target.prop[j] - chems[i].prop[j]; // add คือสารตั้งต้นที่ต้องการมาผสมเพื่อได้ผลลัพธ์ที่ต้องการ
    	res = search(i+1, n-1, add);
    	if(res != -1){ // ถ้าเจอ
    		int ii = -1;
    		int rres = -1;
    		for(int k = 0; k < n; k++){ // check ใน array ก่อนจะ sort ว่าค่าของ i กับ res อยู่ใหน
    			if(equal(org[k], chems[i])) ii = k;
    			if(equal(org[k], chems[res])) rres = k;
    			if(ii > -1 && rres > -1){ // print อันที่เล็กกว่า
    				if(ii < rres) printf("%d %d", ii+1, rres+1);
    				else printf("%d %d", rres+1, ii+1);
    				return 0;
    			}
    		}
    	}
    }
    if(res == -1) printf("NO");
}
