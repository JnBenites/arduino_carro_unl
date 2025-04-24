## Control de Motores Bluetooth con Arduino
Control de dos motores DC mediante comandos Bluetooth usando un módulo HC-05/06. El robot puede moverse adelante, atrás y girar en ambas direcciones durante 1 segundo por comando.

# Diagrama de Conexiones

### Motores
```
Motor Izquierdo:
- Terminal 1 → IN1 (Pin 9)
- Terminal 2 → IN2 (Pin 8)

Motor Derecho:
- Terminal 1 → IN3 (Pin 7)
- Terminal 2 → IN4 (Pin 6)
```
### Módulo Bluetooth:
```
- VCC → 5V Arduino
- GND → GND Arduino
- TX → RX Arduino (Pin 0)
- RX → TX Arduino (Pin 1)
```

<a href="https://github.com/JnBenites/arduino_carro_unl" target="_blank">Imagenes de referencia para armado</a>

### Puente H
```
Controlador L298N:
- +12V → Batería 9V+
- GND → Batería 9V- y GND Arduino
- OUT1-OUT2 → Motor Izquierdo
- OUT3-OUT4 → Motor Derecho
```

## Conexiones Eléctricas
```
Conectar motores al L298N:
Motor izquierdo a OUT1 y OUT2
Motor derecho a OUT3 y OUT4
```

## Conectar L298N a Arduino:
```
IN1 → Pin 9
IN2 → Pin 8
IN3 → Pin 7
IN4 → Pin 6
```
## Comandos de movimientos (deben ser definidos por los creadores del apk)
```
y → Adelante
s → Atrás
a → Izquierda
d → Derecha
```

# Diagrama de Flujo
```
Inicio → Esperar comando → Ejecutar movimiento → Temporizar 1s → Detener motores → Repetir
```