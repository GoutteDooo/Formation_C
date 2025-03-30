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
-- id   name     year  month  day  transcript                                                  
-- ---  -------  ----  -----  ---  ------------------------------------------------------------
-- 161  Ruth     2024  7      28   Sometime within ten minutes of the theft, I saw the thief ge
--                                 t into a car in the bakery parking lot and drive away. If yo
--                                 u have security footage from the bakery parking lot, you mig
--                                 ht want to look for cars that left the parking lot in that t
--                                 ime frame.                                                  

-- 162  Eugene   2024  7      28   I don't know the thief's name, but it was someone I recogniz
--                                 ed. Earlier this morning, before I arrived at Emma's bakery,
--                                  I was walking by the ATM on Leggett Street and saw the thie
--                                 f there withdrawing some money.                             

-- 163  Raymond  2024  7      28   As the thief was leaving the bakery, they called someone who
--                                  talked to them for less than a minute. In the call, I heard
--                                  the thief say that they were planning to take the earliest 
--                                 flight out of Fiftyville tomorrow. The thief then asked the 
--                                 person on the other end of the phone to purchase the flight 
--                                 ticket.                                                    

--Get the range of moments when the thief exited the parking of the bakery.
SELECT * FROM bakery_security_logs WHERE year='2024' AND month='7' AND day='28' AND hour < '11' AND minute > '15' AND minute < '30' AND activity LIKE 'exit';
