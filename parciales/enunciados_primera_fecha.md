# Resumen (Primera fecha)
1. Empresa de Tornillos - Dificultad: 6 √
2. Manejo de ventas - Dificultad: 7
3. Coordinación de hospedaje - Dificultad: 5
4. Lista de alumnos - Dificultad: 8
5. Centro de distribución - Dificultad: 5 √
6. Comunicacon - Dificultad: 8.5
7. Cambio de divisas - Dificultad: 7
8. 8 Descubriendo Impostores - Dificultad: 6 
9. Servicio de planta - Dificultad: 4


# 1 Empresa de Tornillos
Una empresa que se dedica a la manofacturación de tornillos desea crear un sistema
para manejar sus pedidos de tornillos, 
cada día llegan pedidos de cajas de tornillos a las fabricas que deben ser atendidos.
cada caja se compone por 100 tornillos,
de cada tornillo se conoce el tipo(existen 8 tipos), el tamaño(existen 3 tamaños) y el stock disponible.
Los pedidos se componen por una solicitud que contiene (tipo - tamaño - cajas solicitadas).
se desea:
A) Tener un registros de los tornillos disponibles.
B) Generar un listado del stock con la información de cada tornillo.
C) Permitir realizar pedidos y concretarlos.
D) Realizar un informe de lo vendido en el día (cantidad de tornillos en los pedidos concretados).



# 2 Manejo de ventas.
Cada semana, los vendedores de una empresa reciben un informe de las ventas que se realizaron.
El listado de ventas realizadas por la empresa se compone por:
- nroVenta
- nroVendedor
- codigoProducto
- montoGenerado
De cada vendedor se conoce su nombre, su categoría (1-3) y su numero de vendedor, sabiendo que 
para cada categoría corresponden estas comisiones por venta:
1. categoría: 5% de comision
2. categoría: 8% de comision
3. categoría: 10% de comision

Se desea analizar cuando genero cada vendedor esa semana segun el listado de ventas y generar un informe que debe incluir:
- categoría con más recaudación.
- monto recaudado por categoría.
- mejor vendedor por categoría.
- porcentaje de vendedores que superaron las 10 ventas semanales


# 3 Coordinación de hospedaje
En un hotel dividido en tres bloques (A, B, C), cada bloque con 100 habitaciones, se desea realizar un manejo del uso del alojamiento. Cada habitación puede ser ocupada o estar libre.
Se desea implementar un sistema que permita:
    A) Registrar el estado de cada habitación (ocupada o libre).
    B) Listar las habitaciones disponibles por bloque.
    C) Permitir la reserva de habitaciones.
    D) Generar un informe diario de ocupación por bloque.

# 4 Lista de alumnos
Esta semana llego un listado de notas de los 500 alumnos de una universidad para las
20 catedras que se dictan y se desea realizar
un informe solicitado por el gobierno sobre el rendimiento de los mismos.
El listado de notas de los alumnos esta compuesto por el legajo del alumno, el id de la catedra del examen y la nota del alumno.
Para el informe se debe pasar el porcentaje de aprobados(nota >= 4), promocionados(nota >= 6) y reprobados(nota < 4) por cada catedra.
Sabiendo ademas que de cada alumno se sabe su nombre, dni y su legajo.
desarrollar una forma de verificar las notas de los alumnos por dni.


# 5 Centro de Distribución
Dentro de un centro de distribución se requiere el diseño de un sistema para el manejo de los productos.
De cada producto se conoce:
- nroProducto
- cantidadDisponible

dentro del centro existen dos procesos `ingresos` y `egresos` ambos se componen por un
formulario que puede tener hasta 5 productos distintos, cada uno con las cantidades solicitadas/recibidas por producto.
Se desea:
A) Tener un registro de los productos disponibles (número de producto, cantidad disponible).
B) Permitir registrar ingresos de productos, actualizando las cantidades disponibles.
C) Permitir registrar egresos de productos, actualizando las cantidades disponibles.
D) Generar un informe de los productos egresados/ingresados.

