import java.util.Scanner;

class Is {

    public static boolean DevoLer(String ent) {
        return ent.length() == 3 && ent.charAt(0) == 'F' && ent.charAt(1) == 'I' && ent.charAt(2) == 'M';
    }

    public static boolean SoVogais(String ent) {
        boolean resp = true;
        int ver = 0;
        String vog = "aeiouAEIOU";

        for (int i = 0; i < ent.length(); i++) {
            char tmp = ent.charAt(i);
            for (int j = 0; j < vog.length(); j++) {
                if (tmp == vog.charAt(j)) {
                    ver++;
                    j = vog.length();
                }
            }
        }
        if (ver != ent.length()) {
            resp = false;
        }

        return resp;
    }

    public static boolean SoConsoantes(String ent) {
        boolean resp = true;
        int ver = 0;
        String conso = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";

        for (int i = 0; i < ent.length(); i++) {
            char tmp = ent.charAt(i);
            for (int j = 0; j < conso.length(); j++) {
                if (tmp == conso.charAt(j)) {
                    ver++;
                    j = conso.length();
                }
            }
        }
        if (ver != ent.length()) {
            resp = false;
        }

        return resp;
    }

    public static boolean SoInt(String ent) {
        boolean resp = true;
        int ver = 0;
        String dig = "0123456789";

        for (int i = 0; i < ent.length(); i++) {
            char tmp = ent.charAt(i);
            boolean valido = false;
            for (int j = 0; j < dig.length(); j++) {
                if (tmp == dig.charAt(j)) {
                    j = dig.length();
                    valido = true;
                }
            }
            if (!valido && i == 0 && (tmp == '-' || tmp == '+')) {
                valido = true;
            }
            if (valido) {
                ver++;
            }

        }
        if (ver != ent.length()) {
            resp = false;
        }

        return resp;
    }

    public static boolean SoReal(String ent) {
        boolean resp = true;
        int ver = 0 , pontos = 0;
        String dig = "0123456789";

        for (int i = 0; i < ent.length(); i++) {
            char tmp = ent.charAt(i);
            boolean valido = false;
            for (int j = 0; j < dig.length(); j++) {
                if (tmp == dig.charAt(j)) {
                    j = dig.length();
                    valido = true;
                }
            }
            if (!valido && i == 0 && (tmp == '-' || tmp == '+')) {
                valido = true;
            }
            if (!valido && (tmp == '.' || tmp == ',') && pontos == 0) {
                valido = true;
                pontos++;
            }
            if (valido) {
                ver++;
            }

        }

        if (ver != ent.length()) {
            resp = false;
        }

        return resp;
    }

    public static void Printresultados(boolean[] resp) {

       if(resp[0] == true){
        System.out.print("SIM");
       }else{
         System.out.print("NAO");
       }

        System.out.print(" ");

        if(resp[1] == true){
        System.out.print("SIM");
       }else{
         System.out.print("NAO");
       }

        System.out.print(" ");

        if(resp[2] == true){
        System.out.print("SIM");
       }else{
         System.out.print("NAO");
       }

        System.out.print(" ");

        if(resp[3] == true){
        System.out.print("SIM");
       }else{
         System.out.print("NAO");
       }
        System.out.println();

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String ent = sc.nextLine();

        while (!DevoLer(ent)) {
            boolean[] resp = new boolean[4];

            resp[0] = SoVogais(ent);
            resp[1] = SoConsoantes(ent);
            resp[2] = SoInt(ent);
            resp[3] = SoReal(ent);

            Printresultados(resp);
            ent = sc.nextLine();
        }

        sc.close();
    }
}
