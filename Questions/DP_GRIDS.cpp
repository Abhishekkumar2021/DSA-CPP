#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

bool find_path_sum_equal_target(int a[][COL], int i, int j, bool visited[][COL], int &target,int ROW ,int COL)
{
  if ((i < 0) || (j < 0) || (i >= ROW) || (j >= COL) || (visited[i][j])) 
  {
    return false;
  }
  
  // Mark this cell as visited
  visited[i][j] = true;

  if (target-a[i][j] == 0)
    return true;
  
  target = target-a[i][j];

  return (find_path_sum_equal_target(a, i-1, j, visited, target,ROW,COL) 
       || find_path_sum_equal_target(a, i+1, j, visited, target,ROW,COL) 
       || find_path_sum_equal_target(a, i, j-1, visited, target,ROW,COL) 
       || find_path_sum_equal_target(a, i, j+1, visited, target,ROW,COL));

}

int main()
{
    int t;
    cin>>t;
    while(t--){
    int a[ROW][COL];
    bool visited[ROW][COL];

    bool ret = false;
    int target = 0;

    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            target = 36;
            memset(visited, 0, sizeof(visited));
            if (a[i][j] && !visited[i][j]) 
            {                         
                ret = find_path_sum_equal_target(a, i, j, visited, target);
		if (ret == true) {
		  cout << "Find the path" << endl;
                  break;
                } 
            }
        }
        if (ret == true) break;
    }
    }

}