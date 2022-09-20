//Função para parar os motores
void PARAR(int tempo) {

  analogWrite(m_frente, 0);
  analogWrite(m_tras, 0);
  analogWrite(m_direita, 0);
  analogWrite(m_esquerda, 0);
  delay(tempo);
}

//Função para andar para frente em linha reta
void FRENTE_RETO(int pot, int tempo) {

  pot = pot * 255 / 100;

  analogWrite(m_frente, pot);
  analogWrite(m_tras, 0);
  analogWrite(m_direita, 0);
  analogWrite(m_esquerda, 0);
  delay(tempo);
}

//Função para andar para frente fazendo curva do movimento que estava sendo realizado anteriormente
void FRENTE(int pot, int tempo) {

  pot = pot * 255 / 100;

  analogWrite(m_frente, pot);
  analogWrite(m_tras, 0);
  delay(tempo);
}


//Função para andar para tras em linha reta
void TRAS(int pot, int tempo) {

  pot = pot * 255 / 100;

  analogWrite(m_frente, 0);
  analogWrite(m_tras, pot);
  analogWrite(m_direita, 0);
  analogWrite(m_esquerda, 0);
  delay(tempo);
}

//Função para andar para frente em fazendo curva para direita
void DIREITA_FRENTE(int potM, int potC, int tempo) {

  potM = potM * 255 / 100;
  potC = potC * 255 / 100;

  analogWrite(m_frente, potM);
  analogWrite(m_tras, 0);
  analogWrite(m_direita, potC);
  analogWrite(m_esquerda, 0);
  delay(tempo);
}

//Função para andar para frente em fazendo curva para esquerda
void ESQUERDA_FRENTE(int potM, int potC, int tempo) {

  potM = potM * 255 / 100;
  potC = potC * 255 / 100;

  analogWrite(m_frente, potM);
  analogWrite(m_tras, 0);
  analogWrite(m_direita, 0);
  analogWrite(m_esquerda, potC);
  delay(tempo);
}

//Função para andar para tras em fazendo curva para direita
void DIREITA_TRAS(int potM, int potC, int tempo) {

  potM = potM * 255 / 100;
  potC = potC * 255 / 100;

  analogWrite(m_frente, 0);
  analogWrite(m_tras, potM);
  analogWrite(m_direita, potC);
  analogWrite(m_esquerda, 0);
  delay(tempo);
}

//Função para andar para tras em fazendo curva para esquerda
void ESQUERDA_TRAS(int potM, int potC, int tempo) {

  potM = potM * 255 / 100;
  potC = potC * 255 / 100;

  analogWrite(m_frente, 0);
  analogWrite(m_tras, potM);
  analogWrite(m_direita, 0);
  analogWrite(m_esquerda, potC);
  delay(tempo);
}
