// Оленчук Є., ІК-12. ЛР 4.4, варіант 10. Функція за графіком.
#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    double R, xp, xk, dx;   // радіус дуги, межі табуляції, крок

    // Введення даних з перевіркою: за графіком 0 < R <= 4
    cout << "R, xp, xk, dx: ";
    if (!(cin >> R >> xp >> xk >> dx) || !isfinite(R)
        || !isfinite(xp) || !isfinite(xk) || !isfinite(dx)
        || R <= 0 || R > 4 || dx <= 0 || xp > xk
        || (xk-xp)/dx > 1000000) {
        cerr << "Require 0 < R <= 4 and valid grid\n";
        return 1;
    }

    // Кількість кроків (мала добавка компенсує похибку double)
    const int m = int(floor((xk-xp)/dx + 1e-10));

    cout << "TABLE graph y(x)\n" << setw(12) << "x"
         << setw(16) << "y" << '\n';
    cout << fixed << setprecision(6);

    for (int j = 0; j <= m; ++j) {
        const double x = xp + j*dx;   // через j, без накопичення похибки
        double y;

        if (x <= -8-R) y = R;                    // пряма y = R
        else if (x <= -8+R)                      // півколо, центр (-8; R)
            y = R - sqrt(max(0.0, R*R-(x+8)*(x+8)));
        else if (x <= -4) y = R;                 // пряма y = R
        else if (x <= 2) y = R-(R+1)*(x+4)/6;    // пряма (-4; R)-(2; -1)
        else y = x-3;                            // пряма (2; -1)-(3; 0)

        cout << setw(12) << x << setw(16) << y << '\n';
    }
}
