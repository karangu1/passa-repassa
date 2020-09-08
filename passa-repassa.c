struct player{
    const int pino_botao;
    const int pino_led;
    boolean jogador_en;
};


void setup(){
    player azul     = { 1, 1, 1};
    player vermelho = { 1, 1, 1};
    player amarelo  = { 1, 1, 1};
    player verde    = { 1, 1, 1};
    const int botao_rs = 1;
    bool flat_pressed_btn = false;

    participantes_init(azul);
    participantes_init(vermelho);
    participantes_init(verde);
    participantes_init(amarelo);
}

void loop(){

}

void venceJogo(player vencedor){
    int tempo_ciclo = millis();
    int indice = 0;
    if (millis() - tempo_ciclo < 100) indice = 0;
    int intervalos[] = {200, 200, 200, 100, 100, 100, 50, 50};
        
}
void participantes_init(struct player jogador){
    pinMode(jogador.pino_led, OUTPUT);
    pinMode(jogador.pino_botao, INPUT);
}
void selecionaParticipantes(){

}
