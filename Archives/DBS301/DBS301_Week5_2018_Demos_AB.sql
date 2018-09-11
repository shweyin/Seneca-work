-- Week 5 Demo 
-- Using Sportleagues database
-- June 5th, 2018
SELECT * FROM tbldatplayers;
SELECT Count(playerid) FROM tbldatplayers;

SELECT * FROM tbldatteams;
SELECT COUNT(teamID) FROM tbldatteams;

SELECT * FROM tbljncRosters;
SELECT COUNT(rosterID) from tbljncrosters;

-- let's add names to the rosters
SELECT rosterid, tbljncrosters.playerid, teamid, 
    tbljncrosters.isactive, jerseynumber, namefirst, namelast
    FROM tbljncrosters, tbldatplayers;
  --  This returns 595 * 230 records...--> USELESS
  
  SELECT rosterid, tbljncrosters.playerid, teamid, 
    tbljncrosters.isactive, jerseynumber, namefirst, namelast
    FROM tbljncrosters, tbldatplayers
    WHERE tbljncrosters.playerid = tbldatplayers.playerid;
    
    -- very inefficient
    -- let's use joins

-- 4 types
-- INNER, LEFT OUTER, RIGHT OUTER, FULL OUTER
  SELECT rosterid, tbljncrosters.playerid, teamid, 
    tbljncrosters.isactive, jerseynumber, namefirst, namelast
    FROM tbljncrosters INNER JOIN tbldatplayers
    ON tbljncrosters.playerid = tbldatplayers.playerid;
    
    -- let's show all players regardless if they are
    -- currently on a team roster
SELECT rosterid, tbljncrosters.playerid, teamid, 
    tbljncrosters.isactive, jerseynumber, namefirst, namelast
    FROM tbljncrosters 
    RIGHT OUTER JOIN 
    tbldatplayers
    ON tbljncrosters.playerid = tbldatplayers.playerid;
    -- let's try LEFT
SELECT rosterid, tbljncrosters.playerid, teamid, 
    tbljncrosters.isactive, jerseynumber, namefirst, namelast
    FROM tbljncrosters 
    LEFT OUTER JOIN 
    tbldatplayers
    ON tbljncrosters.playerid = tbldatplayers.playerid;
-- FULL OUTER
SELECT rosterid, tbljncrosters.playerid, teamid, 
    tbljncrosters.isactive, jerseynumber, namefirst, namelast
    FROM tbljncrosters 
    FULL OUTER JOIN 
    tbldatplayers
    ON tbljncrosters.playerid = tbldatplayers.playerid;
    
-- let us display all players NOT currently on a roster
SELECT rosterid, tbldatplayers.playerid, 
    jerseynumber, namefirst, namelast
    FROM tbldatplayers LEFT OUTER JOIN tbljncrosters
    ON tbljncrosters.playerid = tbldatplayers.playerid
    WHERE rosterid IS NULL;
    
-- Let's show rosters showing both team and player names
SELECT tbljncrosters.teamid, tbljncrosters.playerid, 
    namefirst, namelast, tbljncrosters.isactive, teamnameshort
    FROM (tbldatteams INNER JOIN tbljncrosters 
        ON tbldatteams.teamid = tbljncrosters.teamid)
        INNER JOIN tbldatplayers 
            ON tbldatplayers.playerid = tbljncrosters.playerid
            ORDER BY teamnameshort, namelast, namefirst;
-- let's print 1 team only
SELECT tbljncrosters.teamid, tbljncrosters.playerid, 
    namefirst, namelast, tbljncrosters.isactive, teamnameshort
    FROM (tbldatteams INNER JOIN tbljncrosters 
        ON tbldatteams.teamid = tbljncrosters.teamid)
        INNER JOIN tbldatplayers 
            ON tbldatplayers.playerid = tbljncrosters.playerid
            WHERE tbljncrosters.teamid = 214
            ORDER BY teamnameshort, namelast, namefirst;
-- BUT, i want to choose the team
SELECT tbljncrosters.teamid, tbljncrosters.playerid, 
    namefirst, namelast, tbljncrosters.isactive, teamnameshort
    FROM (tbldatteams INNER JOIN tbljncrosters 
        ON tbldatteams.teamid = tbljncrosters.teamid)
        INNER JOIN tbldatplayers 
            ON tbldatplayers.playerid = tbljncrosters.playerid
            WHERE tbljncrosters.teamid = &TeamID
            ORDER BY teamnameshort, namelast, namefirst;
-- but i don't know teamid
SELECT tbljncrosters.teamid, tbljncrosters.playerid, 
    namefirst, namelast, tbljncrosters.isactive, teamnameshort
    FROM (tbldatteams INNER JOIN tbljncrosters 
        ON tbldatteams.teamid = tbljncrosters.teamid)
        INNER JOIN tbldatplayers 
            ON tbldatplayers.playerid = tbljncrosters.playerid
            WHERE UPPER(tbldatteams.teamnameshort) = 
            UPPER('&TeamName')
            ORDER BY teamnameshort, namelast, namefirst;
-- but i don't know how to spell
SELECT tbljncrosters.teamid, tbljncrosters.playerid, 
    namefirst, namelast, tbljncrosters.isactive, teamnameshort
    FROM (tbldatteams INNER JOIN tbljncrosters 
        ON tbldatteams.teamid = tbljncrosters.teamid)
        INNER JOIN tbldatplayers 
            ON tbldatplayers.playerid = tbljncrosters.playerid
            WHERE UPPER(tbldatteams.teamnameshort) LIKE 
            UPPER('%&TeamName%')
            ORDER BY teamnameshort, namelast, namefirst;
            
-- USE Table aliases for simplicity
SELECT R.teamid, R.playerid, 
    namefirst, namelast, R.isactive, teamnameshort
    FROM (tbldatteams T INNER JOIN tbljncrosters R
        ON T.teamid = R.teamid)
        INNER JOIN tbldatplayers P
            ON P.playerid = R.playerid
            WHERE UPPER(T.teamnameshort) LIKE 
            UPPER('%&TeamName%')
            ORDER BY teamnameshort, namelast, namefirst;