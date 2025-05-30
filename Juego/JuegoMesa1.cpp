// proyecto: Grupal/Juego
// arhivo:   JuegoMesa.cpp
// versión:  1.1  (9-Ene-2023)


#include "juego.h"


namespace juego1 {

    string JuegoMesa1::carpeta_activos_juego{ "./activos/" };
    string JuegoMesa1::carpeta_retratos_juego{ "./retratos/" };
    string JuegoMesa1::carpeta_habilids_juego{ "./habilidades/" };
    string JuegoMesa1::carpeta_sonidos_juego{ "./sonidos/" };


    const std::wstring JuegoMesa1::tituloVentana() const {
        return L"Nivel 1 - Volcan Edad Media";
    }


    JuegoMesa1::JuegoMesa1() {
        ModoJuegoEquipo* modo = new ModoJuegoEquipo{ this };
        SucesosJuegoEquipo* sucesos = new SucesosJuegoEquipo{ this, modo };

        JuegoMesaBase::configura(sucesos, modo);
    }



    static ActorTablero::GraficoMuros grafico_muros_vacio{
        "-     -     -     O     O     O     O     O     O",
        "   -     -     -     O     O     O     O     O   ",
        "-     -     -     -     O     O     O     O     O",
        "   -     -     -     -     O     O     O     O   ",
        "-     -     -     -     F     O     O     O     O",
        "   -     -     -     -     -     F     F     F   ",
        "-     -     -     -     F     F     F     F     -",
        "   -     -     -     -     -     F     F     F   ",
        "-     -     -     -     F     O     O     O     O",
        "   -     -     -     -     O     O     O     O   ",
        "-     -     -     -     O     O     O     O     O",
        "   -     -     -     O     O     O     O     O   ",
        "-     -     -     O     O     O     O     O     O" };



    void JuegoMesa1::preparaTablero() {
        agregaTablero(new ActorTablero(this));

        tablero()->ponArchivoMuro(carpeta_activos_juego + "muro_piedra.png");
        tablero()->ponArchivoBaldosas(carpeta_activos_juego + "suelo_lava.png");
        tablero()->ponArchivoFondo(carpeta_activos_juego + "fondo_volcanes.png");

        tablero()->equipa(LadoTablero::Izquierda, L"Devils", carpeta_activos_juego + "escudo_devils.png");
        tablero()->equipa(LadoTablero::Derecha, L"Tusk", carpeta_activos_juego + "escudo_tusk.png");

        tablero()->situaMuros(grafico_muros_vacio);

    }


    void JuegoMesa1::preparaPersonajes() {

        Guillermo = new ActorPersonaje{ this, LadoTablero::Izquierda, 0, L"Guillermo" , Elemento::Fuego };


        Enemigo1 = new ActorPersonaje{ this, LadoTablero::Derecha,   0, L"Enemigo1", Elemento::nulo };


        //
        Guillermo->ponArchivoRetrato(carpeta_retratos_juego + "guillermo_retrato.png");


        Enemigo1->ponArchivoRetrato(carpeta_retratos_juego + "dragon_retrato.png");

        //
        Guillermo->ponArchivoFicha(carpeta_retratos_juego + "guillermo_idle.png");


        Enemigo1->ponArchivoFicha(carpeta_retratos_juego + "dragon_idle.png");

        //
        Guillermo->ponIniciativa(20);


        Enemigo1->ponIniciativa(19);

        //
        agregaPersonaje(Guillermo);


        agregaPersonaje(Enemigo1);

    }


