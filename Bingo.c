#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){//Bingo
    int i, t1, j, v2[20], v3[20], k=0;

    printf("Entre com o tamanho da aposta (max:20): ");
    scanf("%d", &t1);//Recebe a quantidade de apostas
    while(t1<1 || t1>20){//Invalida valores não compativeis
        printf("Valor invalido\n");
        printf("Entre com o tamanho da aposta: ");
        scanf("%d", &t1);
    }
    int v1[t1];//Recebe tamanho da aposta

    for(i=0; i<t1; i++){//Recebe as apostas
        printf("Entre com o valor do numero %d (max:100): ", i+1);
        scanf("%d", &v1[i]);
        while(v1[i]<0 || v1[i]>100){//Invalida valores não compativeis
            printf("Valor invalido\n");
            printf("Entre com o valor do numero %d: ", i+1);
            scanf("%d", &v1[i]);
        }
        for(j=0; j<i; j++){//Invalida apostas repetidas
            if(v1[i]==v1[j]){
                printf("Voce ja apostou esse numero\n");
                printf("Entre outro valor do numero %d: ", i+1);
                scanf("%d", &v1[i]);
                j=-1;
            }
        }
    }

    srand( (unsigned)time(NULL) );
    for(i=0; i<20; i++){
        v2[i]=rand()%100;//Gera 20 números aleatórios
        for(j=0; j<i; j++){//Invalida números repetidos
            if(v2[i]==v2[j]){
                v2[i]=rand()%100;
                j=0;
            }
        }
		printf("%d ",v2[i] );//Exibe os números sorteados
        for(j=0; j<t1; j++){//Compara apostas e sorteios
            if(v2[i]==v1[j]){
                v3[k]=v2[i];
                k++;
            }
        }
    }
    v3[k]=-1;//Decreta o fim do vetor de acertos
    printf("\n");
    if(k==0){//Verifica se houve acertos
        printf("Voce nao acertou nenhum numero\n");
        return 0;
    }

    printf("Voce acertou %d numeros\n", k);//Exibe quantidade de acertos
    printf("Voce acertou os numeros: \n");
    for(i=0; i<20; i++){//Exibe os acertos
        if(v3[i]==-1){
            printf("\n");
            system ("pause");
            return 0;
        }
        printf("%d ", v3[i]);
    }
	
	//printf("\n");
    //getchar();
    return 0;
}
