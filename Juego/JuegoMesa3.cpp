// proyecto: Grupal/Juego
// arhivo:   JuegoMesa.cpp
// versi�n:  1.1  (9-Ene-2023)


#include "juego.h"


namespace juego3 {

    string JuegoMesa3::carpeta_activos_juego{ "./activos/" };
    string JuegoMesa3::carpeta_retratos_juego{ "./retratos/" };
    string JuegoMesa3::carpeta_habilids_juego{ "./habilidades/" };
    string JuegoMesa3::carpeta_sonidos_juego{ "./sonidos/" };


    const std::wstring JuegoMesa3::tituloVentana() const {
        return L"Nivel 3 - Espacio exterior";
    }


    JuegoMesa3::JuegoMesa3() {
        ModoJuegoEquipo* modo = new ModoJuegoEquipo{ this };
        SucesosJuegoEquipo* sucesos = new SucesosJuegoEquipo{ this, modo };

        JuegoMesaBase::configura(sucesos, modo);
    }



    static ActorTablero::GraficoMuros grafico_muros_vacio{
        "-     -     P     -     -     -     -     F     -",
        "   -     -     -     -     O     -     -     -   ",
        "-     -     -     -     -     O     -     -     -",
        "   -     -     -     -     -     O     -     -   ",
        "-     -     -     L     -     -     O     -     -",
        "   -     -     -     -     -     -     O     -   ",
        "-     -     -     -     L     -     O     -     -",
        "   -     -     -     -     -     O     -     -   ",
        "-     -     -     -     -     O     O     -     -",
        "   -     -     -     -     -     O     -     -   ",
        "-     -     F     -     -     -     -     -     -",
        "   -     -     -     -     L     -     -     -   ",
        "-     -     -     -     -     -     -     -     -" };



    void JuegoMesa3::preparaTablero() {
        agregaTablero(new ActorTablero(this));

        tablero()->ponArchivoMuro(carpeta_activos_juego + "muro_piedra.png");
        tablero()->ponArchivoBaldosas(carpeta_activos_juego + "tablero.png");
        
       
        tablero()->ponArchivoFondo(carpeta_activos_juego + "fondo_estrellas.png");

        tablero()->equipa(LadoTablero::Izquierda, L"Devils", carpeta_activos_juego + "escudo_devils.png");
        tablero()->equipa(LadoTablero::Derecha, L"Tusk", carpeta_activos_juego + "escudo_tusk.png");

        tablero()->situaMuros(grafico_muros_vacio);

    }


    void JuegoMesa3::preparaPersonajes() {

        Guillermo = new ActorPersonaje{ this, LadoTablero::Izquierda, 0, L"Guillermo" , Elemento::Fuego };
        Wuuf = new ActorPersonaje{ this, LadoTablero::Izquierda, 1, L"Wuuf", Elemento::Hielo };
        Rosa = new ActorPersonaje{ this, LadoTablero::Izquierda, 2, L"Rosa", Elemento::Rayo };


        Enemigo1 = new ActorPersonaje{ this, LadoTablero::Derecha,   0, L"Enemigo1", Elemento::Rayo };
        Enemigo2 = new ActorPersonaje{ this, LadoTablero::Derecha,   1, L"Enemigo2", Elemento::nulo };

        //
        Guillermo->ponArchivoRetrato(carpeta_retratos_juego + "guillermo_retrato.png");
        Wuuf->ponArchivoRetrato(carpeta_retratos_juego + "male1_75.png");
        Rosa->ponArchivoRetrato(carpeta_retratos_juego + "RosaPortreit.png");


        Enemigo1->ponArchivoRetrato(carpeta_retratos_juego + "ElectromentalPortreit.png");
        Enemigo2->ponArchivoRetrato(carpeta_retratos_juego + "aristocrat_75.png");

        //
        Guillermo->ponArchivoFicha(carpeta_retratos_juego + "guillermo_idle.png");
        Wuuf->ponArchivoFicha(carpeta_retratos_juego + "sprite1.png");
        Rosa->ponArchivoFicha(carpeta_retratos_juego + "RosaChar.png");


        Enemigo1->ponArchivoFicha(carpeta_retratos_juego + "sprite2.png");
        Enemigo2->ponArchivoFicha(carpeta_retratos_juego + "Electromental4Frame.png");

        //
        Guillermo->ponIniciativa(20);
        Wuuf->ponIniciativa(18);
        Rosa->ponIniciativa(16);


        Enemigo1->ponIniciativa(19);
        Enemigo2->ponIniciativa(17);

        //
        agregaPersonaje(Guillermo);
        agregaPersonaje(Wuuf);
        agregaPersonaje(Rosa);


        agregaPersonaje(Enemigo1);
        agregaPersonaje(Enemigo2);

    }


