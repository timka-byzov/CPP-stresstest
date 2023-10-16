#pragma once
#include <bits/stdc++.h>

#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

namespace slow{
    int coverageCount(std::vector<Point> &points, long double r, int k) {
        long double start = -100, stop = 100, eps = 1e-3;
        int max_count = 0;

        long double c = start;
        while(c < stop){
            int count = 0;
            for (const auto &point: points) {
                long double distance = (point.x - c) * (point.x - c) + point.y * point.y;
                if (distance <= r * r) {
                    ++count;
                }
            }
            max_count = std::max(max_count, count);
            c += eps;
        }

        return max_count;
    }



    long double findMinRadius(std::vector<Point> points, int k) {
        // отражаю все точки из-за симметричности
        for (auto &point: points) {
            point.y = abs(point.y);
        }

        long double rmin = 0, rmax = 14; // TODO: поправить границы

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
