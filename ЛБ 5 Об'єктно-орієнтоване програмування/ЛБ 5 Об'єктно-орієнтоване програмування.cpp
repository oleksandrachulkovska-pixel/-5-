#include <iostream>
#include <clocale>
#include <iomanip>
#include "Angle.h"

using namespace std;

void PrintAngle(const char* name, const Angle& angle)
{
    cout << name << ": "
        << angle.GetDegrees() << " град. "
        << angle.GetMinutes() << " хв."
        << endl;
}

int main()
{
    setlocale(LC_ALL, "");

    Angle angle1(45, 30);
    Angle angle2(90, 15);

    cout << "Початкові значення кутів:" << endl;

    PrintAngle("Перший кут", angle1);
    PrintAngle("Другий кут", angle2);

    cout << endl;
    cout << fixed << setprecision(6);

    cout << "Перший кут у радіанах: "
        << angle1.ToRadians() << endl;

    cout << "Синус першого кута: "
        << angle1.Sin() << endl;

    cout << endl;

    Angle sum = angle1.Add(angle2);
    PrintAngle("Сума кутів", sum);

    Angle difference = angle2.Subtract(angle1);
    PrintAngle("Різниця кутів", difference);

    cout << endl;

    if (angle1.IsEqual(angle2))
        cout << "Кути рівні." << endl;
    else
        cout << "Кути не рівні." << endl;

    cout << endl;

    Angle angle3;
    PrintAngle("Кут за замовчуванням", angle3);

    Angle angle4(120);
    PrintAngle("Кут з одним параметром", angle4);

    Angle angle5(370, 90);
    PrintAngle("Нормалізований кут", angle5);

    return 0;
}