package java;

import java.util.LinkedList;

public class ListaEncadeada {
    public static void main(String[] args) {
        // Criando uma lista encadeada
        LinkedList<Integer> listaEncadeada = new LinkedList<>();

        // Adicionando elementos à lista
        listaEncadeada.add(10);
        listaEncadeada.add(20);
        listaEncadeada.add(30);
        listaEncadeada.add(40);

        // Exibindo os elementos da lista
        System.out.println("Elementos da lista:");
        for (Integer elemento : listaEncadeada) {
            System.out.println(elemento);
        }

        // Adicionando um elemento em uma posição específica
        listaEncadeada.add(1, 15);

        // Exibindo os elementos atualizados da lista
        System.out.println("\nElementos da lista após adicionar 15 na posição 1:");
        for (Integer elemento : listaEncadeada) {
            System.out.println(elemento);
        }

        // Removendo um elemento da lista
        listaEncadeada.remove(2);

        // Exibindo os elementos atualizados da lista
        System.out.println("\nElementos da lista após remover o elemento na posição 2:");
        for (Integer elemento : listaEncadeada) {
            System.out.println(elemento);
        }
    }

}
