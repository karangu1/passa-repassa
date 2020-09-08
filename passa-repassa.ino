typedef struct{
    const int pino_botao;
    const int pino_led;
    boolean jogador_en;
} player;


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
    pinMode(botao_rs, INPUT);
}

void loop(){
// comparar com o que ja tem escrito
// TODO 
// [ ] piscar leds
// [ ] selecionar  jogadores 
// [ ] 
}

void venceJogo(player vencedor){
    int tempo_ciclo = millis();
    int indice = 0;
    if (millis() - tempo_ciclo < 100) indice = 0;
    int intervalos[] = {200, 200, 200, 100, 100, 100, 50, 50};
        
}
void participantes_init(player jogador){
    pinMode(jogador.pino_led, OUTPUT);
    pinMode(jogador.pino_botao, INPUT);
    jogador.jogador_en = 1;
}
void selecionaParticipantes(){
    digitalWrite(azul.pino_led, !digitalRead(azul.pino_botao));
    digitalWrite(vermelho.pino_led, !digitalRead(vermelho.pino_botao));
    digitalWrite(verde.pino_led, !digitalRead(verde.pino_botao));
    digitalWrite(amarelo.pino_led, !digitalRead(amarelo.pino_botao));

    if (digitalRead(azul.pino_botao) == LOW) azul.jogador_en = true;
    else azul.jogador_en = false;
    if (digitalRead(vermelho.pino_botao) == LOW) vermelho.jogador_en = true; 
    else vermelho.jogador_en = false;
    if (digitalRead(amarelo.pino_botao) == LOW) amarelo.jogador_en = true;
    else amarelo.jogador_en = false;
    if (digitalRead(verde.pino_botao) == LOW) verde.jogador_en = true;
    else verde.jogador_en = false;
}
