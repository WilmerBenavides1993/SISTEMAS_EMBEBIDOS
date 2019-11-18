/*                        UNIVERSIDAD TECNICA DEL NORTE
 *                            FICA-CIERCOM
 *                            SISTEMAS EMBEBIDOS
 *              BENAVIDES WILMER
 *              18-11-2019
 * 
 */
 #include "matriz_entrenamiento.h"
float datos_prueba[5] = {5 , 2 , 3.5 , 1, 2};

int respuesta;
void setup() {
  Serial.begin(9600);
}

void loop() {
  cnn(3, 5, 120);
}
void cnn (int etiquetas , int tam_col, int tam_fil) {
  int i;
  int j;
  int col;
  int fil;
  float sumatoria = 0; // sumatoria de la elevación al cuadrado de cada col
  float distancia = 0; // raiz de sumatoria
  int matriz_etiq[1][etiquetas];
  /*centroide -> promedio
                 promedio por columna y por etiqueta
                 almaceno los vectores
                 knn entre vectores y matriz entrenaminto

  */
  float centroides[etiquetas][tam_col];
  float centroid = 0;
  int cont;
  int dist_menor = 200;
  for (i = 0; i < etiquetas; i++) {
    for (j = 0; j < tam_col; j++) {
      centroides[i][j] = 0;

    }
  }


  centroid = 0;

  for (int l = 0; l < etiquetas; l++) {
    for (i = 0; i < tam_col - 1; i++) { // col-1 porque el ultimo es de la etiqute
      for (j = (40 * l); j < 40 * (l + 1); j++) {
        centroid = centroid + matriz[j][i];
      }
      centroides[l][i] = centroid / 40;
      centroid = 0;
    }
  }
  for (int fil = 0; fil < tam_fil; fil++) {// movernos en filas de la matriz entrenamiento
    for (int fil_centroides = 0; fil_centroides < 3; fil_centroides++) {// para movernos en la fila de centroides 
      for (int col = 0; col < 4; col++) {// para movernos en columna de matriz y centride
        distancia = distancia + pow(matriz[fil][col] - centroides[fil_centroides][col], 2);// distancia entre la mtriz y los centroides
        cont = cont + 1;// controlar el ploteo de matriz
        if (cont < 5) {// condicion de la matriz
          Serial.print(matriz[fil][col]);// imprimir la matriz
          delay(200);// tiempo 
          Serial.print("|");// separador

        }
      }

      sumatoria = sqrt(distancia);// la riaz de la distanta
      distancia = 0;// encera
      Serial.print(sumatoria);// imprimir la raiz de la disntacia
      delay(200);
      Serial.print("|");
    }    Serial.println(' ');// salto de linea
    cont = 0;
  }
}




// correr knn con los 120 datos
// si clasifican bien al drenaje y
