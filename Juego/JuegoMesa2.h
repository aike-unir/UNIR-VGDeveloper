// proyecto: Grupal/Juego
// archivo: JuegoMesa2.h
// versión: 1.1 (9-Ene-2023)

#pragma once
#include <string>

namespace juego2 {

    class JuegoMesa2 : public JuegoMesaBase {
    public:

        JuegoMesa2();

        void setTituloVentana(int nivel, const std::wstring& epoca);
        const std::wstring tituloVentana() const override;

    private:

        std::wstring tituloActual{ L"Nivel 2 - Edad de Hielo" }; // Valor inicial

        ActorPersonaje* Guillermo{};
        ActorPersonaje* Wuuf{};
        ActorPersonaje* Rosa{};
        ActorPersonaje* Clint{};
        ActorPersonaje* Panoramix{};

        ActorPersonaje* Enemigo1{};
        ActorPersonaje* Enemigo2{};

        Habilidad* ataqueEspadaNormal{};
        Habilidad* ataqueArco{};
        Habilidad* ataqueEspadaPoderoso{};
        Habilidad* defensaFerrea{};
        Habilidad* curacionSimple{};
        Habilidad* curacionGrupo{};

        TipoAtaque* ataqueCuerpoACuerpo{};
        TipoAtaque* ataqueADistancia{};
        TipoDefensa* defensaCuerpoACuerpo{};
        TipoDefensa* defensaADistancia{};
        TipoDano* danoFisico{};

        GradoEfectividad* fallo{};
        GradoEfectividad* roce{};
        GradoEfectividad* impacto{};
        GradoEfectividad* critico{};

        static string carpeta_activos_juego;
        static string carpeta_retratos_juego;
        static string carpeta_habilids_juego;
        static string carpeta_sonidos_juego;

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

} // Cierre del namespace juego2


