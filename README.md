# Taller 2 Jorge Saavedra
- Nombre: Jorge Andrés Saavedra Sánchez
- Rut: 22.347.590-6
- Usuario Github: PanchoGamer
- Paralelo: C2

## Funcionamiento
El taller se nos pide atender una cola de pacientes y dependiendo de ciertos atributos derivarlos a departamentos, los cuales funcionan mediante un AVL.

Para saber a que departamento debe ser derivados se debe seguir ciertas condiciones para saber que departamento tiene una prioridad mayor a otra.

## Arbol de Decision
El arbol sigue la siguiente estructura
```
Urgencia->Cirugia/Traumatologia->Cardiologia->Neurologia->Pediatria->Hospitalizacion->Medicina General
```
- Urgencias: Es el primer escalon en verificar, el cual va si el Dolor es mayor a 7 o si presenta temperatura extrema tanto muy baja o muy alta.
- Cirugia/Traumatologia: Su primera verificacion es que exista Trauma pero para cada uno dependera si necesita cirugia. Si para ir a Cirugia y No para Traumatologia.
- Cardiologia: Se ingresa por el atributo de TipoDolor, el cual tiene que ser de Pecho.
- Neurologia: Al haber otro tipo de dolor se verifica si hay sintomas neurologicos, si existen se deriva a Neurologia.
- Pediatria: Al no haber sintomas neurologicos se verifica si el paciente tiene 14 años o menos. Si es asi se deriva a Pediatria.
- Hospitalizacion: Se verifica si tiene 1 o más dias en hospitalizacion, si es asi se va a Hospitalizacion.
- Medicina General: Al no cumplir con ninguna de las condiciones anteriores se envia a Medicina General.

## Instrucciones de Compilacion y Ejecucion
Para compilar el taller debe ingresar a la seccion de codespace de github y crear un espacio con el repocitorio. Luego en la terminal del codespace utilice el comando:
```
g++ Implement/Main.cpp Implement/ADD.cpp Implement/AVL.cpp Implement/Persona.cpp -o Taller2
```
"Taller2" puede ser cambiado al nombre que prefiera
Esto compilara el taller en un .exe

Para ejecutarlo debe usar el comando:
```
./Taller2
```
O en su defecto colocar el nombre que coloco en el comando anterior despues del "-o" en el comando de ejecutar.

El txt en el repositorio fue usado unicamente para probar casos de todos los departamentos y asi poder hacer prueba del AVL. Puede ser cambiado si necesita realizar casos en especifico.
