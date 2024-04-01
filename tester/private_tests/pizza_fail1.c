// Semantic failure 4

int i, j;
int toppings[10];
bool hasTopping;

bool checkTop(int x) {
    if (x == 1)
        return true;
    return false;
}

bool whichTop(bool x) {
    if (x == false) 
        return true;
    return false;
}

int main() {
    i = 0;
    hasTopping = false;

    if (!hasTopping) {
        return -1;
    }
    if (i > 0) {
        return true;
    }

    whichTop(hasTopping);
    return 0;
}