public class Mergesort {
    
    public void concatena(int vetor[], int inicio, int fim) {
        int meio = (fim+inicio) / 2;
        int i = inicio;
        int j = meio+1;
        int k = 0;
        
        int aux[] = new int[fim - inicio +1];

        while(i <= meio && j <= fim){
            if(vetor[i] <= vetor[j]){
                aux[k++] = vetor[i++]; 
            } else{
                aux[k++] = vetor[j++];
            }
        }
        
        while(i <= meio){
            aux[k++] = vetor[i++]; 
        }
        while(j <= fim){
            aux[k++] = vetor[j++]; 
        }

        System.arraycopy(aux, 0, vetor, inicio, fim - inicio + 1 );
    }

    public void mergeSort(int vetor[], int inicio, int fim){
        if ( inicio == fim){
            return;
        }
        int meio = (fim+inicio) / 2;
        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio+1, fim);
        concatena(vetor, inicio, fim);

    }

    // public static void main(String[] args){
    //     int[] vetor = {12, 4, 20, 22, -7, 2, 1, 25, 3};   
    //     Mergesort merge = new Mergesort();
    //     merge.mergeSort(vetor, 0, vetor.length -1);
        

    //     for(int a = 0; a < vetor.length; a++){
    //         System.out.println(vetor[a]);

    //     }
    //     System.out.println("Vc conseguiu vagabunda!!");
    // }

}