    void JuegoMesa3::preparaHabilidades() {

        ataqueEspadaNormal = new Habilidad{
                L"Ataque cuerpo a cuerpo normal",
                EnfoqueHabilidad::personaje, AccesoHabilidad::directo,   Antagonista::oponente, Elemento::nulo };
        ataqueArco = new Habilidad{
                L"Ataque a distancia normal",
                EnfoqueHabilidad::personaje, AccesoHabilidad::directo,   Antagonista::oponente, Elemento::Rayo };
        ataqueEspadaPoderoso = new Habilidad{
                L"Ataque poderoso",
                EnfoqueHabilidad::personaje, AccesoHabilidad::directo,   Antagonista::oponente, Elemento::Hielo };
        llamarada = new Habilidad{
             L"Ataque poderoso de fuego",
             EnfoqueHabilidad::personaje, AccesoHabilidad::directo,   Antagonista::oponente, Elemento::Fuego };
        defensaFerrea = new Habilidad{
                L"Defensa f�rrea",
                EnfoqueHabilidad::si_mismo,  AccesoHabilidad::ninguno,   Antagonista::si_mismo, Elemento::nulo };
        curacionSimple = new Habilidad{
                L"Curaci�n",
                EnfoqueHabilidad::personaje, AccesoHabilidad::directo,   Antagonista::aliado, Elemento::nulo };
        curacionGrupo = new Habilidad{
                L"Curaci�n en grupo",
                EnfoqueHabilidad::area,      AccesoHabilidad::directo,   Antagonista::aliado, Elemento::nulo };

        //
        ataqueEspadaNormal->ponDescripcion(
            L"El personaje usa su espada para atacar a un enemigo que se encuentra en una casilla pr�xima.");
        ataqueArco->ponDescripcion(
            L"El personaje usa su arco para atacar a un enemigo que se encuentra en una casilla pr�xima.");
        ataqueEspadaPoderoso->ponDescripcion(
            L"El personaje blande su espada con fuerza para atacar a un enemigo que se encuentra en una casilla pr�xima.");
        llamarada->ponDescripcion(
            L"El personaje lanza fuego para atacar a un enemigo que se encuentra en una casilla próxima.");
        defensaFerrea->ponDescripcion(
            L"El personaje aumenta su defensa hasta su pr�ximo ronda.");
        curacionSimple->ponDescripcion(
            L"El personaje canaliza poder divino para sanar a un aliado.");
        curacionGrupo->ponDescripcion(
            L"El personaje canaliza poder divino para sanar a todos los personajes en un �rea.");

        //
        ataqueEspadaNormal->ponArchivosImagenes(
            carpeta_habilids_juego + "espada.png", carpeta_habilids_juego + "fondo_5.png");
        ataqueArco->ponArchivosImagenes(
            carpeta_habilids_juego + "arco_flecha.png", carpeta_habilids_juego + "fondo_rayo.png");
        ataqueEspadaPoderoso->ponArchivosImagenes(
            carpeta_habilids_juego + "espada_poderosa.png", carpeta_habilids_juego + "fondo_hielo.png");
        llamarada->ponArchivosImagenes(
            carpeta_habilids_juego + "llamarada.png", carpeta_habilids_juego + "fondo_fuego.png");
        defensaFerrea->ponArchivosImagenes(
            carpeta_habilids_juego + "escudo.png", carpeta_habilids_juego + "fondo_5.png");
        curacionSimple->ponArchivosImagenes(
            carpeta_habilids_juego + "vela.png", carpeta_habilids_juego + "fondo_5.png");
        curacionGrupo->ponArchivosImagenes(
            carpeta_habilids_juego + "vela_triple.png", carpeta_habilids_juego + "fondo_5.png");

        //
        ataqueEspadaNormal->ponArchivoSonido(carpeta_sonidos_juego + "Magic Missiles.wav");
        ataqueArco->ponArchivoSonido(carpeta_sonidos_juego + "Magic Missiles.wav");
        ataqueEspadaPoderoso->ponArchivoSonido(carpeta_sonidos_juego + "Magic Missiles.wav");
        llamarada->ponArchivoSonido(carpeta_sonidos_juego + "arrowFire.wav");
        defensaFerrea->ponArchivoSonido(carpeta_sonidos_juego + "Magic Missiles.wav");
        curacionSimple->ponArchivoSonido(carpeta_sonidos_juego + "Magic Missiles.wav");
        curacionGrupo->ponArchivoSonido(carpeta_sonidos_juego + "Magic Missiles.wav");

        //
        agregaHabilidad(ataqueEspadaNormal);
        agregaHabilidad(ataqueArco);
        agregaHabilidad(ataqueEspadaPoderoso);
        agregaHabilidad(llamarada);
        agregaHabilidad(defensaFerrea);
        agregaHabilidad(curacionSimple);
        agregaHabilidad(curacionGrupo);


    }


