# Champions League

The UEFA Champions League is the most prestigious annual sports competition in the world. In the group stage of this competition, European football clubs are divided into 8 groups; there are four teams in each group. The teams in each group are ranked based on the matches they play against each other, according to the following rules:

- Based on the results of matches, teams are awarded _points_. Each football match is played between a **home team** and an **away team**. If one of the teams scores more goals than the other, this team gains 3 points and the other team gains 0 points. In case of a tie (if both teams score the same number of goals), each of those teams gains 1 point.
- The **goal difference** of a team is the number of goals it scored minus the number of goals it received, regardless if it scored/received them as the home team or as the away team.
- Between any two teams, the team with more points is ranked higher.
- If they have the same number of points (in case of a tie), the team with higher goal difference is ranked higher.

Each team plays two matches against every other team in its group — one match as the home team and one match as the away team. You are given the number of goals scored by each team for all twelve matches in one group. Determine the leaders of this group — the first and second top-ranked team. It is guaranteed that there are no ties for either of these places (for the given results of the matches).

---

## 🔽 Input

- The first line of the input contains a single integer `T` denoting the number of test cases. The description of `T` test cases follows.
- For each test case, 12 lines follow. Each of these lines describes the result of one match in the format `HomeTeamName HomeTeamGoals vs. AwayTeamGoals AwayTeamName` where `HomeTeamName` and `AwayTeamName` are strings and `HomeTeamGoals` and `AwayTeamGoals` are integers denoting the number of goals scored by the respective teams in this match.

---

## 🔼 Output

For each scenario, print a single line containing two space-separated strings — the name of the top-ranked team and the name of the second top-ranked team.

---

## 🔒 Constraints

- \( 1 \leq T \leq 50 \)
- The length of the name of each team does not exceed 10
- The name of each team contains only lowercase English letters
- \( 0 \leq \text{number of goals scored by each team} \leq 100 \)

---

## 🧪 Sample 1:

### Input

2
manutd 8 vs. 2 arsenal
lyon 1 vs. 2 manutd
fcbarca 0 vs. 0 lyon
fcbarca 5 vs. 1 arsenal
manutd 3 vs. 1 fcbarca
arsenal 6 vs. 0 lyon
arsenal 0 vs. 0 manutd
manutd 4 vs. 2 lyon
arsenal 2 vs. 2 fcbarca
lyon 0 vs. 3 fcbarca
lyon 1 vs. 0 arsenal
fcbarca 0 vs. 1 manutd
a 3 vs. 0 b
a 0 vs. 0 c
a 0 vs. 0 d
b 0 vs. 0 a
b 4 vs. 0 c
b 0 vs. 0 d
c 0 vs. 0 a
c 0 vs. 0 b
c 1 vs. 0 d
d 3 vs. 0 a
d 0 vs. 0 b
d 0 vs. 0 c

### Output

manutd fcbarca
d b


## 💡 Explanation:

### Example case 1:

The total number of points and goal difference for each team is as follows:

- **manutd** : 16 points, goal difference 12  
- **fcbarca** : 8 points, goal difference 4  
- **arsenal** : 5 points, goal difference −5  
- **lyon** : 4 points, goal difference −11  

### Example case 2:

The total number of points and goal difference for each team is as follows:

- **d** : 7 points, goal difference 2  
- **b** : 7 points, goal difference 1  
- **a** : 7 points, goal difference 0  
- **c** : 7 points, goal difference −3  

Note that in this test case, all teams have the same number of points, but teams with higher goal difference are ranked higher.