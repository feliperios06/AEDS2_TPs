import java.util.Scanner;

class CiframentoCezar {

    static public boolean Devoler(String ent) {
        return ent.length() == 3 && ent.charAt(0) == 'F' && ent.charAt(1) == 'I' && ent.charAt(2) == 'M';
    }

    static public void cifra(String ent) {

        String resp = new String();

        for (int i = 0; i < ent.length(); i++) {

            resp += (char)(ent.charAt(i) + 3);

        }

        System.out.println(resp);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String ent;
        ent = sc.nextLine();

        while (!Devoler(ent)) {

            cifra(ent);

            ent = sc.nextLine();
        }

        sc.close();
    }

}
//Felipe de Faria Rios Coelho