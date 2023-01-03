#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstddef>

struct Point {
    int x;
    int y;
};

double distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

std::pair<Point, Point> brute_force(std::vector<Point> points) {
    double min_distance = INFINITY;

    std::pair<Point, Point> min_points;
    for (size_t i = 0; i < points.size(); i++) {
        for (size_t j = i + 1; j < points.size(); j++) {
            if (distance(points[i], points[j]) < min_distance) {
                min_distance = distance(points[i], points[j]);
                min_points = std::make_pair(points[i], points[j]);
            }
        }
    }
    return min_points;
}


std::pair<Point, Point> solve(std::vector<Point> points) {
    if (points.size() <= 10) {
        return brute_force(points);
    }

    sort(points.begin(), points.end(), [](Point p1, Point p2) { return p1.x < p2.x; });
    long mid = static_cast<long> (points.size() / 2);
    std::vector<Point> left(points.begin(), points.begin() + mid);
    std::vector<Point> right(points.begin() + mid, points.end());

    std::pair<Point, Point> left_points = solve(left);
    std::pair<Point, Point> right_points = solve(right);

    double min_distance = std::min(
            distance(left_points.first, left_points.second),
            distance(right_points.first, right_points.second)
    );

    std::pair <Point, Point> min_points =
            distance(left_points.first, left_points.second)
            < distance(right_points.first, right_points.second)
            ? left_points : right_points;


    long mid_line = (points[mid - 1].x + points[mid].x) / 2;
    std::vector <Point> mid_points;

    for (Point point: points) {
        if (static_cast<double> (abs(point.x - mid_line)) < min_distance) {
            mid_points.push_back(point);
        }
    }

    sort(mid_points.begin(), mid_points.end(), [](Point p1, Point p2) { return p1.y < p2.y; });
    for (size_t i = 0; i < mid_points.size(); i++) {
        for (size_t j = i + 1; j < std::min(i + 7, static_cast<size_t> (mid_points.size())); j++) {
            if (distance(mid_points[i], mid_points[j]) < min_distance) {
                min_distance = distance(mid_points[i], mid_points[j]);
                min_points = std::make_pair(mid_points[i], mid_points[j]);
            }
        }
    }
    return min_points;
}


int main() {
    int n;
    std::cin >> n;
    std::vector <Point> points;

    for (int i = 0; i < n; i++) {
        Point point{};
        std::cin >> point.x >> point.y;
        points.push_back(point);
    }

    std::pair <Point, Point> min_points = solve(points);
    std::cout << min_points.first.x << " " << min_points.first.y << std::endl;
    std::cout << min_points.second.x << " " << min_points.second.y << std::endl;
    return 0;
}
