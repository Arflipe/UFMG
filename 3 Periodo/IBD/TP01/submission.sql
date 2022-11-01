-- 2021031920
-- A2
SELECT DISTINCT estadio
FROM (local NATURAL JOIN partidas)
WHERE ano = 1958;
-- A0
SELECT DISTINCT nome_jogador
FROM jogadores
WHERE numero_camisa = 14;
-- A3
SELECT DISTINCT nome_treinador
FROM (jogadores NATURAL JOIN partidas)
WHERE gols_mandante >= 7;
-- A1
SELECT DISTINCT nome_jogador
FROM (jogadores NATURAL JOIN partidas)
WHERE iniciais_time = 'ITA' AND ano = 1994;
-- A4
SELECT DISTINCT time_mandante
FROM (copasdomundo NATURAL JOIN partidas)
WHERE gols_marcados >= 150;
-- B3
SELECT DISTINCT cidade , pais
FROM ((copasdomundo NATURAL JOIN partidas) NATURAL JOIN local)
GROUP BY cidade
HAVING COUNT(cidade) > 1;
-- B1
SELECT DISTINCT iniciais_time, nome_treinador
FROM (jogadores NATURAL JOIN partidas)
WHERE ano = 1970 AND fase = 'Quartas de Final';
-- B9
SELECT DISTINCT juiz, data_hora, publico
FROM (arbitragem NATURAL JOIN partidas)
WHERE ano = 2010 ORDER BY publico DESC LIMIT 5;
-- B2
SELECT id_partida, data_hora, ano
FROM partidas
WHERE fase = 'Final';
-- B0
SELECT DISTINCT juiz, assistente_um, assistente_dois
FROM (arbitragem NATURAL JOIN partidas)
WHERE ano=2014 AND (fase = 'Semifinal' OR fase = 'Final');