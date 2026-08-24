import java.util.Random;
import java.util.Scanner;

class AlteracaoAleatoria {

    public static boolean Devoler(String ent) {
        return ent.length() == 3 && ent.charAt(0) == 'F' && ent.charAt(1) == 'I' && ent.charAt(2) == 'M';
    }

    public static final Random GERADOR = new Random();

    public static char charAleatorio() {
        return (char) ('a' + (Math.abs(GERADOR.nextInt()) % 26));
    }

    public static void Codificar(String ent){
        String resp = new String();
        char ori = charAleatorio();
        char sub = charAleatorio();
        System.out.println(ori + " " + sub);

       for(int i = 0; i < ent.length(); i++){
          if(ent.charAt(i) == ori){
            resp += sub;
          }else{
          resp += ent.charAt(i);
          }
       }

       System.out.println(resp);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String ent;
        ent = sc.nextLine();

        GERADOR.setSeed(4);

        while (!Devoler(ent)) {
              
            Codificar(ent);
            ent = sc.nextLine();
        }

        sc.close();
    }
}