import java.util.Scanner;

class Main {
   public static void main(String[] args) throws Exception {
   
      Scanner sc = new Scanner(System.in);
   
      String point = sc.nextLine();
      String[] pointarray = point.split(" ");
      int total = Integer.parseInt(pointarray[0]);
      int cnt = Integer.parseInt(pointarray[1]);
   
      String num = sc.nextLine();
      String[] numarray = num.split(" ");
      double[] numint = new double[numarray.length];
      for(int i = 0; i< numarray.length; i++) {
         numint[i] = Double.parseDouble(numarray[i]);
      }
      double result = 10000.0;
      
      for(int i = 0; i + cnt < total; i++) {
         for(int k = cnt; i + k < total; k++) {
            double avgtot = 0.0;
            for(int j = i; j < i + k; j++) {
               avgtot += numint[j];
            }
            double avg = avgtot/k;
            
            double tot2 = 0.0;
            for(int j = i ; j < i + k; j++) {
               tot2 += (numint[j] - avg) * (numint[j] - avg);
            }
            double tot3 = tot2 / k;
            if(result > tot3) {
               result = tot3;
            }
         }
      }
      double real = Math.sqrt(result);
      System.out.println(Double.parseDouble(String.format("%.11f",real)));
   }
}