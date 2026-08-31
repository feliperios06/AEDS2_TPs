import java.util.Scanner;

class SomaDigitoRec{

    static int resp = 0; // esta declarada aqui para q a funçao soma possa ser void e o main e ela possam
                         // pegar seus valores

    public static void soma(String num, int i) { // funçao recusiva para somar os numeros

        if (i < num.length()) {

            resp += (num.charAt(i) - '0');
            soma(num, i + 1);

        }

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String num;
        

        while (sc.hasNext()) {

            num = sc.nextLine();

            resp = 0; // sempre zera antes de cada chamada

            soma(num, 0);
            
            System.out.println(resp);

        }

        sc.close();
    }
}
//Felipe de Faria Rios Coelho
