/*
F. Football
time limit per test: 3 seconds
memory limit per test: 1024 megabytes
input: standard input
output: standard output
Scientists are researching an impact of football match results on the mood of football fans. They have a hypothesis that there is a correlation between the number of draws and fans' desire to watch football matches in the future.

In football, two teams play a match. The teams score goals throughout a match. A score "x:y" means that the team we observe scored x goals and conceded y goals. If x=y, then the match ends in a draw. If x>y, then the observed team wins, and if x<y, then it loses.

To find out if there is a correlation, the scientists gathered information about the results of teams in lower leagues. The information they found is the number of matches played by the team (n), the number of goals scored in these matches (a), and the number of goals conceded in these matches (b).

You are given this information for a single team. You are asked to calculate the minimum number of draws that could have happened during the team's matches and provide a list of match scores with the minimum number of draws.

Input
The first line contains an integer n — the number of matches played by the team (1≤n≤100). The second line contains an integer a — the total number of goals scored by the team in all n matches (0≤a≤1000). The third line contains an integer b — the total number of goals conceded by the team in all n matches (0≤b≤1000).

Output
In the first line, print a single integer d — the minimum number of draws.

In the following n lines, print a list of match scores, each line in the format "x:y", where x is the number of goals scored in the match, and y – the number of goals conceded, so that exactly d of these matches have ended in a draw. In case multiple such lists of match scores exist, print any of them.

Examples
input 
3
2
4
output  
0
1:0
1:2
0:2
input 
1
2
2
output 
1
2:2
input 
4
0
7
output 
0
0:1
0:2
0:1
0:3
input 
6
3
1
output 
2
0:0
1:0
0:0
0:1
1:0
1:0

Note
In the first example, the team played 3 matches, scored 2 goals and conceded 4 goals. The team could have won 1 match, lost 1 match and drawn 1 match. However, the team could not have drawn 2 matches, because then the total number of goals scored would be 3, and the total number of goals conceded would be 3. So the minimum number of draws is 0.

In the second example, the team played 1 match, scored 2 goals and conceded 2 goals. The team could have drawn 1 match, but it could not have drawn 2 matches, because then the total number of goals scored would be 4, and the total number of goals conceded would be 4. So the minimum number of draws is 1.

In the third example, the team played 4 matches, scored 0 goals and conceded 7 goals. The team could have won 1 match, lost 3 matches and drawn 0 matches. However, the team could not have drawn 1 match, because then the total number of goals scored would be 1, and the total number of goals conceded would be 5. So the minimum number of draws is 0.

In the fourth example, the team played 6 matches, scored 3 goals and conceded 1 goal. The team could have won 1 match, lost 1 match and drawn 4 matches. However, the team could not have drawn 5 matches, because then the total number of goals scored would be 8, and the total number of goals conceded would be 6. So the minimum number of draws is 2.


Approach:
1. The minimum number of draws is the difference between the total number of goals scored and the total number of goals conceded, divided by the number of matches played.
2. The number of matches that have to end in a draw is the remainder of the division of the difference between the total number of goals scored and the total number of goals conceded, divided by the number of matches played.
3. The number of matches that have to end in a win or a loss is the number of matches played minus the number of matches that have to end in a draw.
4. The number of goals scored in a match that has to end in a draw is the difference between the total number of goals scored and the total number of goals conceded, divided by the number of matches played.
5. The number of goals conceded in a match that has to end in a draw is the difference between the total number of goals scored and the total number of goals conceded, divided by the number of matches played.
6. The number of goals scored in a match that has to end in a win or a loss is the difference between the total number of goals scored and the total number of goals conceded, divided by the number of matches played plus 1.
7. The number of goals conceded in a match that has to end in a win or a loss is the difference between the total number of goals scored and the total number of goals conceded, divided by the number of matches played minus 1.
8. Print the minimum number of draws.
9. Print the number of goals scored and the number of goals conceded in the matches that have to end in a draw.
10. Print the number of goals scored and the number of goals conceded in the matches that have to end in a win or a loss.

Time Complexity: O(n)
Space Complexity: O(1)

*/


#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,a,b;
        cin>>n>>a>>b;
        int d = a-b;
        int x = d/n;
        int y = d%n;
        int z = n-y;
        for(int i=0;i<z;i++){
            cout<<x<<" "<<x+1<<endl;
        }
        for(int i=0;i<y;i++){
            cout<<x+1<<" "<<x+1<<endl;
        }
    }
}

/*

(a*b*c)%m = ((a*b)%m * (c%m))%m = ((a%m * b%m)%m * (c%m))%m = ((a%m * c%m)%m * (b%m))%m = ((c%m * a%m)%m * (b%m))%m = ((c%m * b%m)%m * (a%m))%m = ((b%m * c%m)%m * (a%m))%m = ((b%m * a%m)%m * (c%m))%m 
*/