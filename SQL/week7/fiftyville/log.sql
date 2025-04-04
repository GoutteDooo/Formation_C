-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Get the description of the crime scene report that contains the word "CS50".
SELECT * FROM crime_scene_reports WHERE description LIKE "%CS50 duck%";
-- id   year  month  day  street           description                                                 
-- ---  ----  -----  ---  ---------------  ------------------------------------------------------------
-- 295  2024  7      28   Humphrey Street  Theft of the CS50 duck took place at 10:15am at the Humphrey
--                                          Street bakery. Interviews were conducted today with three w
--                                         itnesses who were present at the time – each of their interv
--                                         iew transcripts mentions the bakery. 


-- Get the interviews of interviewees who were present at the theft.
SELECT name,transcript FROM interviews WHERE year='2024' AND month='7' AND day='28' AND transcript LIKE "%thief%" OR "%theft%";
-- name     transcript                                                  
-- -------  ------------------------------------------------------------
-- Ruth     Sometime within ten minutes of the theft, I saw the thief ge
--          t into a car in the bakery parking lot and drive away. If yo
--          u have security footage from the bakery parking lot, you mig
--          ht want to look for cars that left the parking lot in that t
--          ime frame.                                                  

-- Eugene   I don't know the thief's name, but it was someone I recogniz
--          ed. Earlier this morning, before I arrived at Emma's bakery,
--           I was walking by the ATM on Leggett Street and saw the thie
--          f there withdrawing some money.                             

-- Raymond  As the thief was leaving the bakery, they called someone who
--           talked to them for less than a minute. In the call, I heard
--           the thief say that they were planning to take the earliest 
--          flight out of Fiftyville tomorrow. The thief then asked the 
--          person on the other end of the phone to purchase the flight 
--          ticket.


--Get the range of moments when the thief exited the parking of the bakery with their car.
SELECT license_plate, hour, minute FROM bakery_security_logs WHERE year='2024' AND month='7' AND day='28' AND hour = '10' AND minute > '15' AND minute < '30' AND activity LIKE 'exit';
-- license_plate  hour  minute
-- -------------  ----  ------
-- 5P2BI95        10    16    
-- 94KL13X        10    18    
-- 6P58WS2        10    18    
-- 4328GD8        10    19    
-- G412CB7        10    20    
-- L93JTIZ        10    21    
-- 322W7JE        10    23    
-- 0NTHK55        10    23


--Get infos about all people who left the bakery with their car between 10:15 and 10:30.
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


--Try to get account numbers of people who left the bakery with their car between 10:15 and 10:30.
--with their id because of their license plate.
SELECT account_number FROM bank_accounts WHERE person_id IN (
  SELECT id FROM people WHERE license_plate IN (
    SELECT license_plate FROM bakery_security_logs WHERE year='2024' AND month='7' AND day='28' AND hour = '10' AND minute > '15' AND minute < '30' AND activity LIKE 'exit')
);
-- account_number
-- --------------
-- 49610011      
-- 26013199      
-- 25506511      
-- 28500762      
-- 56171033


--Get account numbers of people who withdrawed this morning AND them who left the bakery with their car between 10:15 and 10:30.
SELECT a.account_number FROM (
  SELECT account_number FROM atm_transactions WHERE year='2024' AND month='7' AND day='28' AND atm_location LIKE 'Leggett Street' AND transaction_type LIKE 'withdraw') AS a 
  JOIN ( 
    SELECT account_number FROM bank_accounts WHERE person_id IN (
      SELECT id FROM people WHERE license_plate IN (
        SELECT license_plate FROM bakery_security_logs WHERE year='2024' AND month='7' AND day='28' AND hour = '10' AND minute > '15' AND minute < '30' AND activity LIKE 'exit'
      )
    )
  ) AS b ON a.account_number = b.account_number;

--... And now, get their datas
--So, this is the datas of people who withdrawed this morning AND who left the bakery with their car between 10:15 and 10:30.
SELECT * FROM people WHERE id IN (
  SELECT b.person_id FROM (
    SELECT account_number FROM atm_transactions WHERE year='2024' AND month='7' AND day='28' AND atm_location LIKE 'Leggett Street' AND transaction_type LIKE 'withdraw'
  ) 
  AS a JOIN ( 
    SELECT account_number,person_id FROM bank_accounts WHERE person_id IN (
      SELECT id FROM people WHERE license_plate IN (
        SELECT license_plate FROM bakery_security_logs WHERE year='2024' AND month='7' AND day='28' AND hour = '10' AND minute > '15' AND minute < '30' AND activity LIKE 'exit'
      )
    )
  ) AS b ON a.account_number = b.account_number
);
-- id      name   phone_number    passport_number  license_plate
-- ------  -----  --------------  ---------------  -------------
-- 396669  Iman   (829) 555-5269  7049073643       L93JTIZ      
-- 467400  Luca   (389) 555-5198  8496433585       4328GD8      
-- 514354  Diana  (770) 555-1861  3592750733       322W7JE      
-- 686048  Bruce  (367) 555-5533  5773159633       94KL13X


