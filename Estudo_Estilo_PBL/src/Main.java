public class Main {
    public static void main(String[] args) {
        Conta conta = new Conta(123456789);
        ContaInterface contaInterface = new ContaInterface();

        contaInterface.menu(conta);
    }
}