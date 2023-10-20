// Task-5.3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>


class Figure {
protected:
    int sides_count;
    std::string name;
public:
    Figure() {
        sides_count = 0;
        name = "Фигура";
    }

    virtual bool check() {
        if (sides_count == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    virtual void print_info() {
        std::cout << name << ": \n";
        if (check() == true) {
            std::cout << "Правильная\n";
        }
        else {
            std::cout << "Неправильная\n";
        }
        std::cout << "Количество сторон: " << sides_count << "\n";
    }
};


class Triangle : public Figure {
protected:
    int a, b, c;
    int A, B, C;
public:
    Triangle() {
        sides_count = 3;
        name = "Треугольник";
        a = 0; b = 0; c = 0;
        A = 0; B = 0; C = 0;
    }
    Triangle(int a, int b, int c, int A, int B, int C) {
        this->a = a; this->b = b; this->c = c;
        this->A = A; this->B = B; this->C = C;
        sides_count = 3;
        name = "Треугольник";
    }

    bool check() override {
        if (A + B + C == 180 && sides_count == 3) {
            return true;
        }
        else {
            return false;
        }
    }

    void print_info() override {
        Figure::print_info();
        std::cout << "Стороны: a = " << a << " b = " << b << " c = " << c << '\n';
        std::cout << "Углы: A = " << A << " B = " << B << " C = " << C << '\n';
    }
};


class Quadrangl : public Figure {
protected:
    int a, b, c, d;
    int A, B, C, D;
public:
    Quadrangl() {
        sides_count = 4;
        name = "Четырёхугольник";
        a = 0; b = 0; c = 0; d = 0;
        A = 0; B = 0; C = 0; D = 0;
    }
    Quadrangl(int a, int b, int c, int d, int A, int B, int C, int D) {
        this->a = a; this->b = b; this->c = c; this->d = d;
        this->A = A; this->B = B; this->C = C; this->D = D;
        sides_count = 4;
        name = "Четырёхугольник";

    }
    bool check() override {
        if (A + B + C + D == 360 && sides_count == 4) {
            return true;
        }
        else {
            return false;
        }
    }

    void print_info() override {
        Figure::print_info();
        std::cout << "Стороны: a = " << a << " b = " << b << " c = " << c << " d = " << d << '\n';
        std::cout << "Углы: A = " << A << " B = " << B << " C = " << C << " D = " << D << '\n';
    }
};


class Right_triangle : public Triangle {
public:
    Right_triangle() {
        C = 90;
        name = "Прямоугольный треугольник";
    }
    Right_triangle(int a, int b, int c, int A, int B) {
        this->a = a; this->b = b; this->c = c;
        this->A = A; this->B = B;
        C = 90;
        name = "Прямоугольный треугольник";
    }

    bool check() override {
        if (A + B == 90 && Triangle::check() == true) {
            return true;
        }
        else {
            return false;
        }
    }
};


class Isosceles_triangle : public Triangle {
public:
    Isosceles_triangle() {
        name = "Равнобедренный треугольник";
    }
    Isosceles_triangle(int a, int b, int A, int B) {
        this->a = a; this->b = b;
        this->A = A; this->B = B;
        c = a;
        C = A;
        name = "Равнобедренный треугольник";
    }

    bool check() override {
        if (B == 180 - A - A && b + a + c == b + c + c && Triangle::check() == true) {
            return true;
        }
        else {
            return false;
        }
    }
};


class Equal_triangle : public Triangle {
public:
    Equal_triangle() {
        A = 60; B = A; C = A;
        name = "Равносторонний треугольник";
    }
    Equal_triangle(int b) {
        this->b = b;
        a = b; c = b;
        A = 60; B = A; C = A;
        name = "Равносторонний треугольник";
    }

    bool check() override {
        if (A == 60 && B == 60 && C == 60 && a == b && c == b && Triangle::check() == true) {
            return true;
        }
        else {
            return false;
        }
    }
};


class Restangle : public Quadrangl {
public:
    Restangle() {
        A = 90; B = A; C = A; D = A;
        name = "Прямоугольник";
    }
    Restangle(int a, int b) {
        this->a = a; this->b = b;
        c = a; d = b;
        A = 90; B = A; C = A; D = A;
        name = "Прямоугольник";
    }

    bool check() override {
        if (A == 90 && B == 90 && C == 90 && D == 90 && c == a && d == b && Quadrangl::check() == true) {
            return true;
        }
        else {
            return false;
        }
    }
};


class Square : public Restangle {
public:
    Square() {
        name = "Квадрат";
    }
    Square(int a) {
        this->a = a;
        c = a; d = a; b = a;
        name = "Квадрат";
    }

    bool check() override {
        if (A == 90 && B == 90 && C == 90 && D == 90 && c == a && d == a && b == a && Quadrangl::check() == true) {
            return true;
        }
        else {
            return false;
        }
    }
};

class Parallelogram : public Quadrangl {
public:
    Parallelogram() {
        name = "Параллелограм";
    }
    Parallelogram(int a, int b, int A, int B) {
        this->a = a; this->b = b;
        this->A = A; this->B = B;
        c = a; d = b;
        C = A; D = B;
        name = "Параллелограм";
    }

    bool check() override {
        if (C == A && D == B && c == a && d == b && Quadrangl::check() == true) {
            return true;
        }
        else {
            return false;
        }
    }
};


class Rhomb : public Parallelogram {
public:
    Rhomb() {
        name = "Ромб";
    }
    Rhomb(int a, int A, int B) {
        this->a = a;
        this->A = A; this->B = B;
        c = a; d = a; b = a;
        C = A; D = B;
        name = "Ромб";
    }

    bool check() override {
        if (C == A && D == B && c == a && d == a && b == a && Quadrangl::check() == true) {
            return true;
        }
        else {
            return false;
        }
    }
};

void print_info(Figure* figure) {
    figure->print_info();
}


int main() {

    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    Figure figure;
    print_info(&figure);
    std::cout << '\n';
    Triangle triangle{ 10, 20, 30, 50, 60, 70 };
    print_info(&triangle);
    std::cout << '\n';
    Right_triangle right_triangle{ 10, 20, 30, 40, 50 };
    print_info(&right_triangle);
    std::cout << '\n';
    Isosceles_triangle isosceles_triangle{ 10, 20, 50, 60 };
    print_info(&isosceles_triangle);
    std::cout << '\n';
    Equal_triangle equal_triangle{ 30 };
    print_info(&equal_triangle);
    std::cout << '\n';
    Quadrangl quadrangl{ 10, 20, 30, 40, 50, 60, 70, 80 };
    print_info(&quadrangl);
    std::cout << '\n';
    Restangle restangle{ 10,20 };
    print_info(&restangle);
    std::cout << '\n';
    Square square{ 20 };
    print_info(&square);
    std::cout << '\n';
    Parallelogram parallelogram{ 20,30,30,40 };
    print_info(&parallelogram);
    std::cout << '\n';
    Rhomb rhomb{ 30, 30, 40 };
    print_info(&rhomb);


    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
