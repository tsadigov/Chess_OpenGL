#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <bits/stdc++.h>
#include <string>
using namespace std;

int r = 0,g = 0,b = 0;
int temp = 0;
int pos_x,pos_y;
string temp_pos;

string board_figs[8][8] = { {"bc","bh","be","bk","bq","be","bh","bc"},
                            {"bp","bp","bp","bp","bp","bp","bp","bp"},
                            {"0","0","0","0","0","0","0","0",},
                            {"0","0","0","0","0","0","0","0",},
                            {"0","0","0","0","0","0","0","0",},
                            {"0","0","0","0","0","0","0","0",},
                            {"wp","wp","wp","wp","wp","wp","wp","wp"},
                            {"wc","wh","we","wk","wq","we","wh","wc"},
                            };

void draw_board(){

    float y = 8;
    float x = -8;

    for(int j = 0;j<8;j++){

        if(temp == 0){r = 1;g = 1;b = 1; temp = 1;}
        else{r = 0;g = 0;b = 0; temp = 0;}

        for(int i = 0;i<4;i++){
            glBegin(GL_POLYGON);
                glColor3f(r,g,b);
                glVertex2f(x,y);
                glVertex2f(x+2,y);
                glVertex2f(x+2,y-2);
                glVertex2f(x,y-2);
            glEnd();
            glBegin(GL_POLYGON);
                glColor3f(!r,!g,!b);
                glVertex2f(x+2,y);
                glVertex2f(x+4,y);
                glVertex2f(x+4,y-2);
                glVertex2f(x+2,y-2);
            glEnd();
            x+=4;
        }

        x = -8;
        y -= 2;
    }
        glBegin(GL_LINE_LOOP);
            glVertex2f(-8.2,8.2);
            glVertex2f(8.2,8.2);
            glVertex2f(8.2,-8.2);
            glVertex2f(-8.2,-8.2);
        glEnd();
        glBegin(GL_LINE_LOOP);
            glVertex2f(-9.5,9.5);
            glVertex2f(9.5,9.5);
            glVertex2f(9.5,-9.5);
            glVertex2f(-9.5,-9.5);
        glEnd();

        glColor4f(0.2,1,0,0);

        for(int i = 0;i<8;i++){
            glRasterPos2f(-7.2 + i*2 ,8.5);
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ('A'+i));
        }
        for(int i = 0;i<8;i++){
            glRasterPos2f(-8.7 , 6.8 - i*2);
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ('1'+i));
        }
}

void paint(bool color){
    if(color)
        glColor3f(0.5,0.5,0);
    else
        glColor3f(0.5,0,0.5);
}

void cannon(float x, float y, bool color){
    paint(color);
    glBegin(GL_POLYGON);
        glVertex2f(x+0.5,y-0.25);
        glVertex2f(x+1.5,y-0.25);
        glVertex2f(x+1.5,y-0.5);
        glVertex2f(x+0.5,y-0.5);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(x+0.75,y-0.25);
        glVertex2f(x+1.25,y-0.25);
        glVertex2f(x+1.5,y-1.5);
        glVertex2f(x+0.5,y-1.5);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(x+0.25,y-1.5);
        glVertex2f(x+1.75,y-1.5);
        glVertex2f(x+1.75,y-1.75);
        glVertex2f(x+0.25,y-1.75);
    glEnd();
}

void horse(int x, int y, bool color){
    paint(color);
    glBegin(GL_POLYGON);
        glVertex2f(x+0.5,y-0.25);
        glVertex2f(x+1.5,y-0.75);
        glVertex2f(x+1,y-1);
        glVertex2f(x+0.5,y-0.5);
        glVertex2f(x+1.5,y-1.5);
        glVertex2f(x+0.5,y-1.5);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(x+0.25,y-1.5);
        glVertex2f(x+1.75,y-1.5);
        glVertex2f(x+1.75,y-1.75);
        glVertex2f(x+0.25,y-1.75);
    glEnd();
}

void elephant(int x, int y, bool color){
    paint(color);
    glBegin(GL_TRIANGLES);
        glVertex2f(x+0.75,y-0.25);
        glVertex2f(x+1.25,y-0.25);
        glVertex2f(x+1,y-0.75);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex2f(x+1,y-0.25);
        glVertex2f(x+1.25,y-1.5);
        glVertex2f(x+0.75,y-1.5);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(x+0.25,y-1.5);
        glVertex2f(x+1.75,y-1.5);
        glVertex2f(x+1.75,y-1.75);
        glVertex2f(x+0.25,y-1.75);
    glEnd();
}

void king(float x, float y, bool color){
    paint(color);
    glBegin(GL_POLYGON);
        glVertex2f(x+0.95,y-0.05);
        glVertex2f(x+1.05,y-0.05);
        glVertex2f(x+1.05,y-0.6);
        glVertex2f(x+0.95,y-0.6);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(x+0.7,y-0.25);
        glVertex2f(x+1.3,y-0.25);
        glVertex2f(x+1.3,y-0.4);
        glVertex2f(x+0.7,y-0.4);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex2f(x+0.6,y-0.6);
        glVertex2f(x+1.4,y-0.6);
        glVertex2f(x+1,y-1);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(x+0.75,y-0.75);
        glVertex2f(x+1.25,y-0.75);
        glVertex2f(x+1.25,y-1.5);
        glVertex2f(x+0.75,y-1.5);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(x+0.25,y-1.5);
        glVertex2f(x+1.75,y-1.5);
        glVertex2f(x+1.75,y-1.75);
        glVertex2f(x+0.25,y-1.75);
    glEnd();
}

