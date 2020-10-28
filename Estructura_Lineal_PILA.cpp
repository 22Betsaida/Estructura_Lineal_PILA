//Ejemplo b�sico del funcionamiento de una Pila en C++
#include <iostream> //Libreria para poder usar la funci�n princilpa main
#include<windows.h> //Libreria para poder usar la funci�n gotoxy
#include<locale.h>	//Libreria para poder imprimir caracteres especiales
using namespace std;

//-------------Estructura de la funci�n gotoxy----------------//
void gotoxy(int x,int y){ 
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);}  						
//----------------------------------------------------------//

//-------------------Estructura tipo nodo--------------------//
struct nodo	{
    int numero;
    struct nodo *sgte;};			
//----------------------------------------------------------//

//---------------Estructura nodo tipo puntero----------------//
typedef nodo *ptrPila;   
//----------------------------------------------------------// 
 
//------Estructura tipo void para agregar valores-----------//
void AGREGAR_NUM( ptrPila &p, int valor ){
     ptrPila aux;
     aux = new(struct nodo);
     aux->numero = valor;
     aux->sgte = p ;
     p = aux ;}											
//----------------------------------------------------------//
 
//-----------------Estructura para eliminar un valor de la pila-------------//
int QUITAR_NUM( ptrPila &p ){
     int num ;
     ptrPila aux;
     aux = p ;
     num = aux->numero;
     p = aux->sgte ;
     delete(aux);
     return num;}
//-------------------------------------------------------------------------//	   
       				 
//-------------Estructura tipo void que muestra elementos de la pila-------//
void MOSTRAR_PILA( ptrPila p ){
     ptrPila aux;
     aux = p;  
   		while( aux !=NULL ){ 
		 	cout<<"\t"<< aux->numero <<endl;
            aux = aux->sgte;}}
//------------------------------------------------------------------------//     						    
							 
//-----------------------Estructura que presenta el menu en pantalla----------------------------// 
void menu(){
	setlocale(LC_CTYPE, "Spanish");//Funci�n que nos permite mostrar caracteres especiales en pantalla
	gotoxy(30,8);cout<<"****************************************************"<<endl;
	gotoxy(30,9);cout<<"* INGRESE EL N�MERO DE LA OPCI�N QUE DESEA ELEGIR  *"<<endl;
	gotoxy(30,10);cout<<"*\t[1]___INSERTAR N�MERO A LA PILA\t                 *"<<endl;
	gotoxy(30,11);cout<<"*\t[2]___BORAR N�MERO DE LA PILA                    *"<<endl;
	gotoxy(30,12);cout<<"*\t[3]___MOSTRAR N�MEROS DE LA PILA                 *"<<endl;
	gotoxy(30,13);cout<<"*\t[4]___SALIR                                      *"<<endl;
	gotoxy(30,14);cout<<"*\t\t\tINGRESE OPCI�N:     		 * "<<endl;
	gotoxy(30,15);cout<<"****************************************************";}
//--------------------------------------------------------------------------------------------//			
 
//-------------------------Funci�n principal main---------------------//
int main(){
    ptrPila p = NULL;//Se crea la pila con ayuda del puntero
    int dato;
    int op,to;
    int x ; 
setlocale(LC_CTYPE, "Spanish");//Funci�n que nos permite presentar en pantalla caracteres 
    do
    {
		menu();  
		gotoxy(64,14);cin>> op;
        switch(op)
        {
            case 1:
            	system("cls");
            	gotoxy(30,8);cout<<"****************************************************"<<endl;
            	gotoxy(30,9);cout<<"*\t\t___INSERTAR N�MERO A LA PILA___          *"<<endl;
            	gotoxy(30,10);cout<<"*\t�CUANTOS N�MEROS DESEA INSERTAR A LA PILA?:      *";
            	gotoxy(30,11);cout<<"****************************************************"<<endl;
            	gotoxy(76,10);cin>>to;
            	system("cls");
            	for(int i=0; i<to; i++){system("cls");
                gotoxy(30,9);cout<<"\t INGRESE EL N�MERO QUE DESEA A�ADIR:             "; gotoxy(69,9);cin>> dato;
                AGREGAR_NUM( p, dato );
                gotoxy(30,11);cout<<"\tN�MERO " << dato << " A�ADIDO A LA PILA CORRECTAMENTE\n\n";
                system("pause");
            	}
            break;
            
            
            case 2:system("cls");
				 if(p!=NULL){			
               	 x = QUITAR_NUM( p );
                 gotoxy(30,8);cout<<"****************************************************"<<endl;
                 gotoxy(30,9);cout<<"*\t\tN�MERO "<< x <<" BORRADO CORRECTAMENTE          *";
                 gotoxy(30,10);cout<<"****************************************************"<<endl;
             		}
				 else{
				 	gotoxy(30,8);cout<<"******************************************************************"<<endl;
                    gotoxy(30,9);cout<<"*LA PILA EST� VACIA POR FAVOR INSERTE UN DATO PARA PODER ELIMINAR*"<<endl;
                    gotoxy(30,10);cout<<"******************************************************************"<<endl;				 	
				 	 }
            break;
            case 3:system("cls");                                                           
                	if(p!=NULL){
				 	cout<<"\tMOSTRANDO PILA"<<endl;
                	MOSTRAR_PILA( p );
							}
                 else{
                 	gotoxy(30,8);cout<<"****************************************************"<<endl;
                    gotoxy(30,9);cout<<"*\t\t\tLA PILA ESTA VACIA               *"<<endl;
                    gotoxy(30,10);cout<<"****************************************************"<<endl;
                    }
            break;
         }
        cout<<endl<<endl;
        system("pause");  system("cls");
    }while(op!=4);
    return 0;}
