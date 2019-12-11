#include <iostream>
#include <windows.h>
//AUTOR: FRAN ESPINO MOSTACERO
//EXPERIENCIA CURRICULAR: ALGORITMOS Y COMPLEJIDAD
//FECHA ENTREGA: 26/11/19

using namespace std;


void mochilaDinamica(){
int n,W;
 cout<<"Ingrese la cantidad de objetos: ";
 cin>>n;
 cout<<"Ingrese el peso maximo: ";
 cin>>W;
 n=n+1;
 W=W+1;
 int V[n][W];
 int peso[n+1];
 int beneficio[n+1];
 peso[0]=0;
 beneficio[0]=0;
cout<<"\n\nINGRESAR PESOS: "<<endl;
 for(int q=1;q<n;++q){

 	cout<<"Ingresar peso para peso["<<q<<"] : ";
 	cin>>peso[q];
 }
 cout<<"\n\nINGRESAR BENEFICION: "<<endl;
  for(int q=1;q<n;++q){
 	cout<<"Ingrese beneficio para beneficio["<<q<<"] : ";
 	cin>>beneficio[q];
 }

 for(int a=0;a<W;a++){
 	V[0][a]=0;
 	if(a<n){
 		V[a][0]=0;
	 }
 }

 for(int i=1;i<=n-1;++i){

    for(int j=1;j<=W-1;++j){

    	if(j-peso[i]<0){
    			V[i][j]=V[i-1][j];
		}
		else{
        V[i][j]= max(V[i-1][j], V[i-1][j-peso[i]] + beneficio[i]);
    	}
    }
 }
 cout<<"\n";
 int may=-1,M=0;
 cout<<"\n\nVALORES DE LA MATRIZ: "<<endl;
 for(int i=0;i<n;++i){
    for(int j=0;j<W;++j){
    	cout<<V[i][j]<<" ";
    	if(V[i][j]>may){
    		may=V[i][j];
    		M=V[i][j];
		}

    }
    cout<<"\n";
}
cout<<"\n";
cout<<"El mayor beneficio es: "<<M<<endl;

}




void Menu(){
    int op=0;
    do{
            cout<<"\n\t\t\t\t*******************************************"<<endl;
            cout<<"\t\t\t\t*\t\tMENU PRINCIPAL            *"<<endl;
            cout<<"\t\t\t\t*                                         *"<<endl;
            cout<<"\t\t\t\t* 1-Informacion                           *"<<endl;
            cout<<"\t\t\t\t* 2-Instrucciones                         *"<<endl;
            cout<<"\t\t\t\t* 3-Problema de la mochila                *"<<endl;
            cout<<"\t\t\t\t* 4-Exit                                  *"<<endl;
            cout<<"\t\t\t\t*                                         *"<<endl;
            cout<<"\t\t\t\t*******************************************"<<endl;
            cout<<"Ingrese una opcion: ";
            cin>>op;

    switch(op){
        case 1: MessageBox(HWND_DESKTOP,"ESTE PROGRAMA MUESTRA EL FUNCIONAMIENTO DE UNO DE LOS PARADIGMAS DE ALGORITMOS LLAMADO PROGRAMACION DINAMICA, QUE ES UNO DE LOS PARADIGMAS MAS OPTIMOS PARA LA SOLUCION DE PROBLEMAS, EN ESTE CASO EL PROGRAMA REALIZARA EL PROBLEMA NP DE KNAPSACK MAS CONOCIDO COMO 'EL PROBLEMA DE LA MOCHILA'.\n\nDocente: Jose Rodriguez Melquiades\n\nAutor: Fran Espino Mostacero","INFORMACION DEL PROGRAMA",MB_ICONASTERISK);
                system("cls");
                break;
        case 2: MessageBox(HWND_DESKTOP,"\n\n1-En el menu donde se encuentra en la opcion 3 podra realizar el problema de la mochila.\n\n\n2-Si desea como realizar este algorimo manualmente valla al siguiente enlace: https://informaticauntvallejequetepeque.000webhostapp.com/\n\n\n3-Busque el apartado de proyectos y ubiquese en 'Knapsack dinamico'.","INSTRUCCIONES",MB_SETFOREGROUND);
                system("cls");
                break;
        case 3: system("cls");
                cout<<"\t\t\t\t\tPROBLEMA DE LA MOCHILA\n-PARADIGMA DE ALGORITMO DINAMICO."<<endl<<endl;
                mochilaDinamica();
                cout<<"\n"<<endl;
                system("pause");
                system("cls");
                break;
        case 4: MessageBox(HWND_DESKTOP,"Confirme para salir del programa","Desea salir del programa? ",MB_YESNOCANCEL);
                if(MB_YESNOCANCEL == IDYES){
                    exit(0);
                }
    }

    }while(op!=4);



}



int WINAPI WinMain(HINSTANCE ins,HINSTANCE ins2,LPSTR cmd, int estado){
    system("color 1E");
    Menu();

}