void queen(float x, float y, bool color){
    paint(color);

    glBegin(GL_TRIANGLES);
        glVertex2f(x+0.6,y-0.1);
        glVertex2f(x+0.9,y-0.6);
        glVertex2f(x+0.6,y-0.6);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex2f(x+1,y-0.1);
        glVertex2f(x+0.8,y-0.6);
        glVertex2f(x+1.2,y-0.6);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex2f(x+1.4,y-0.1);
        glVertex2f(x+1.4,y-0.6);
        glVertex2f(x+1.1,y-0.6);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex2f(x+0.6,y-0.6);
        glVertex2f(x+1.4,y-0.6);
        glVertex2f(x+1,y-1);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(x+0.75,y-0.75);
        glVertex2f(x+1.25,y-0.75);
        glVertex2f(x+1.25,y-1.5);
        glVertex2f(x+0.75,y-1.5);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(x+0.25,y-1.5);
        glVertex2f(x+1.75,y-1.5);
        glVertex2f(x+1.75,y-1.75);
        glVertex2f(x+0.25,y-1.75);
    glEnd();
}

void pedestrian(float x, float y, bool color){
    paint(color);
    glBegin(GL_POLYGON);
        glVertex2f(x+0.75,y-0.25);
        glVertex2f(x+1.25,y-0.25);
        glVertex2f(x+1.45,y-0.5);
        glVertex2f(x+1.25,y-0.75);
        glVertex2f(x+0.75,y-0.75);
        glVertex2f(x+0.55,y-0.5);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(x+1.25,y-0.75);
        glVertex2f(x+1.45,y-1.5);
        glVertex2f(x+0.55,y-1.5);
        glVertex2f(x+0.75,y-0.75);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(x+0.25,y-1.5);
        glVertex2f(x+1.75,y-1.5);
        glVertex2f(x+1.75,y-1.75);
        glVertex2f(x+0.25,y-1.75);
    glEnd();
}

float getPosX(int x){

    float s = 0;
    if(x >= 163 && x <= 208) s = -8;
    else if(x >= 210 && x <= 255) s = -6;
    else if(x >= 257 && x <= 298) s = -4;
    else if(x >= 300 && x <= 345) s = -2;
    else if(x >= 347 && x <= 392) s = 0;
    else if(x >= 394 && x <= 449) s = 2;
    else if(x >= 451 && x <= 496) s = 4;
    else if(x >= 498 && x <= 543) s = 6;
    return s;

}
float getPosY(int y){

    float s = 0;
    if(y >= 272 && y <= 317) s = 8;
    else if(y >= 225 && y <= 270) s = 6;
    else if(y >= 178 && y <= 223) s = 4;
    else if(y >= 131 && y <= 176) s = 2;
    else if(y >= 84 && y <= 129) s = 0;
    else if(y >= 41 && y <= 86) s = -2;
    else if(y >= -6 && y <= 39) s = -4;
    else if(y >= -53 && y <= -8) s = -6;
    return s;

}
int getFigIndexX(float x){
    return (x+8)/2;}

int getFigIndexY(float y){
    return (-y+8)/2;}

string toString(int n){
    char str[100] ;
    sprintf(str , "%d" , n );
    string s = str;
    return s;
 }

void mouse(int button, int state, int mousex, int mousey){
    pos_x = mousex;
    pos_y = 480-mousey;

    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
        if((getPosX(pos_x)>=-8 && getPosX(pos_x)<=6)&& (getPosY(pos_y)<=8 && getPosY(pos_y)>=-6))
        {
            int temp_x = getFigIndexX(getPosX(pos_x));
            int temp_y = getFigIndexY(getPosY(pos_y));

            cout<<"X_index = "<<temp_x<< "   Y_index = " <<temp_y<<endl;

            string merged_temp = toString(temp_x)+toString(temp_y);

            if(temp_pos == "")
                if(board_figs[temp_y][temp_x] != "0")
                    temp_pos += merged_temp;

            if(temp_pos.length() != 0 && temp_pos != toString(temp_x)+toString(temp_y))
                temp_pos += merged_temp;

            if(temp_pos.length()==4){

                board_figs[temp_pos[3]-48][temp_pos[2]-48] = "0";
                swap(board_figs[temp_pos[1]-48][temp_pos[0]-48],board_figs[temp_pos[3]-48][temp_pos[2]-48]);
                glutPostRedisplay();
                temp_pos="";

            }
        }
    }
    else if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
    {
        cout<<"RIGHT CLICKED"<<endl;
    }
}

void draw_figures(){
    float x = -8,y = 8;
    for(int i = 0;i<8;i++){
        for(int j = 0;j<8;j++){
            int temp_color = 1;
            if(board_figs[i][j][0] == 'b')
                temp_color = 0;
                switch(board_figs[i][j][1]){
                case 'c':
                    cannon(x,y,temp_color);
                    break;
                case 'h':
                    horse(x,y,temp_color);
                    break;
                case 'e':
                    elephant(x,y,temp_color);
                    break;
                case 'k':
                    king(x,y,temp_color);
                    break;
                case 'q':
                    queen(x,y,temp_color);
                    break;
                case 'p':
                    pedestrian(x,y,temp_color);
                    break;
            }
            x+=2;
        }
        x = -8;
        y-=2;
    }
}

void display(){
    draw_board();
    draw_figures();
    glFlush();
}

void init(){
    glOrtho(-15, 15, -15, 15, -1, 1);
    glClearColor(1,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc, char *argv[]){
    draw_figures();
    glutInit(&argc, argv);
    glutInitWindowSize(700,700);
    glutInitWindowPosition(500,20);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Chess Board");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();

    return 0;
}
