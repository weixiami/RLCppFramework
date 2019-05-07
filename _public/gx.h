
#pragma once
namespace rcf
{

#define GX1(x, y) (!x ? (y) : x)
#define GX2(x1, x2, y) ((!x1 || !(x1->x2)) ? (y) : x1->x2)
#define GX3(x1, x2, x3, y) (((!x1 || !(x1->x2) || !(x1->x2->x3)) ? (y) : x1->x2->x3))
#define GX4(x1, x2, x3, x4, y) (((!x1 || !(x1->x2) || !(x1->x2->x3) || !(x1->x2->x3->x4))) ? (y) : x1->x2->x3->x4)
#define GX5(x1, x2, x3, x4, x5, y) (((!x1 || !(x1->x2) || !(x1->x2->x3) || !(x1->x2->x3->x4) || !(x1->x2->x3->x4->x5))) ? (y) : x1->x2->x3->x4->x5)


}