    void JuegoMesa1::preparaHabilidades() {

        ataqueEspadaNormal = new Habilidad{
                L"Ataque cuerpo a cuerpo normal",
                EnfoqueHabilidad::personaje, AccesoHabilidad::directo,   Antagonista::oponente, Elemento::nulo };
        garra = new Habilidad{
                L"Ataque cuerpo a cuerpo normal",
                EnfoqueHabilidad::personaje, AccesoHabilidad::directo,   Antagonista::oponente, Elemento::nulo };
        ataqueArco = new Habilidad{
                L"Ataque a distancia normal",
                EnfoqueHabilidad::personaje, AccesoHabilidad::directo,   Antagonista::oponente, Elemento::nulo };
        ataqueEspadaPoderoso = new Habilidad{
                L"Ataque poderoso de Hielo",
                EnfoqueHabilidad::personaje, AccesoHabilidad::directo,   Antagonista::oponente, Elemento::Hielo };
        llamarada = new Habilidad{
                L"Ataque poderoso de fuego",
                EnfoqueHabilidad::personaje, AccesoHabilidad::directo,   Antagonista::oponente, Elemento::Fuego };
        defensaFerrea = new Habilidad{
                L"Defensa férrea",
                EnfoqueHabilidad::si_mismo,  AccesoHabilidad::ninguno,   Antagonista::si_mismo, Elemento::nulo };
        curacionSimple = new Habilidad{
                L"Curación",
                EnfoqueHabilidad::personaje, AccesoHabilidad::directo,   Antagonista::aliado, Elemento::nulo };
        curacionGrupo = new Habilidad{
                L"Curación en grupo",
                EnfoqueHabilidad::area,      AccesoHabilidad::directo,   Antagonista::aliado, Elemento::nulo };

        //
        ataqueEspadaNormal->ponDescripcion(
            L"El personaje usa su espada para atacar a un enemigo que se encuentra en una casilla próxima.");
        garra->ponDescripcion(
            L"El personaje usa su garra para atacar a un enemigo que se encuentra en una casilla próxima.");
        ataqueArco->ponDescripcion(
            L"El personaje usa su arco para atacar a un enemigo que se encuentra en una casilla próxima.");
        ataqueEspadaPoderoso->ponDescripcion(
            L"El personaje blande su espada con fuerza para atacar a un enemigo que se encuentra en una casilla próxima.");
        llamarada->ponDescripcion(
            L"El personaje lanza fuego para atacar a un enemigo que se encuentra en una casilla próxima.");
        defensaFerrea->ponDescripcion(
            L"El personaje aumenta su defensa hasta su próximo ronda.");
        curacionSimple->ponDescripcion(
            L"El personaje canaliza poder divino para sanar a un aliado.");
        curacionGrupo->ponDescripcion(
            L"El personaje canaliza poder divino para sanar a todos los personajes en un área.");

        //
        ataqueEspadaNormal->ponArchivosImagenes(
            carpeta_habilids_juego + "espada.png", carpeta_habilids_juego + "fondo_5.png");
        garra->ponArchivosImagenes(
            carpeta_habilids_juego + "garra.png", carpeta_habilids_juego + "fondo_5.png");
        ataqueArco->ponArchivosImagenes(
            carpeta_habilids_juego + "arco_flecha.png", carpeta_habilids_juego + "fondo_5.png");
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
        garra->ponArchivoSonido(carpeta_sonidos_juego + "Magic Missiles.wav");
        ataqueArco->ponArchivoSonido(carpeta_sonidos_juego + "Magic Missiles.wav");
        ataqueEspadaPoderoso->ponArchivoSonido(carpeta_sonidos_juego + "Magic Missiles.wav");
        llamarada->ponArchivoSonido(carpeta_sonidos_juego + "arrowFire.wav");
        defensaFerrea->ponArchivoSonido(carpeta_sonidos_juego + "Magic Missiles.wav");
        curacionSimple->ponArchivoSonido(carpeta_sonidos_juego + "Magic Missiles.wav");
        curacionGrupo->ponArchivoSonido(carpeta_sonidos_juego + "Magic Missiles.wav");

        //
        agregaHabilidad(ataqueEspadaNormal);
        agregaHabilidad(garra);
        agregaHabilidad(ataqueArco);
        agregaHabilidad(ataqueEspadaPoderoso);
        agregaHabilidad(llamarada);
        agregaHabilidad(defensaFerrea);
        agregaHabilidad(curacionSimple);
        agregaHabilidad(curacionGrupo);


    }


    void JuegoMesa1::preparaTiposEstadisticas() {

        //
        ataqueCuerpoACuerpo = new TipoAtaque{ L"Ataque cuerpo a cuerpo" };
        ataqueADistancia = new TipoAtaque{ L"Ataque a distancia" };
        defensaCuerpoACuerpo = new TipoDefensa{ L"Defensa cuerpo a cuerpo" };
        defensaADistancia = new TipoDefensa{ L"Defensa a distancia" };
        danoFisico = new TipoDano{ L"Daño físico" };
        //
        agregaAtaque(ataqueCuerpoACuerpo);
        agregaAtaque(ataqueADistancia);
        agregaDefensa(defensaCuerpoACuerpo);
        agregaDefensa(defensaADistancia);
        agregaDano(danoFisico);

    }


