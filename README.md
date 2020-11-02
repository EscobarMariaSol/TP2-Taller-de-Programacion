# Trabajo Práctico 2 - Taller de Programación I - (75.42/95.08)
# Informe de Resolución


**Nombre:**  Escobar Benitez Maria Soledad

**Padrón:**  97877

**Repositorio:** [Link GitHub!](https://github.com/EscobarMariaSol/TP2-Taller-de-Programacion)

**Fecha de entrega:** 03/11/2020


## Introducción

En este trabajo se implementará una versión simplificada de un verificador de 
programas eBPF que sólo verificará la existencia o no de bucles de código y/o 
instrucciones sin ejecutar. 

#### Modelado del programa como grafo

Para realizar esto la idea es modelar el programa como un grafo dirigido: los 
nodos serán las instrucciones y las aristas serán los posibles saltos. 

#### Detección de ciclos

El verificador de eBPF deberá detectar ciclos o bucles en el código. Esto es 
saltos hacia instrucciones ya ejecutadas. Al garantizar la no existencia de 
ciclos se puede garantizar que el programa de eBPF no se podrá colgar. 
Si se modela un programa como un grafo dirigido, la detección de ciclos se 
reduce tan solo a una búsqueda Deep First Search ​o DFS. 

#### Detección de instrucciones sin usar

DFS no solo detecta los ciclos sino que además, por la naturaleza del 
algoritmo, recorre todo el grafo visitando todos los nodos, o sea, todas 
las instrucciones. 
Si alguna instrucción no es visitada durante el DFS es porque no puede ser 
accedida y por ende es una instrucción sin usar que nunca sería ejecutada. 

#### Verificación

El verificador de programas deberá procesar los archivos pasados por línea de 
comandos y determinar si tienen ciclos y/o instrucciones sin usar. 
Deberá imprimir por pantalla el nombre de cada archivo procesado y un mensaje 
indicando los resultados linea a linea, con la salida ordenada alfabéticamente. 

#### Verificación en paralelo

El verificador deberá procesar los archivos en paralelo con una serie de 
threads definidos por línea de comandos.
Es requerimiento del trabajo práctico que se implemente un objeto que servirá 
de repositorio de los archivos a ser procesados.
Cada hilo deberá pedir un archivo a este objeto, parsearlo, modelarlo y 
analizarlo para luego volver a pedir otro archivo y repetir la operación. 
Por el otro lado, los hilos deberán guardar los resultados a medida que los 
vayan obteniendo en un único objeto compartido.
Solo cuando todos los archivos hayan sido procesados se imprimirán los 
resultados.

## Esquema de Resolución

Para la resolución de este trabajo práctico se decidió pensar en una división 
por partes, de los diferentes procesos a realizarse a la hora de llevar a cabo 
la verificación de un programa.

Inicialmente se detectan 3 grandes partes del programa, el procesamiento del 
archivo bpf, la creación del grafo y su verificación y la implementación de 
threads. Luego se puede notar la existencia de dos objetos que serán 
compartidos por todos los threads a lo largo del programa, uno de ellos es el 
repositorio donde se guardaran los archivos, que se reciben al momento de 
iniciar la ejecución del programa, y el otro es un repositorio donde cada 
thread irá guardando el resultado de la verificación de cada archivo.

Al momento de comenzar a modelar la solución se comienza a detectar la 
necesidad de otras entidades a las cuales se les delegaran ciertos 
comportamientos a lo largo de la vida del programa.

#### Procesamiento del archivo 

Para comenzar con la primer parte se decide implementar una clase *FileParser*, 
la cual recibe el nombre de un archivo y lo procesa para recolectar la 
información que resulte relevante para nuestro programa, para que esta 
información sea presentada de manera más ordenada se decide además crear una 
clase *LineMap* que almacena la información relevante de cada linea del archivo, 
es así que el *FileParser* devuelve una instancia de la clase *LineMap*.

#### Cración del grafo y su verificación

Para esta parte del programa se crea una clase *Checker* que se encarga de 
solicitar las rutas a los archivos, que se encuentran almacenadas en la única 
instancia existente de la clase *FileRepository*, que es una de las clases 
que se menciona será compartida por todos los threads, y luego llamar a las 
diferentes clases que intervienen en la verificación del archivo. 
Esta parte del programa está a su vez sub-divida en la creación del grafo y la 
verificación del mismo.

##### Creación del grafo

Para crear el grafo la clase *Checker* hace utilización de la clase 
*GraphGenerator*, la cual recibe la ruta a un archivo y se encarga de crear  
una instancia de la clase  *Graph* a partir de este archivo, para hacer esto 
llama al *FileParser* y el mismo le devuelve un *LineMap*, el cual el 
*GraphGenerator* consultará para ir creando cada instancia de la clase *Node*, 
que luego agregará la *Graph*.

##### Verificación del grafo

Para verificar el grafo el *Checker* usa además una clase llamada *Dfs*, la 
cual se encargará de recorrer el grafo y detectar la existencia de ciclos o 
instrucciones sin usar.

Finalmente el *Checker* crea el mensaje de salida, de acuerdo al resultado 
arrojado por la instancia de la clase *Dfs* y se encarga de almacenarlo en el 
repositorio de salidas, el cual es una clase a la cual se ha llamado 
*OutputRepository*, que es una de las clases compartidas por todos los threads.

#### Implementación de los threads

LLegada a esta parte de la resolución ya se cuenta con todas las clases ya 
mencionadas y además se cuenta con una clase *CheckerProgram* que será la 
encargada de ejecutar todo el programa en sí, este será nuestro thread 
principal. Desde esta clase se lanzarán los diferentes threads, donde cada 
thread será una instancia de la clase *Checker*, para que esto fuese posible 
se creó una clase llamada *CheckerThread*, de la cual heredara la clase 
*Checker* y le permitira a cada instancia comprotarse con un thread.

La clase *CheckerProgram* será la encargada de crear los repositorios 
compartidos, *FileRepository* y *OutputRepository*, y le pasará una referencia 
a los mismos a cada instancia de la clase *Checker*, logrando así que todos 
tengan acceso a los mismos, puedan pedir las rutas de los archivos y luego 
almacenar los resultados. 

Una vez se hayan procesados todos los archivos, *CheckerProgram* hará un join 
de todos los hilos, para luego mostrar los resultados y finalizar liberando 
todos los recursos utilizados.

##### Detección de las critical sections

Como el enunciado los requiere, contamos con dos objetos compartidos por todos 
los threads, *FileRepository* y *OutputRepository*, para evitar corromper los 
resultados del verificador, o generar errores a la hora de procesar los 
archivos, se ha debido detectar cuáles son las secciones críticas, es decir, 
cuales son las operaciones que no pueden ser interrumpidas por un context 
switch, pudiendo provocar así alteraciones en los resultados. 
En la clase *FileRepository*, se han detectado que la petición de rutas de 
archivos y la agregación de las mismas son secciones críticas, 
pues si estas fuesen interrumpidas y se cambiara el estado del repositorio
justo antes de obner la respuesta, esto podria generar un resultado 
completamente inesperado, lo mismo sucede con la clase *OutputRepository*, 
la cual tiene como secciones críticas a la operación de guardar las salidas y 
la de mostrar las mismas.

Para proteger estas seciones críticas se ha asignado un *mutex* para cada uno de 
estos repositorios y se ha hecho utilización de *lock_guard* para evitar que 
las operaciones sean interrumpidas, y además despreocuparse de tener que llamar 
a *lock* y *unlock*, pues *lock_guard* nos garantiza que esa sección estará 
resguarda desde el momento en que inicia su ejecución  hasta el fin de la 
ejecución del método.

#### Diagramas

A continuación se muestra un esquema, a alto nivel, de como se ha interpretado 
el flujo del programa, de acuerdo a la resolución implementada.

![Flujo](https://github.com/EscobarMariaSol/TP2-Taller-de-Programacion/blob/main/img/TP2-Flujo.png)


Por otro lado se presenta el siguiente diagrama de clases que intenta detallar, 
de la mejor manera posible, las clases implementadas para la resolución del 
trabajo práctico y la relación existente entre ellas.

![Clases](https://github.com/EscobarMariaSol/TP2-Taller-de-Programacion/blob/main/img/TP2-Clases.png)


## Clases implementadas

A continuación se detallará un poco más acerca de las interfaces implementadas 
para cada una de las clases creadas, explicacando brevemente el proqué de dicha 
implementación.
Enn caso de buscar una explicación más detallada, se puede consultar la 
documentación existente en cada uno de los archivos de cabecera.

### CheckerProgram

Esta clase es la encargada de llevar a cabo la ejecución del verificdor de 
archivos, la cual nos permite proveer al main una completa abstracción de toda 
lógica. La clase cuenta con los siguientes atributos:
1. **file_repo**: que corresponde al objeto compartido, donde se almacenan las 
rutas a los archivos a verificar.
2. **output_repo**: corresponde al repositorio compartido, donde se almacenan
las salidas registradas.

La clase posee la siguiente interfaz:
``` C++
    class CheckerProgram {
    private:
        FileRepository file_repo;
        OutputRepository output_repo;
        void saveFiles(std::vector<std::string>& files);

    public:
        CheckerProgram();
        ~CheckerProgram();
        int start(const char *threads_num, std::vector<std::string>& files);
    };
``` 
A continuación se detalla un poco acerca de los métodos que posee la clase:
1. **saveFiles**: es un método que se ha marcado como privado, pues sólo es 
utilizado por la misma clase, la cual lo utiliza para guardar las rutas, a los 
archivos a verificar, dentro del repositorio de archivos.
2. **start**: es el método que se invoca desde el main para dar inicio a la 
ejecución del programa.

### FileRepository

Esta es una de las clases compartidas que se encarga de alamacenar las rutas 
de los archivos a verificar. La clase cuenta con los siguientes atributos:
1. **files**: es una cola en la que se guardan los archivos a verificar
2. **mutex**: es el mutex que se utilizará para proteger los secciones que 
realizan operaciones que no pueden ser interrrumpidas por un context switch. 

La clase posee la siguiente interfaz:
```C++
    class FileRepository {
    private:
        std::queue<std::string> files;
        std::mutex mutex;

    public:
        FileRepository();
        ~FileRepository();
        void addFile(const std::string& file_path);
        std::string getFile();
        FileRepository(const FileRepository&);
        FileRepository& operator=(const FileRepository&); 
    };
```
A continuación se detalla un poco acerca de los métodos que posee la clase:
1. **addFile**: este método se encarga de guardar una ruta a un archivo 
dentro del atributo *files*, este es uno de los métodos protegidos por 
un lock_guard del mutex.
2. **getFile**: este método chequea si hay rutas disponibles en *files*, 
si es así devuelve el próximo en la cola, este es otro de los métodos protegidos 
por un lock_guard del mutex.

### OutputRepository

Esta es la segunda clase compartida, es un repositorio encargado de almacenar 
las salidas correspondientes al resultado de las verificaciones de los archivos. 
La clase cuenta con los siguientes atributos:
1. **outputs**: es donde se almacenan la salidas ordenadas alfabeticamente
2. **mutex**: es el mutex que se utilizará para evitar que un thread pueda 
interrumpir a otro, mediante un context switch, mientras interactua con las 
secciones críticas del repositorio.

La clase posee la siguiente interfaz:
```C++
    class OutputRepository {
    private:
        std::set<std::string> outputs;
        std::mutex mutex;

    public:
        OutputRepository();
        ~OutputRepository();
        int addOutput(const std::string output);
        void showOutput();
        OutputRepository(const OutputRepository& other);
        OutputRepository& operator=(const OutputRepository& other);
    };
```
A continuación se detalla un poco acerca de los métodos que posee la clase:
1. **addOutput**: este método se encarga de guardar una nueva salida 
al set de resultados *outputs* y es uno de los métodos protegidos por 
un lock_guard del mutex.
2. **showOutput**: este método es el encargado de mostrar por pantalla 
todas las salidas almacenadas durante el proceso de verificación de los 
archivos y es otro de los métodos protegidos por un lock_guard del mutex. 

### Checker

Esta clase es la encargada de llevar a cabo al verificador de archivos,
esto implica la creación del grafo y la verificación del mismo, para luego 
almacenar los resultados dentro del repositorio de salidas.
La misma hereda de la clase CheckerThread, pues cada instacia de la misma 
corresponderá a un thread.
La clase cuenta con los siguientes atributos:
1. **result**: es un string correspondiente al resultado obtenido luego de 
verificar un archivo
2. **file_repo**: corresponde al repositorio al cual se le pediran las rutas
de los archivos que deben ser verificados
3. **utput_repo**: corresponde al repositorio en el cual se almacenaran
los resultados obtenidos luego de verificar los archivos

La clase posee la siguiente interfaz:
```C++
    class Checker: public CheckerThread {
    private:
        std::string result;
        FileRepository& file_repo;
        OutputRepository& output_repo;
        void setResult(Dfs& dfs);
        std::string createOutput(std::string& path);
        
    public:
        Checker(FileRepository& file_repo, OutputRepository& output_repo);
        ~Checker();
        void verifyFile();
    };
``` 
A continuación se detalla un poco acerca de los métodos que posee la clase:
1. **setResult**: este es un método privado, al cual sólo accede el *Checker* 
luego de que se haya obtenido el resultado de la verificación y el cual se 
encarga de transformar el resultado del recorrido del *Dfs* a un string que 
coincida con parte de la salida esperada.
2. **createOutput**: este método, también privado, es encargado de crear el 
formato del resultado que corresponde con la salida final del verificador.
3. **verifyFile**: este es el método que se hereda de la clase *CheckerThread* 
y al cual se llama desde cada instancia de la clase *Checker*, al momento de 
lanzarse cada thread, el mismo encapsula toda la interacción de las clases 
involucradas en la verificación del archivo, en sí, es decir, desde el 
pedido de los archivos hasta la creación del grafo, su verificación y 
finalmente de guardar el resultado.

### CheckerThread

Esta en una clase abstracta la cual encapsula el comportamiento de crear un 
thread para cada instancia de la clase *Checker* y ejecutar el correspondiente 
verificador.
La clase cuenta con un único atributo, llamado **thread** correspondiente al 
thread que se lanzará cada vez que se llame al método *start*.

La clase cuenta con la siguiente interfaz:
```C++
    class CheckerThread {
    private:
        std::thread thread;
    
    public:
        CheckerThread();
        virtual ~CheckerThread();
        void start();
        void join();
        virtual void verifyFile() = 0;
        CheckerThread(const CheckerThread& other) = delete;
        CheckerThread& operator=(const CheckerThread& other) = delete;
        CheckerThread(CheckerThread&& other);
        CheckerThread& operator=(CheckerThread&& other);
    };
```
A continuación se detalla un poco acerca de los métodos que posee la clase:
1. **start**: este método se encarga de lanzar el thread, indicandole que 
debe ejecutar el método *verifyFile* y pasandole un puntero a la instancia 
misma.
2. **join**: luego de que el método *start* haya finalizado su ejecución, se 
utiliza este método para que el thread se vuelva a unir al thread principal.
3. **verifyFile**: este es un método virtual puro, el cual carece de 
implementación en esta clase, pero las clases que hereden de ella tienen la 
obligación de implementar, como ya se ha mencionado anteriormente, la clase 
*Checker* es la encargada de implementar este método.

### GraphGenerator

Esta clase es la encargada de crear el grafo a partir del archivo que se debe 
verificar, para hacer esto se vale de otras dos clases *FileParser* y *LineMap* 
las cuales se detallaran más adelante.
La clase cuenta con un único atributo llamado **parser**, correspondiente al 
*LineParser* encargado de convertir las lineas del archivo en información de 
fácil manipulación para la creación del grafo.

La clase posee la siguiente interfaz:
```C++
    class GraphGenerator {
    private:
        FileParser parser;
        int addNodes(Graph& new_graph, std::map<Node, std::set<std::string>>& edges);
        int addEdges(Graph& new_graph, std::map<Node, std::set<std::string>>& edges);

    public:
        explicit GraphGenerator(const std::string path);
        ~GraphGenerator();
        int generateGraph(Graph& new_graph);
    };
```
A continuación se detallan alguno de los métodos implementados por la clase:
1. **addNodes**: método que llama al parser para obtener la información de 
cada linea del archivo y generar los nodos para agregarlos al grafo.
2. **addEdges**: método que agrega aristas al grafo, esto lo logra colocando 
en cada nodo una referencia a sus correspondiente vecinos dentro del grafo.    
3. **generateGraph**: este es el método que será visible para que la clase 
*Checker* lo utilice y ejecute para generar el grafo a partir de la ruta de 
un archivo.
    
### FileParser

Es la clase encargada de abrir un archivo, leer sus lineas y parsear el texto 
del archivo para convertirlo en información utilizable para que así la clase 
*GraphGenerator* pueda crear un grafo a partir de ello.
La clase cuenta con un único atributo, llamado **file** correspondiente al 
filestream que se desea parsear.

La clase provee la siguiente interfaz:
```C++
    class FileParser {
    private:
        std::fstream file;
        
    public:
        explicit FileParser(const std::string file_name);
        ~FileParser();
        LineMap parseLine();
        bool hasLine() const;
    };
```
A continuación se detalla un poco acerca de los métodos que posee la clase:
1. **parseLine**: este es el método que lee una línea del archivo y la procesa, 
almacenando toda la información relevante en el *LineMap* que será devuelto.
2. **hasLine**: método que indica si todavía existen lineas del archivo a ser 
procesadas.

### LineMap

Esta es la clase encargada de almacenar de manera organizada la información 
leída en las líneas de los archivos, correspondiente a las instrucciones del 
programa bpf.
La clase cuenta con los siguientes atributos:
1. **line_map**: el cual es un map donde se almacenan las instrucciones, su tipo 
y sus parámetros, si existen etiquetas estas también se almacenan con su 
correspondiente nombre.
2. **status**: indica si el *LineMap* es válido o ha sido corrompido por algún
error durante su uso.

Esta clase posee la siguiente interfaz:
```C++
class LineMap {
private:
    std::map<std::string, std::string> line_map;
    int status;
    bool isARet() const;
    bool isATag(std::string tag) const;
    bool isAJump() const;

public:
    LineMap();
    ~LineMap();
    std::string getTagId();
    std::set<std::string> getNeighbors();
    int add(std::string key, std::string value);
    bool isEmpty() const;
    bool canGoToTheNexLine() const;
    void invalidate();
    bool isValid() const;
};
```
A continuación se detalla un poco acerca de los métodos que posee la clase:
1. **isARet**: método que indica si una instrucción almacenada en el *LineMap* 
es una instrucción "ret".   
2. **isATag**: método que indica si un string corresponde a una etiqueta.   
3. **isAJump**: método que indica si una instrucción almacenada en el *LineMap* 
corresponde a una instrucción de salto o no.
4. **getTagId**: método que, en caso de ser una etiqueta, devuelve el nombre de 
la etiqueta a la cual corresponde la instrucción almacenada en el *LineMap*.
5. **getNeighbors**: método que devuelve un set con los id correspondientes a 
las instrucciones que pueden ser ejecutadas luego de la instrucción actual, es 
decir, a los vecinos a los cuales puede saltarse desde la instrucción actual.
6. **add**: método para agregar nueva información al *LineMap*, el formato 
consiste en una key indicando el tipo de información y un value correspondiente 
a la información misma.
7. **isEmpty**: método que indica si el LineMap está vacío o no.
8. **canGoToTheNextLine**: método que indica si la instrucción almacenada dentro 
del *LineMap* puede dar como resultado un salto a la instrucción inmediatamente 
consecutiva o no.
9. **invalidate**: método que invalida el *LineMap* para que el mismo quede 
inutilizable, esto puede hacerse luego de que suceda algún error en alguna de 
sus operaciones.
10. **isValid**: método que indica si el *LineMap* es válido o no
    
### Graph

Clase que representa el grafo en el cual se van almacendando los nodos 
correspondientes a las instrucciones del programa bpf que se debe verificar. 
La clase cuenta con único atributo, llamado **nodes**, que es una lista con 
los nodos pertenecientes al grafo.

Esta clase posee la siguiente interfaz:
```C++
    class Graph {
    private:
        std::list<Node> nodes;
        
    public:
        Graph();
        ~Graph();
        size_t getSize() const;
        std::list<Node> getNodes() const;
        int addNode(Node& node);
        Node& getNode(const std::string id);
        bool containsNode(const std::string id);
        Node& getFirst();
    };
```
A continuación se detalla un poco acerca de los métodos que posee la clase:
1. **getSize**: método que devuelve el tamaño del grafo, es decir, la cantidad
de nodos que se encuentran dentro del mismo.
2. **getNodes**: método que devuelve la lista con la referencia a los nodos que 
han sido agregados al grafo.
3. **addNode**: método que recibe una referencia a un nodo y la almacena en la 
lista de nodos pertenecientes al grafo.
4. **getNode**: método que localiza un nodo dentro del grafo a partir de la id 
del mismo.
5. **containsNode**: método que a partir de un id, indica si el nodo con esa id 
pertenece o no al grafo.
6. **getFirst**: método que devuelve el primer nodo de la lista de nodos que 
pertenecen al grafo.
        
### Dfs

Clase encargada de realizar un recorrido DFS sobre un grafo permitiendo así 
detectar la existencia de ciclos o la existencia de instrucciones que nunca 
se ejecutaran.
La clase cuenta con los siguientes atributos:
1. **cycle**: atributo booleano para indicar si durante el recorrido de un 
grafo se ha detectado un ciclo o no.
2. **unusedInstructions**: atributo booleano para indicar si se han 
encontrado instrucciones a las cuales no se puede acceder.

La clase posee la siguiente interfaz:
```C++
class Dfs {
private:
    bool cycle;
    bool unusedInstructions;
    int visit(Graph& graph, Node& actual, std::set<Node>& visited);

public:
    Dfs();
    ~Dfs();
    int walkGraph(Graph& graph);
    bool hasCycle() const;
    bool hasUnusedInstructions() const;
    };
```
A continuación se detalla un poco acerca de los métodos que posee la clase:
1. **visit**: método que visita todos los nodos accesibles de un grafo, 
partiendo desde un nodo que se le pasa por parametro comienza a moverse entre 
los vecinos, como el clasico algoritmo dfs.
2. **walkGraph**: método que que llama a la función visit y luego verifica si 
el recorrido detectó ciclos o nodos que no sean accesibles.
3. **hasCycle**: método que señala si un grafo que fue previamente recorrido 
contiene un ciclo o no.
4. **hasUnusedInstructions**: método que señala si un grafo que fue recorrido 
previamente contiene nodos que no se han podido visitar o no.
