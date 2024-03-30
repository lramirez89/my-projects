public class ej5 {

    static boolean subset_sum(Boolean[][] matriz, int[] c, int i, int j){
        if(j<0) return false;
        if(i==0) return (j==0);
        
        if(matriz[i][j]== null)
            matriz[i][j]= subset_sum(matriz, c, i-1, j) || subset_sum(matriz, c, i-1, j-c[i-1]);
        
        return matriz[i][j];
    }


    public static void main(String[] args) {


        int k= 24;
        int[] c= {6,12,6};
        int n = c.length;
    
        Boolean[][] matriz= new Boolean[n+1][k+1];
        for(int i=0; i<n+1 ;i++)
            for(int j=0; j<k+1  ;j++)
                matriz[i][j] = null;

        boolean suman = subset_sum(matriz, c, c.length, k);

        System.out.print("Hay subconjutos que sumen?: ");
        System.out.println(suman);
    }
}  