#include <bits/stdc++.h>
using namespace std;

int limx, limy;

bool isincluded(int x, int y, vector<int>& window) {
    return window[0] <= x && x < window[0] + window[2] && window[1] <= y && y < window[1] + window[3];
}

bool poverlap(vector<int>& recta, vector<int>& rectb) {
    return !(
        rectb[0] + rectb[2] <= recta[0] ||
        recta[0] + recta[2] <= rectb[0] ||
        rectb[1] + rectb[3] <= recta[1] ||
        recta[1] + recta[3] <= rectb[1]
    );
}

bool overlap(int x, int y, int w, int h, vector<vector<int> >& windows) {
    vector<int> temp;
    temp.push_back(x);
    temp.push_back(y);
    temp.push_back(w);
    temp.push_back(h);
    for (int i = 0; i < windows.size(); ++i) {
        if (poverlap(windows[i], temp)) {
            return true;
        }
    }
    return false;
}

bool windowexists(int x, int y, vector<vector<int> >& windows) {
    for (int i = 0; i < windows.size(); ++i) {
        if (isincluded(x, y, windows[i])) {
            return true;
        }
    }
    return false;
}

// returns true iff there is a window at x, y, and that window was successfully removed
bool removewindow(int x, int y, vector<vector<int> >& windows) {
    int remidx = -1;
    for (int i = 0; i < windows.size(); ++i) {
        if (isincluded(x, y, windows[i])) {
            remidx = i;
            break;
        }
    }
    if (remidx != -1) {
        windows.erase(windows.begin() + remidx);
    }
    return remidx != -1;
}

// void moveh(int x, int y, int dx, vector<vector<int> >& windows, int cmdid) {
//     // get the window that will be moved
//     int startidx = -1;
//     for (int i = 0; i < windows.size(); ++i) {
//         // case where the given point is included in the current window
//         if (isincluded(x, y, windows[i])) {
//             startidx = i;
//             break;
//         }
//     }
//     // get the list of windows that will be moved
//     vector<int> movedwindows;
//     long long sumw = windows[startidx][2];
//     movedwindows.push_back(startidx);
//     int init = windows[startidx][0], initdel = dx;
//     int s2 = windows[startidx][1];
//     int e2 = windows[startidx][1] + windows[startidx][3];
//     if (dx > 0) { // move right
//         for (int i = startidx + 1; i < windows.size(); ++i) {
//             // case where current rectangle start is greater than or equal to the distance moved by the first window
//             if (windows[startidx][0] + windows[startidx][2] + dx <= windows[i][0]) {
//                 break;
//             }
//             // case where overlap in y 
//             if (intervaloverlap(windows[i][1], windows[i][1] + windows[i][3], s2, e2)) {
//                 sumw += windows[i][2];
//                 movedwindows.push_back(i);
//             }
//         }
//         // then move the rectangles
//         for (int i = 0; i < movedwindows.size(); ++i) {
//             int delta = i < movedwindows.size() - 1 ? windows[movedwindows[i + 1]][0] - windows[movedwindows[i]][0] - windows[movedwindows[i]][2] : 0;
//             windows[movedwindows[i]][0] = min(limx - sumw, (long long) dx + windows[movedwindows[i]][0]);
//             sumw -= windows[movedwindows[i]][2];
//             if (i < movedwindows.size() - 1) {
//                 dx -= delta;
//             }
//         }
//     } else { // move left
//         for (int i = startidx - 1; i >= 0; --i) {
//             // case where current rectangle start is greater than or equal to the distance moved by the first window
//             if (windows[startidx][0] + dx >= windows[i][0] + windows[i][2]) {
//                 break;
//             }
//             // case where overlap in y 
//             if (intervaloverlap(windows[i][1], windows[i][1] + windows[i][3], s2, e2)) {
//                 sumw += windows[i][2];
//                 movedwindows.push_back(i);
//             }
//         }
//         // then move the rectangles
//         for (int i = 0; i < movedwindows.size(); ++i) {
//             int delta = i >= 0 ? windows[movedwindows[i]][0] + windows[movedwindows[i]][2] - windows[movedwindows[i - 1]][0]: 0;
//             sumw -= windows[movedwindows[i]][2];
//             windows[movedwindows[i]][0] = max(0 + sumw, (long long) dx + windows[movedwindows[i]][0]);
//             if (i >= 0) {
//                 dx += delta;
//             }
//         }
//     }
//     // get actual distance moved
//     int dmoved = abs(windows[startidx][0] - init);
//     if (dmoved != initdel) {
//         cout << "Command " << cmdid << ": MOVE - moved " << dmoved << " instead of " << abs(initdel) << endl;
//     }
// }

