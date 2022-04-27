"""
-------------------------------------------------
Crear Tabla Personas

CREATE TABLE public.personas
(
    id_personas bigserial NOT NULL,
    nombre text NOT NULL,
    PRIMARY KEY (id_personas)
);

ALTER TABLE IF EXISTS public.personas
    OWNER to postgres;


-------------------------------------------------
Crear Tabla Peliculas

CREATE TABLE public.peliculas
(
    id_pelicula bigserial NOT NULL,
    nombre_pelicula text NOT NULL,
    PRIMARY KEY (id_pelicula)
);

ALTER TABLE IF EXISTS public.peliculas
    OWNER to postgres;
-------------------------------------------------

Crear Tabla Calificacion

CREATE TABLE public.calificaciones
(
    id_calificacion bigserial NOT NULL,
    persona_id bigint NOT NULL,
    pelicula_id bigint NOT NULL,
    calificacion integer,
    PRIMARY KEY (id_calificacion)
);

ALTER TABLE IF EXISTS public.calificaciones
    OWNER to postgres;


-------------------------------------------------
"""

import psycopg2

conexion = psycopg2.connect(
    user='postgres',
    password='root',
    host='localhost',
    port='5432',
    database='bbdd2'
)

try:
    with conexion:
        with conexion.cursor() as cursor:
            sentencia = 'SELECT * FROM personas'

            cursor.execute(sentencia)
            registros = cursor.fetchall()

            print(registros)
except Exception as e:
    print(f'Ocurrio un error: {e}')
finally:
    conexion.close()


