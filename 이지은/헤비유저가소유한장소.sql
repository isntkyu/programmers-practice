-- 코드를 입력하세요
SELECT P.ID, P.NAME, P.HOST_ID
FROM PLACES P,
(SELECT HOST_ID
FROM PLACES
GROUP BY HOST_ID 
HAVING COUNT(HOST_ID) >= 2) F
WHERE F.HOST_ID = P.HOST_ID
ORDER BY ID