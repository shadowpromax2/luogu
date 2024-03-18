#include <stdio.h>
#include <stdlib.h>

int road = 0;
void originate_board();

void change();
int board[25][25] = {0};

int start_x = 0;
int start_y = 0;
int target_x;
int target_y;
int horse_x;
int horse_y;

void find_way(int temp_x,int temp_y);

int main() {
    scanf("%d%d%d%d",&target_x,&target_y,
          &horse_x,&horse_y);
    change();
    originate_board();
    find_way(start_x,start_y);
    printf("%d\n",road);
    return 0;
}
void change(){
    start_x+=2;
    start_y+=2;
    target_x+=2;
    target_y+=2;
    horse_x+=2;
    horse_y+=2;
}
void originate_board(){
    for(int r = 0;r<25;r++){
        for(int c = 0;c<25;c++){
            if((abs(horse_x-r) + abs(horse_y-c)==3)&&
            abs(horse_x-r)!=3&& abs(horse_y-c)!=3){
                board[r][c]=-1;
            }
        }
    }
    board[horse_x][horse_y]=-1;
    board[target_x][target_y]=1;
}
void find_way(int temp_x,int temp_y){
    if(temp_x>target_x || temp_y>target_y){
        return;
    } else{
        if(temp_x==target_x&&temp_y==target_y){
            road++;
            return;
        } else if(board[temp_x][temp_y]==-1){
            return;
        } else if(board[temp_x][temp_y]==0){
            find_way(temp_x+1,temp_y);
            find_way(temp_x,temp_y+1);
        }
    }
}

