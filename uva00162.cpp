#include <bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        // read the current deck of cards
        vector<string> nondealer;
        vector<string> dealer;
        for (int i = 0; i < 52; ++i) {
            string curr;
            cin >> curr;
            if (i == 0 && curr == "#") {
                return 0;
            }
            if ((i & 1)) {
                dealer.insert(dealer.begin(), curr);
            } else {
                nondealer.insert(nondealer.begin(), curr);
            }
        }
        // simulate the game
        // turn flag: true = non-dealer's turn, false = dealer's turn
        bool turn = true;
        vector<string> heap;
        while (true) {
            // check winner
            if ((turn && nondealer.size() == 0) || (!turn && dealer.size() == 0)) {
                break;
            }
            // nondealer turn
            if (turn) {
                // last card is ace, king, queen or jack
                if (heap.size() > 0 && (heap[heap.size() - 1][1] == 'A' || heap[heap.size() - 1][1] == 'K' || heap[heap.size() - 1][1] == 'Q' || heap[heap.size() - 1][1] == 'J')) {
                    // compute the number of cards that player needs to play
                    int numCover = heap[heap.size() - 1][1] == 'J' ? 1 : heap[heap.size() - 1][1] == 'Q' ? 2 : heap[heap.size() - 1][1] == 'K' ? 3 : heap[heap.size() - 1][1] == 'A' ? 4 : 0;
                    char cover = '*';
                    bool haveCover = false;
                    // then play the exact number of cards unless a face card is played
                    while (numCover-- > 0) {
                        if (nondealer.size() == 0) {
                            goto end;
                        }
                        // play the card
                        string currCard = nondealer[0];
                        nondealer.erase(nondealer.begin());
                        cover = currCard[1];
                        heap.push_back(currCard);
                        if (cover == 'A' || cover == 'K' || cover == 'Q' || cover == 'J') {
                            haveCover = true;
                            break;
                        }
                    }
                    // no cover from player, give the heap to the other player 
                    if (!haveCover) {
                        for (int i = 0; i < heap.size(); ++i) {
                            dealer.push_back(heap[i]);
                        }
                        heap.clear();
                    }
                } else { // normal cover
                    string currCard = nondealer[0];
                    nondealer.erase(nondealer.begin());
                    heap.push_back(currCard);
                }
            } else { // dealer turn
                // last card is ace, king, queen or jack
                if (heap.size() > 0 && (heap[heap.size() - 1][1] == 'A' || heap[heap.size() - 1][1] == 'K' || heap[heap.size() - 1][1] == 'Q' || heap[heap.size() - 1][1] == 'J')) {
                    // compute the number of cards that player needs to play
                    int numCover = heap[heap.size() - 1][1] == 'J' ? 1 : heap[heap.size() - 1][1] == 'Q' ? 2 : heap[heap.size() - 1][1] == 'K' ? 3 : heap[heap.size() - 1][1] == 'A' ? 4 : 0;
                    char cover = '*';
                    bool haveCover = false;
                    // then play the exact number of cards unless a face card is played
                    while (numCover-- > 0) {
                        if (dealer.size() == 0) {
                            goto end;
                        }
                        // play the card
                        string currCard = dealer[0];
                        dealer.erase(dealer.begin());
                        cover = currCard[1];
                        heap.push_back(currCard);
                        if (cover == 'A' || cover == 'K' || cover == 'Q' || cover == 'J') {
                            haveCover = true;
                            break;
                        }
                    }
                    // no cover from player, give the heap to the other player 
                    if (!haveCover) {
                        for (int i = 0; i < heap.size(); ++i) {
                            nondealer.push_back(heap[i]);
                        }
                        heap.clear();
                    }
                } else { // normal cover
                    string currCard = dealer[0];
                    dealer.erase(dealer.begin());
                    heap.push_back(currCard);
                }
            }
            // cout << "dealer size: " << dealer.size() << " | nondealer size: " << nondealer.size() << endl;
            // switch turns
            turn = !turn;
            // check winner
            if ((turn && nondealer.size() == 0) || (!turn && dealer.size() == 0)) {
                break;
            }
        }
        end:;
        // dealer wins
        if (nondealer.size() > dealer.size()) {
            printf("%d%3d\n", 2, nondealer.size());
        } else {
            // for (int i = 0; i < dealer.size(); ++i) {
            //     cout << dealer[i] << " ";
            // }
            // cout << endl;
            printf("%d%3d\n", 1, dealer.size());
        }
    }
    return 0;
}
