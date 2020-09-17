# SO_1
Tarea 1 de Sistemas Operativos. 2020-1

## Notas temporales
v.4: gametda funciona, las listas deberian funcionar. <br /> Trata de usar solo append, aunque el insert esta implementado, creo que el
 insert tiene problemas con insertar al final, asi que yo que tu uso append no mas.
 <br />Para ingresar en la lista, crea un puntero de game y pide memoria, luego le pasas el puntero a append.<br />
 El destroy de la lista te libera toda la memoria, incluyendo la de los game (En teoria, no use valgrind).<br />
 Agregue sort, le pasas la lista que quieres ordenar y retorna la lista ordenada<br />
 IMPORTANTE: l = sort(l); Si no se pierde. <br />
 
 ## Consideraciones
 El gametda asume que los juegos estan en una carpeta "Juegos", desde ahi busca las otras de categoria.

