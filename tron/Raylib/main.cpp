#include <raylib.h>
#include <vector>
using namespace std;

void Grid();


struct LineSegment{
  int startX, startY;
  int endX, endY;
};


int main(){

  int direction = 0;
  int previousDirection = -1;
  bool hasSwapped = false;
  
  int x = 300;
  int y = 240;
  int sizeX = 20;
  int sizeY = 10;
  int v1 = 2;

  vector<LineSegment> lines;
  int startX = x, startY= y;

  int LineX = x;
  int LineY = y;
  
  InitWindow(1440, 1080, "Test Window");
  SetTargetFPS(144);

  while(!WindowShouldClose()){

    BeginDrawing();
    ClearBackground(BLACK);

    for(const auto& line : lines){
      DrawLine(line.startX, line.startY, line.endX, line.endY, BLUE);
    }
    
    DrawRectangle(x,y,sizeX,sizeY,BLUE);
    DrawLine(LineX, LineY, x, y, BLUE);
    if(direction == 0){
      x += v1;      
    }
    else if(direction == 1){
      y += v1;
    }
    else if(direction == 2){
      x -= v1;
    }
    else if(direction == 3){
      y -= v1;
    }


    if(!hasSwapped){
      int temp = 0;
      temp = sizeX;
      sizeX = sizeY;
      sizeY = temp;
      hasSwapped = true;
    }
      
    if(IsKeyPressed(KEY_UP) and direction != 1 and direction != 3){
      direction = 3;
      LineX = x;
      LineY = y;
    }
    if(IsKeyPressed(KEY_DOWN) and direction != 3 and direction != 1){
      direction = 1;
      LineX = x;
      LineY = y;
    }
    if(IsKeyPressed(KEY_LEFT) and direction != 0 and direction != 2){
      direction = 2;
      LineX = x;
      LineY = y;
    }
    if(IsKeyPressed(KEY_RIGHT) and direction != 2 and direction != 0){
      direction = 0;
      LineX = x;
      LineY = y;
    }

    if(direction != previousDirection){
      LineSegment line = {startX, startY, x, y};
      lines.push_back(line);
      startX = x;
      startY = y;
      hasSwapped = false;
      previousDirection = direction;
    }
      
    
    EndDrawing();
  }
  
  return 0;
}



void Grid(){
  
}
