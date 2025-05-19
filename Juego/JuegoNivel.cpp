// proyecto: Grupal/Juego
// arhivo:   JuegoMesa.cpp
// versión:  1.1  (9-Ene-2023)


#include "juego.h"


namespace juegoNivel {

    void JuegoNivel::seleccionNivel(int nivel)
    {
        juegoNivel::JuegoNivel* niveles = new juegoNivel::JuegoNivel{};
        juego::JuegoMesa* juego = new juego::JuegoMesa{};
        juego1::JuegoMesa1* juego1 = new juego1::JuegoMesa1{};
        juego2::JuegoMesa2* juego2 = new juego2::JuegoMesa2{};
        juego3::JuegoMesa3* juego3 = new juego3::JuegoMesa3{};
        juego4::JuegoMesa4* juego4 = new juego4::JuegoMesa4{};
        juego5::JuegoMesa5* juego5 = new juego5::JuegoMesa5{};
        

        try {
            std::setlocale(LC_ALL, "es_ES.utf8");

            switch (nivel){
            case 0:
                motor->ejecuta(niveles);
                break;
            case 1:
                motorNivel->ejecuta(juego1);
                break;
            case 2:
                motorNivel->ejecuta(juego2);
                break;
            case 3:
                motorNivel->ejecuta(juego3);
                break;
            case 4:
                motorNivel->ejecuta(juego4);
                break;
            case 5:
                motorNivel->ejecuta(juego5);
                break;
            default:
                break;
            }

            
            /*
            delete niveles;
            
            delete juego;
            delete juego1;
            delete juego2;
            delete juego3;
            delete juego4;
            delete juego5;
            */
           // delete motor;
           // delete motorNivel;
        }
        catch (const std::exception& excepcion) {

            if (strcmp(excepcion.what(), "LEVEL1") == 0) {
                JuegoNivel::seleccionNivel(1);   
            } 
            else if (strcmp(excepcion.what(), "LEVEL2") == 0) {
                JuegoNivel::seleccionNivel(2);
            }
            else if (strcmp(excepcion.what(), "LEVEL3") == 0) {
                JuegoNivel::seleccionNivel(3);
            }
            else if (strcmp(excepcion.what(), "LEVEL4") == 0) {
                JuegoNivel::seleccionNivel(4);
            }
            else if (strcmp(excepcion.what(), "LEVEL5") == 0) {
                JuegoNivel::seleccionNivel(5);
            }
            else {
                std::cerr << std::endl;
                std::cerr << "********************************************************************************" << std::endl;
                std::cerr << "********************************************************************************" << std::endl;
                std::cerr << std::endl;
                std::cerr << "UNIR-2D :: Juego de Mesa" << std::endl;
                std::cerr << "------------------------" << std::endl;
                std::cerr << std::endl;
                std::cerr << excepcion.what() << std::endl;
                std::cerr << "********************************************************************************" << std::endl;
                std::cerr << "********************************************************************************" << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(5000));
            }
            
        }
    }


    string JuegoNivel::carpeta_activos_juego{ "./activos/" };
    string JuegoNivel::carpeta_retratos_juego{ "./retratos/" };
    string JuegoNivel::carpeta_habilids_juego{ "./habilidades/" };
    string JuegoNivel::carpeta_sonidos_juego{ "./sonidos/" };


    const std::wstring JuegoNivel::tituloVentana() const {
        return L"UNIR-2D :: Selector de Niveles";
    }


    JuegoNivel::JuegoNivel() {

        motor = new unir2d::Motor{};
        motorNivel = new unir2d::Motor{};
       
        ModoJuegoEquipo* modo = new ModoJuegoEquipo{ this };
        SucesosJuegoEquipo* sucesos = new SucesosJuegoEquipo{ this, modo };

        JuegoMesaBase::configura(sucesos, modo);
    }

   


    static ActorTablero::GraficoMuros grafico_muros_vacio{
        "-     -     -     -     -     -     -     -     -",
        "   -     -     -     -     -     -     -     -   ",
        "-     -     -     -     -     -     -     -     -",
        "   -     -     -     -     -     -     -     -   ",
        "-     -     -     -     -     -     -     -     -",
        "   -     -     -     -     -     -     -     -   ",
        "-     -     -     -     -     -     -     -     -",
        "   -     -     -     -     -     -     -     -   ",
        "-     -     -     -     -     -     -     -     -",
        "   -     -     -     -     -     -     -     -   ",
        "-     -     -     -     -     -     -     -     -",
        "   -     -     -     -     -     -     -     -   ",
        "-     -     -     -     -     -     -     -     -" };



    void JuegoNivel::preparaTablero() {

        agregaTablero(new ActorTablero(this));

        tablero()->ponArchivoBaldosas(carpeta_activos_juego + "estampas_fondo.png");
        tablero()->ponArchivoFondo(carpeta_activos_juego + "fondo_volcanes.png");

        tablero()->equipa(LadoTablero::Izquierda, L"Devils", carpeta_activos_juego + "escudo_devils.png");
        tablero()->equipa(LadoTablero::Derecha, L"Tusk", carpeta_activos_juego + "escudo_tusk.png");

        tablero()->situaMuros(grafico_muros_vacio);
       
        tablero()->selectorNiveles();

    }


    void JuegoNivel::preparaPersonajes() {
       
        //
        Miner = new ActorPersonaje{ this, LadoTablero::Izquierda, 0, L"Miner" , Elemento::nulo };
        Aristo = new ActorPersonaje{ this, LadoTablero::Derecha,   0, L"Aristo" , Elemento::nulo };


        //
        Miner->ponArchivoRetrato(carpeta_retratos_juego + "miner1_75.png");
        Aristo->ponArchivoRetrato(carpeta_retratos_juego + "aristocrat_75.png");

        //
        Miner->ponArchivoFicha(carpeta_retratos_juego + "sprite1.png");
        Aristo->ponArchivoFicha(carpeta_retratos_juego + "sprite2.png");

        //
        Miner->ponIniciativa(20);
        Aristo->ponIniciativa(19);

        //
        agregaPersonaje(Miner);
        agregaPersonaje(Aristo);


    }


    void JuegoNivel::preparaHabilidades() {
        
        ataqueEspadaNormal = new Habilidad{
                L"Ataque cuerpo a cuerpo normal",
                EnfoqueHabilidad::personaje, AccesoHabilidad::directo,   Antagonista::oponente , Elemento::nulo };

        //
        ataqueEspadaNormal->ponDescripcion(
            L"El personaje usa su espada para atacar a un enemigo que se encuentra en una casilla próxima.");

        //
        ataqueEspadaNormal->ponArchivosImagenes(
            carpeta_habilids_juego + "espada.png", carpeta_habilids_juego + "fondo_5.png");

        //
        ataqueEspadaNormal->ponArchivoSonido(carpeta_sonidos_juego + "Magic Missiles.wav");

        //
        agregaHabilidad(ataqueEspadaNormal);

        //
        /*******************************************************************************************
        /******************************************************************************************/
    }


    void JuegoNivel::preparaTiposEstadisticas() {

        //
        ataqueCuerpoACuerpo = new TipoAtaque{ L"Ataque cuerpo a cuerpo" };
        ataqueADistancia = new TipoAtaque{ L"Ataque a distancia" };
        ataqueMagico = new TipoAtaque{ L"Ataque mágico" };
        defensaCuerpoACuerpo = new TipoDefensa{ L"Defensa cuerpo a cuerpo" };
        defensaADistancia = new TipoDefensa{ L"Defensa a distancia" };
        defensaMagica = new TipoDefensa{ L"Defensa mágica" };
        danoFisico = new TipoDano{ L"Daño físico" };
        danoMagico = new TipoDano{ L"Daño mágico" };
        //
        agregaAtaque(ataqueCuerpoACuerpo);
        agregaAtaque(ataqueADistancia);
        agregaAtaque(ataqueMagico);
        agregaDefensa(defensaCuerpoACuerpo);
        agregaDefensa(defensaADistancia);
        agregaDefensa(defensaMagica);
        agregaDano(danoFisico);
        agregaDano(danoMagico);
        //
        /*******************************************************************************************
        /******************************************************************************************/
    }


    void JuegoNivel::agregaHabilidadesPersonajes() {

        //
        Miner->agregaHabilidad(ataqueEspadaNormal);



        //
        Aristo->agregaHabilidad(ataqueEspadaNormal);


        //
        /*******************************************************************************************
        /******************************************************************************************/
    }


    void JuegoNivel::agregaEstadisticasHabilidades() {
        /*******************************************************************************************
        /*******************************************************************************************

        CONFIGURACIÓN DEL JUEGO
        Novena sección - Las estadísticas de las habilidades

        En esta sección se establecen diversos atributos y valores para las habilidades del juego,
        incluyendo las estadisticas del juego.

        Estadísticas
        ------------

        Las habilidades se clasifican en habilidades de ataque, de curación y auto-aplicada. Esta
        clasificación se establece mediante el atributo 'Antagonista' de la habilidad.

            - Si 'Antagonista' es 'oponente' la habilidad es de ataque. El ataque puede afectar a un
              personaje o a los personajes de un área del tablero.
            - Si 'Antagonista' es 'aliado' la habilidad es de curación. La curación puede afectar a
              un personaje o a los personajes de un área del tablero.
            - Si 'Antagonista' es 'si_mismo' la habilidad es auto-aplicada.

        Los valores que se establecen para las habilidades son:

             a) Coste: Es el número de puntos de acción que se gastan al usar la habilidad.

             b) Alcance: En las habilidades de ataque y curación debe estar establecido el alcance
                de la habilidad. La habilidad solo se puede usar si el alcance lo permite. Es un
                valor que indica un número de casillas del tablero y debe ser positivo.

             c) Radio de ara de alcance: En las habilidades de ataque y curación que afectan a un
                área del tablero, debe estar establecido el radio del área. Es un valor que indica
                un número de casillas del tablero y debe ser positivo.

             d) Tipo de ataque: Cuando una habilidad es de ataque, debe tener establecido un tipo de
                ataque. El tipo de ataque se usa en el personaje atacante.

             e) Tipo de defensa: Cuando una habilidad es de ataque, debe tener establecido un tipo
                de defensa. El tipo de defensa se usa en el personaje atacado.

             f) Tipo de daño: Cuando una habilidad es de ataque, debe tener establecido un tipo de
                daño. El tipo de daño se usa en el personaje atacado.

             g) Valor del daño: Cuando una habilidad es de ataque, debe tener establecido un valor
                para el daño en puntos de vitalidad. El valor del daño se usa con el personaje
                atacado.

             h) Curación: Cuando una habilidad es de curación, debe tener establecido un valor de
                curación en puntos.

             i) Efecto en ataque: Cuando una habilidad es auto-aplicada, puede tener establecido uno
                o más tipos de ataque, asignado como tipo de efecto en ataque. Alternativamente
                (y excluyentemente) puede tener establecido un efecto en defensa (véase k).

             j) Valor del efecto en ataque: Cuando una habilidad es auto-aplicada, para cada tipo de
                efecto en ataque establecido (véase i), debe tener establecido un valor del efecto
                en ataque en puntos de vitalidad.

             k) Efecto en defensa: Cuando una habilidad es auto-aplicada, puede tener establecido
                uno o más tipos de defensa, asignado como tipo de efecto en defensa. Alternativamente
                (excluyentemente) puede tener establecido un efecto en ataque (véase i).

             l) Valor del efecto en defensa: Cuando una habilidad es auto-aplicada, para cada tipo de
                efecto en defensa establecido (véase k), debe tener establecido un valor del efecto
                en defensa en puntos de vitalidad.


        Programación
        ------------

        Se deben modificar las líneas de código que aparecen a continuación.

        Se deben sustituir las asignaciones de valores por asignaciones similares, obtenidas a
        partir del diseño del juego.

        Los métodos usados en las líneas de código siguientes establecen si se debe usar un tipo de
        ataque, de defensa o de daño. Por ejemplo, el método 'asignaAtaque' debe ser llamado con un
        parámetro del tipo (puntero) 'TipoAtaque'.

        *******************************************************************************************/
        //
        ataqueEspadaNormal->ponCoste(3);
        ataqueEspadaNormal->ponAlcance(1);
        ataqueEspadaNormal->asignaAtaque(ataqueCuerpoACuerpo);
        ataqueEspadaNormal->asignaDefensa(defensaCuerpoACuerpo);
        ataqueEspadaNormal->asignaDano(danoFisico, 20);
        //

        //
        /*******************************************************************************************
        /******************************************************************************************/
    }


    void JuegoNivel::agregaEstadisticasPersonajes() {
        /*******************************************************************************************
        /*******************************************************************************************

        CONFIGURACIÓN DEL JUEGO
        Décima sección - Los tipos de ataque, defensa y reducción de daño de los personajes

        En esta sección se establecen que tipos de ataque, defensa y reducción de daño tiene cada
        personajes del juego, junto con la correspondiente puntuación.

        Configuración
        -------------

        La configuración de los tipos se debe realizar de la siguiente forma:

             a) Si un personaje tiene una habilidad y esta habilidad tiene un tipo de ataque, el
                personaje debe tener ese tipo de ataque.

             b) Cada personaje debe tener todos los tipos de defensa.

             c) Cada personaje debe tener todos los tipos de daño, en forma de reducción de daño.

             d) Si un personaje tiene una habilidad y esta habilidad tiene un efecto en ataque,
                que está definido usando un tipo de ataque, el personaje debe tener dicho tipo de
                ataque.

             e) Si un personaje tiene una habilidad y esta habilidad tiene un efecto en defensa,
                que está definido usando un tipo de defensa, el personaje debe tener dicho tipo de
                defensa. Esta propiedad está establecida previamente mediante el punto (b)

             f) Cada tipo de ataque, defensa y reducción de daño del personaje debe tener una
                puntuación. La puntuación no puede ser negativa.

        Programación
        ------------

        Se deben modificar las líneas de código que aparecen a continuación.

        Se deben sustituir las listas de tipos de ataque, defensa y reducción de daño de cada
        personaje por listas similares, obtenidas a partir del diseño del juego.

        Los métodos usados en las líneas de código siguientes establecen si el tipo es ataque,
        defensa o daño. Por ejemplo, el método 'agregaReduceDano' debe ser llamado con un parámetro
        del tipo (puntero) 'TipoDano'.

        *******************************************************************************************/
        //
        Miner->agregaAtaque(ataqueCuerpoACuerpo, 70);
        Miner->agregaAtaque(ataqueADistancia, 50);
        Miner->agregaDefensa(defensaCuerpoACuerpo, 70);
        Miner->agregaDefensa(defensaADistancia, 70);
        Miner->agregaDefensa(defensaMagica, 20);
        Miner->agregaReduceDano(danoFisico, 10);
        Miner->agregaReduceDano(danoMagico, 5);

        //

        //                       
        Aristo->agregaAtaque(ataqueCuerpoACuerpo, 70);
        Aristo->agregaAtaque(ataqueADistancia, 50);
        Aristo->agregaDefensa(defensaCuerpoACuerpo, 70);
        Aristo->agregaDefensa(defensaADistancia, 70);
        Aristo->agregaDefensa(defensaMagica, 20);
        Aristo->agregaReduceDano(danoFisico, 10);
        Aristo->agregaReduceDano(danoMagico, 5);
        //                       

        //
        /*******************************************************************************************
        /******************************************************************************************/
    }


    void JuegoNivel::preparaSistemaAtaque() {
        /*******************************************************************************************
        /*******************************************************************************************

        CONFIGURACIÓN DEL JUEGO
        Séptima sección - Los grados de efectividad - Segunda parte

        En esta sección se configuran los grados de efectividad de los ataques del juego. En la
        primera parte se establecen las variables destinadas a almacenar las instancias que definen
        los grados de efectividad. En esta parte se crean las instancias y se configuran.

        Las variable usan un nombre similar al nombre de los tipos correspondiente. Las variables
        son de tipo puntero, la creación de las instancias utiliza la palabra reservada 'new'.

        Atributos
        ---------

        Se asignan los siguientes atributos a los tipos:

             a) Descripción: Asignado en la creación de la instancia en una cadena de caracteres.
                Deben ser cortos.

             b) Intervalo de puntos: Es el intervalo de puntos al que se aplica la efectividad.
                Se establece con un valor mínimo y uno máximo. En el primer intervalo el valor
                mínimo es el número entero mínimo y en el último intervalo, el valor máximo es
                el número entero máximo.

             c) Efectividad: Es un porcentaje que se aplica a una puntuación para modificar su
                valor cuando dicha puntuación esta en el intervalo definido por el intervalo
                correspondiente.

        Programación
        ------------

        Se deben modificar las líneas de código que aparecen a continuación.

        Se debe sustituir las listas de creaciones de instancias por listas similares, obtenidas a
        partir de la lista de grados de efectividad diseñados para el juego.

        Se deben cambiar los valores de los parámetros según los valores establecidos para cada
        grados de efectividad en el diseño del juego.

        *******************************************************************************************/
        //
        GradoEfectividad* fallo = new GradoEfectividad{ L"Fallo" };
        GradoEfectividad* roce = new GradoEfectividad{ L"Roce" };
        GradoEfectividad* impacto = new GradoEfectividad{ L"Impacto" };
        GradoEfectividad* critico = new GradoEfectividad{ L"Impacto crítico" };
        //
        fallo->estableceRango(INT_MIN, 9, 0);
        roce->estableceRango(10, 49, 50);
        impacto->estableceRango(50, 89, 100);
        critico->estableceRango(90, INT_MAX, 150);
        //
        agregaEfectividad(fallo);
        agregaEfectividad(roce);
        agregaEfectividad(impacto);
        agregaEfectividad(critico);
        //
        /*******************************************************************************************
        /******************************************************************************************/
    }


    void JuegoNivel::configuraJuego() {
        agregaMusica(new ActorMusica{ this });
        //
        /*******************************************************************************************
        /*******************************************************************************************

        CONFIGURACIÓN DEL JUEGO
        Undécima sección - Configuración miscelánea del juego.

        En esta sección se establecen varios valores de configuración que no tienen sitio en otras
        secciones.

        Configuración
        -------------

        La configuración tiene los siguientes aspectos:

                 a) Se establece el consumo de puntos de acción de los desplazamientos de los
                    personajes. Para ello se indica el número píxeles de desplazamiento que
                    originan el consumo de un punto de acción.

                 b) Se establece la posición inicial de las fichas de los personajes en el tablero
                    de juego.

                 c) Se establecen los archivos de sonido, que se escuchan en momentos concretos del
                    juego. Se deben especificar los sonidos:

                      - Sonido de una pulsación con el ratón (clic)
                      - Sonido de desplazamiento de una ficha.

                 d) Se establece la música que se escucha con el juego. En un fragmento musical que
                    se repite en bucle.

                 e) Se almacenan los nombres de los alumnos diseñadores del juego. Estos nombres
                    aparecen en la ayuda del juego.

                 f) Se almacena el curso académico durante el que los alumnos han elaborado el
                    diseño del juego.

        Sonidos y música
        ----------------

        Los sonidos se cargan de archivos de tipo 'wav', 'ogg' o 'flac', pero no 'mp3'. El tiempo de
        emisión del sonido debe ser corto (escasos segundos).

        Los sonidos y la música se han tomado de:
                https://opengameart.org/content/metal-click
                https://opengameart.org/content/walking-on-snow-sound
        La licencia aparece en esas mismas páginas.

        La música que suena en momentos determinados del juego también se carga de un archivo. Sin
        embargo, no es necesario que sea corta, por que se atenúa a los pocos segundos.

        La música se han tomado de:
                https://opengameart.org/content/unused-music
        La licencia aparece en esa misma página.

        Programación
        ------------

        Se deben modificar las líneas de código que aparecen a continuación.

        Se deben sustituir las listas de personajes por listas similares, obtenidas a partir del
        diseño del juego.

        *******************************************************************************************/
        //
        modo()->configuraDesplaza(RejillaTablero::distanciaCeldas);
        //
        Miner->ponSitioFicha(Coord{ 6, 4 });
        Aristo->ponSitioFicha(Coord{ 6,8 });

        //
        tablero()->asignaSonidoEstablece(carpeta_sonidos_juego + "Metal Click.wav", 100);
        tablero()->asignaSonidoDesplaza(carpeta_sonidos_juego + "SnowWalk.ogg", 100);
        musica()->asignaMusica(carpeta_sonidos_juego + "Silence.ogg", 100);
        //
        agregaNombreAlumno(L"Fulano de Tal");
        agregaNombreAlumno(L"Mengano de Cual");
        agregaNombreAlumno(L"Zutano de Pascual");
        indicaCursoAcademico(L"2022 - 2023");
        //
        /*******************************************************************************************
        /******************************************************************************************/
    }


    void JuegoNivel::termina() {
        //
        JuegoMesaBase::termina();
        //
        Aristo = nullptr;
        Miner = nullptr;
        Male = nullptr;
        //
        ataqueEspadaNormal = nullptr;

        //
        ataqueCuerpoACuerpo = nullptr;
        ataqueADistancia = nullptr;
        ataqueMagico = nullptr;
        defensaCuerpoACuerpo = nullptr;
        defensaADistancia = nullptr;
        defensaMagica = nullptr;
        danoFisico = nullptr;
        danoMagico = nullptr;

        delete motor;
        motor = nullptr;

        delete motorNivel;
        motorNivel = nullptr;
    }


}