// void movev(int x, int y, int dy, vector<vector<int> >& windows, int cmdid) {
//     // get the window that will be moved
//     int startidx = -1;
//     for (int i = 0; i < windows.size(); ++i) {
//         // case where the given point is included in the current window
//         if (isincluded(x, y, windows[i])) {
//             startidx = i;
//             break;
//         }
//     }
//     // get the list of windows that will be moved
//     vector<int> movedwindows;
//     long long sumh = windows[startidx][3];
//     movedwindows.push_back(startidx);
//     int init = windows[startidx][1], initdel = dy;
//     int s2 = windows[startidx][0];
//     int e2 = windows[startidx][0] + windows[startidx][2];
//     if (dy > 0) { // move right
//         for (int i = startidx + 1; i < windows.size(); ++i) {
//             // case where current rectangle start is greater than or equal to the distance moved by the first window
//             if (windows[startidx][1] + windows[startidx][3] + dy <= windows[i][1]) {
//                 break;
//             }
//             // case where overlap in x
//             if (intervaloverlap(windows[i][0], windows[i][0] + windows[i][2], s2, e2)) {
//                 sumh += windows[i][3];
//                 movedwindows.push_back(i);
//             }
//         }
//         // then move the rectangles
//         for (int i = 0; i < movedwindows.size(); ++i) {
//             int delta = i < movedwindows.size() - 1 ? windows[movedwindows[i + 1]][1] - windows[movedwindows[i]][1] - windows[movedwindows[i]][3] : 0;
//             windows[movedwindows[i]][1] = min(limy - sumh, (long long) dy + windows[movedwindows[i]][1]);
//             sumh -= windows[movedwindows[i]][3];
//             if (i < movedwindows.size() - 1) {
//                 dy -= delta;
//             }
//         }
//     } else { // move left
//         for (int i = startidx - 1; i >= 0; --i) {
//             // case where current rectangle start is greater than or equal to the distance moved by the first window
//             if (windows[startidx][1] + dy >= windows[i][1] + windows[i][3]) {
//                 break;
//             }
//             // case where overlap in x
//             if (intervaloverlap(windows[i][0], windows[i][0] + windows[i][2], s2, e2)) {
//                 sumh += windows[i][3];
//                 movedwindows.push_back(i);
//             }
//         }
//         // then move the rectangles
//         for (int i = 0; i < movedwindows.size(); ++i) {
//             int delta = i >= 0 ? windows[movedwindows[i]][1] + windows[movedwindows[i]][3] - windows[movedwindows[i - 1]][1]: 0;
//             sumh -= windows[movedwindows[i]][3];
//             windows[movedwindows[i]][1] = max(0 + sumh, (long long) dy + windows[movedwindows[i]][1]);
//             if (i >= 0) {
//                 dy += delta;
//             }
//         }
//     }
//     // get actual distance moved
//     int dmoved = abs(windows[startidx][1] - init);
//     if (dmoved != initdel) {
//         cout << "Command " << cmdid << ": MOVE - moved " << dmoved << " instead of " << abs(initdel) << endl;
//     }
// }

