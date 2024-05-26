#define TAMANIO_REGISTROS 10000

//Estructura de los gastos:
typedef struct RegistroGasto
{
    int nroTarjeta;
    char fecha[7];
    float monto;
}Gasto;

//Estructura de Area Contable:
typedef struct RegistroMovimiento
{
    int nroTarjeta,nroCuenta;
    float monto;
}Movimiento;

int main()
{
    Cuenta cuentas[TAMANIO_REGISTROS];
    Gasto gastos[TAMANIO_REGISTROS];
    
    Movimiento contableLista[TAMANIO_REGISTROS];
    Movimiento pendienteLista[TAMANIO_REGISTROS];

    //carga de datos de cuentas y gastos
    ////////////////////////////////

    float totalDebitado,totalPendiente = 0;//para guardar los totales
    float acumGastos, montoADebitar = 0.0;//para guardar el gasto + el impuesto
    int iPendiente, iContable = 0;//para registrar en los arreglos.

    for (int x = 0; x < TAMANIO_REGISTROS; x++)
    {
        cuentas[x].nroTarjeta = 0;
        cuentas[x].nroCuenta = 0;
        cuentas[x].saldo = 0.0;
        gastos[x].nroTarjeta = 0;
        strcpy(gastos[x].fecha, "");
        gastos[x].monto = 0.0;
        contableLista[x].monto = 0.0;
        pendienteLista[x].monto = 0.0;
    }


    
    cuentas[0].nroTarjeta = 1;
    cuentas[0].nroCuenta = 1;
    cuentas[0].saldo = 3;

    gastos[0].nroTarjeta = 1;
    strcpy(gastos[0].fecha, "20220101");
    gastos[0].monto = 1000;

    
    //por cada cuenta en cuentas
    for (int iCuenta = 0; iCuenta < TAMANIO_REGISTROS; iCuenta++) {
        //por cada gasto en gastos
        acumGastos=0.0;
        montoADebitar=0.0;
        for (int iGasto = 0; iGasto < TAMANIO_REGISTROS; iGasto++) {
            //verifico si el gasto es de la cuenta donde estoy parado:
            if (gastos[iGasto].nroTarjeta == cuentas[iCuenta].nroTarjeta) {
                //caso el gasto correspone a la cuenta, aplico el gasto:
                //aplico los impuestos al gasto:
                acumGastos = gastos[iGasto].monto + round(gastos[iGasto].monto * IMPUESTO_GASTOS_ADMINISTRACION);
            }
        }
        printf("%.2f\n", acumGastos);
        if (cuentas[iCuenta].saldo >= acumGastos) {
            // me alcanza... debito el total
            montoADebitar = acumGastos;
        } else {
            // NO me alcanza... debito lo que se tenga de saldo, le vacío la cuenta...
            montoADebitar = cuentas[iCuenta].saldo;
            cuentas[iCuenta].saldo = 0;
        }
        if (montoADebitar > 0) {
            //si tiene el saldo suficiente:
            //aplico gasto y hago un registro de area contable
            cuentas[iCuenta].saldo -= montoADebitar;
            //creo el registro Contable
            contableLista[iContable].nroCuenta = cuentas[iCuenta].nroCuenta;
            contableLista[iContable].nroTarjeta = cuentas[iCuenta].nroTarjeta;
            contableLista[iContable].monto = montoADebitar;
            ++iContable;
            if (montoADebitar < acumGastos) {
                //si no tiene el saldo suficiente:
                //creo un registro contable de la parte del pago que si pudo pagar.
                //el monto pendiente sera el gasto menos lo que pudo saldar con su saldo
                //creo el registro Moroso con lo que falto pagar
                pendienteLista[iPendiente].nroCuenta = cuentas[iCuenta].nroCuenta;
                pendienteLista[iPendiente].nroTarjeta = cuentas[iCuenta].nroTarjeta;
                pendienteLista[iPendiente].monto = acumGastos - montoADebitar;
                ++iPendiente;
            }
        }
    }
    //realizo los totales:
    //como tengo dos registros donde guarde los montos(totales y pendientes)

    //calculo total debitado
    for (int i = 0; i < TAMANIO_REGISTROS; i++) totalDebitado += contableLista[i].monto;
    //calculo total pendiente    
    for (int i = 0; i < TAMANIO_REGISTROS; i++) totalPendiente += pendienteLista[i].monto;
    

    printf("Total debitado:%.2f\n",totalDebitado);
    printf("Total Pendiente:%.2f\n",totalPendiente);

    return 0;
}