typedef struct{
    int pino_botao;
    int pino_led;
    boolean jogador_en;
} jog_participante;

const int botao_rs = 1;
bool flag_pressed_btn = false;
int timer = 0;
int rs_clk = 0;
jog_participante az     = { 1, 1, 1};
jog_participante vm     = { 1, 1, 1};
jog_participante am     = { 1, 1, 1};
jog_participante vd     = { 1, 1, 1};


void setup(){

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
        if(digitalRead(botao_rs) == LOW){
            if (millis() - rs_clk > 3000) selecionaParticipantes();
            else flag_pressed_btn = 0;
        } else rs_clk = millis();
    }               
// comparar com o que ja tem escrito
// TODO 
// [ ] piscar leds
// [ ] selecionar  jogadores 
// [ ] 
}

void venceJogo(int tempo_jogo){
    int indice = 0;
    int periodo_comutacoes[] = {100, 50, 20, 0};
    jog_participante vencedor = {0, 0, 0}; 
    if(digitalRead(az.pino_led) == HIGH) vencedor = az;
    if(digitalRead(vm.pino_led) == HIGH) vencedor = vm;
    if(digitalRead(am.pino_led) == HIGH) vencedor = am;
    if(digitalRead(vd.pino_led) == HIGH) vencedor = vd;
    if(millis() - tempo_jogo < 400) indice = 0;
    else if (millis() - tempo_jogo < 600) indice = 1;
    else if (millis() - tempo_jogo < 800) indice = 2;
    else indice = 3;
    if((millis() - tempo_jogo) % periodo_comutacoes[indice]){
      digitalWrite(vencedor.pino_led, !digitalRead(vencedor.pino_led));
      if(indice == 3) digitalWrite(vencedor.pino_led, HIGH);
    }
        
}
void participantes_init(jog_participante jogador){
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
