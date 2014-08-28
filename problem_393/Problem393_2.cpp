#include <iostream>
using namespace std;


class AntMoveRegulator {
private:
    int n;
    int sol;
    int** cross_rights;
    bool* occupied;
    bool* moved;
    bool* crossed;
    void initialize() {
        for(int i = 0; i < n*n; ++i) {
            moved[i] = false;
            occupied[i] = false;
        }
        for(int i = 0; i < 2*n*(n+1); ++i) {
            crossed[i] = false;
        }
    }

    void print_crossed_edges() {
        for(int i = 0; i < 2*n*(n+1); ++i) {
            if(crossed[i])
                cout << i << " ";
        }
        cout << endl;
    }

    bool is_solved() {
        for(int i = 0; i < n*n; ++i) {
            if(!moved[i]) {
                return false;
            }
        }
        return true;
    }

    int next_ant() {
        for(int i = 0; i < n*n; ++i) {
            if(!moved[i]) {
                return i;
            }
        }
        return -1;
    }

    void move(int ant_pos) {
        // cout << " enter: ant-pos: " << ant_pos << endl;
        int crossed_edge = -1;
        int new_pos = -1;

        if(is_solved()) {
            sol++;
            print_crossed_edges();
        }
        else if(ant_pos == -1) {
            // cout << "all ants moved! but no solution" << endl;
        }
        else {
            // let's move it
            for(int i = 0; i < 4; ++i) {

                if(cross_rights[ant_pos][i] != -1 && !crossed[cross_rights[ant_pos][i]]) {

                    switch(i) {
                    case 0:
                        new_pos = ant_pos - 1;
                        break;
                    case 1:
                        new_pos = ant_pos + 1;
                        break;
                    case 2:
                        new_pos = ant_pos - n;
                        break;
                    case 3:
                        new_pos = ant_pos + n;
                        break;
                    }

                    if(!occupied[new_pos]) {
                        // cout << "move-info:" << endl;
                        // cout << "ant-pos: " << ant_pos << " new_pos: " << new_pos << " crossed_edge:"
                        //     << cross_rights[ant_pos][i] << endl;
                        moved[ant_pos] = true;
                        occupied[new_pos] = true;
                        crossed_edge = cross_rights[ant_pos][i];
                        crossed[crossed_edge] = true;
                        move(next_ant());
                    }
                }

                if(moved[ant_pos]) {
                    // take-back:
                    moved[ant_pos] = false;
                    crossed[crossed_edge] = false;
                    occupied[new_pos] = false;
                    // cout << " takeback: ant-pos: " << ant_pos << endl;
                    // cout << "takeback corrected crossed_edge: " << crossed_edge << endl;
                    // cout << "takeback corrected occupied square: " << new_pos << endl;
                }
            }
        }

        // cout << " exit: ant-pos: " << ant_pos << endl;
    }

public:
    AntMoveRegulator(int grid_size) : n(grid_size), sol(0) {

        // Let's define the rules for the crossing
        cross_rights = new int*[n*n];
        for(int i = 0; i < n*n; ++i) {
            cross_rights[i] = new int[4];
        }
        int a = 0;
        int b = n*(n+1);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                cross_rights[i*n + j][0] = a++; // Left
                cross_rights[i*n + j][1] = a;   // Right
                cross_rights[i*n + j][2] = b;   // Top
                cross_rights[i*n + j][3] = b+n; // Bottom
                b++;
                if(j == 0) {
                    cross_rights[i*n][0] = -1;
                }
                else if(j == n-1) {
                    cross_rights[i*n + j][1] = -1;
                }
                if(i == 0) {
                    cross_rights[j][2] = -1;
                }
                else if(i == n-1) {
                    cross_rights[n*(n-1) + j][3] = -1;
                }
            }
            a++;
        }
        cross_rights[0][0]      = -1;    // Left
        cross_rights[0][2]      = -1;    // Top
        cross_rights[n-1][1]    = -1;    // Right
        cross_rights[n-1][2]    = -1;    // Top
        cross_rights[n*n-n][0]  = -1;    // Left
        cross_rights[n*n-n][3]  = -1;    // Bottom
        cross_rights[n*n-1][1]  = -1;    // Right
        cross_rights[n*n-1][3]  = -1;    // Bottom

        occupied = new bool[n*n];
        crossed = new bool[2*n*(n+1)];
        moved = new bool[n*n];

        initialize();
    }

    void execute() {
        move(0);
        cout << "Sol: " << sol << endl;
    }

    void print_cross_rights() {
        for(int i = 0; i < n*n; ++i) {
            for(int j = 0; j < 4; ++j) {
                cout << cross_rights[i][j] << " ";
            }
            cout << endl;
        }
    }

    ~AntMoveRegulator() {
        for(int i = 0; i < n; ++i) {
            delete[] cross_rights[i];
        }
        delete[] occupied;
        delete[] crossed;
        delete[] moved;
    }

};

int main() {

    int n;
    cout << "Enter the problem size: ";
    cin >> n;

    AntMoveRegulator amr(n);
    // amr.print_cross_rights();
    amr.execute();

    return 0;
}
