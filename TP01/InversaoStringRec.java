import java.util.Scanner;

class InversaoStringRec {

    public static boolean devoLer(String ent) { //metodo para verificar se devo ler
        return ent.length() == 3 && ent.charAt(0) == 'F'
                && ent.charAt(1) == 'I' && ent.charAt(2) == 'M';
    }

    public static void inverter(String ent, char[] resp, int i, int j) { // metodo recursivo que inverte a string

        if (i < ent.length()) {

            resp[i] = ent.charAt(j);

            inverter(ent, resp, i + 1, j - 1);//chama recusivamente
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String ent = sc.nextLine();

        while (!devoLer(ent)) {

            char[] resp = new char[ent.length()]; // cria um array de char para escrever a palavra invertida 

            inverter(ent, resp, 0, ent.length() - 1);

            System.out.println(new String(resp)); // print transformando um array de char em string 

            ent = sc.nextLine();
        }

        sc.close();
    }
}
//Felipe de Faria Rios Coelho