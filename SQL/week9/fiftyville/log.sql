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

--Get the range of moments when the thief exited the parking of the bakery with their car.
SELECT * FROM bakery_security_logs WHERE year='2024' AND month='7' AND day='28' AND hour = '10' AND minute > '15' AND minute < '30' AND activity LIKE 'exit';
-- id   year  month  day  hour  minute  activity  license_plate
-- ---  ----  -----  ---  ----  ------  --------  -------------
-- 260  2024  7      28   10    16      exit      5P2BI95      
-- 261  2024  7      28   10    18      exit      94KL13X      
-- 262  2024  7      28   10    18      exit      6P58WS2      
-- 263  2024  7      28   10    19      exit      4328GD8      
-- 264  2024  7      28   10    20      exit      G412CB7      
-- 265  2024  7      28   10    21      exit      L93JTIZ      
-- 266  2024  7      28   10    23      exit      322W7JE      
-- 267  2024  7      28   10    23      exit      0NTHK55


--GET infos about all people who left the bakery with their car between 10:15 and 10:30.
SELECT * FROM people WHERE license_plate IN (
  SELECT license_plate FROM bakery_security_logs WHERE year='2024' AND month='7' AND day='28' AND hour = '10' AND minute > '15' AND minute < '30' AND activity LIKE 'exit');
-- id      name     phone_number    passport_number  license_plate
-- ------  -------  --------------  ---------------  -------------
-- 221103  Vanessa  (725) 555-4692  2963008352       5P2BI95      
-- 243696  Barry    (301) 555-4174  7526138472       6P58WS2      
-- 396669  Iman     (829) 555-5269  7049073643       L93JTIZ      
-- 398010  Sofia    (130) 555-0289  1695452385       G412CB7      
-- 467400  Luca     (389) 555-5198  8496433585       4328GD8      
-- 514354  Diana    (770) 555-1861  3592750733       322W7JE      
-- 560886  Kelsey   (499) 555-9472  8294398571       0NTHK55      
-- 686048  Bruce    (367) 555-5533  5773159633       94KL13X 

--IDK what to do with this for the moment. Let's get the datas Eugene told us.
--Search for withdrawing at Leggett Street before 10:15.
--There is no hours, but I got all transactions this day and the account_numbers.
SELECT account_number FROM atm_transactions WHERE year='2024' AND month='7' AND day='28' AND atm_location LIKE 'Leggett Street' AND transaction_type LIKE 'withdraw';
-- account_number
-- --------------
-- 28500762      
-- 28296815      
-- 76054385      
-- 49610011      
-- 16153065      
-- 25506511      
-- 81061156      
-- 26013199

