#include"stdio.h"
#include"string.h"
#include <algorithm>

struct person
{
	int point;
	char name;
}person[7];

char vote[20000] = {};
int survivor = 7;

bool greater(struct person a, struct person b){
	if(a.point > b.point) return true;
	else if(a.point == b.point && a.name-'A' < b.name-'A') return true;
	return false;
}

int main(){
	for(int i = 0; i < 7; i++) person[i].name = 'A'+i, person[i].point = 0; 
	while(true){
		scanf("%s", vote);
		if(vote[0] == '!') break;
		for(int i = 0; i < strlen(vote); i++){
			int atoi = vote[i] - 'A';
			if(person[atoi].point != 1000000) person[atoi].point++;
		}
		if(survivor > 1){
			int min = 0, count = 0;
			for(int i = 1 ; i < 7 ; i++)
				if(person[i].point < person[min].point) min = i;
			for(int i = 0 ; i < 7 ; i++)
			{
				count = 0;
				if(person[i].point == person[min].point && i != min)
				{
					count++;
					break;
				}
			}
			if(count == 0)
			{
				person[min].point = 1000000;
				survivor--;
			}

			/*int min = 1000000;
			  int mini = 0;
			  bool g1 = false;
			  for(int i = 0; i < 7; i++){
			  if(c[i].point < min) min = c[i].point, mini = i;
			  }
			  for(int i = 0; i < 7; i++){
			  if(c[i].point == min && i != mini) g1 = true;
			  }
			  if(!g1) c[mini].point = 1000000, survivor--; 
			 */}
	}
	std::sort(person, person+7, greater);
	printf("%d\n", survivor);
	for(int i = 0; i < 7; i++){
		if(person[i].point != 1000000){
			printf("%c %d\n", person[i].name, person[i].point);
		}
	}
}

