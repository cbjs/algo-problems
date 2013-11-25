/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

struct Line {
    int a, b, c;
    Line(const Point& p1, const Point& p2) {
        a = p2.y - p1.y;
        b = p1.x - p2.x;
        c = p2.x * p1.y - p1.x * p2.y;
        int t = gcd(abs(a), gcd(abs(b), abs(c)));
        a /= t;
        b /= t;
        c /= t;
        if (a < 0) {
            a *= -1;
            b *= -1;
            c *= -1;
        } else if (a == 0 && b < 0) {
            b *= -1;
            c *= -1;
        }
    }

    int gcd(int x, int y) {
        while (y != 0) {
            int t = x % y;
            x = y;
            y = t;
        }
        return x;
    }

    bool operator<(const Line& line) const {
        return a < line.a || (a == line.a && b < line.b) || (a == line.a && b == line.b && c < line.c);
    }
};

typedef set<int> PointSet;

class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if (points.size() <= 2) return points.size();
        int i = 1;
        for (; i < points.size(); ++i) {
            if (points[i].x != points[i - 1].x || points[i].y != points[i - 1].y) break;
        }
        if (i == points.size()) return points.size();

        map<Line, PointSet> count;
        for (int i = 0; i < points.size(); ++i) {
            for (int j = i + 1; j < points.size(); ++j) {
                if (points[i].x == points[j].x && points[i].y == points[j].y) continue;
                PointSet& ps = count[Line(points[i], points[j])];
                ps.insert(i);
                ps.insert(j);
            }
        }

        int max_count = 0;
        for(map<Line, PointSet>::iterator i = count.begin(); i != count.end(); i++) {
            if (max_count < i->second.size()) max_count = i->second.size();
        }

        return max_count;
    }
};
