#include <iostream>
#include <vector>

using namespace std;

struct Page {
    int number;
    bool reference;
};

bool checkHit(int incomingPage, const vector<Page>& frames) {
    for (const auto& frame : frames) {
        if (incomingPage == frame.number)
            return true;
    }
    return false;
}

void printFrame(const vector<Page>& frames) {
    for (const auto& frame : frames) {
        cout << frame.number << "\t";
    }
    cout << "\n";
}

int main() {
    vector<int> seq = {1, 2, 3, 3, 1, 5, 2, 1, 6, 2, 5, 6, 3, 1, 3};
    int n = seq.size();
    int framesCount = 3;
    vector<Page> frames;
    int pagefaults = 0;
    int pointer = 0;

    cout << "Page\tFrame1\tFrame2\tFrame3\n";

    for (int i = 0; i < n; i++) {
        cout << seq[i] << ":\t";

        if (checkHit(seq[i], frames)) {
            for (auto& frame : frames) {
                if (frame.number == seq[i]) {
                    frame.reference = true;
                    break;
                }
            }
            printFrame(frames);
            continue;
        }

        if (frames.size() < framesCount) {
            frames.push_back({seq[i], true});
            pagefaults++;
            printFrame(frames);
        } else {
            while (true) {
                if (!frames[pointer].reference) {
                    frames[pointer] = {seq[i], true};
                    pagefaults++;
                    pointer = (pointer + 1) % framesCount;
                    break;
                } else {
                    frames[pointer].reference = false;
                    pointer = (pointer + 1) % framesCount;
                }
            }
            printFrame(frames);
        }
    }

    cout << "Page Faults: " << pagefaults << endl;

    return 0;
}
