#include <bits/stdc++.h>
using namespace std;

int main() {
	int t,goals_home,goals_away;
	string team_home,team_away,tmp;
	cin >> t;
	while(t--){
	    map <string,int>teams_goals;
	    map <string,int>team_points;
	    for(int i=0;i<12;i++){
	        cin >> team_home >> goals_home >> tmp >> goals_away >> team_away;
	        if(teams_goals.find(team_home) != teams_goals.end()){
	            teams_goals[team_home] += (goals_home-goals_away);
	            if(goals_home > goals_away){
	                team_points[team_home] += 3;
	            }
	            else if(goals_home == goals_away){
	                team_points[team_home]++;
	            }
	        }
	        else{
	            teams_goals[team_home] = (goals_home-goals_away);
	            if(goals_home > goals_away){
	                team_points[team_home] = 3;
	            }
	            else if(goals_home == goals_away){
	                team_points[team_home] = 1;
	            }
	            else{
	                team_points[team_home] = 0;
	            }
	        }
	        if(teams_goals.find(team_away) != teams_goals.end()){
	            teams_goals[team_away] += (goals_away-goals_home);
	            if(goals_away > goals_home){
	                team_points[team_away] += 3;
	            }
	            else if(goals_home == goals_away){
	                team_points[team_away]++;
	            }
	        }
	        else{
	            teams_goals[team_away] = (goals_away-goals_home);
	            if(goals_away > goals_home){
	                team_points[team_away] = 3;
	            }
	            else if(goals_home == goals_away){
	                team_points[team_away] = 1;
	            }
	            else{
	                team_points[team_away] = 0;
	            }
	        }
	    }
	    for(int i=0;i<2;i++){
	        auto first_winner = team_points.begin();
	        auto it = team_points.begin();
    	    while(it != team_points.end()){
    	        if(first_winner->second < it->second){
    	            first_winner = it;
    	        }
    	        else if(first_winner->second == it->second){
    	            if(teams_goals[first_winner->first]-teams_goals[it->first] < 0){
    	                first_winner = it;
    	            }
    	        }
    	        ++it;
    	    }
    	    cout << first_winner->first << " ";
    	    team_points.erase(first_winner->first);
	    }
	    cout << endl;
	}
	return 0;
}