//Markus Heikkilä
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 4096


int main(int argv, char **argc)
{
	if (argv < 1) //Varmistetaan että käyttäjä antaa oikean määrän tietoa
	{exit(0);}
		
	char buffer[MAX];
	char *grep = argc[1];
	int i = 0;
	int j = 1;
	int count = 0;
	
	for ( int k = 1; argv > k; k++){//Käydään kaikki käyttäjän antamat sovellukset läpi ja avataan ne
		char *filename = argc[k];
    	FILE *fp = fopen(filename, "r");
    	
    	if (fp == NULL)
    {
        fprintf(stderr, "my-cat: cannot open file %s", filename);
        exit(1);//Jos tiedosto ei aukea suljetaan sovellus
       	}
		
	char * line = NULL;
    size_t len = 0;
    ssize_t read;

	while ((read = getline(&line, &len, fp)) != -1) {
		while (line[i] != '\0'){//Luetaan rivi ja käydään siihen läpi että rivi loppuu
		
			
        	if(line[i]==line[j]){//Jos nykyinen ja seuraava kirjain sama lisätään laskuriin 1 ja siirrytään seuraavaan kirjaimeen
 		 		count++;
 		 		j++;
 		 		continue;}
//Muuten tulosteaan kirjain sekä laskimen mukaan kuinka monta niitä on ollut 		 	
 		 	else{
 		 	
 		 	if (line[i] == '\n'){
 		 		break;}

 		 	printf("%d%c",count + 1, line[i]);
       		count = 0;
 		 	i=j;
 		 	j++;
 		 	}	
 		 	}
 		 }
	printf("\n");	
	fclose(fp);
	}
	
	return 0;
}