    void JuegoMesa3::preparaTiposEstadisticas() {

        //
        ataqueCuerpoACuerpo = new TipoAtaque{ L"Ataque cuerpo a cuerpo" };
        ataqueADistancia = new TipoAtaque{ L"Ataque a distancia" };
        defensaCuerpoACuerpo = new TipoDefensa{ L"Defensa cuerpo a cuerpo" };
        defensaADistancia = new TipoDefensa{ L"Defensa a distancia" };
        danoFisico = new TipoDano{ L"Da�o f�sico" };
        //
        agregaAtaque(ataqueCuerpoACuerpo);
        agregaAtaque(ataqueADistancia);
        agregaDefensa(defensaCuerpoACuerpo);
        agregaDefensa(defensaADistancia);
        agregaDano(danoFisico);

    }


    void JuegoMesa3::agregaHabilidadesPersonajes() {

        Guillermo->agregaHabilidad(ataqueEspadaNormal);
        Guillermo->agregaHabilidad(ataqueEspadaPoderoso);
        Guillermo->agregaHabilidad(defensaFerrea);
        Guillermo->agregaHabilidad(llamarada);


        Wuuf->agregaHabilidad(ataqueEspadaNormal);
        Wuuf->agregaHabilidad(ataqueEspadaPoderoso);
        Wuuf->agregaHabilidad(defensaFerrea);

        Rosa->agregaHabilidad(ataqueEspadaNormal);
        Rosa->agregaHabilidad(ataqueArco);
        Rosa->agregaHabilidad(ataqueEspadaPoderoso);
        Rosa->agregaHabilidad(defensaFerrea);


        //
        Enemigo1->agregaHabilidad(ataqueEspadaNormal);
        Enemigo1->agregaHabilidad(ataqueEspadaPoderoso);
        Enemigo1->agregaHabilidad(defensaFerrea);


        Enemigo2->agregaHabilidad(ataqueEspadaNormal);
        Enemigo2->agregaHabilidad(ataqueEspadaPoderoso);
        Enemigo2->agregaHabilidad(defensaFerrea);

    }


    void JuegoMesa3::agregaEstadisticasHabilidades() {

        //
        ataqueEspadaNormal->ponCoste(3);
        ataqueEspadaNormal->ponAlcance(1);
        ataqueEspadaNormal->asignaAtaque(ataqueCuerpoACuerpo);
        ataqueEspadaNormal->asignaDefensa(defensaCuerpoACuerpo);
        ataqueEspadaNormal->asignaDano(danoFisico, 20);
        //
        ataqueArco->ponCoste(5);
        ataqueArco->ponAlcance(15);
        ataqueArco->asignaAtaque(ataqueADistancia);
        ataqueArco->asignaDefensa(defensaADistancia);
        ataqueArco->asignaDano(danoFisico, 20);
        //
        ataqueEspadaPoderoso->ponCoste(5);
        ataqueEspadaPoderoso->ponAlcance(1);
        ataqueEspadaPoderoso->asignaAtaque(ataqueCuerpoACuerpo);
        ataqueEspadaPoderoso->asignaDefensa(defensaCuerpoACuerpo);
        ataqueEspadaPoderoso->asignaDano(danoFisico, 50);
        //
        llamarada->ponCoste(5);
        llamarada->ponAlcance(1);
        llamarada->asignaAtaque(ataqueCuerpoACuerpo);
        llamarada->asignaDefensa(defensaCuerpoACuerpo);
        llamarada->asignaDano(danoFisico, 50);
        //
        defensaFerrea->ponCoste(3);
        defensaFerrea->agregaEfectoDefensa(defensaCuerpoACuerpo, 30);
        defensaFerrea->agregaEfectoDefensa(defensaADistancia, 30);
        //
        curacionSimple->ponCoste(5);
        curacionSimple->ponAlcance(3);
        curacionSimple->asignaCuracion(40);
        //
        curacionGrupo->ponCoste(10);
        curacionGrupo->ponAlcance(3);
        curacionGrupo->ponRadioAlcance(3);
        curacionGrupo->asignaCuracion(40);
        //

    }


