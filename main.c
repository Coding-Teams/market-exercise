/*
 * spicoli piersilvio
 * università degli studi di bari - Aldo Moro
 * dip. Informatica
 *
 * 06 / 12 / 2020
 * market exercise
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define max 100

//struct record declaration
typedef struct{
	char id[30];
	char nome_resp[30];
	char cognome_resp[30];
	char indirizzo[30];
	char citta[30];
	int num_dip;
	float fatturato;
}supermarket;

//declaration as array of record
supermarket sup[max];

//global variables
int i;
int choise;
_Bool flagControl;
int n_sup = 0;

//function's declaration
void searchManager();
void searchCity();
void searchMax();

int main(){

	setbuf(stdout, NULL);

	printf("\n");
	printf("Market exercise! idea by spicoli piersilvio \n");

	printf(":: load the data before starting! \n \n");

	//load data
	do{
			printf(":: insert the number of the supermarket -> ");
			scanf("%d", &n_sup);
		}while(n_sup <= 0);

		for(i = 0; i < n_sup; i++){

			printf(":: id -> \n");
			scanf("%s", sup[i].id);
			printf(":: name manager -> \n");
			scanf("%s", sup[i].nome_resp);
			printf(":: second name manager -> \n");
			scanf("%s", sup[i].cognome_resp);
			printf(":: address city -> \n");
			scanf("%s", sup[i].indirizzo);
			printf(":: city -> \n");
			scanf("%s", sup[i].citta);
			printf(":: number of employes -> \n");
			scanf("%d", &sup[i].num_dip);
			printf(":: revenue -> \n");
			scanf("%f", &sup[i].fatturato);

		}

	do{
			printf("\n");
			printf("1 - :: search the manager and print the data \n");
			printf("2 - :: search the city and print the market inside \n");
			printf("3 - :: print the market with max employes \n");
			printf("4 - :: exit to the progam \n");
			printf("\n");
			printf(":: choise -> ");
			scanf("%d", &choise);

			switch(choise){

				case 1:
						searchManager();
				break;
				case 2:
						searchCity();
				break;
				case 3:
					searchMax();
				break;
			}

	}while(choise != 4);

	system("pause");
	return 0;
}

void searchManager(){

	//local variables
	char id_input[30];
	_Bool flag;

	printf(":: insert the id of manager -> \n");
	scanf("%s", id_input);

	flag = 0;

	for(i = 0; i < n_sup; i++){

		if(strcmp(id_input, sup[i].id) == 0){ //compare the strings with functions. read the doc
			flag = 1;

			printf(":: id: %s \n", sup[i].id);
			printf(":: name manager: %s \n", sup[i].nome_resp);
			printf(":: second name manager: %s \n", sup[i].cognome_resp);
			printf(":: address city of market: %s \n", sup[i].indirizzo);
			printf(":: city of the market: %s \n", sup[i].citta);
			printf(":: number of employes of the market: %d \n", sup[i].num_dip);
			printf(":: revenue of the market: %.2f $\n", sup[i].fatturato);
		}
	}

	if(!flag)
		printf(":: id was wrong! search failled! \n");

}

void searchCity(){

	//local variables
	char city_input[30];
	_Bool flag;
	int contMarket = 0;

	printf(":: insert the city -> \n");
	scanf("%s", city_input);

		flag = 0;

		for(i = 0; i < n_sup; i++){

			if(strcmp(city_input, sup[i].citta) == 0){
				flag = 1;
				contMarket++;
				printf(":: there are %d market in %s\n", contMarket, sup[i].citta);
			}
		}

		if(!flag)
			printf(":: search failled! \n");
}

void searchMax(){

	//local variables
	int pos = 0;
	int maximNumb = 0;

	for(i = 0; i < n_sup; i++){

		if(sup[i].num_dip > maximNumb){
			pos = i;
			maximNumb = sup[i].num_dip;
		}
	}

	printf(":: here's the market with a max employes \n");
	printf("\n");
	printf(":: id: %s \n", sup[pos].id);
	printf(":: name manager: %s \n", sup[pos].nome_resp);
	printf(":: second name manager: %s \n", sup[pos].cognome_resp);
	printf(":: address city of market: %s \n", sup[pos].indirizzo);
	printf(":: city of the market: %s \n", sup[pos].citta);
	printf(":: number of employes of the market: %d \n", sup[pos].num_dip);
	printf(":: revenue of the market: %.2f $\n", sup[pos].fatturato);

}
