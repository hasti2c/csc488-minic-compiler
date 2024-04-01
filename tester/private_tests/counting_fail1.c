// Semantic fail 5

int i;
int a[10];
bool x[10];

void dummy(int j) {
    return;
}

void main() {
    for (; 1+1; ) {
        if (true) 
            break;
    }

    x[0] = true;
    for (i = 1; i < 10; i = i + 1) {
        x[i] = x[0];
    }

    for (i = 0; i < 10; i = i + 1) {
        a[i] = i;
    }

    dummy(i);

    return;
}