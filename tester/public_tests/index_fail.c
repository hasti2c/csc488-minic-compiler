// Semantic failure 2

int i, j;
int x[10];

int main() {
    i[0] = 0;
    x[0] = 1;
    j = x[0];
    if (j == 1) {
        x[1] = 2;
        break;
    }
    else {
        x[1] = -1;
    }
}