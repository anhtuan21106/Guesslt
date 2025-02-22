#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
using namespace std;

int ranDom(int a, int b)
{
    return a + rand() % (b - a + 1);
}
void guess()
{
    int x, a, b, n, F = 0;
    cout << "VUI LÒNG NHẬP KHOẢNG CẦN ĐOÁN: ";
    cin >> a >> b;
    n = ranDom(a, b);
    do
    {
        cout << "Vui lòng nhập số bạn đoán: ";
        cin >> x;
        if (x > n)
        {
            cout << "Số " << x << " lớn hơn số cần đoán" << endl;
            F++;
        }
        else if (x < n)
        {
            cout << "Số " << x << " nhỏ hơn số cần đoán" << endl;
            F++;
        }
        else
        {
            cout << "Bạn đã đoán đúng số " << x << " sau " << F << " lần!" << endl;
        }
    } while (x != n);
}

void AI()
{
    int a, x, b, n, F = 0;
    cout << "VUI LÒNG NHẬP KHOẢNG CẦN ĐOÁN: ";
    cin >> a >> b;
    cout << "NHẬP SỐ CẦN ĐOÁN: ";
    cin >> n;
    do
    {
        x = (a + b) / 2;
        cout << "Máy đoán: " << x << endl;
        F++;

        if (x > n)
        {
            cout << "Số " << x << " lớn hơn số cần đoán" << endl;
            b = x - 1;
        }
        else if (x < n)
        {
            cout << "Số " << x << " nhỏ hơn số cần đoán" << endl;
            a = x + 1;
        }
        else
        {
            cout << "Máy đã đoán đúng số " << x << " sau " << F << " lần!" << endl;
        }
    } while (x != n);
}

void VsAi()
{
    int a, b, n;
    cout << "VUI LÒNG NHẬP KHOẢNG CẦN ĐOÁN: ";
    cin >> a >> b;
    n = ranDom(a, b);
    int x, y;
    int F1 = 0, F2 = 0;
    int a1 = a, a2 = b;
    while (true)
    {
        cout << "Vui lòng nhập số bạn đoán: ";
        cin >> x;
        F1++;

        if (x > n)
        {
            cout << "Số " << x << " lớn hơn số cần đoán" << endl;
            if (x < a2)
                a2 = x - 1;
        }
        else if (x < n)
        {
            cout << "Số " << x << " nhỏ hơn số cần đoán" << endl;
            if (x > a1)
                a1 = x + 1;
        }
        else
        {
            cout << "Bạn đã đoán đúng số " << x << " sau " << F1 << " lần!" << endl;
            cout << "Người chơi THẮNG!" << endl;
            return;
        }
        y = (a1 + a2) / 2;
        cout << "Máy đoán: " << y << endl;
        F2++;
        if (y > n)
        {
            cout << "Máy đoán lớn hơn số cần tìm." << endl;
            a2 = y - 1;
        }
        else if (y < n)
        {
            cout << "Máy đoán nhỏ hơn số cần tìm." << endl;
            a1 = y + 1;
        }
        else
        {
            cout << "Máy đã đoán đúng số " << y << " sau " << F2 << " lần!" << endl;
            cout << "Máy THẮNG!" << endl;
            return;
        }
    }
}
bool playAgain()
{
    while (true)
    {
        char c;
        cout << "Bạn có muốn chơi tiếp không? (Y/N): ";
        cin >> c;
        c = tolower(c);
        if (c == 'y')
            return true;
        if (c == 'n')
            return false;

        cout << "Vui lòng nhập Y hoặc N." << endl;
    }
}
void Game()
{
    bool run = true;
    while (run)
    {

        int choice, a, b, n;
        cout << "1. BẠN ĐOÁN" << endl
             << "2. MÁY ĐOÁN" << endl
             << "3. CHƠI VỚI MÁY" << endl
             << "4. THOÁT" << endl;
        cout << "VUI LÒNG CHỌN CHẾ ĐỘ: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            guess();
            run = playAgain();
            break;
        case 2:
            AI();
            run = playAgain();
            break;
        case 3:
            VsAi();
            run = playAgain();
            break;
        default:
            run = false;
            break;
        }
    }
}
int main()
{
    srand(time(0));
    Game();
    return 0;
}
