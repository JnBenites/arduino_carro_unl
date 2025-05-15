## 1. Cargar el siguiente código en el Arduino:

```
#include <SoftwareSerial.h>  // Librería para comunicación serie en pines digitales

SoftwareSerial miBT(10, 11); // Pin 10 como RX, 11 como TX

void setup() {
  Serial.begin(9600);        // Comunicación con monitor serial
  Serial.println("Listo");   // Mensaje de inicio
  miBT.begin(38400);         // Velocidad por defecto del modo AT del HC-05
}

void loop() {
  if (miBT.available())             // Si el módulo envía algo
    Serial.write(miBT.read());      // Mostrarlo en el monitor serial

  if (Serial.available())           // Si el usuario escribe algo en el monitor
    miBT.write(Serial.read());      // Enviarlo al módulo Bluetooth
}
```

## 2. Conexiones del HC-05 al Arduino
```
| HC-05 | Arduino                                      |
| ----- | -------------------------------------------- |
| VCC   | 5V                                           |
| GND   | GND                                          |
| TXD   | Pin 11 (Arduino)                             |
| RXD   | Pin 10 (Arduino, con divisor de voltaje)\*\* |
```

##  3. Entrar en modo AT del HC-05
1. Apaga el módulo (desconectando VCC).
2. Presiona el botón del módulo HC-05 (si lo tiene).
3. Mantén presionado el botón y vuelve a conectar VCC.

## 4. Abrir el Monitor Serial en el IDE de Arduino
1. Velocidad: 9600 baudios
2. Ambos NL y CR activados

## 5. 5El LED debe parpadear lentamente (modo AT).
```
AT                → Debe responder OK
AT+ORGL           → Restaura valores de fábrica (OK)
AT+NAME?          → Consulta nombre actual (ej: +NAME:HC-05)
AT+NAME=ECOLOGICA → Cambia el nombre a ECOLOGICA (OK)
AT+NAME?          → Verifica el nuevo nombre (+NAME:ECOLOGICA)
```

