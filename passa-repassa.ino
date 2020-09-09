typedef struct{
    const int pino_botao;
    const int pino_led;
    boolean jogador_en;
} player;


void setup(){
    player az     = { 1, 1, 1};
    player vm     = { 1, 1, 1};
    player am     = { 1, 1, 1};
    player vd     = { 1, 1, 1};
    const int botao_rs = 1;
    bool flag_pressed_btn = false;
    int timer = 0;

    participantes_init(az);
    participantes_init(vm);
    participantes_init(vd);
    participantes_init(am);
    pinMode(botao_rs, INPUT);
}

void loop(){
    if (!flag_pressed_btn){
        timer = millis();
        if (digitalRead(az.pino_botao) == LOW){ 
            flag_pressed_btn = 1;
            digitalWrite(az.pino_led, HIGH);
        }else if (digitalRead(vm.pino_botao) == LOW){ 
            flag_pressed_btn = 1;
            digitalWrite(vm.pino_led, HIGH);
        }else if (digitalRead(vd.pino_botao) == LOW){ 
            flag_pressed_btn = 1;
            digitalWrite(vd.pino_led, HIGH);
        }else if (digitalRead(am.pino_botao) == LOW){ 
            flag_pressed_btn = 1;
            digitalWrite(am.pino_led, HIGH);
        }
    }else{
        venceJogo(timer);
        if(digitalRead(botao_rs) == LOW){};
    }               
// comparar com o que ja tem escrito
// TODO 
// [ ] piscar leds
// [ ] selecionar  jogadores 
// [ ] 
}

void venceJogo(int tempo_jogo){
    int indice = 0;
    if (millis() - tempo_jogo < 400) indice = 0;
    else if (millis() - tempo_jogo < 600) indice = 1;
    else if (millis() - tempo_jogo < 800) indice = 2;
    else indice = 3;
        
}
void participantes_init(player jogador){
    pinMode(jogador.pino_led, OUTPUT);
    pinMode(jogador.pino_botao, INPUT);
    jogador.jogador_en = 1;
}
void selecionaParticipantes(){
    digitalWrite(az.pino_led, !digitalRead(az.pino_botao));
    digitalWrite(vm.pino_led, !digitalRead(vm.pino_botao));
    digitalWrite(vd.pino_led, !digitalRead(vd.pino_botao));
    digitalWrite(am.pino_led, !digitalRead(am.pino_botao));

    if (digitalRead(az.pino_botao) == LOW) az.jogador_en = true;
    else az.jogador_en = false;
    if (digitalRead(vm.pino_botao) == LOW) vm.jogador_en = true; 
    else vm.jogador_en = false;
    if (digitalRead(am.pino_botao) == LOW) am.jogador_en = true;
    else am.jogador_en = false;
    if (digitalRead(vd.pino_botao) == LOW) vd.jogador_en = true;
    else vd.jogador_en = false;
}
