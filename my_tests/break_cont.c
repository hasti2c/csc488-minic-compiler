int main() {
    break; // error: break must appear in for loop
    for (;;)
        break;
    for (;;) {
        break;
    }

    continue; // error: continue must appear in for loop
    for (;;)
        continue;
    for (;;) {
        continue;
    }
    return 0;
}