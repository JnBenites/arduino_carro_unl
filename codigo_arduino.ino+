// Pines de los motores
const int IN1 = 9;  // Motor izquierdo (IN1)
const int IN2 = 8;  // Motor izquierdo (IN2)
const int IN3 = 7;  // Motor derecho (IN3)
const int IN4 = 6;  // Motor derecho (IN4)

// Tiempo de movimiento en milisegundos
const int TIEMPO_MOVIMIENTO = 900;

unsigned long tiempoInicio = 0;
bool enMovimiento = false;
char comandoActual = '\0';

void setup() {
  Serial.begin(9600);  // Inicia comunicación Bluetooth

  // Configura pines de los motores
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  detenerMotores();  // Inicia con motores detenidos
}

void loop() {
  // Si llega un comando y no está en movimiento
  if (Serial.available() && !enMovimiento) {
    comandoActual = Serial.read();
    iniciarMovimiento(comandoActual);
    tiempoInicio = millis();
    enMovimiento = true;
  }

  // Si ya pasó 1 segundo desde que se inició el movimiento
  if (enMovimiento && millis() - tiempoInicio >= TIEMPO_MOVIMIENTO) {
    detenerMotores();
    enMovimiento = false;
  }
}

// Inicia el movimiento según el comando recibido
void iniciarMovimiento(char comando) {
  switch (comando) {
    case 'y':  // Adelante
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      break;
    case 's':  // Atrás
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      break;
    case 'a':  // Girar izquierda
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      break;
    case 'd':  // Girar derecha
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      break;
    default:
      detenerMotores();  // En caso de comando desconocido
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