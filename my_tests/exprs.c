int main() {
    int n, a[5];
    bool b, c[5];

    if (true) {}
    if (1) {} // error: non-bool type

    for (;;) {}
    for (; true;) {}
    for (; 1;) {} // error: non-bool type

    n = -3;
    b = -true; // error: non-int operand
    a = -a; // error: non-primitive operand

    b = !true;
    n = !3; // error: non-bool operand
    c = !c; // error: non-primitive operand

    b = true && false;
    b = true && 2; // error: non-bool operand
    n = 2 && true; // error: non-bool operand
    n = 2 && 3; // error: non-bool operand
    c = c && true; // error: non-primitive operand

    b = true || false;
    b = true || 2; // error: non-bool operand
    n = 2 || true; // error: non-bool operand
    n = 2 || 3; // error: non-bool operand
    c = c || true; // error: non-primitive operand

    b = 2 == 3;
    b = true == false;
    b = true == 3; // error: comparison of different types
    b = 2 == true; // error: comparison of different types
    b = a == a; // error: comparison of non-primitive types
    b = c == c; // error: comparison of non-primitive types
    b = a == c; // error: comparison of non-primitive types
    b = a == 3; // error: comparison of non-primitive types

    b = 2 != 3;
    b = true != false;
    b = true != 3; // error: comparison of different types
    b = 2 != true; // error: comparison of different types
    b = a != a; // error: comparison of non-primitive types
    b = c != c; // error: comparison of non-primitive types
    b = a != c; // error: comparison of non-primitive types
    b = a != 3; // error: comparison of non-primitive types

    b = 2 < 3;
    b = true < false; // error: non-int operand
    b = true < 3; // error: non-int operand
    b = 2 < true; // error: non-int operand
    b = a < a; // error: comparison of non-primitive types
    b = c < c; // error: comparison of non-primitive types
    b = a < c; // error: comparison of non-primitive types
    b = a < 3; // error: comparison of non-primitive types

    b = 2 > 3;
    b = true > false; // error: non-int operand
    b = true > 3; // error: non-int operand
    b = 2 > true; // error: non-int operand
    b = a > a; // error: comparison of non-primitive types
    b = c > c; // error: comparison of non-primitive types
    b = a > c; // error: comparison of non-primitive types
    b = a > 3; // error: comparison of non-primitive types

    b = 2 <= 3;
    b = true <= false; // error: non-int operand
    b = true <= 3; // error: non-int operand
    b = 2 <= true; // error: non-int operand
    b = a <= a; // error: comparison of non-primitive types
    b = c <= c; // error: comparison of non-primitive types
    b = a <= c; // error: comparison of non-primitive types
    b = a <= 3; // error: comparison of non-primitive types

    b = 2 >= 3;
    b = true >= false; // error: non-int operand
    b = true >= 3; // error: non-int operand
    b = 2 >= true; // error: non-int operand
    b = a >= a; // error: comparison of non-primitive types
    b = c >= c; // error: comparison of non-primitive types
    b = a >= c; // error: comparison of non-primitive types
    b = a >= 3; // error: comparison of non-primitive types

    n = 2 + 3;
    b = true + false; // error: non-int operand
    b = true + 3; // error: non-int operand
    n = 2 + true; // error: non-int operand
    a = a + a; // error: non-primitive operand

    n = 2 - 3;
    b = true - false; // error: non-int operand
    b = true - 3; // error: non-int operand
    n = 2 - true; // error: non-int operand
    a = a - a; // error: non-primitive operand

    n = 2 * 3;
    b = true * false; // error: non-int operand
    b = true * 3; // error: non-int operand
    n = 2 * true; // error: non-int operand
    a = a * a; // error: non-primitive operand

    n = 2 / 3;
    b = true / false; // error: non-int operand
    b = true / 3; // error: non-int operand
    n = 2 / true; // error: non-int operand
    a = a / a; // error: non-primitive operand

    return 0;
}