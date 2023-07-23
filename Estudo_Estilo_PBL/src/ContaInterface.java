import java.util.Scanner;
public class ContaInterface {

    private int opc;
    private Scanner input = new Scanner(System.in);

    public ContaInterface() {

    }

    public void menu(Conta conta){
        do {
            System.out.printf("1 -> Depositar valor\n2 -> Sacar valor\n3 -> Conferir saldo\n4 -> Sair\nOpção: ");
            this.opc = input.nextInt();

            switch (this.opc) {
                case 1:
                    System.out.printf("Informe o valor que deseja depositar: ");
                    double valor = input.nextDouble();
                    System.out.println();
                    System.out.println();
                    conta.deposito(valor);
                    break;
                case 2:
                    System.out.printf("Informe o valor que deseja sacar: ");
                    valor = input.nextDouble();
                    System.out.println();
                    System.out.println();
                    conta.sacar(valor);
                    break;
                case 3:
                    double saldo = conta.getSaldo();
                    System.out.printf("O seu saldo é: %.2f\n", saldo);
                    break;
                case 4: System.out.println("Obrigado pela utilização");
                    break;

                default: System.out.println("Opção não disponivel");

            }
        } while(this.opc != 4);
    }

}
