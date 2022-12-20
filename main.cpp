#include<bits/stdc++.h>
#include<graphics.h>
#include<time.h>

using namespace std;

int main()
{
    int gd = DETECT,gm,key_dir,foodX,foodY,snakeX[200],snakeY[200],wallX,wallY;   // DETECT = 0; gm = graph mode ; gd =graph diver
    initgraph(&gd,&gm,(char*)" ");

    //initialization

    int  delayTime = 170;
    int food = 0;        // snake food
    int body= 500;   // snake body
    int p_dir = 1;     //p_dir = previous direction;
    int length = 1;   // snake game;
    bool game = true;  // declaration a bool variable for the loop

    // snake array

        snakeX[200] = {0};
        snakeY[200] = {0};

    // initialization for display snake ;

    snakeX[0] = 200,snakeY[0] = 200; // starting position of the snake
    foodX = 200, foodY = 200; // starting position of food
    key_dir = rand()%2;


    // drawing game panel

    while(game)
    {
        setfillstyle(SOLID_FILL,WHITE); // initialization back ground color
        bar(0,0,630,470);  //  initializing background size or wide (lower width 630 and right length 470)

        setfillstyle(SOLID_FILL,BLACK);  // initializing boarder color

        bar(0,0,630,10); // upper boarder width,length

        bar(0,0,10,470); // right boarder width,length

        bar(0,470,630,460); // lower boarder width,length

        bar(620,10,630,470); // lower boarder width,length


        setfillstyle(SOLID_FILL, RED); // initialization food color

        if(snakeX[0] == foodX && snakeY[0] == foodY) // checking snake and food is in the same position or not
        {
            length++;
            food++;
            delayTime = delayTime - 5;  // food consumed by snake then the delay time reduced and snake spread increase

            bar(foodX,foodY,foodX + 10 , foodY + 10 ); // food poosition

            do{
                foodX = (10 + rand() % 590);
                foodY = (10 + rand() % 440);
            }while(getpixel(foodX,foodY) != 0 && foodX > 10 && foodY>10 && (foodX<150 && foodX>350) && (foodY<110 && foodY>125) &&(foodY<300 && foodY>315) && (foodX<75 && foodX>90)&& (foodY<120 && foodY>200) &&(foodX<400 && foodX>415) &&(foodY<150 && foodY>350)); //condition for food visualization

            // condition for not overlaping food or snake

            foodX = foodX / 10;
            foodX = foodX * 10;
            foodY = foodY / 10;
            foodY = foodY * 10;

            // condition for food coordinate can't be 10, if so then the food will situated beside the boarder line every time

            if(foodX == 10){
                foodX = rand() % 10 + 5;
                foodX = food * 10;
            }
            else if(foodY == 10)
            {
                foodY = rand() % 10 + 5;
                foodY = foodY * 10;
            }

        }

        bar(foodX,foodY,foodX + 10, foodY + 10); // final  food position for display

        setfillstyle(SOLID_FILL,	CYAN); // initialize snake color

        // condition for key direction

        if(GetAsyncKeyState(VK_RIGHT)||GetAsyncKeyState('D')){
            key_dir = 1;
        }
        else if(GetAsyncKeyState(VK_LEFT)||GetAsyncKeyState('A')){
            key_dir = 2;
        }
        else if(GetAsyncKeyState(VK_UP)||GetAsyncKeyState('W')){
            key_dir = 3;
        }
        else if(GetAsyncKeyState(VK_DOWN)||GetAsyncKeyState('S')){
            key_dir = 4;
        }
        else {
                key_dir = 0;
        }

        // condition for moving snake according to key direction

        switch(key_dir)
        {
        case 0:
            if(p_dir == 1){
                snakeX[0] = snakeX[0] + 10;
            }
            else if(p_dir == 2){
                snakeX[0] = snakeX[0] - 10;
            }
            else if(p_dir == 3){
                snakeY[0] = snakeY[0] - 10;
            }
            else if(p_dir == 4){
                snakeY[0] = snakeY[0] + 10;
            }
            else{
                key_dir = 0;
            }
            break;

        case 1:
            snakeX[0] = snakeX[0] + 10;
            p_dir = 1;
            break;
        case 2:
            snakeX[0] = snakeX[0] - 10;
            p_dir = 2;
            break;
        case 3:
            snakeY[0] = snakeY[0] - 10;
            p_dir = 3;
            break;
        case 4:
            snakeY[0] = snakeY[0] + 10;
            p_dir = 4;
            break;

        }

       // displaying snake

       for(int i =0; i < length; i++)
       {
           bar(snakeX[i], snakeY[i], snakeX[i] + 10, snakeY[i] + 10);
       }

       // body of snake

       for(int i = 199; i > 0; i--)
       {
           snakeX[i] = snakeX[i - 1];
           snakeY[i] = snakeY[i - 1];
       }

       //wall 01

       wallX=180, wallY=300;
           setfillstyle(SOLID_FILL,	BLACK);
           bar(wallX, wallY, wallX + 200, wallY + 15);


        //checking bumping in the wall

        for(int i=0;i<200;i++)
        {
            for(int j=0;j<15;j++){

        if(snakeX[0] ==wallX+i && snakeY[0] ==wallY+j){
        std::cout<<"Snake bumped into the wall !!\n\n";
        game = false; break;
            }
          }
        }

        //wall 02

       wallX=75, wallY=120;
           setfillstyle(SOLID_FILL,	BLUE);
           bar(wallX, wallY, wallX + 15, wallY + 200);


        //checking bumping in the wall

        for(int i=0;i<15;i++)
        {
            for(int j=0;j<200;j++){

        if(snakeX[0] ==wallX+i && snakeY[0] ==wallY+j){
        std::cout<<"Snake bumped into the wall !!\n\n";
        game = false; break;
            }
          }
        }

        //wall 03

       wallX=400, wallY=150;
           setfillstyle(SOLID_FILL,	GREEN);
           bar(wallX, wallY, wallX + 15, wallY + 200);


        //checking bumping in the wall

        for(int i=0;i<15;i++)
        {
            for(int j=0;j<200;j++){

        if(snakeX[0] ==wallX+i && snakeY[0] ==wallY+j){
        std::cout<<"Snake bumped into the wall !!\n\n";
        game = false; break;
            }
          }
        }
        //wall 04

        if(food>20){
       wallX=150, wallY=110;
           setfillstyle(SOLID_FILL,	YELLOW);
           bar(wallX, wallY, wallX + 200, wallY + 15);


        //checking bumping in the wall

        for(int i=0;i<200;i++)
        {
            for(int j=0;j<15;j++){

        if(snakeX[0] ==wallX+i && snakeY[0] ==wallY+j){
        std::cout<<"Snake bumped into the wall !!\n\n";
        game = false; break;
            }
          }
        }

        }


    // checking bumping into body

    for(int i = 2; i < length; i++)
    {
        if(snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i])
        {
            body = i;
            break;
        }
    }

    delay(delayTime);

    // checking bumping in to boundary;

    if(snakeX[0] > 615 || snakeX[0] <5 || snakeY[0] < 5|| snakeY[0] > 455){
        std::cout<<"Snake bumped into the wall !!\n\n";
        game = false;
    }

    // checking bumping into body

    if(snakeX[0] == snakeX[body] && snakeY[0] ==  snakeY[body] ){
        std::cout<<"Snake bumped into itself !!!\n\n";
        game = false;
    }

    }

    // game result

    std::cout<<"Your score: "<<food-1<<"\n\n";
    std::cout<<"Game Over !\n\n";
    getch();
    return 0;
}

