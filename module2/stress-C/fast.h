#pragma once
#include <bits/stdc++.h>

#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

struct Point {
    int x;
    int y;

    bool operator<(const Point &other) const {
        if (x == other.x) {
            return y < other.y;
        }
        return x < other.x;
    }
};

namespace fast{
    enum class EventType {
        Open,
        Close
    };

    std::pair<long double, long double> get_centers(const Point &p, long double r) {
        long double h = p.y;
        long double t = sqrtl(r * r - h * h);
        long double xc1 = p.x - t, xc2 = p.x + t;

        if (xc1 > xc2) {
            std::swap(xc1, xc2);
        }

        return std::make_pair(xc1, xc2);
    }

    int coverageCount(std::vector<Point> &points, long double r, int k) {
        int max_count = 0;
        std::vector<std::pair<long double, EventType>> events;

        for (const auto &point: points) {
            if (point.y > r) {
                continue;
            }

            long double xc1, xc2;
            std::tie(xc1, xc2) = get_centers(point, r);
            events.emplace_back(xc1, EventType::Open);
            events.emplace_back(xc2, EventType::Close);
        }

        std::sort(events.begin(), events.end());
        int curr_count = 0;
        for (const auto &event: events) {
            if (event.second == EventType::Open) {
                ++curr_count;
            } else {
                --curr_count;
            }
            max_count = std::max(max_count, curr_count);
        }

        return (int) max_count;
    }


    long double findMinRadius(std::vector<Point> points, int k) {
        // отражаю все точки из-за симметричности
        for (auto &point: points) {
            point.y = abs(point.y);
        }

        long double rmin = -1001, rmax = 1001;

        while (rmax - rmin > 1e-4) {
            long double r = (rmin + rmax) / 2;
            if (coverageCount(points, r, k) >= k) {
                rmax = r;
            } else {
                rmin = r;
            }
        }
        return rmax;
    }
}
