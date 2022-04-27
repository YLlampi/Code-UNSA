import psycopg2
import time

conn = psycopg2.connect(
    user="postgres",
    password="root",
    host="localhost",
    port="5432",
    database="DataBase2",
)


cursor = conn.cursor()

def getSentencia():
    sentencia = """CREATE TABLE personas(
        id bigint PRIMARY KEY,
        peliculas text,
        Patrick_C integer,
        Heather integer,
        Bryan integer,
        Patrick_T integer,
        Thomas integer,
        aaron integer,
        vanessa integer,
        greg integer,
        brian integer,
        ben integer,
        Katherine integer,
        Jonathan integer,
        Zwe integer,
        Erin integer,
        Chris_1 integer,
        Zak integer,
        Matt integer,
        Chris_2 integer,
        Josh integer,
        Amy integer,
        Valerie integer,
        Gary integer,
        Stephen integer,
        Jessica integer,
        Jeff integer);
    """
    return sentencia


def maximo_num_calif(tuple_input):
    # count=menor=0     
    max_it=0
    count=0
    max=-1
    for i in range(len(tuple_input)):
        count=0
        for j in range(2,len(tuple_input[i])):
            if(tuple_input[i][j]>=0):
                count+=1
        if (count>max) :
            max=count
            max_it=i  
    # print(tuple_input)
    print("Pelicula "+tuple_input[max_it][1]+" / Num de votos "+str(max) )
    return max_it


def minimo_num_calif(tuple_input):
    # count=menor=0     
    max_it=0
    count=0
    min=10000
    for i in range(len(tuple_input)):
        count=0
        for j in range(2,len(tuple_input[i])):
            if(tuple_input[i][j]>=0):
                count+=1
        if (count<min):
            min=count
            max_it=i  
    # print(tuple_input)
    print("Pelicula "+tuple_input[max_it][1]+" / Num de votos "+str(min) )
    return max_it


"""
with open('Movie_Ratings.csv', 'r') as f:
    next(f)
    cursor.copy_from(f, 'personas', sep=',')
"""

inicio = time.time()

senSelect = ('SELECT * FROM personas')

cursor.execute(senSelect)

registros = cursor.fetchall()

dic ={
    -1:0,
    1: 0,
    2: 0,
    3: 0,
    4: 0,
    5: 0,
}

pos_max = maximo_num_calif(registros)
pelicula = registros[pos_max][1]
for j in range(2,len(registros[pos_max])):
    val = dic[registros[pos_max][j]]
    dic[registros[pos_max][j]] = val + 1

print(f'Pelicula:  {pelicula}:')
print(f'Calificacion    Numero de votos')
for k in dic:
    print(f'{k}                  {dic[k]}')


print('------------------------------------------------')


dic[-1]=0
dic[1]=0
dic[2]=0
dic[3]=0
dic[4]=0
dic[5]=0

pos_min = minimo_num_calif(registros)
pelicula = registros[pos_min][1]
for j in range(2,len(registros[pos_min])):
    val = dic[registros[pos_min][j]]
    dic[registros[pos_min][j]] = val + 1

print(f'Pelicula:  {pelicula}:')
print(f'Calificacion    Numero de votos')
for k in dic:
    print(f'{k}                  {dic[k]}')

print('------------------------------------------------')


conn.commit()

fin = time.time()
print(fin - inicio)


print("_-------------------------------------_")







"""
for i in range(len(registros)):
    pelicula = registros[i][1]
    for j in range(2,len(registros[i])):
        val = dic[registros[i][j]]
        dic[registros[i][j]] = val + 1

    print(f'Pelicula:  {pelicula}:')
    print(f'Calificacion    Numero de votos')
    for k in dic:
        print(f'{k}                  {dic[k]}')

    print('------------------------------------------------')
    dic[-1]=0
    dic[1]=0
    dic[2]=0
    dic[3]=0
    dic[4]=0
    dic[5]=0
"""

