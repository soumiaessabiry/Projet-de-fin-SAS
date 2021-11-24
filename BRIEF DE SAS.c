#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
// variable globale
int nbrcompte;
//declaration d'une structure :
         typedef struct {
                char Nom[20];
                char Prenom[20];
                char CIN[10];   
                float montant;
          } info_client;
  //declaration d'une tableau de type struct:
 info_client clt[1050];//clt=client
//la fonction clenCls
  void cleanCls(){
  	system("cls||clear");
  }
  int nbrcompte=0;
  //declaration d'une fonction pour creation des comptes:
   	bool creationcompte(int nbnvcompte){
       int i;
       for(i=0;i<nbnvcompte;i++){
        printf(" Nom : ");
        scanf("%s",clt[i].CIN);
        printf(" Prenom : ");
        scanf("%s",clt[i].Nom);
        printf(" CIN : ");
        scanf("%s",clt[i].Prenom);
        printf(" Montant : ");
        scanf("%f",&clt[i].montant);
        nbrcompte++;   
       }
       
       return true; 
   }
  //declaration d'une fonction pour les operations
  void operation(){
      int option,i;
      char cin[11];
      float montantentrer;
        printf("Donner le CIN de client");
        scanf("%s",cin);
    cleanCls();
	 
	 do {
      
      printf("[1]--> pour le Retrait d'argent . \n");
      printf("[2]--> pour le Depot d'argent . \n");
      printf("[0]--> Retourne menu initial. \n");
      printf(" taper votre choix");
      scanf("%d",&option);
      //pour option Retrait:
      switch(option){
        case 1:
        	cleanCls();
           for(i=0;i<nbrcompte;i++){
                    if(strcmp(cin,clt[i].CIN)==0){
                     printf(" Donner la valeur du montant que vous souhaitez retirer");
                    scanf("%f",&montantentrer);
                    if(clt[i].montant>=montantentrer){
                        clt[i].montant=clt[i].montant-montantentrer;
                        printf("le montant reste est %f DH",clt[i].montant);
                       }else 
                  printf("Votre solde n'est pas suffisant pour effectuer cette opération");
                    }
                } 
          
      
                   break;
                   cleanCls();
       	case 2 :
     	    for(i=0;i<nbrcompte;i++){
                    if(strcmp(cin,clt[i].CIN)==0){
                    printf(" Donner la valeur du montant que vous souhaitez retirer");
                    scanf("%f",&montantentrer);
                    clt[i].montant=clt[i].montant+montantentrer;
                    printf(" votre sole devient   %f DH",clt[i].montant);
                   
				 			  }
          							}
		    break;
        
			 default:printf("le choix est inccorect\n");
}		}while(option!=0);
cleanCls();

}
  //la fonction main princibale.
  			int main(){
      printf( " ******************* Application pour Gere les comptes bancaire.**************           .\n");
      int choix,nbnvcompte,i,option;
      //declaration de menu.
                
					do{
          
     printf("[ 1 ] -->  Ajouter un nouveau compte.     \n");
     printf("[ 2 ] -->  Ajouter un plusieur  nouveau compte.     \n");
     printf("[ 3 ] -->  Operation sur le compte.        \n");
     printf("[ 4 ] -->  Affichage des comptes.  \n");
     printf("[ 5 ] -->  Fidilisation.   \n");
     printf("[ 0 ] -->  Quitter.   \n");
     printf("     Taper votre choix :     ");  
     scanf("%d",&choix);
           switch(choix){
		  cleanCls();
case 1: if(creationcompte(1)){
         printf("le compte etait bien cree\n :");
          		
		}else{
		printf("vous avez une erreur veuillez cree le comte a nouveau:");
		}
          break;
case 2:
          printf("taper  le nombre des comptes que vous pouvez cree : ");
		  scanf("%d",&nbnvcompte);
		  creationcompte(nbnvcompte);
		  	printf("les comptes etait bien cree\n :");
		  break;
case 3:
			operation();
			break;
			
	case 4:	
	 cleanCls();
	break;
		
      }
    }while(option!=0);
    return 0;
}

  		
         
     	
				
				
				
		
		
 
