//Markus Heikkilä
//Lähteinä käytetty : https://www.geeksforgeeks.org/command-line-arguments-in-c-cpp/
//https://austinedger.medium.com/unix-commands-lets-build-cat-59b8a91b9708
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 4096


int main(int argv, char **argc)
{
//Tarkastetaan, että käyttäjä on antanut vaadittavat tiedot
	if (argv < 1)
	{exit(0);}
		
	char buffer[MAX];
	
//Käydään läpi yksi kerrallaa kaikki käyttäjän antamat tiedostot	
	for ( int i = 1; argv > i; i++){
		char *filename = argc[i];
    	FILE *fp = fopen(filename, "r");
    	
    	if (fp == NULL) //Tarkistetaan tiedoston toimivuus
    {
        fprintf(stderr, "my-cat: cannot open file %s", filename); 
        exit(1); //Jos tiedosto ei avaudu suljetaan ohjelma
       	}
    
    //Tulostetaan tekstitiedoston teksti   	
	while(fgets(buffer,MAX,fp) != NULL){
		printf("%s",buffer);
	}
	fclose(fp);
	}
	return 0;
}
