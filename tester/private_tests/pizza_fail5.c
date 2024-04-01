// Semantic failure 4

int pepperoni;
int toppings[10];
bool hasTopping;


int main() {
    pepperoni = 3;
    hasTopping = false;

    toppings[hasTopping];
    return 1;
}