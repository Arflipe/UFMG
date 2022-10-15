#include "doctest.h"
#include "DiarioClasse.hpp"

TEST_CASE("Teste 05 - Excecao Frequencia") {
	DiarioClasse diario;
	CHECK_THROWS_AS(diario.determinarAprovacao(100, 0, -0.1), ExcecaoFrequenciaInvalida);
}

TEST_CASE("Teste 06 - Excecao NotaSemestre") {
	DiarioClasse diario;
	CHECK_THROWS_AS(diario.determinarAprovacao(-100, 0, 1), ExcecaoNotaSemestreInvalida);
}

TEST_CASE("Teste 07 - Excecao NotaEspecial") {
	DiarioClasse diario;
	CHECK_THROWS_AS(diario.determinarAprovacao(100, 150, 1), ExcecaoNotaEspecialInvalida);
}

TEST_CASE("Teste 08 - Excecao NotaEspecial") {
	DiarioClasse diario;
	CHECK_THROWS_AS(diario.determinarAprovacao(100, -100, 1), ExcecaoNotaEspecialInvalida);
}

TEST_CASE("Teste 09 - >= 60, sem Exame, sem Frequencia") {
	DiarioClasse diario;
	bool aprovado = diario.determinarAprovacao(100, 0, 0);
	CHECK_FALSE(aprovado);
};

TEST_CASE("Teste 10 - < 40, Exame, Frequencia") {
	DiarioClasse diario;
	bool aprovado = diario.determinarAprovacao(39, 60, 0.75);
	CHECK_FALSE(aprovado);
};

TEST_CASE("Teste 11 - >= 60, sem Exame, Frequencia") {
	DiarioClasse diario;
	bool aprovado = diario.determinarAprovacao(80, 0, 0.80);
	CHECK(aprovado);
};

TEST_CASE("Teste 12 - >= 40, Exame, sem Frequencia") {
	DiarioClasse diario;
	bool aprovado = diario.determinarAprovacao(40, 100, 0.7);
	CHECK_FALSE(aprovado);
};

TEST_CASE("Teste 13 - >= 60, Exame, Frequencia") {
	DiarioClasse diario;
	bool aprovado = diario.determinarAprovacao(80, 100, 0.9);
	CHECK(aprovado);
};

TEST_CASE("Teste 14 - < 40, sem Exame, sem Frequencia") {
	DiarioClasse diario;
	bool aprovado = diario.determinarAprovacao(30, 0, 0.7);
	CHECK_FALSE(aprovado);
};