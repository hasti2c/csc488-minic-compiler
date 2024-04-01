// Semantic failure 1

int x, y, z;
bool z;

bool main() {
    x = 10;
    y = -10;
    z = true;
    10 + 4;
    true + false;
    
    if (x || y)
        return x;
    return true;
}