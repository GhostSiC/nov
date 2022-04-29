
#include <iostream>
#include <array>
#include <cmath>
#include <algorithm>

struct vec2
{
    float x, y;
};

struct triangle
{
    std::array<vec2, 3> points;
};

float vectorDotProduct(vec2 pt1, vec2 pt2)
{
    return (pt1.x * pt2.x) + (pt1.y * pt2.y);
}

bool isColliding(const triangle& triangle1, const triangle& triangle2) {


    for (int i = 0; i < triangle1.points.size(); i++) {

        

        vec2 axis{
            -(triangle1.points.at(i).y - triangle1.points.at((i+1) % triangle1.points.size()).y),
            triangle1.points.at(i).x - triangle1.points.at((i + 1) % triangle1.points.size()).x
        };


        vec2 magnitude{
            sqrt(pow(axis.x, 2)),
            sqrt(pow(axis.y, 2))
        };

        if (magnitude.x != 0 && magnitude.y != 0)
        {
            axis.x *= 1 / magnitude.x;
            axis.y *= 1 / magnitude.y;
        }

        float p1min = vectorDotProduct(axis, triangle1.points.at(i));
        float p1max = std::numeric_limits<int>::min();


        vec2 dot = triangle1.points.at(i);
        p1min = std::min(p1min, dot.x);
        p1max = std::max(p1max, dot.y);
        

        std::cout << axis.x << '\n';
        std::cout << axis.y << '\n';
        
        std::cout << p1min << '\n';
        std::cout << p1max << '\n';
    }
    return 0;
}

int main()
{

    //triangle triangle1 = { (0,0), (4,0), (2,4) };
    triangle triangle1{};

    triangle1.points.at(0).x = 0;
    triangle1.points.at(0).y = 0;

    triangle1.points.at(1).x = 4;
    triangle1.points.at(1).y = 0;

    triangle1.points.at(2).x = 2;
    triangle1.points.at(2).y = 4;

    //triangle triangle2 = { (2,2), (6,2), (4,6) };
    triangle triangle2{};

    triangle2.points.at(0).x = 2;
    triangle2.points.at(0).y = 2;

    triangle2.points.at(1).x = 6;
    triangle2.points.at(1).y = 2;

    triangle2.points.at(2).x = 4;
    triangle2.points.at(2).y = 6;

    isColliding(triangle1, triangle2);
}
