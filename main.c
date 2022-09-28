#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>

int factorial(int x); /// 1
int factorialNinja(int x); /// 1
int potencia(int num, int exp); /// 2
void arregloRecursivo(int arreglo[], int i, int posicionInicial); ///3
void arregloInvertidoRecursivo(int arreglo[], int i); ///4
int esCapicua(int arreglo[], int i, int j); ///5
int sumaRecursiva(int arreglo[], int i); ///6
int buscarMenor(int arreglo[],int i, int validos); ///7
void crearArchivo(); ///8
void mostrarArchivo(); ///8
int buscarMenorArchivo(); ///8
int leerArchivo(); ///8
int cantidadElementos(FILE* archivoF); ///9
void InvertirArchivo(int posInicial, int posFinal, FILE* archivoF); ///9
void mostrarArchivoInverso(FILE* archivoF,int validos); ///10
int crearArchivoChar(); ///11
void mostrarArchivoChar(FILE* archivoC, int validos); ///11
int buscarElemento(int arreglo[],int validos, int buscado, int i); ///12

int main(){
    setlocale(LC_ALL, "");
    printf(" ----------- \n");
    printf(" EJERCICIO 1 \n");
    printf(" ----------- \n");
    int numero=0;
    int exp=0;
    printf("\n INGRESE UN NUMERO PARA VER SU FACTORIAL: ");
    fflush(stdin);
    scanf("%d", &numero);
    printf("\n EL FACTORIAL DE %d ES: %d \n", numero,factorial(numero));
    printf("\n EL FACTORIAL MODO NINJA DE %d ES: %d \n", numero,factorialNinja(numero));

    printf(" ----------- \n");
    printf(" EJERCICIO 2 \n");
    printf(" ----------- \n");

    printf("\n INGRESE UN NUMERO PARA CALCULAR LA POTENCIA: ");
    fflush(stdin);
    scanf("%d", &numero);
    printf("\n INGRESE LA POTENCIA: ");
    fflush(stdin);
    scanf("%d", &exp);
    printf("\n EL NUMERO %d ELEVADO A LA %d ES: %d \n\n", numero,exp,potencia(numero, exp));

    printf(" ----------- \n");
    printf(" EJERCICIO 3 \n");
    printf(" ----------- \n");
    int validos=5;
    int arreglo[10]={1,2,3,4,5};
    printf(" ARREGLO\n\n");
    arregloRecursivo(arreglo,validos,0);
    printf("\n");
    printf("\n");

    printf(" ----------- \n");
    printf(" EJERCICIO 4 \n");
    printf(" ----------- \n");

    arregloInvertidoRecursivo(arreglo,validos);
    printf("\n");

    printf(" ----------- \n");
    printf(" EJERCICIO 5 \n");
    printf(" ----------- \n");
    if(esCapicua(arreglo,0,validos-1)==1){
       printf(" ARREGLO CAPICUA\n");
    }else{
        printf(" ARREGLO NO CAPICUA\n");
    }

    printf(" ----------- \n");
    printf(" EJERCICIO 6 \n");
    printf(" ----------- \n");
    printf(" LA SUMA DA %d \n", sumaRecursiva(arreglo,validos));

    printf(" ----------- \n");
    printf(" EJERCICIO 7 \n");
    printf(" ----------- \n");
    printf(" EL MENOR ELEMENTO DEL ARREGLO ES %d\n", buscarMenor(arreglo,0,validos));

    printf(" ----------- \n");
    printf(" EJERCICIO 8 \n");
    printf(" ----------- \n");
    crearArchivo();
    mostrarArchivo();
    printf(" EL MENOR ELEMENTO ES %d \n", leerArchivo());

    printf(" ----------- \n");
    printf(" EJERCICIO 9 \n");
    printf(" ----------- \n");
    FILE* archivo = fopen("enteros.bin", "r+b");
    if(archivo!=NULL){
        printf(" CANTIDAD DE ELEMENTOS: %d \n",cantidadElementos(archivo));
        InvertirArchivo(0, 4,archivo);
        mostrarArchivo();
        fclose(archivo);
    }

    printf(" ------------ \n");
    printf(" EJERCICIO 10 \n");
    printf(" ------------ \n");
    archivo = fopen("enteros.bin", "r+b");
    if(archivo!=NULL){
        mostrarArchivoInverso(archivo,4);
        fclose(archivo);
    }

    printf(" ------------ \n");
    printf(" EJERCICIO 11 \n");
    printf(" ------------ \n");
    archivo = fopen("char.bin", "r+b");
    if(archivo!=NULL){
        int validosC=crearArchivoChar();
        mostrarArchivoChar(archivo,validosC-1);
        fclose(archivo);
    }

    printf(" ------------ \n");
    printf(" EJERCICIO 12 \n");
    printf(" ------------ \n");
    //int validos=5;
    //int arreglo[10]={1,2,3,2,1};
    printf(" ARREGLO\n\n");
    arregloRecursivo(arreglo,validos,0);
    int buscado;
    printf("\n\n ELEMENTO A BUSCAR: ");
    fflush(stdin);
    scanf("%i", &buscado);
    int encontrado=buscarElemento(arreglo,validos,buscado,0);
    if(encontrado==1){
        printf("\n EL ELEMENTO %i SE ENCUENTRA EN EL ARREGLO\n",buscado);
    }else{
        printf("\n EL ELEMENTO %i NO SE ENCUENTRA EN EL ARREGLO\n",buscado);
    }

}

