// Pines de los motores
const int IN1 = 9;  // Motor izquierdo (IN1)
const int IN2 = 8;  // Motor izquierdo (IN2)
const int IN3 = 7;  // Motor derecho  (IN3)
const int IN4 = 6;  // Motor derecho  (IN4)

// Tiempos en milisegundos
const unsigned long TIEMPO_MOVIMIENTO = 500;  // adelante / atrás
const unsigned long TIEMPO_GIRO      = 100;  // giro izquierda / derecha

unsigned long tiempoInicio     = 0;
unsigned long duracionActual  = 0;
bool enMovimiento             = false;
char comandoActual            = '\0';

void setup() {
  Serial.begin(9600);  // Inicia comunicación Bluetooth

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  detenerMotores();
}

void loop() {
  // Si llega un comando y no está en movimiento
  if (Serial.available() && !enMovimiento) {
    comandoActual = Serial.read();
    iniciarMovimiento(comandoActual);
    tiempoInicio    = millis();
    enMovimiento    = true;
  }

  // Comprueba si ya pasó la duración configurada
  if (enMovimiento && millis() - tiempoInicio >= duracionActual) {
    detenerMotores();
    enMovimiento = false;
  }
}

// Inicia el movimiento según el comando y ajusta la duración
void iniciarMovimiento(char comando) {
  switch (comando) {
    case 'w':  // Adelante
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      duracionActual = TIEMPO_MOVIMIENTO;
      break;
    case 's':  // Atrás
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      duracionActual = TIEMPO_MOVIMIENTO;
      break;
    case 'a':  // Girar izquierda
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      duracionActual = TIEMPO_GIRO;
      break;
    case 'd':  // Girar derecha
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      duracionActual = TIEMPO_GIRO;
      break;
    default:
      detenerMotores();
      duracionActual = 0;
      break;
  }
}

// Detiene todos los motores
void detenerMotores() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
