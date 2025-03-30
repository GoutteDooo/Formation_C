-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Obtain the description of the crime scene report that contains the word "CS50".
SELECT * FROM crime_scene_reports WHERE description LIKE "%CS50 duck%";
-- id   year  month  day  street           description                                                 
-- ---  ----  -----  ---  ---------------  ------------------------------------------------------------
-- 295  2024  7      28   Humphrey Street  Theft of the CS50 duck took place at 10:15am at the Humphrey
--                                          Street bakery. Interviews were conducted today with three w
--                                         itnesses who were present at the time – each of their interv
--                                         iew transcripts mentions the bakery. 

-- Obtain the interviews of interviewees who were present at the theft.
SELECT * FROM interviews WHERE year='2024' AND month='7' AND day='28' AND transcript LIKE "%thief%" OR "%theft%";