public class ej5bottomup {

    //copio los valores de arr1 en arr2
    static void copiarArreglo(Boolean[] arr1, Boolean[] arr2){
        for(int i=0; i<arr1.length ;i++)
            arr2[i]= arr1[i].booleanValue();
    }

    static boolean subset_sum(int[] c, int k){
        int n= c.length;

        //primera version botton up

        /* 

        Boolean[][] matriz = new Boolean[n+1][k+1];


        //inicializo la matriz
        for(int j=0; j<=k ;j++)
            matriz[0][j]= j==0;

        for(int i=1; i<=n ;i++)
            for(int j=0; j<=k ;j++)
                matriz[i][j] = matriz[i-1][j] || ( j-c[i-1]>=0 &&  matriz[i-1][j-c[i-1]]);
        
        return matriz[n][k];
        */

        //segunda version botton up utilizando menos memoria
        Boolean[] matrizAnterior = new Boolean[k+1];
        
        //inicializo el arreglo
        for(int j=0; j<=k ;j++)
            matrizAnterior[j]= j==0;

        Boolean[] matrizActual = new Boolean[k+1];

        for(int i=1; i<=n ;i++){
            for(int j=0; j<=k ;j++){
                matrizActual[j] = matrizAnterior[j] || ( j-c[i-1]>=0 &&  matrizAnterior[j-c[i-1]]);
            }
            copiarArreglo(matrizActual, matrizAnterior);
        }
        return matrizActual[k];


    }


    public static void main(String[] args) {


        int k= 24;
        int[] c= {6,12,6};
        int n = c.length;

        boolean suman = subset_sum(c, k);

        System.out.print("Hay subconjutos que sumen?: ");
        System.out.println(suman);
    }
}  