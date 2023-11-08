#include <stdio.h>
#include <string.h>
#include <ctype.h>

void toLowerCase(char *str) {
    while (*str) {
        *str = tolower(*str);
        str++;
    }
}

int main(){
    char placaCarro[9] = "AAA-1010";
    char diaSemana[14] = "DOMINGO";
    char diaSemanaNaoPermitido[14];
    char *diasDaSemana[] = {
            "DOMINGO", "SEGUNDA-FEIRA", "TERÇA-FEIRA",
            "QUARTA-FEIRA", "QUINTA-FEIRA", "SEXTA-FEIRA", "SÁBADO"
    };
    char *contemHifem = strchr(placaCarro, '-');
    int ultimoDigitoPlaca = placaCarro[strlen(placaCarro) - 1] - '0', count = 0;

    //Validacao placa
        //Validacao das placas antigas
    if(contemHifem != NULL){

    }
    printf("%d", count);



    if(ultimoDigitoPlaca == 0 || ultimoDigitoPlaca == 1){
        strcpy(diaSemanaNaoPermitido, "SEGUNDA-FEIRA");
    }else if(ultimoDigitoPlaca == 2 || ultimoDigitoPlaca == 3){
        strcpy(diaSemanaNaoPermitido, "TERCA-FEIRA");
    }else if(ultimoDigitoPlaca == 4 || ultimoDigitoPlaca == 5){
        strcpy(diaSemanaNaoPermitido, "QUARTA-FEIRA");
    }else if(ultimoDigitoPlaca == 6 || ultimoDigitoPlaca == 7){
        strcpy(diaSemanaNaoPermitido, "QUINTA-FEIRA");
    }else if(ultimoDigitoPlaca == 8 || ultimoDigitoPlaca == 9){
        strcpy(diaSemanaNaoPermitido, "SEXTA-FEIRA");
    }

    if (strcmp(diaSemana, "SABADO") == 0 || strcmp(diaSemana, "DOMINGO") == 0){
        printf("Nao ha proibicao no fim de semana");
    } else if(strcmp(diaSemana, diaSemanaNaoPermitido) != 0){
        toLowerCase(diaSemana);
        printf("%s pode circular %s", placaCarro, diaSemana);
    } else{
        toLowerCase(diaSemana);
        printf("%s nao pode circular %s", placaCarro, diaSemana);

    }
    return 0;
}