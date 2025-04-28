# Sistema de Control de Semáforo Peatonal

## Integrantes
- Luis Manuel Hurtado Almaraz
- Luis Fernando Garduño Quintana
- Antonio Garza Lozano

---

## Justificación

Diseñamos e implementamos un sistema de control de semáforo peatonal usando el microcontrolador PIC16F877A para mejorar la seguridad de los peatones en cruces viales. Mediante un botón, el peatón puede solicitar el cruce seguro, activando un ciclo especial en el semáforo vehicular y un buzzer de advertencia.

El proyecto demuestra la aplicación de sistemas embebidos en problemas reales, usando recursos de hardware básicos y sienta bases para futuras expansiones como comunicación inalámbrica o sensores inteligentes.

## Objetivo

- Controlar luces de tráfico vehicular (verde, amarillo, rojo).
- Permitir el cruce seguro del peatón mediante un botón de solicitud.
- Activar una alarma sonora antes del cambio de señal.
- Regresar automáticamente al ciclo vehicular normal.

---

## Requisitos del Sistema

### Requisitos Generales
- Control de LEDs vehiculares y peatonales.
- Detección de presión de botón.
- Activación de buzzer de advertencia.

### Requisitos de Módulos
- **Semáforo Vehicular:** LEDs rojo, amarillo y verde.
- **Semáforo Peatonal:** LEDs rojo y verde.
- **Botón de Peatón:** Entrada digital.
- **Buzzer:** Salida digital.

---

## Diseño del Sistema

### Diagrama de Bloques

![Diagrama de Bloques](Diseño/Diagrama_de_Bloques.png)

### Diagrama de Flujo

![Diagrama de Flujo](Diseño/Diagrama_de_Flujo.png)


### Diagrama de Clases

![Diagrama de Clases](Diseño/Diagrama_de_Clases_Correcto.png)


---

## Implementación

### Hardware Utilizado
- PIC16F877A
- Cristal de 4MHz + 2 capacitores de 22pF
- LEDs (2 rojos, 1 amarillo, 2 verdes)
- Resistencias (330Ω para LEDs, 10kΩ para botón y MCLR)
- Botón pulsador
- Buzzer activo 5V
- Protoboard y cables

### Software
- Lenguaje C en MPLAB X IDE con compilador XC8.
- Control modularizado de semáforo y buzzer.

---

## Plan de Pruebas

### Pruebas Unitarias
- Encendido individual de LEDs.
- Activación correcta del buzzer.

### Pruebas de Integración
- Cambio correcto del ciclo vehicular al peatonal tras presionar el botón.
- Activación de buzzer durante el cruce peatonal.

### Validación Final
- Validación en simulador Proteus.
- Validación física en protoboard.

---

## Conclusiones

El sistema implementado cumple completamente los requisitos planteados, ofreciendo un control seguro de tráfico peatonal. El uso del PIC16F877A permitió integrar de manera eficiente sensores, actuadores y lógica de control en un diseño sencillo pero efectivo. La modularidad del código facilita su futura expansión e integración de nuevas funcionalidades.

---

## Instrucciones para Compilar y Simular

### Compilar
1. Abrir MPLAB X IDE.
2. Crear un nuevo proyecto seleccionando PIC16F877A.
3. Copiar el código de `Implementacion/CodigoComentado.c`.
4. Compilar usando el compilador XC8.

### Simular en Proteus
1. Abrir Proteus.
2. Importar el archivo `.pdsprj` ubicado en la carpeta `Simulacion/`.
3. Cargar el `.hex` generado en el PIC16F877A.
4. Ejecutar la simulación.

---

## Estructura de Carpetas

```plaintext
Sistema_Control_Semaforo_Peatonal/
├── Diseño/
│   ├── Diagrama_de_Bloques.png
│   ├── Diagrama_de_Flujo.png
│   └── Diagrama_de_Clases_Correcto.png
├── Implementacion/
│   └── CodigoComentado.c
├── Pruebas/
│   └── Plan_de_Pruebas.txt
├── Requisitos/
│   ├── Requisitos_Generales.txt
│   └── Requisitos_Modulos.txt
├── Simulacion/
│   └── ArchivoProteus.pdsprj
├── Justificacion.txt
├── Conclusiones.txt
├── README.md
```

---
