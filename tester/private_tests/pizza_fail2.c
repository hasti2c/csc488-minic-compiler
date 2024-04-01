// Semantic failure 4

int i, j;
int toppings[10];
bool hasTopping;

bool checkTop(int x) {
    if (x >= 1)
        return true;
    return false;
}

int whichTop(bool x) {
    if (x || !true) 
        return 1;
    return 0;
}

int main() {
    i = 0;
    hasTopping = false;

    if (hasTopping == false) {
        return 1;
    }
    if (i > 0) {
        return -1;
    }

    whichTop(hasTopping);
    checkTop(i);

    i = 52356146424;

    return false;
}
