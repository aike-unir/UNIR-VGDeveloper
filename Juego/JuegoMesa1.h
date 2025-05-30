// proyecto: Grupal/Juego
// arhivo:   JuegoMesa.h
// versión:  1.1  (9-Ene-2023)


#pragma once


namespace juego1 {


    class JuegoMesa1 : public JuegoMesaBase {
    public:

        JuegoMesa1();

    private:

        ActorPersonaje* Guillermo{};


        ActorPersonaje* Enemigo1{};



        Habilidad* ataqueEspadaNormal{};
        Habilidad* garra{};
        Habilidad* ataqueArco{};
        Habilidad* ataqueEspadaPoderoso{};
        Habilidad* llamarada{};
        Habilidad* defensaFerrea{};
        Habilidad* curacionSimple{};
        Habilidad* curacionGrupo{};


        TipoAtaque* ataqueCuerpoACuerpo{};
        TipoAtaque* ataqueADistancia{};
        TipoDefensa* defensaCuerpoACuerpo{};
        TipoDefensa* defensaADistancia{};
        TipoDano* danoFisico{};


        GradoEfectividad* impacto{};
        GradoEfectividad* critico{};


    private:

        static string carpeta_activos_juego;
        static string carpeta_retratos_juego;
        static string carpeta_habilids_juego;
        static string carpeta_sonidos_juego;

        const std::wstring tituloVentana() const override;

        void preparaTablero() override;
        void preparaPersonajes() override;
        void preparaHabilidades() override;
        void preparaTiposEstadisticas() override;
        void agregaHabilidadesPersonajes() override;
        void agregaEstadisticasHabilidades() override;
        void agregaEstadisticasPersonajes() override;
        void preparaSistemaAtaque() override;
        void configuraJuego() override;
        void termina() override;

    };


}