    void JuegoMesa1::agregaHabilidadesPersonajes() {

        Guillermo->agregaHabilidad(ataqueEspadaNormal);
        Guillermo->agregaHabilidad(ataqueArco);
        Guillermo->agregaHabilidad(ataqueEspadaPoderoso);
        Guillermo->agregaHabilidad(defensaFerrea);


        //
        Enemigo1->agregaHabilidad(garra);
        Enemigo1->agregaHabilidad(llamarada);
        


    }


    void JuegoMesa1::agregaEstadisticasHabilidades() {

        //
        ataqueEspadaNormal->ponCoste(3);
        ataqueEspadaNormal->ponAlcance(1);
        ataqueEspadaNormal->asignaAtaque(ataqueCuerpoACuerpo);
        ataqueEspadaNormal->asignaDefensa(defensaCuerpoACuerpo);
        ataqueEspadaNormal->asignaDano(danoFisico, 20);
        //
        garra->ponCoste(3);
        garra->ponAlcance(1);
        garra->asignaAtaque(ataqueCuerpoACuerpo);
        garra->asignaDefensa(defensaCuerpoACuerpo);
        garra->asignaDano(danoFisico, 20);
        //
        ataqueArco->ponCoste(5);
        ataqueArco->ponAlcance(15);
        ataqueArco->asignaAtaque(ataqueADistancia);
        ataqueArco->asignaDefensa(defensaADistancia);
        ataqueArco->asignaDano(danoFisico, 20);
        //
        ataqueEspadaPoderoso->ponCoste(5);
        ataqueEspadaPoderoso->ponAlcance(3);
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


    void JuegoMesa1::agregaEstadisticasPersonajes() {

        //
        Guillermo->agregaAtaque(ataqueCuerpoACuerpo, 70);
        Guillermo->agregaAtaque(ataqueADistancia, 50);
        Guillermo->agregaDefensa(defensaCuerpoACuerpo, 70);
        Guillermo->agregaDefensa(defensaADistancia, 70);
        Guillermo->agregaReduceDano(danoFisico, 10);


        //

        //                       
        Enemigo1->agregaAtaque(ataqueCuerpoACuerpo, 70);
        Enemigo1->agregaAtaque(ataqueADistancia, 50);
        Enemigo1->agregaDefensa(defensaCuerpoACuerpo, 70);
        Enemigo1->agregaDefensa(defensaADistancia, 70);
        Enemigo1->agregaReduceDano(danoFisico, 10);


        //                       


    }


    void JuegoMesa1::preparaSistemaAtaque() {


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


    void JuegoMesa1::configuraJuego() {
        agregaMusica(new ActorMusica{ this });

        modo()->configuraDesplaza(RejillaTablero::distanciaCeldas);
        //
        Guillermo->ponSitioFicha(Coord{ 7,1 });


        Enemigo1->ponSitioFicha(Coord{ 7,17 });

        //
        tablero()->asignaSonidoEstablece(carpeta_sonidos_juego + "Metal Click.wav", 100);
        tablero()->asignaSonidoDesplaza(carpeta_sonidos_juego + "SnowWalk.ogg", 100);
        musica()->asignaMusica(carpeta_sonidos_juego + "medieval.wav", 100);
        //
        agregaNombreAlumno(L"Maksym Chernykh");
        agregaNombreAlumno(L"Aike Fernández Roza");
        agregaNombreAlumno(L"Julián Guérrez Losada");
        agregaNombreAlumno(L"Carlos Pablos Rivero");
        agregaNombreAlumno(L"Vidal Rodrigo Mínguez");
        indicaCursoAcademico(L"2024 - 2025");

    }


    void JuegoMesa1::termina() {
        //
        // JuegoMesaBase::termina();
        //
        Guillermo = nullptr;

        Enemigo1 = nullptr;

        //
        ataqueEspadaNormal = nullptr;
        ataqueArco = nullptr;
        ataqueEspadaPoderoso = nullptr;
        defensaFerrea = nullptr;
        curacionSimple = nullptr;
        curacionGrupo = nullptr;
        garra = nullptr;
        llamarada = nullptr;

        //
        ataqueCuerpoACuerpo = nullptr;
        ataqueADistancia = nullptr;
        defensaCuerpoACuerpo = nullptr;
        defensaADistancia = nullptr;
        danoFisico = nullptr;
    }


}