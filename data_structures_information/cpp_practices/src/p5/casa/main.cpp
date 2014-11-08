#include <square.h>
#include <circle.h>
using namespace shapes;

void modify(int x, int y, int color, Shapes *S)
{
    S->setPosition(x,y);
    S->setColor(color);
    //S->draw();
}
 
int main(int argc,char **argv)
{
Circle *C=new Circle;
Shapes *S=dynamic_cast<Shapes*>(C);
S->setPosition(10,10);
S->setColor(10);
S->draw();
// S->setRadius(1); this is not possible
C->setRadius(1); //this is not possible
C->draw();
cout<<"----------------------"<<endl;
Square *Sq=new Square;
S=dynamic_cast<Shapes*>(Sq);
S->setPosition(20,20);
S->setColor(20);
S->draw();

Sq->setSquareSize(10);
Sq->draw();
}