    void JuegoMesa3::agregaEstadisticasPersonajes() {

        //
        Guillermo->agregaAtaque(ataqueCuerpoACuerpo, 70);
        Guillermo->agregaAtaque(ataqueADistancia, 50);
        Guillermo->agregaDefensa(defensaCuerpoACuerpo, 70);
        Guillermo->agregaDefensa(defensaADistancia, 70);
        Guillermo->agregaReduceDano(danoFisico, 10);

        Wuuf->agregaAtaque(ataqueCuerpoACuerpo, 70);
        Wuuf->agregaAtaque(ataqueADistancia, 50);
        Wuuf->agregaDefensa(defensaCuerpoACuerpo, 70);
        Wuuf->agregaDefensa(defensaADistancia, 70);
        Wuuf->agregaReduceDano(danoFisico, 10);

        Rosa->agregaAtaque(ataqueCuerpoACuerpo, 70);
        Rosa->agregaAtaque(ataqueADistancia, 50);
        Rosa->agregaDefensa(defensaCuerpoACuerpo, 70);
        Rosa->agregaDefensa(defensaADistancia, 70);
        Rosa->agregaReduceDano(danoFisico, 10);



        //

        //                       
        Enemigo1->agregaAtaque(ataqueCuerpoACuerpo, 70);
        Enemigo1->agregaAtaque(ataqueADistancia, 50);
        Enemigo1->agregaDefensa(defensaCuerpoACuerpo, 70);
        Enemigo1->agregaDefensa(defensaADistancia, 70);
        Enemigo1->agregaReduceDano(danoFisico, 10);

        Enemigo2->agregaAtaque(ataqueCuerpoACuerpo, 70);
        Enemigo2->agregaAtaque(ataqueADistancia, 50);
        Enemigo2->agregaDefensa(defensaCuerpoACuerpo, 70);
        Enemigo2->agregaDefensa(defensaADistancia, 70);
        Enemigo2->agregaReduceDano(danoFisico, 10);
        //                       


    }


    void JuegoMesa3::preparaSistemaAtaque() {


        //
        GradoEfectividad* impacto = new GradoEfectividad{ L"Impacto" };
        GradoEfectividad* critico = new GradoEfectividad{ L"Impacto crítico" };
        //

        impacto->estableceRango(INT_MIN, 89, 100);
        critico->estableceRango(90, INT_MAX, 150);
        //

        agregaEfectividad(impacto);
        agregaEfectividad(critico);

    }


    void JuegoMesa3::configuraJuego() {
        agregaMusica(new ActorMusica{ this });

        modo()->configuraDesplaza(RejillaTablero::distanciaCeldas);
        //
        Guillermo->ponSitioFicha(Coord{ 1,1 });
        Wuuf->ponSitioFicha(Coord{ 5,1 });
        Rosa->ponSitioFicha(Coord{ 11,1 });


        Enemigo1->ponSitioFicha(Coord{ 5,17 });
        Enemigo2->ponSitioFicha(Coord{ 9,17 });

        //
        tablero()->asignaSonidoEstablece(carpeta_sonidos_juego + "Metal Click.wav", 100);
        tablero()->asignaSonidoDesplaza(carpeta_sonidos_juego + "SnowWalk.ogg", 100);
        musica()->asignaMusica(carpeta_sonidos_juego + "space.ogg", 100);
        //
        agregaNombreAlumno(L"Maksym Chernykh");
        agregaNombreAlumno(L"Aike Fern�ndez Roza");
        agregaNombreAlumno(L"Juli�n Gu�rrez Losada");
        agregaNombreAlumno(L"Carlos Pablos Rivero");
        agregaNombreAlumno(L"Vidal Rodrigo M�nguez");
        indicaCursoAcademico(L"2024 - 2025");

    }


    void JuegoMesa3::termina() {
        //
        // JuegoMesaBase::termina();
        //
        Guillermo = nullptr;
        Wuuf = nullptr;
        Rosa = nullptr;

        Enemigo1 = nullptr;
        Enemigo2 = nullptr;

        //
        ataqueEspadaNormal = nullptr;
        ataqueArco = nullptr;
        ataqueEspadaPoderoso = nullptr;
        defensaFerrea = nullptr;
        curacionSimple = nullptr;
        curacionGrupo = nullptr;

        //
        ataqueCuerpoACuerpo = nullptr;
        ataqueADistancia = nullptr;
        defensaCuerpoACuerpo = nullptr;
        defensaADistancia = nullptr;
        danoFisico = nullptr;
    }


}