int mv(vector<vector<int> >& windows, int idx, int dx, int dy) {
    if (dx > 0) {
        vector<int> movez;
        movez.push_back(idx);
        int moved = 0;
        int right = windows[idx][0] + windows[idx][2];
        while (moved < dx) {
            vector<int> closei;
            vector<int> closej;
            int closed = INT_MAX;

            for (int i = 0; i < windows.size(); ++i) {
                if (find(movez.begin(), movez.end(), i) != movez.end())continue;

                for (int j = 0; j < movez.size(); ++j) {
                    const auto& winj = windows[movez[j]];
                    if (windows[i][0] < winj[0])continue;
                    if (windows[i][1] >= winj[1] + winj[3])continue;
                    if (windows[i][1] + windows[i][3] <= winj[1])continue;
                    int dist = windows[i][0] - (winj[0] + winj[2]);
                    assert(dist >= 0);
                    if (dist < 0) {
                        cout << winj[0] << " " << winj[1] << " " << winj[2] << " " << winj[3] << endl;
                        cout << windows[i][0] << " " << windows[i][1] << " " << windows[i][2] << " " << windows[i][3] << endl;
                        exit(1);
                    }
                    if (dist < closed) {
                        closed = dist;
                        closej = {j};
                        closei = {i};
                    } else if (dist == closed) {
                        closej.push_back(j);
                        closei.push_back(i);
                    }
                }
            }

            if (closei.empty()) {
                int mov = min(limx - right, dx - moved);
                for (int j : movez) {
                    windows[j][0] += mov;
                }
                moved += mov;
                break;
            } else {
                int mov = min(closed, dx - moved);
                mov = min(limx - right, mov);
                for (int j : movez) {
                    windows[j][0] += mov;
                }
                moved += mov;

                if (mov == limx - right)break;

                if (mov == closed) {
                    for (int i : closei) {
                        if (find(movez.begin(), movez.end(), i) != movez.end())continue;
                        movez.push_back(i);
                    }
                }
            }

            for (int j : movez) {
                right = max(right, windows[j][0] + windows[j][2]);
            }
        }
        return moved;
    } else if (dx < 0) {
        vector<int> movez;
        movez.push_back(idx);
        int moved = 0;
        int left = windows[idx][0];
        while (moved > dx) {
            vector<int> closei;
            vector<int> closej;
            int closed = INT_MAX;

            for (int i = 0; i < windows.size(); ++i) {
                if (find(movez.begin(), movez.end(), i) != movez.end())continue;

                for (int j = 0; j < movez.size(); ++j) {
                    const auto& winj = windows[movez[j]];
                    if (windows[i][0] > winj[0])continue;
                    if (windows[i][1] >= winj[1] + winj[3])continue;
                    if (windows[i][1] + windows[i][3] <= winj[1])continue;
                    int dist = winj[0] - (windows[i][0] + windows[i][2]);
                    assert(dist >= 0);
                    if (dist < closed) {
                        closed = dist;
                        closej = {j};
                        closei = {i};
                    } else if (dist == closed) {
                        closej.push_back(j);
                        closei.push_back(i);
                    }
                }
            }

            if (closei.empty()) {
                int mov = min(left, moved - dx);
                for (int j : movez) {
                    windows[j][0] -= mov;
                }
                moved -= mov;
                break;
            } else {
                int mov = min(closed, moved - dx);
                mov = min(left, mov);
                for (int j : movez) {
                    windows[j][0] -= mov;
                }
                moved -= mov;

                if (mov == left)break;

                if (mov == closed) {
                    for (int i : closei) {
                        if (find(movez.begin(), movez.end(), i) != movez.end())continue;
                        movez.push_back(i);
                    }
                }
            }
            for (int j : movez) {
                left = min(left, windows[j][0]);
            }
        }
        return moved;
    } else if (dy > 0) {
        vector<int> movez;
        movez.push_back(idx);
        int moved = 0;
        int bot = windows[idx][1] + windows[idx][3];
        while (moved < dy) {
            vector<int> closei;
            vector<int> closej;
            int closed = INT_MAX;

            for (int i = 0; i < windows.size(); ++i) {
                if (find(movez.begin(), movez.end(), i) != movez.end())continue;

                for (int j = 0; j < movez.size(); ++j) {
                    const auto& winj = windows[movez[j]];
                    if (windows[i][1] < winj[1])continue;
                    if (windows[i][0] >= winj[0] + winj[2])continue;
                    if (windows[i][0] + windows[i][2] <= winj[0])continue;
                    int dist = windows[i][1] - (winj[1] + winj[3]);
                    assert(dist >= 0);
                    if (dist < closed) {
                        closed = dist;
                        closej = {j};
                        closei = {i};
                    } else if (dist == closed) {
                        closej.push_back(j);
                        closei.push_back(i);
                    }
                }
            }

            if (closei.empty()) {
                int mov = min(limy - bot, dy - moved);
                for (int j : movez) {
                    windows[j][1] += mov;
                }
                moved += mov;
                break;
            } else {
                int mov = min(closed, dy - moved);
                mov = min(limy - bot, mov);
                for (int j : movez) {
                    windows[j][1] += mov;
                }
                moved += mov;

                if (mov == limy - bot)break;

                if (mov == closed) {
                    for (int i : closei) {
                        if (find(movez.begin(), movez.end(), i) != movez.end())continue;
                        movez.push_back(i);
                    }
                }
            }
            for (int j : movez) {
                bot = max(bot, windows[j][1] + windows[j][3]);
            }
        }
        return moved;
    } else if (dy < 0) {
        vector<int> movez;
        movez.push_back(idx);
        int moved = 0;
        int top = windows[idx][1];
        while (moved > dy) {
            vector<int> closei;
            vector<int> closej;
            int closed = INT_MAX;

            for (int i = 0; i < windows.size(); ++i) {
                if (find(movez.begin(), movez.end(), i) != movez.end())continue;

                for (int j = 0; j < movez.size(); ++j) {
                    const auto& winj = windows[movez[j]];
                    if (windows[i][1] > winj[1])continue;
                    if (windows[i][0] >= winj[0] + winj[2])continue;
                    if (windows[i][0] + windows[i][2] <= winj[0])continue;
                    int dist = winj[1] - (windows[i][1] + windows[i][3]);
                    assert(dist >= 0);
                    if (dist < closed) {
                        closed = dist;
                        closej = {j};
                        closei = {i};
                    } else if (dist == closed) {
                        closej.push_back(j);
                        closei.push_back(i);
                    }
                }
            }

            if (closei.empty()) {
                int mov = min(top, moved - dy);
                for (int j : movez) {
                    windows[j][1] -= mov;
                }
                moved -= mov;
                break;
            } else {
                int mov = min(closed, moved - dy);
                mov = min(top, mov);
                for (int j : movez) {
                    windows[j][1] -= mov;
                }
                moved -= mov;

                if (mov == top)break;

                if (mov == closed) {
                    for (int i : closei) {
                        if (find(movez.begin(), movez.end(), i) != movez.end())continue;
                        movez.push_back(i);
                    }
                }
            }
            for (int j : movez) {
                top = min(top, windows[j][1]);
            }
        }
        return moved;
    } else {
        assert(false);
    }
    return 0;
}

