-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Consulta para encontrar o relatório da cena do crime para o roubo do pato
SELECT *
FROM crime_scene_reports
WHERE year = 2020
AND month = 7
AND day = 28
AND street = 'Chamberlin Street';
-- Consulta para encontrar entrevistas realizadas na data do roubo
SELECT *
FROM interviews
WHERE year = 2020
AND month = 7
AND day = 28;
-- Consulta para verificar logs de segurança do tribunal na data do roubo
SELECT *
FROM courthouse_security_logs
WHERE year = 2020
AND month = 7
AND day = 28;
-- Consulta para verificar registros de transações de caixas eletrônicos na data do roubo
SELECT *
FROM atm_transactions
WHERE year = 2020
AND month = 7
AND day = 28;
-- Consulta para verificar registros de voos na data do roubo
SELECT *
FROM flights
WHERE year = 2020
AND month = 7
AND day = 28;
-- Consulta para verificar registros de chamadas telefônicas na data do roubo
SELECT *
FROM phone_calls
WHERE year = 2020
AND month = 7
AND day = 28;


