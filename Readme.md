## Control de Motores Bluetooth con Arduino
Control de dos motores DC mediante comandos Bluetooth usando un módulo HC-05/06. El robot puede moverse adelante, atrás y girar en ambas direcciones durante 1 segundo por comando.

# Diagrama de Conexiones

### Puente H y Arduino

```
IN1 → Pin 9
IN2 → Pin 8
IN3 → Pin 7
IN4 → Pin 6
```

<a href="https://github.com/JnBenites/arduino_carro_unl/blob/main/componentes/PuenteHArduino/Readme.md" target="_blank">Imagenes de referencia</a> 

### Módulo Bluetooth:
```
- VCC → 5V Arduino
- GND → GND Arduino
- TX → RX Arduino (Pin 0)
- RX → TX Arduino (Pin 1)
```

<a href="https://github.com/JnBenites/arduino_carro_unl/blob/main/componentes/Bluetooth/Readme.md" target="_blank">Imagenes de referencia</a> 


#### Conectar motores al L298N:
```
Motor izquierdo a OUT1 y OUT2
Motor derecho a OUT3 y OUT4
```
<a href="https://github.com/JnBenites/arduino_carro_unl/blob/main/componentes/motores/Readme.md" target="_blank">Imagenes de referencia</a> 

### Arduino - interlocutor - Pilas
```
- 5V → Pila 6V+
- GND → Pilas 6V-
```
<a href="https://github.com/JnBenites/arduino_carro_unl/blob/main/componentes/pilas/Readme.md" target="_blank">Imagenes de referencia</a> 


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