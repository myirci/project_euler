#include <iostream>
using namespace std;


class AntMoveRegulator {
private:
    int n;
    unsigned long sol;
    int** edge_move_rights;
    int* moved_square;
    int* crosssed_edge;
    bool* crosssed;
    bool* ant_moved;
    bool* square_occupied;
    void execute(int ant_pos) {
        if(!ant_moved[ant_pos]) {
            int sq_to_move = -1;
            int next_ant_to_move = -2;
            for(int i = 0; i < 4; ++i) {

                if(ant_moved[ant_pos]) {
                    // take-back the move
                    cout << "take_back for: " << ant_pos << endl;
                    ant_moved[ant_pos] = false;
                    if(moved_square[ant_pos] != -1)
                        square_occupied[moved_square[ant_pos]] = false;
                    if(crosssed_edge[ant_pos] != -1)
                        crosssed[crosssed_edge[ant_pos]] = false;
                }

                if(edge_move_rights[ant_pos][i] != -1 && !crosssed[edge_move_rights[ant_pos][i]]) {
                    sq_to_move = -1;
                    switch(i) {
                    case 0: // Move to Left
                        if(!square_occupied[ant_pos - 1]) {
                            sq_to_move = ant_pos - 1;
                        }
                        break;
                    case 1: // Move to Right
                        if(!square_occupied[ant_pos + 1]) {
                            sq_to_move = ant_pos + 1;
                        }
                        break;
                    case 2: // Move to Top
                        if(!square_occupied[ant_pos - n]) {
                            sq_to_move = ant_pos - n;
                        }
                        break;
                    case 3: // Move to Bottom
                        if(!square_occupied[ant_pos + n]) {
                            sq_to_move = ant_pos + n;
                        }
                        break;
                    }

                    if(sq_to_move != -1) {
                        square_occupied[sq_to_move] = true;
                        ant_moved[ant_pos] = true;
                        crosssed[edge_move_rights[ant_pos][i]] = true;
                        moved_square[ant_pos] = sq_to_move;
                        crosssed_edge[ant_pos] = edge_move_rights[ant_pos][i];
                        next_ant_to_move = next_ant();
                        cout << "ant_pos: " << ant_pos << " i: " << i << " sq_to_move: " << sq_to_move << endl;
                        if(next_ant_to_move == -1) {
                            sol++;
                            // set_to_initial_pos();
                        }
                        else {
                            cout << "next_ant_to_move: " << next_ant_to_move << endl;
                            execute(next_ant_to_move);
                        }
                    }

                } // end-of-if

            } // end-of-for

            if(ant_moved[ant_pos]) {
                // take-back the move
                cout << "take_back for: " << ant_pos << endl;
                ant_moved[ant_pos] = false;
                if(moved_square[ant_pos] != -1)
                    square_occupied[moved_square[ant_pos]] = false;
                if(crosssed_edge[ant_pos] != -1)
                    crosssed[crosssed_edge[ant_pos]] = false;
            }
        }
    }

    int next_ant() const {
        for(int i = 0; i < n*n; ++i) {
            if(!ant_moved[i]) {
                return i;
            }
        }
        return -1;
    }

    void set_to_initial_pos() {
        for(int i = 0; i < n*n; ++i) {
            square_occupied[i] = false;
            ant_moved[i] = false;
            moved_square[i] = -1;
            crosssed_edge[i] = -1;
        }
        for(int i = 0; i < 2*n*(n+1); ++i) {
           crosssed[i] = false;
        }
    }
public:
    AntMoveRegulator(int size) : n(size), sol(0) {

        // On each square we have an ant
        square_occupied = new bool[n*n];

        // Keep track the crossed edges, not allowed to cross the same edge twice.
        crosssed = new bool[2*n*(n+1)];

        // Each ant must move once
        ant_moved = new bool[n*n];

        // To keep track of the moves
        moved_square = new int[n*n];
        crosssed_edge = new int[n*n];

        set_to_initial_pos();

        // Let's define the rules for the crossing
        edge_move_rights = new int*[n*n];
        for(int i = 0; i < n*n; ++i) {
            edge_move_rights[i] = new int[4];
        }
        int a = 0;
        int b = n*(n+1);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                edge_move_rights[i*n + j][0] = a++; // Left
                edge_move_rights[i*n + j][1] = a;   // Right
                edge_move_rights[i*n + j][2] = b;   // Top
                edge_move_rights[i*n + j][3] = b+n; // Bottom
                b++;
                if(j == 0) {
                    edge_move_rights[i*n][0] = -1;
                }
                else if(j == n-1) {
                    edge_move_rights[i*n + j][1] = -1;
                }
                if(i == 0) {
                    edge_move_rights[j][2] = -1;
                }
                else if(i == n-1) {
                    edge_move_rights[n*(n-1) + j][3] = -1;
                }
            }
            a++;
        }
        edge_move_rights[0][0] = -1;        // L
        edge_move_rights[0][2] = -1;        // T
        edge_move_rights[n-1][1] = -1;      // R
        edge_move_rights[n-1][2] = -1;      // T
        edge_move_rights[n*n-n][0] = -1;    // L
        edge_move_rights[n*n-n][3] = -1;    // B
        edge_move_rights[n*n-1][1] = -1;    // R
        edge_move_rights[n*n-1][3] = -1;    // B
    }
    ~AntMoveRegulator() {
        for(int i = 0; i < n; ++i) {
            delete[] edge_move_rights[i];
        }
        delete[] ant_moved;
        delete[] crosssed;
    }
    void print_edge_move_rights() const {
        cout << "edge_move_rights: " << endl;
        for(int i = 0; i < n*n; ++i) {
            for(int j = 0; j < 4; ++j) {
                cout << edge_move_rights[i][j] << " ";
            }
            cout << endl;
        }
    }
    void solve() {
        execute(0);
        std::cout << "Sol: " << sol << endl;
    }
};

int main() {
    int n;
    cout << "Enter the problem size: ";
    cin >> n;

    AntMoveRegulator amr(n);
    amr.print_edge_move_rights();
    amr.solve();
    return 0;
}
