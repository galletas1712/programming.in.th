#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int nums[n];
	for(int i = 0; i < n; i++){
		scanf("%d", &nums[i]);
	}
	std::sort(nums, nums+n);
	if(nums[0] == 0){
		for(int i = 1; i < n; i++){
			if(nums[i] > 0){
				nums[0] = nums[i];
				nums[i] = 0;
				break;
			}
		}
	}
	for(int i = 0; i < n; i++){
		printf("%d", nums[i]);
	}
}
