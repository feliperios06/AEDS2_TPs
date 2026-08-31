import java.util.Scanner;

class ValidacaoSenha{

   public static boolean Devoler(String ent){ // funcao para ver se tem q continuar lendo 
        return ent.length() == 3 && ent.charAt(0) == 'F' && ent.charAt(1) == 'I' && ent.charAt(2) == 'M';
    }

    public static void valida(String ent){ //verifica as condiçoes e depois disso printa a resposta
      boolean temMin = false ;
      boolean temMa = false;
      boolean temNum = false;
      boolean temCar = false;

      if(ent.length() >= 8){ // so vai entrar no loop se tiver o minimo de caracteres
        for(int i = 0; i < ent.length(); i++){
            if(ent.charAt(i) >= 'A' && ent.charAt(i) <= 'Z'){
                temMa = true;
            }else if(ent.charAt(i) >= 'a' && ent.charAt(i) <= 'z'){
                temMin = true;
            }else if(ent.charAt(i) >= '0' && ent.charAt(i) <= '9'){
                temNum = true;
            }else{
                temCar = true;
            }
        }
      }

      if(temMa && temMin && temNum && temCar){
        System.out.println("SIM");
      }else{
        System.out.println("NAO");
      }

    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        String ent = sc.nextLine();

        while(!Devoler(ent)){
          
            valida(ent);
            ent = sc.nextLine();
        }
         

        sc.close();
    }
}
//Felipe de Faria Rios Coelho