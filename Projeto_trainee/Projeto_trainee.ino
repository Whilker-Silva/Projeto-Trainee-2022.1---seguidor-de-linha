#include <Ultra.h> // incluindo biblioteca do sensor ultrassonico

//definindo pinos de controle dos motores
#define m_frente 6
#define m_tras 5
#define m_direita 10
#define m_esquerda 9

//definindo pinos de leituras do sensores de refletância
#define ep A1
#define em A5
#define c A4
#define dm A3
#define dp A2

//definindo pinos do sensor ultrassonico
#define trig 2
#define echo 3

#define led 13

//variáveis de leitura dos sensores de refletância
int l_ep = 0;
int l_em = 0;
int l_c = 0;
int l_dm = 0;
int l_dp = 0;

//variável de leitura dos sensor ultrassonico
byte l_ultra = 0;
byte parar = 0;

// define o valor mínimo para preto
const int preto = 300;

//define o objeto do ultrassônico (trigpin, echopin, dist max, tempo de atualização)
ultra_u ultra (trig, echo, 40, 10);

void setup() {

  //serial para obter os valores
  Serial.begin(9600);

  //define os pinos dos motore como porta de saída
  pinMode(m_frente, OUTPUT);
  pinMode(m_tras, OUTPUT);
  pinMode(m_direita, OUTPUT);
  pinMode(m_esquerda, OUTPUT);

  //define os pinos dos sensores como porta de entrada
  pinMode(ep, INPUT);
  pinMode(em, INPUT);
  pinMode(c, INPUT);
  pinMode(dm, INPUT);
  pinMode(dp, INPUT);

  //define o pino do led como saída
  pinMode(led, OUTPUT);

}

//
void loop() {

  OBSTACULO();//Função para verifacar e realizar desvio de obstaculos
  SEGUELINHA(65, 70);//função para seguimento de linha (potecia linha reta, potcencia em curva)

}
