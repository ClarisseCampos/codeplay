
from manim import *


# ==========================================================
# CONFIGURAÇÃO DO VÍDEO
# ==========================================================

config.pixel_width = 1920
config.pixel_height = 1080
config.frame_rate = 60


class AnimacaoHorizontal(MovingCameraScene):

    # ======================================================
    # CONFIGURAÇÃO CENTRAL
    # ======================================================

    RAIO_TERRA = 4.8
    POS_TERRA = LEFT * 4.0 + DOWN * 3.0

    ALTURA_H = 1.15
    POS_PAINEL = RIGHT * 6.3 + DOWN * 0.45

    ZOOM_LARGURA = 24
    ZOOM_CENTRO = RIGHT * 2.0 + DOWN * 1.5

    COR_TERRA = BLUE_D
    COR_H = YELLOW

    # ======================================================
    # CONSTRUÇÃO DA CENA
    # ======================================================

    def construct(self):

        # ==================================================
        # 1. TERRA
        # ==================================================

        terra = Circle(
            radius=self.RAIO_TERRA,
            color=self.COR_TERRA,
            fill_opacity=0.30,
            stroke_width=5,
        )

        terra.move_to(self.POS_TERRA)

        centro = terra.get_center()
        topo = terra.get_top()

        rotulo_terra = Text(
            "Terra",
            font_size=40,
            color=BLUE_A,
        )

        rotulo_terra.move_to(
            centro + DOWN * 0.3
        )

        self.play(
            Create(terra),
            run_time=1,
        )

        self.play(
            Write(rotulo_terra),
            run_time=0.5,
        )

        self.wait(0.5)

        # ==================================================
        # 2. ALTURA h
        # ==================================================

        ponto_h = topo + UP * self.ALTURA_H

        linha_h = DoubleArrow(
            topo,
            ponto_h,
            buff=0,
            color=self.COR_H,
            stroke_width=4,
        )

        rotulo_h = MathTex(
            r"h \approx 63{,}7\text{ km}",
            font_size=35,
            color=self.COR_H,
        )

        rotulo_h.next_to(
            linha_h,
            RIGHT,
            buff=0.18,
        )

        objeto = Dot(
            ponto_h,
            color=self.COR_H,
            radius=0.13,
        )

        referencia_h = DashedLine(
            ponto_h + LEFT * 0.45,
            ponto_h + RIGHT * 0.45,
            color=self.COR_H,
            stroke_width=2,
        )

        self.play(
            GrowFromPoint(
                linha_h,
                topo,
            ),
            Create(objeto),
            Write(rotulo_h),
            Create(referencia_h),
            run_time=1.2,
        )

        self.wait(1)

        # ==================================================
        # 3. PRÉ-CÁLCULO
        # ==================================================

        linha_raio = Line(
            centro,
            topo,
            color=WHITE,
            stroke_width=4,
        )

        rotulo_R = MathTex(
            r"R \approx 6371\text{ km}",
            font_size=45,
        )

        rotulo_R.next_to(
            linha_raio,
            LEFT,
            buff=0.18,
        )

        # ==================================================
        # EQUAÇÃO DO ERRO
        # ==================================================

        eq_erro = MathTex(
            r"\text{Erro} \approx \frac{h}{R}",
            font_size=45,
        )

        # ==================================================
        # CÁLCULO
        # ==================================================

        eq_calc = MathTex(
            r"\text{Erro} = "
            r"\frac{63{,}7}{6371}"
            r" = 0{,}01 = 1\%",
            font_size=45,
            color=GREEN,
        )

        caixa = SurroundingRectangle(
            eq_calc,
            color=GREEN,
            buff=0.28,
            corner_radius=0.08,
            stroke_width=3,
        )

        # ==================================================
        # TEXTO EXPLICATIVO
        # ==================================================

        linha1 = Tex(
            r"Abaixo de ",
            r"\textbf{63,7 km}",
            r", a aproximação",
            font_size=45,
        )

        linha1[1].set_color(YELLOW)

        linha2 = Tex(
            r"$E_p = m \cdot g \cdot h$ possui menos de ",
            r"\textbf{1\%}",
            font_size=45,
        )

        linha2[1].set_color(YELLOW)

        linha3 = Tex(
            r"de erro em relação à fórmula real.",
            font_size=45,
            color=GRAY_A,
        )

        explicacao = VGroup(
            linha1,
            linha2,
            linha3,
        ).arrange(
            DOWN,
            aligned_edge=LEFT,
            buff=0.3,
        )

        # ==================================================
        # PAINEL
        # ==================================================

        painel = VGroup(
            eq_erro,
            VGroup(
                eq_calc,
                caixa,
            ),
            explicacao,
        ).arrange(
            DOWN,
            aligned_edge=LEFT,
            buff=0.40,
        )

        painel.move_to(
            self.POS_PAINEL
        )

        # ==================================================
        # 4. ZOOM OUT
        # ==================================================

        self.play(
            self.camera.frame.animate
            .move_to(self.ZOOM_CENTRO)
            .set(width=self.ZOOM_LARGURA),
            run_time=1.6,
        )

        self.wait(0.5)

        # ==================================================
        # 5. TERRA INTEIRA REVELADA
        # ==================================================

        self.play(
            FadeOut(referencia_h),
            run_time=0.4,
        )

        self.wait(0.3)

        # ==================================================
        # 6. RAIO DA TERRA
        # ==================================================

        self.play(
            Create(linha_raio),
            Write(rotulo_R),
            run_time=1,
        )

        self.wait(0.7)

        # ==================================================
        # 7. EQUAÇÃO DO ERRO
        # ==================================================

        self.play(
            Write(eq_erro),
            run_time=0.8,
        )

        self.wait(0.4)

        # ==================================================
        # 8. CÁLCULO DO ERRO
        # ==================================================

        self.play(
            Write(eq_calc),
            Create(caixa),
            run_time=1,
        )

        self.wait(0.5)

        # ==================================================
        # 9. EXPLICAÇÃO
        # ==================================================

        self.play(
            FadeIn(
                explicacao,
                shift=UP * 0.15,
            ),
            run_time=1,
        )

        self.wait(2)

        # ==================================================
        # 10. ENCERRAMENTO
        # ==================================================

        self.play(
            *[
                FadeOut(m)
                for m in self.mobjects
            ],
            run_time=1,
        )

