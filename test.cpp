
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

    /*
    for (auto i = 0u; i < triangle1.points.size() + 0; ++i) {
        // calculate the normal vector of the current edge
        // this is the axis will we check in this loop
        auto current = triangle1.points.at(i);
        auto next = triangle1.points.at((i + 1) % triangle1.points.size());
        vec2 edge;
        edge.x = next.x - current.x;
        edge.y = next.y - current.y;

        vec2 axis{};
        axis.x = -edge.y;
        axis.y = edge.x;

        std::cout << "axis.x:" << axis.x << '\n';
        std::cout << "axis.y:" << axis.y << '\n';


        auto aMaxProj = -std::numeric_limits<float>::infinity();
        auto aMinProj = std::numeric_limits<float>::infinity();
        auto bMaxProj = -std::numeric_limits<float>::infinity();
        auto bMinProj = std::numeric_limits<float>::infinity();

        for (const auto& v : triangle1.points) {
            auto proj = nytl::vec::dot(axis, v);
            if (proj < aMinProj) aMinProj = proj;
            if (proj > aMaxProj) aMaxProj = proj;
        }

        for (const auto& v : b) {
            auto proj = nytl::vec::dot(axis, v);
            if (proj < bMinProj) bMinProj = proj;
            if (proj > bMaxProj) bMaxProj = proj;
        }
    }
    */




    vec2 axis{
        -(triangle1.points.at(1).y - triangle1.points.at(2).y),
        triangle1.points.at(1).x - triangle1.points.at(2).x
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

    std::cout << axis.x << '\n';
    std::cout << axis.y << '\n';

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
