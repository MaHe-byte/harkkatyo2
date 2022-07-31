#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 4096


int main(int argv, char **argc)
{
	if (argv < 1)//Varmistetaan että käyttäjä antanut oikean määrän muuttujia
	{exit(0);}
		
	char buffer[MAX];
	char *grep = argc[1];
	int i = 0;
	int j = 1;
	int count = 0;
	
	for ( int k = 1; argv > k; k++){//Käydään tiedostot läpi 
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
//Luetaan rivi ja sitä kirjain kerrallaan
	while ((read = getline(&line, &len, fp)) != -1) {
		while (line[i] != '\0'){
		
//Tarkistetaan onko kirjan numero, jos on lisätään laskuriin yksi			
        	if(isdigit(line[i])){
 		 		count = line[i]-'0';
 		 		i++;
 		 		continue;}
 		 	
 		 	else{
 		 	
 		 	if (line[i] == '\n'){
 		 		break;}
//Jos kyseessä kirjain tulosteaan kirjaimia laskurin summan mukaan			
			for(int z = 1; z<=count; z++){
			printf("%c",line[i]);
			}
       		count = 0;
 		 	i++;
 		 	}	
 		 	}
 		 }
	printf("\n");	
	fclose(fp);
	}
	
	return 0;
}
