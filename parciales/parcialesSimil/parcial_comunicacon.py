from dataclasses import dataclass, field
from typing import Set

@dataclass
class Interaccion:
    id_consume: int
    id_consumido: int

@dataclass
class Reporte:
    id: int
    lista_contactos_directos: Set[int] = field(default_factory=set)
    lista_contactos_indirectos: Set[int] = field(default_factory=set)

def obtener_lista_cuentas(interacciones: list[Interaccion]):
    ret = set()
    for interaccion in interacciones:
        ret.add(interaccion.id_consume)
        ret.add(interaccion.id_consumido)
    return ret

def imprimir_reportes(reportes: list[Reporte]):
    for reporte in reportes:
        print(f"REPORTE usuario #{reporte.id}:")
        print("\t############################## CONTACTOS DIRECTOS ##############################")
        if reporte.lista_contactos_directos:
            for i, contacto_id in enumerate(reporte.lista_contactos_directos):
                print(f"\t\tcontacto directo #{i+1}: {contacto_id}")
        else:
            print("\t\t\t\tNO TIENE CONTACTOS DIRECTOS")

        print("\t############################# CONTACTOS INDIRECTOS #############################")
        if reporte.lista_contactos_indirectos:
            for i, contacto_id in enumerate(reporte.lista_contactos_indirectos):
                print(f"\t\tcontacto indirecto #{i+1}: {contacto_id}")
        else:
            print("\t\t\t\tNO TIENE CONTACTOS INDIRECTOS")

def cargar_reportes(reportes: list[Reporte], interacciones: list[Interaccion]):
    # cargo los contactos directos
    for reporte in reportes:
        # si coincide el id del reporte
        filtro = lambda interaccion: reporte.id == interaccion.id_consume
        interacciones_del_reporte = filter(filtro, interacciones)
        reporte.lista_contactos_directos.update([interaccion.id_consumido for interaccion in interacciones_del_reporte])
    
    # cargo los contactos indirectos
    for reporte in reportes:
        # si el reporte_actual esta en los contactos directos de r
        filtro_indirectos = lambda r: r.id in reporte.lista_contactos_directos
        reportes_indirectos = filter(filtro_indirectos, reportes)
        for reporte_indirecto in reportes_indirectos:
            reporte.lista_contactos_indirectos.update(reporte_indirecto.lista_contactos_directos)

interacciones = [Interaccion(a, b) for a, b in (
                (1, 2), (1, 3), (1, 4), (1, 5),
                (2, 6), (2, 3), (2, 4), (2, 5),
                (3, 1), (3, 2), (3, 5), (3, 4),
                (4, 1), (4, 2), (4, 3), (4, 6), (5, 4)
            )]
lista_cuentas = obtener_lista_cuentas(interacciones)

reportes = [Reporte(id_cuenta) for id_cuenta in lista_cuentas]

cargar_reportes(reportes, interacciones)

imprimir_reportes(reportes)