//declaration des bibloiteque:
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
    //declaration d'un structur
    struct client{
        char nom[20];
        char prenom[20];
        char cin[10];
        float montant;
                };
    //varaiable global
   struct client clt[1000];
   int nbc=0;
   //void cleanCls pour vider le terminal:
   void cleanCls(){
       system("cls||clear");
   }
   //fonction pour création des comptes:
bool creation(int nb) {
     int i,choix;
     for(i=0;i<nb;i++){
        printf(" Nom : ");
        scanf("%s",clt[nbc].nom);
        printf(" Prenom : ");
        scanf("%s",clt[nbc].prenom);
        printf(" CIN : ");
        scanf("%s",clt[nbc].cin);
        printf(" Montant : ");
        scanf("%.2f",&clt[nbc].montant);
        printf("le compte et bien cree\n\n");

        nbc++;
        

        printf("\n le compte a bien cree .\n");
     }
}
//fonction pour les Opérations:
     
   bool Operation(){
        int option,i;
        char cind[10];
        float montantentrer;
         printf("entrer votre cin");
         scanf("%s",cind);
        do{
        
        printf("\n\n");
		printf("\t  1.Pour le  Retrait  : \n");
		printf("\t  2.Pour le depot : \n");
		printf("\t  00.Return au Menu principale \n");
		printf("Entrer un choix : ");
		scanf("%d",&option);
        switch(option) {
            //pour retrait:
        case 1:
    
        for(i=0;i< nbc;i++){
            if(strcmp(cind,clt[i].cin)==0){
            printf(" Donner la valeur du montant que vous souhaitez retirer :");				
            scanf("%f", &montantentrer);
			if (clt[i].montant >= montantentrer)
			clt[i].montant -= montantentrer;
			else 
			printf("Votre solde n'est pas suffisant pour effectuer cette opération  \n");
							
			printf("Le montant est : %.2f \n \n \n", clt[i].montant);
			}
            }
            //pour depot:
       break;
        case 2 :
        for(i=0;i< nbc;i++){
            if(strcmp(cind,clt[i].cin)==0){
            printf(" Donner la valeur du montant que vous souhaitez Deposer");				
             scanf("%f", &montantentrer);
		    clt[i].montant += montantentrer;
	        printf("Le montant est devait  : %.2f \n \n \n", clt[i].montant);
						}
            }
       break;
       	default : printf("Votre choix  ne trouve  pas \n");
        }
        
      
        }while(option!=0); 
    }
    
    //fonction pour recherche cin
bool recherchcin(){
    int i;
    char cind[10];
    bool existe=false;
    printf("entrer votre cin");
    scanf("%s",cind);
    
    for (i = 0; i < nbc ; i++) {
		if(strcmp(clt[i].cin, cind) == 0)
			existe = true;
	}
	if (existe) 
		printf(" le CIN Trouve \n");
	else 
		printf(" le CIN non trouve \n");
}
   
    
   //Affichage des compte:
    void affichagecompte() {
	int i;
	if(nbc > 0){
		printf("\t\t\t NOM \t | PRENOM \t | CIN \t | MONTANT | \n");
		for(i = 0; i < nbc; i++) 
			printf("\t\t\t%s \t %s \t %s \t %.2f \n", clt[i].nom, clt[i].prenom, clt[i].cin, clt[i].montant);	
	} else 
		printf("il n y a pas de comptes !!");
}

//main princibale
int main(){
    int i,choix,nvc,nbc;
    char cind[10];
    
    printf("\n     ***********************Application Bancaire********************       \n\n");
            printf("\n*********** Menu princibale************* \n\n");

    do{
     printf("[ 1 ] - Ajouter un nouveau compte.     \n");
     printf("[ 2 ] -  Ajouter un plusieur  nouveau compte.     \n");
     printf("[ 3 ] - Operation sur le compte.        \n");
     printf("[ 4 ] - Affichage des comptes.  \n");
     printf("[ 5 ] - statue des compte.   \n");
     printf("[ 0 ] -  Quitter.   \n");
     printf(" Taper votre choix :     "); 
     scanf("%d",&choix);
     switch(choix){
         case 1: creation(1);
         break;
         case 2:
         printf("Donner le nombre des client:");
         scanf("%d",&nbc);
        creation(nbc);
        break;
         case 3: Operation();
                break;
        
        case 4:
            affichagecompte();
       break;
       case 5 :
       printf("les comptes cree et %d\n",nbc);
       break;
     }
     
      
    }while(choix!=0);
  return 0;  
}

