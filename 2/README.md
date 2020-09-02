# Práctica 2 - Inicialiazión y procesos del kernel

Esta práctica está enfocada en entender los procesos que ocurren cuando se inicializa un sistema operativo (xv6, en neustro caso).

Para probar al funcionalidad, correr
```bash
cd xv6-public/
make qemu-nox
```

Al inicializarse debe salir un mensaje de bienvenida al sistema operativo.

Para probar la funcionalidad implementada, correr
```bash
$ kill 1
```
Esto intenta apagar el proceso encargado de la inicialización del OS. Deberá salir un error, indicando que no se puede apagar dicho proceso.