/// 1. Calcular el factorial de un numero en forma recursiva.
int factorial(int x){
    int rta;
    if(x==0){
        rta=1;
    }else{
        rta=x*factorial(x-1);
    }
    return rta;
}
int factorialNinja(int x){
    return (x==0) ? 1 : x*factorialNinja(x-1);
}

/// 2. Calcular la potencia de un numero en forma recursiva.
int potencia(int num, int exp){
    int rta;
    if(exp==0){
        rta=1;
    }else{
        rta=num*potencia(num,exp-1);
    }
    return rta;
}

/// 3. Recorrer un arreglo y mostrar sus elementos en forma recursiva.
void arregloRecursivo(int arreglo[], int i, int posicionInicial){
    if(posicionInicial != i){
        printf(" [%d]", arreglo[posicionInicial]);
        arregloRecursivo(arreglo, i, posicionInicial+1);
    }
}

/// 4 Recorrer un arreglo comenzando desde la posición 0 y mostrar sus elementos en
/// forma invertida (recursivo).
void arregloInvertidoRecursivo(int arreglo[], int i){
    if(i>0){
        printf(" [%d]", arreglo[i-1]);
        i--;
        arregloInvertidoRecursivo(arreglo, i);
    }
}

/// 5 Determinar en forma recursiva si un arreglo es capicúa.
int esCapicua(int arreglo[], int i, int j){
    int rta=1;
    if(i<j){
        if(arreglo[i]==arreglo[j]){
            rta=esCapicua(arreglo,i+1,j-1);
        }else{
            rta=0;
        }
    }
    return rta;
}

/// 6. Sumar en forma recursiva los elementos de un arreglo de enteros y retornar el total de la suma.
int sumaRecursiva(int arreglo[], int i){
    //return x==1 ? array[0] : array[x-1] + sumaRecursiva(array, x-1);
    int rta=0;
    if(i<0){
        rta;
    }else{
        rta=arreglo[i]+sumaRecursiva(arreglo,i-1);
    }
    return rta;
}

/// 7. Buscar el menor elemento de un arreglo en forma recursiva.
int buscarMenor(int arreglo[],int i,int validos){
    int rta;
    if(i==validos){
        rta=arreglo[validos-1];
    }else{
        rta=buscarMenor(arreglo,i+1,validos);
        if(rta>arreglo[i]){
            rta=arreglo[i];
        }
    }
    return rta;
}