void resizewindow(int x, int y, int w, int h, vector<vector<int> >& windows, int cmdid) {
    // loop over the windows
    int editidx = -1;
    for (int i = 0; i < windows.size(); ++i) {
        if (isincluded(x, y, windows[i])) {
            editidx = i;
            break;
        }
    }
    // no window exists => print error message
    if (editidx == -1) {
        cout << "Command " << cmdid << ": RESIZE - no window at given position" << endl;
        return; // terminate early. we are done here!
    }
    vector<int> temp;
    temp.push_back(windows[editidx][0]);
    temp.push_back(windows[editidx][1]);
    temp.push_back(w);
    temp.push_back(h);
    // now check for overlap
    for (int i = 0; i < windows.size(); ++i) {
        if (i == editidx) continue;
        if (poverlap(windows[i], temp)) {
            cout << "Command " << cmdid << ": RESIZE - window does not fit" << endl; 
            return;
        }
    }
    if (temp[0] < 0 || temp[1] < 0 || temp[0] + temp[2] > limx || temp[1] + temp[3] > limy) {
        cout << "Command " << cmdid << ": RESIZE - window does not fit" << endl; 
        return;
    }
    // else, no overlap => edit the rectangle
    windows[editidx][2] = w;
    windows[editidx][3] = h;
}

int main() {
    // get the dimensions of the screen
    int xmax, ymax;
    cin >> xmax >> ymax;
    limx = xmax, limy = ymax;
    // track the list of windows that are open 
    // each element is a vector, say a, s.t. a[0] = x, a[1] = y, a[2] = w, a[3] = h
    vector<vector<int> > windows;
    int cmdid = 1;
    // then get the commands and simulate
    while (true) {
        string command;
        cin >> command;
        // end of input
        if (cin.eof()) break;
        int x, y, w, h, dx, dy;
        // open command
        if (command == "OPEN") {
            // get the x, y, w, h
            cin >> x >> y >> w >> h;
            // then check for overlap with any existing window or the rectangle is out of bounds
            if (overlap(x, y, w, h, windows) || x < 0 || y < 0 || x + w > limx || y + h > limy) {
                cout << "Command " << cmdid << ": OPEN - window does not fit" << endl; 
                // move to next command
                goto incr;
            }
            // else, add the window to the current list of window
            vector<int> cw;
            cw.push_back(x);
            cw.push_back(y);
            cw.push_back(w);
            cw.push_back(h);
            windows.push_back(cw);
        } else if (command == "CLOSE") { // close command
            cin >> x >> y;
            if (!removewindow(x, y, windows)) {
                cout << "Command " << cmdid << ": CLOSE - no window at given position" << endl;
            }
        } else if (command == "RESIZE") { // resize command
            cin >> x >> y >> w >> h;
            resizewindow(x, y, w, h, windows, cmdid);
        } else if (command == "MOVE") { // move command
            cin >> x >> y >> dx >> dy;
            // case where no window at x and y
            if (!windowexists(x, y, windows)) {
                cout << "Command " << cmdid << ": MOVE - no window at given position" << endl;
                goto incr;
            }
            // get the window that will be moved
            int startidx = -1;
            for (int i = 0; i < windows.size(); ++i) {
                // case where the given point is included in the current window
                if (isincluded(x, y, windows[i])) {
                    startidx = i;
                    break;
                }
            }
            int res = mv(windows, startidx, dx, dy);
            if (abs(res) != max(abs(dx), abs(dy))) {
                cout << "Command " << cmdid << ": MOVE - moved " << abs(res) << " instead of " << max(abs(dx), abs(dy)) << endl;
            }
        }
        incr: ++cmdid;
    }
    // print the remaining windows that are open
    cout << windows.size() << " window(s):" << endl;
    for (int i = 0; i < windows.size(); ++i) {
        cout << windows[i][0] << " " << windows[i][1] << " " << windows[i][2] << " " << windows[i][3] << endl;
    }
}