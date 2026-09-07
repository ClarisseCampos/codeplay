

from manim import *


class DemonstracaoEnergiaPotencial(Scene):

    COR_U = PURPLE
    COR_G = BLUE
    COR_M = ORANGE
    COR_R = RED
    COR_H = YELLOW
    COR_DESTAQUE = BLUE     # termo que vai virar g
    COR_RESULTADO = GREEN

    def construct(self):

        marcador = Text("", font_size=24, color=GRAY_B)
        marcador.to_corner(UL)
        self.play(FadeIn(marcador))

        # Lei da gravitação universal + LEGENDA

        formula_geral = MathTex(
            r"U", r"=", r"-G", r"\frac{m_1 m_2}{", r"r", r"}",
            font_size=48,
        )
        formula_geral.shift(UP * 1.8)
        formula_geral[0].set_color(self.COR_U)   # U
        formula_geral[2].set_color(self.COR_G)   # -G
        formula_geral[3].set_color(self.COR_M)   # m_1 m_2
        formula_geral[4].set_color(self.COR_R)   # r

        self.play(Write(formula_geral))
        self.wait(1)

        def linha_legenda(simbolo_tex, explicacao, cor):
            simbolo = MathTex(simbolo_tex, color=cor, font_size=30)
            texto = Text(explicacao, font_size=24)
            return VGroup(simbolo, texto).arrange(RIGHT, buff=0.2)

        legenda_U = linha_legenda("U", "energia potencial gravitacional", self.COR_U)
        legenda_G = linha_legenda("G", "constante gravitacional universal", self.COR_G)
        legenda_M = linha_legenda("m_1, m_2", "massas dos dois corpos", self.COR_M)
        legenda_R = linha_legenda("r", "distância entre os centros de massa", self.COR_R)

        legenda = VGroup(legenda_U, legenda_G, legenda_M, legenda_R).arrange(
            DOWN, aligned_edge=LEFT, buff=0.25
        )
        legenda.next_to(formula_geral, DOWN, buff=0.6)

        termos = [formula_geral[0], formula_geral[2], formula_geral[3], formula_geral[4]]
        linhas = [legenda_U, legenda_G, legenda_M, legenda_R]

        for termo, linha in zip(termos, linhas):
            self.play(Indicate(termo, scale_factor=1.3), FadeIn(linha))
            self.wait(0.3)

        self.wait(1.5)
        self.play(FadeOut(legenda))

        nota_especial = Text(
            "Aqui: m₁ = M (massa da Terra), m₂ = m (massa do objeto)",
            font_size=22,
            color=GRAY_B,
        )
        nota_especial.next_to(formula_geral, DOWN, buff=0.6)
        self.play(Write(nota_especial))

        formula_especial = MathTex(
            r"U", r"=", r"-G", r"\frac{Mm}{", r"r", r"}",
            font_size=48,
        )
        formula_especial.move_to(formula_geral)

        self.play(TransformMatchingTex(formula_geral, formula_especial))
        self.wait(1.5)
        self.play(FadeOut(nota_especial), FadeOut(formula_especial))

        # Definição de ΔU

        passo1 = MathTex(r"\Delta U = U(R+h) - U(R)", font_size=32)
        passo1.shift(UP * 1.2)

        passo1_exp = MathTex(
            r"\Delta U = -G\frac{Mm}{R+h} - \left( -G\frac{Mm}{R} \right)",
            font_size=32,
        )
        passo1_exp.next_to(passo1, DOWN, buff=0.4)

        self.play(Write(passo1))
        self.wait(1)
        self.play(Write(passo1_exp))
        self.wait(2)

        # Fatoração

        passo2 = MathTex(
            r"\Delta U = GMm \left( \frac{1}{R} - \frac{1}{R+h} \right)",
            font_size=32,
        )
        passo2.move_to(UP * 0.3)

        self.play(FadeOut(passo1), TransformMatchingShapes(passo1_exp, passo2))
        self.wait(1)

        passo2_alg = MathTex(
            r"\Delta U = GMm \cdot \frac{h}{",
            r"R(R+h)",
            r"}",
            font_size=32,
        )
        passo2_alg.move_to(passo2)

        self.play(TransformMatchingShapes(passo2, passo2_alg))
        self.wait(2)

        # Aproximação h = R

        self.play(passo2_alg.animate.shift(UP * 1.5))

        destaque = SurroundingRectangle(passo2_alg[1], color=self.COR_H, buff=0.08)

        texto_aprox = Text(
            "Para pequenas alturas, R + h ≈ R",
            font_size=24,
            color=self.COR_H,
        )
        texto_aprox.next_to(passo2_alg, DOWN, buff=0.5)

        self.play(Create(destaque))
        self.play(Write(texto_aprox))
        self.wait(1.5)
        self.play(FadeOut(destaque))

        passo3 = MathTex(
            r"\Delta U \approx",
            r"\frac{GM}{R^2}",
            r"\cdot m \cdot h",
            font_size=34,
        )
        passo3.next_to(texto_aprox, DOWN, buff=0.45)
        passo3[1].set_color(self.COR_DESTAQUE)

        self.play(Write(passo3))
        self.wait(2)

        # Reconhecendo o g

        self.play(FadeOut(passo2_alg), FadeOut(texto_aprox))
        self.play(passo3.animate.move_to(UP * 1.0))

        passo4_g = MathTex(
            r"\text{Sabemos que } g = \frac{GM}{R^2}",
            font_size=28,
            color=self.COR_DESTAQUE,
        )
        passo4_g.next_to(passo3, DOWN, buff=0.5)

        self.play(Write(passo4_g))
        self.wait(1.5)

        resultado_final = MathTex(
            r"E_p =",
            r"g",
            r"\cdot m \cdot h",
            font_size=44,
            color=self.COR_RESULTADO,
        )
        resultado_final.move_to(DOWN * 0.6)

        self.play(FadeOut(passo4_g), TransformMatchingTex(passo3, resultado_final))
        self.wait(0.5)

        caixa = SurroundingRectangle(
            resultado_final, color=self.COR_RESULTADO, buff=0.2, corner_radius=0.08
        )
        self.play(FadeOut(marcador), Create(caixa))
        self.wait(3)