--I can't unfortunately check time when a call was made, but I can check duration.
--Check people who phone called this day with a duration less than a minute.
SELECT * FROM phone_calls WHERE year='2024' AND month='7' AND day='28' AND duration < '60';
-- id   caller          receiver        year  month  day  duration
-- ---  --------------  --------------  ----  -----  ---  --------
-- 221  (130) 555-0289  (996) 555-8899  2024  7      28   51      
-- 224  (499) 555-9472  (892) 555-8872  2024  7      28   36      
-- 233  (367) 555-5533  (375) 555-8161  2024  7      28   45      
-- 251  (499) 555-9472  (717) 555-1342  2024  7      28   50      
-- 254  (286) 555-6063  (676) 555-6554  2024  7      28   43      
-- 255  (770) 555-1861  (725) 555-3243  2024  7      28   49      
-- 261  (031) 555-6622  (910) 555-3251  2024  7      28   38      
-- 279  (826) 555-1652  (066) 555-9701  2024  7      28   55      
-- 281  (338) 555-6650  (704) 555-2131  2024  7      28   54


--Find calls and receives of people who left the bakery with their car between 10:15 and 10:30 AND people who withdrawed this morning.
SELECT caller, receiver FROM phone_calls AS c JOIN (
  SELECT phone_number FROM people WHERE id IN (
    SELECT b.person_id FROM (
      SELECT account_number FROM atm_transactions WHERE year='2024' AND month='7' AND day='28' AND atm_location LIKE 'Leggett Street' AND transaction_type LIKE 'withdraw'
    )
    AS a JOIN (
      SELECT account_number,person_id FROM bank_accounts WHERE person_id IN (
        SELECT id FROM people WHERE license_plate IN (
          SELECT license_plate FROM bakery_security_logs WHERE year='2024' AND month='7' AND day='28' AND hour = '10' AND minute > '15' AND minute < '30' AND activity LIKE 'exit'
        )
      )
    ) AS b ON a.account_number = b.account_number
  )
) AS d ON c.caller = d.phone_number WHERE (c.year='2024' AND c.month='7' AND c.day='28' AND c.duration < '60');
-- caller          receiver      
-- --------------  --------------
-- (770) 555-1861  (725) 555-3243  <- c: Diana | r: Philip
-- (367) 555-5533  (375) 555-8161  <- c: Bruce | r: Robin

--get receivers numbers
SELECT name,phone_number FROM people JOIN (
  SELECT receiver FROM phone_calls AS c JOIN (
    SELECT phone_number FROM people WHERE id IN (
      SELECT b.person_id FROM (
        SELECT account_number FROM atm_transactions WHERE year='2024' AND month='7' AND day='28' AND atm_location LIKE 'Leggett Street' AND transaction_type LIKE 'withdraw'
      )
      AS a JOIN (
        SELECT account_number,person_id FROM bank_accounts WHERE person_id IN (
          SELECT id FROM people WHERE license_plate IN (
            SELECT license_plate FROM bakery_security_logs WHERE year='2024' AND month='7' AND day='28' AND hour = '10' AND minute > '15' AND minute < '30' AND activity LIKE 'exit'
          )
        )
      ) AS b ON a.account_number = b.account_number
    )
  ) AS d ON c.caller = d.phone_number WHERE (c.year='2024' AND c.month='7' AND c.day='28' AND c.duration < '60')
) AS e ON e.receiver = people.phone_number;
-- name    phone_number  
-- ------  --------------
-- Philip  (725) 555-3243
-- Robin   (375) 555-8161

--So, Thief suspects are : Diana & Bruce, accomplice suspects are : Philip & Robin

--get all infos about these guys
SELECT * FROM people WHERE name IN ('Diana','Bruce','Philip','Robin');
-- id      name    phone_number    passport_number  license_plate
-- ------  ------  --------------  ---------------  -------------
-- 514354  Diana   (770) 555-1861  3592750733       322W7JE      
-- 686048  Bruce   (367) 555-5533  5773159633       94KL13X      
-- 847116  Philip  (725) 555-3243  3391710505       GW362R6      
-- 864400  Robin   (375) 555-8161                   4V16VO0


--We just have to find the flight and the passport number of the THIEF, and I find them.
SELECT * FROM airports WHERE city='Fiftyville';
-- id  abbreviation  full_name                    city      
-- --  ------------  ---------------------------  ----------
-- 8   CSF           Fiftyville Regional Airport  Fiftyville

--Find the earliest flight this day from Fiftyville
SELECT * FROM flights WHERE year='2024' AND month='7' AND day='29' AND origin_airport_id='8' ORDER BY hour,minute LIMIT 1;
-- id  origin_airport_id  destination_airport_id  year  month  day  hour  minute
-- --  -----------------  ----------------------  ----  -----  ---  ----  ------
-- 36  8                  4                       2024  7      29   8     20


--Find all passengers of this flight and try to find passport from Bruce or Diana (respectively 5773159633 & 3592750733)
SELECT * FROM passengers WHERE flight_id=(
  SELECT id FROM flights WHERE year='2024' AND month='7' AND day='29' AND origin_airport_id='8' ORDER BY hour,minute LIMIT 1
) AND passport_number IN ('5773159633','3592750733');
-- flight_id  passport_number  seat
-- ---------  ---------------  ----
-- 36         5773159633       4A

-- 5773159633 = Bruce
-- The accomplice is Robin

--Now, I have to find the town destination of the flight.
SELECT * FROM airports WHERE id IN (
  SELECT destination_airport_id FROM flights WHERE id=(
    SELECT id FROM flights WHERE year='2024' AND month='7' AND day='29' AND origin_airport_id='8' ORDER BY hour,minute LIMIT 1
  )
);
-- id  abbreviation  full_name          city         
-- --  ------------  -----------------  -------------
-- 4   LGA           LaGuardia Airport  New York City

--The city the thief ESCAPED TO is New York City