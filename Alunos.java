public class Alunos {
    private String nome;
    private int matricula;
    private float prova1;
    private float prova2;
    private float trabalho;

    private double media;
    public Alunos(){
        setProva1(-1);
        setProva2(-1);
        setTrabalho(-1);
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getNome() {
        return nome;
    }

    public int getMatricula() {
        return matricula;
    }

    public void setMatricula(int matricula) {
        this.matricula = matricula;
    }

    public float getProva1() {
        return prova1;
    }

    public float getProva2() {
        return prova2;
    }

    public float getTrabalho() {
        return trabalho;
    }

    public void setProva1(float prova1) {
        this.prova1 = prova1;
    }

    public void setProva2(float prova2) {
        this.prova2 = prova2;
    }

    public void setTrabalho(float trabalho) {
        this.trabalho = trabalho;
    }

    public double getMedia() {

        if (this.prova1 > -1 && this.prova2 > -1 && this.trabalho > -1) {
            this.media = ((this.prova1 * 2.5) + (this.prova2 * 2.5) + (this.trabalho * 2.0))/7.0;

            return this.media;
        }
        else {
            return -1;
        }
    }

    public double getFinal() {
        if (this.media > 7.0) {
            return 0;
        }
        else {
            return (5 - (this.media*0.6))/0.4;
        }
    }
}
