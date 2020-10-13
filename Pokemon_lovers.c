#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node {
  char* data;
  struct node* left;
  struct node* right;
};

//Struct y arreglo para ingresar los nombres de los pokemones
struct nam{
    char poken[20];
};
struct nam newname[20];

//Struct y arreglo para ingresar las caracteristicas de los pokemones
struct cha{
    char pokech[20];
};
struct cha newcharac[20];


struct node* root;//se guardara la raiz
struct node* first;//guardara la primera raiz 
struct node* last;//guardara la ultima raiz 
struct node* firstread;//guardara la primera raiz y se usara para mostrar caracteristicas

struct node* createNode(char *info);
struct node* insertLeft(struct node* rootnode, char *charac);
struct node* insertRight(struct node* rootnode, char *charac);
void add_pokemon(struct nam name[], struct cha charact[]);
struct node* getroot();
void inorderTraversal(struct node* root);

int main()
{
    int opt, i, j;
    char again;
    char firstcharac[30]= "es_electrico", firstname[30]= "pikachu";
    int think, choose, yes= 0;//think para seleccionar si piensa en un poke. - choose para indicar si la caract. es del poke. pensado - yes para indicar si agregara otro pokemon  
    int pika;//para indicar si el pokemon ingresado es igual al de la raiz
    struct node* eachroot;//para guardar las raices del arbol cuando se recorra para sugerir caracteristicas 
    int count= -1;
    
    do {
        system("cls");
        printf("\n    ----------------------------------------------------");
        printf("\n\n                       POKEMON LOVERS");
        printf("\n\n    ----------------------------------------------------");
        printf("\n\n                            MENU ");
        printf("\n\n    1. Empezar el juego");
        printf("\n    2. Normas del juego");
        
        //Valida que se escriba una de las opciones
        while(1) {
            printf("\n\n    Digite una de las opciones para realizar uno de ");
            printf("\n    los ejercicios. ");
            scanf("%d", &opt);
            if(opt==1 || opt==2) {
                break;
            } else {
                printf("\n    ----------------------------------------------------");
                printf("\n\n    ERROR!!! Por favor solo ingrese una de las opciones");
                printf("\n    del programa");
            }
        }        
        switch(opt) {
        case 1:
            //Crear nodo raíz
            root = createNode(firstcharac);
            insertRight(root, firstname);            
            first= root;
            last= root;
            printf("\n    ----------------------------------------------------");
            printf("\n\n                       POKEMON LOVERS");                          
            do{                
                yes= 0;
                printf("\n\n    ----------------------------------------------------");
                printf("\n\n                    ADIVINAR EL POKEMON");           
                printf("\n\n    ----------------------------------------------------");                         
                printf("\n\n    Estas pensando en un pokemon? Digite 1 para 'si' o");
                printf("\n    2 para 'no': ");
                scanf("%d", &think);
                if(think== 1){
                    printf("\n    ----------------------------------------------------\n");        
                    printf("\n    Digite 1 para decir 'si' o 2 para decir 'no'. \n");
                    printf("\n    ----------------------------------------------------\n");                      
                    firstread= first;                  
                    
                    //Sugerir caracteristicas de pokemones
                    eachroot= getroot();
                    while(eachroot!= NULL){
		                    printf("\n    %s ? ", eachroot->data);
                       scanf("%d", &choose);
                       if(choose== 1){
                           printf("\n    Pokemon: %s", eachroot->right->data);
                           yes= 1;
                           break;
                       }
                       eachroot= getroot();                      
	                   }
                    if(yes==1){
                        break;
                    }else if(yes== 0){
                        count++;
                        //Ingresar el nombre del pokemon pensado
                        printf("\n    ----------------------------------------------------\n");                                
                        printf("\n    En que pokemon pensaba? ");
                        scanf("%s", newname[count].poken);
                        printf("\n    Que diferencia a un %s de un %s ? ", root->right->data, newname[count].poken);
                        scanf(" %[^\n]s", newcharac[count].pokech);
                        add_pokemon(newname[count].poken, newcharac[count].pokech);                 
                    }
                    printf("\n    Si el pokemon fuera un %s cual seria su ", root->right->data);                  
                    printf("\n    respuesta? ");
                    scanf(" %d", &pika);
                    if(pika== 1){
                        printf("\n    WOW!!! ese es el nombre del pokemon del nodo raiz");
                    }                  
                }else if(think== 2){
                    break;
                }
                
            }while(think== 1);
            //Recorrer el arbol y mostrar sus elementos          
            printf("\n\n    ----------------------------------------------------");         
            printf("\n\n                    ELEMENTOS DEL ARBOL ");
            printf("\n\n    ----------------------------------------------------\n\n");                   
            printf("    ");
            inorderTraversal(root);
            
            break;
        case 2:
            system("cls");
            printf("\n    ----------------------------------------------------");
            printf("\n\n                       POKEMON LOVERS");
            printf("\n\n    ----------------------------------------------------");
            printf("\n\n                   Descripcion del juego\n");
            printf("\n    1. El programa le dara un caracteristicas de pokemones ");
            printf("\n       al usuario y respondera si o no para ver si coincide");
            printf("\n       con una de las caracteristicas del pokemon pensado");
            printf("\n    2. Si coincide el juego dara el nombre del pokemon  ");
            printf("\n       sino se le pedira al usuario que ingrese el nombre");
            printf("\n    3. Luego se le pedira al usuario que ingrese una de las");
            printf("\n       caracteristicas de ese pokemon ");
            printf("\n    4. El juego repetira el mismo proceso hasta que el  ");
            printf("\n       usuario indique que no esta pensando en un pokemon ");
            printf("\n    5. Por ultimo se mostraran lo pokemones ingresados con");           
            printf("\n       sus caracteristicas");
            break;

        }
        count= -1;
        printf("\n\n    ----------------------------------------------------");
        printf("\n\n    Desea volver a jugar? Digite 's' para si o ");
        printf("\n    'n' para no. ");
        scanf(" %c", &again);
    } while(again == 'S' || again =='s');
    if(again == 'N' || again == 'n') {
        printf("\n    ----------------------------------------------------");
        printf("\n\n                            FIN\n");
    }
    return 0;

}

//Crear un nodo
struct node* createNode(char *info) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = info;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

//Poner un nodo a la izq
struct node* insertLeft(struct node* rootnode, char *charac) {
    rootnode->left = createNode(charac);
    return rootnode->left;
}

//Poner un nodo a la derecha
struct node* insertRight(struct node* rootnode, char *charac) {
    rootnode->right = createNode(charac);
    return rootnode->right;
}

//Agregar el nombre y caract. de un pokemon
void add_pokemon(struct nam name[], struct cha charact[]){ 
    insertLeft(last, charact->pokech);
    last= last->left;
    insertRight(last, name->poken); 
}

//Obtener cada raiz del arbol
struct node* getroot(){
   if(firstread == NULL){
		     return NULL;
	  }
	  struct node* root_returned=firstread;
	  firstread= firstread->left;
	  return root_returned;
}

//Recorrido de arbol con inorder
void inorderTraversal(struct node* rootnode) {
    if (rootnode == NULL) return;

    inorderTraversal(rootnode->left);  
    printf("%s ->", rootnode->data);
    inorderTraversal(rootnode->right);
}