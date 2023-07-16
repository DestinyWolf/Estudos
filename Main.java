// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
import java.util.Scanner;
public class Main {

    public static void  getNotaAluno(int matricula, Alunos[] alunos){
        for (Alunos aluno: alunos
             ) {
            if(aluno.getMatricula() == matricula) {
                System.out.printf("O aluno de matriculo %d teve media: %.2f", matricula, aluno.getMedia());
            }
        }
    }

    public static void getFinalCountdown(int matricula, Alunos[] alunos) {
        for (Alunos aluno: alunos
        ) {
            if(aluno.getMatricula() == matricula) {
                System.out.printf("O aluno de matriculo %d precisa tirar %.2f na final para passar", matricula, aluno.getFinal());
            }
        }
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Alunos[] alunos = new Alunos[2];
        int count = 0;

        while(count < alunos.length) {
            System.out.println("Informe o nome do aluno:");
            String nome = input.nextLine();

            System.out.println("informe a matricula:");
            int matricula = input.nextInt();

            System.out.println("informe a nota da primeira prova");
            float nota = input.nextFloat();

            System.out.println("informe a nota do segundo trabalho:");
            float nota2 = input.nextFloat();

            System.out.println("Informe a nota do trabalho:");
            float trabalho = input.nextFloat();

            alunos[count].setNome(nome);
            alunos[count].setMatricula(matricula);
            alunos[count].setProva1(nota);
            alunos[count].setProva2(nota2);
            alunos[count].setTrabalho(trabalho);

            count++;
        }

        System.out.println("escolha uma das opções:\n1->ver a media de um aluno\n2->ver quanto um aluno precisa na final");
        int opc = input.nextInt();

        System.out.println("informe a matricula do aluno");
        int matricula = input.nextInt();

        switch (opc) {
            case 1 -> getNotaAluno(matricula, alunos);
            case 2 -> getFinalCountdown(matricula, alunos);
        }

    }

}