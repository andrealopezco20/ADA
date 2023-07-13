#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Segment {
    int left, right;
};

bool compareSegments(const Segment& s1, const Segment& s2) {
    return s1.left < s2.left;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;

        vector<Segment> segments;
        while (true) {
            int left, right;
            cin >> left >> right;
            if (left == 0 && right == 0) {
                break;
            }
            segments.push_back({left, right});
        }

        sort(segments.begin(), segments.end(), compareSegments);

        int covered = 0;
        int count = 0;
        vector<Segment> selected;
        while (covered < m) {
            int max_right = covered;
            Segment max_segment = {-1, -1};
            bool found = false;
            for (int i = 0; i < segments.size(); i++) {
                if (segments[i].left > covered) {
                    break;
                }
                if (segments[i].right > max_right) {
                    max_right = segments[i].right;
                    max_segment = segments[i];
                    found = true;
                }
            }
            if (!found) {
                cout << "0" << endl;
                break;
            }
            selected.push_back(max_segment);
            count++;
            covered = max_right;
        }

        if (covered >= m) {
            cout << count << endl;
            for (int i = 0; i < selected.size(); i++) {
                cout << selected[i].left << " " << selected[i].right << endl;
            }
        }

        if (t > 0) {
            cout <<std:: endl;
        }
    }
    return 0;
}