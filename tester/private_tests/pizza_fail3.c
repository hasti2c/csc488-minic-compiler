// Semantic failure 4

int i, j;
int toppings[10];
bool hasTopping;
bool testTopping;

bool checkTop(int x) {
    if (x == 1)
        return true;
    return false;
}

int whichTop(bool x) {
    if (x || (x && true) || !x) 
        return 1;
    return 0;
}

int main() {
    i = 0;
    hasTopping = false;
    testTopping = hasTopping;

    if (hasTopping == true) {
        return 1;
    }
    if (i > 0) {
        return checkTop(i);
    }

    return 0;
}