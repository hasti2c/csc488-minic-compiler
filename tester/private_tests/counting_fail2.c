// Semantic fail 5

int i;
int a[10];
bool x[10];

void dummy(int j) {
    return;
}

void main() {

    x[0] = true;
    for (i = 1; i < 10; i = i + 1) {
        x[i] = x[0];
    }

    dumy();
    dummy(i);

    return;
}

void main() {
    0;
}