///8. Buscar el menor elemento de un archivo de n�meros enteros de forma recursiva.
///(desde el mismo archivo)
void crearArchivo(){
    FILE* archivo = fopen("enteros.bin", "w+b");
    if (archivo != NULL){
        int arreglo[] = {60,90,100,33,250};
        fwrite(arreglo, sizeof(arreglo), 1, archivo);
        fclose(archivo);
    }
}
void mostrarArchivo(){
    FILE* archivo = fopen("enteros.bin","rb");
    printf("\n");
    if(archivo!=NULL){
        int contador=1;
        int elementos=0;
        while(fread(&elementos,sizeof(elementos),1,archivo)>0){
            printf(" ELEMENTO N %d: %d\n",contador,elementos);
            contador++;
        }
        fclose(archivo);
    }else{
        printf(" NO SE ENCUENTRA EL ARCHIVO\n");
    }
    printf("\n");
}
int buscarMenorArchivo(FILE* archivo, int menor){
    int nuevaLectura;
    if(fread(&nuevaLectura,sizeof(nuevaLectura),1,archivo)>0){
        if(nuevaLectura<menor){
            return buscarMenorArchivo(archivo,nuevaLectura);
        }else{
            return buscarMenorArchivo(archivo,menor);
        }
    }
    return menor;
}
int leerArchivo(){
    FILE* archivo = fopen("enteros.bin", "r+b");
    int menor;
    if (archivo != NULL){
        fread(&menor, sizeof(menor), 1, archivo);
        menor = buscarMenorArchivo(archivo, menor);
        fclose(archivo);
    }
    return menor;
}

///9. Invertir los elementos de un archivo de numeros enteros de forma recursiva. (si no te
/// sale, primero proba con invertir los elementos de un arreglo de int)
int cantidadElementos(FILE* archivoF){
    int cantidad;
    fseek(archivoF,0,SEEK_END);
    cantidad=ftell(archivoF)/sizeof(cantidad);

    return cantidad;
}
void InvertirArchivo(int posInicial, int posFinal, FILE* archivoF){
    int aux;
    int aux2;
    if(posInicial<=posFinal){
        fseek(archivoF, sizeof(int)*posInicial, SEEK_SET);
        fread(&aux, sizeof(aux), 1, archivoF);

        fseek(archivoF, sizeof(int)*posFinal, SEEK_SET);
        fread(&aux2, sizeof(aux2), 1, archivoF);

        fseek(archivoF, sizeof(int)*posInicial, SEEK_SET);
        fwrite(&aux2, sizeof(aux2), 1, archivoF);

        fseek(archivoF, sizeof(int)*posFinal, SEEK_SET);
        fwrite(&aux, sizeof(aux), 1, archivoF);

        InvertirArchivo(posInicial+1, posFinal-1, archivoF);
    }
}

///10. Recorrer un archivo y mostrar sus elementos en forma invertida de forma recursiva.
void mostrarArchivoInverso(FILE* archivoF,int validos){
    int elemento;
    if(validos >= 0){
        fseek(archivoF, sizeof(int)*(validos), SEEK_SET);
        fread(&elemento,sizeof(elemento),1,archivoF);
        printf(" ELEMENTO: %d\n",elemento);
        mostrarArchivoInverso(archivoF,validos-1);
    }
}

///11. Ingresar valores a una variable de tipo char (por teclado) y mostrarlo en el orden
///inverso (hasta ingresar un '*') de forma recursiva. NO usar arreglos.
int crearArchivoChar(){
    int cantidad=0;
    FILE* archivoC = fopen("char.bin", "w+b");
    if (archivoC != NULL){
        char letter;
        char opt;
        do{
            printf(" INGRESE UNA LETRA: ");
            fflush(stdin);
            scanf("%c", &letter);
            fwrite(&letter, sizeof(letter), 1, archivoC);
            cantidad++;
            printf("\n PRESIONE S PARA SEGUIR O * PARA SALIR: ");
            fflush(stdin);
            scanf("%c", &opt);
            printf("\n");
        }
        while(opt!='*');
        fclose(archivoC);
    }
    return cantidad;
}
void mostrarArchivoChar(FILE* archivoC, int validos){
    char elemento;
    if(validos>=0){
        fseek(archivoC, sizeof(char)*(validos), SEEK_SET);
        fread(&elemento,sizeof(elemento),1,archivoC);
        printf(" ELEMENTO: %c\n",elemento);
        mostrarArchivoChar(archivoC,validos-1);
    }
}

///12. Determinar si un arreglo contiene un determinado elemento de forma recursiva.
/// (Pueden intentarlo también con una función void)
int buscarElemento(int arreglo[],int validos, int buscado, int i){
    int encontrado=0;
    if(buscado==arreglo[i]){
        encontrado=1;
    }else{
        if(i<validos){
            encontrado=buscarElemento(arreglo,validos,buscado,i+1);
        }
    }
    return encontrado;
}
