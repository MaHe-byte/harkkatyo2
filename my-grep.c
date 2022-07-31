//Markus Heikkilä
//Lähteet: https://www.codeproject.com/Questions/5268549/How-do-I-make-a-programme-in-C-which-mimic-the-gre
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 4096


int main(int argv, char **argc)
{
//JOs käyttäjä aukaisee ohjelman ilman muuttujia kerrotaan hänelle mitä sovellukseen on syötettävä
	if (argv == 1)
	{
	printf("my-grep: searchterm [file ...]");
	exit(1);}	
	char buffer[MAX];
	char *grep = argc[1];
	char user[MAX];
//Jos käyttäjä antaa pelkästään etsittävän termin käyttäjältä kysytään teksti mistä etsiä sanaa	
	if (argv == 2){
	scanf("%s",user);
	if(strstr(user,grep)){
 		printf("%s",user);}	
 		 
	exit(1);}
	//Jos käyttäjä antaa etsittävän sanan ja avataan kaikki tiedostot ja käydään läpi
	for ( int i = 2; argv > i; i++){
		char *filename = argc[i];
    	FILE *fp = fopen(filename, "r");
    	
    	if (fp == NULL)
    {
        fprintf(stderr, "my-grep: cannot open file %s", filename);
        exit(1);//Suljetaan jos tiedosto ei aukea
       	}
		
	char * line = NULL;
    size_t len = 0;
    ssize_t read;

	while ((read = getline(&line, &len, fp)) != -1) {
        if(strstr(line,grep)){
 		 printf("%s",line);}	//KÄydää rivi kerrallaan läpi ja tulostetaan rivit joissa sama termi
 		 }
		
	fclose(fp);
	}
	return 0;
}