# 6 Comunicacon
En una empresa que se dedica a la comunicación llego un listado de las interacciones que tuvieron
distintas personas en un informe proveido por una red social.
El informe se compone por 2 ids, cada uno corresponde a una cuenta A y el otro a una cuenta B. siendo la primera cuenta(A) consumidora del contenido de la segunda cuenta(B).
Para Comunicacon cada cuenta tiene 2 tipos de contactos los directos y los indirectos.
Los contactos directos son aquellos que A consume directamente, es decir, en la lista de interacciones existe una relación A -> B.
Los contactos indirectos se componen por los contactos directos de sus contactos directos.
por ejemplo:
listado:
    (1, 2), (2, 3), (2, 4)
representación:    
    A -> B
    B -> C
    B -> D
A:
    tiene un contacto directo (B) y dos indirectos (C, D)

B:
    tiene 2 contactos directos (C, D) y no tiene contactos indirectos
C,D:
    No tienen contactos

Existen algunas cuentas que estan marcadas en una lista negra, las cuentas en esta lista
son baneadas de la red social y no cuentan ni para contactos directos ni indirectos.
Además si una cuenta tiene como contacto directo solo cuentas en la lista negra, tambien se la considera en la lista negra.

- Se desea realizar un informe donde se liste cantidad y ids de los usuarios directos y indirectos de todas las cuentas.
- Porcentaje de cuentas con al menos 5 contactos indirectos.


# 7 Cambio de divisas.
Una empresa llamada ConvertInc, se dedica a la convertibilidad de monedas quiere un sistema para automatizar sus procesos productivos.
La misma cuenta con un stock de todas las monedas de las que realiza convertibilidad (10 tipos de monedas),
cada cuenta de los clientes de ConvertInc pose un registro de las distintas divisas que tiene en su cuenta
y un equivalente en una divisa creada por la empresa (ConvertCoin).

De las divisas se sabe:
- idMoneda
- stock de divisa en fisico (cantidad de unidades que tiene ConvertInc de esa moneda)
- equivalente de una unidad de la divisa en ConvertCoins

De las cuentas se sabe:
- id_cuenta
- divisas de la cuenta

Los usuarios pueden realizar conversiones de cualquiera de sus divisas a cualquiera de las demas,
el stock de las monedas solo se toma en cuenta cuando el cliente desea realizar un retiro de alguna de las monedas.

Se desea realizar lo siguiente:
    A) Impresion de cuenta por id_cuenta:
        id_cuenta
        divisas de la cuenta
        equivalente del patrimonio de la cuenta en ConvertCoins.
    B) Realización de retiros.
    D) Convertivilidad de monedas.
    E) impresion de stock de divisas.

# 8 Descubriendo Impostores.
En una agrupación de personas que decidieron realizar un fondo común se encontraron ciertos problemas con los aportes.
Cada persona puede realizar 2 acciones, ingresar dinero o retirar dinero.
Por mutuo acuerdo nadie puede retirar más del 120% de lo que ingreso, como hay muchas personas participando se complico echar a los deudores del fondo.
Entonces, sabiendo que de la lista de transacciones se sabe:
- operacion (0 ingreso, 1 egreso)
- dni_operante
- monto

De las personas se sabe:
- dni
- nombre

se desea:
- Informar el listado de deudores (id, nombre, % de deuda, monto de la deuda)
- Porcentaje de deudores contra el total

# 9 Servicio de planta
Dentro de una industria deben seguir una regulación de seguridad sobre cada sector, la planta se compone por
5 sectores ('A','B','C','D','E').
cada empleado tiene permiso para acceder a algunos sectores en especifico.
Se desea:
- Registrar un empleado
- Modificar permisos de un empleado
- listar empleados permitidos por sector