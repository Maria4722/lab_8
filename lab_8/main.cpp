#include <iostream>
#include <vector>
#include <numeric>   // Потрібен для std::accumulate
#include <algorithm> // Потрібен для std::find_if

// Допоміжна функція для красивого виводу матриці в консоль
void print_matrix(const std::vector<std::vector<int>>& matrix, const std::string& title)
{
    std::cout << title << std::endl;
    for (const auto& row : matrix)
    {
        for (const int& element : row)
        {
            // Використовуємо 4 символи для кожного числа для кращого форматування
            std::cout.width(4);
            std::cout << element;
        }
        std::cout << std::endl;
    }
}

// Головна функція, що реалізує логіку завдання з використанням STL
int calculate_sum_between_positives(const std::vector<std::vector<int>>& matrix)
{
    // 1. "Вирівнюємо" матрицю в один одновимірний вектор для зручної роботи з алгоритмами
    std::vector<int> flat_vector;
    for (const auto& row : matrix)
    {
        flat_vector.insert(flat_vector.end(), row.begin(), row.end());
    }

    auto is_positive = [](int n) { return n > 0; };

    auto first_positive_it = std::find_if(flat_vector.begin(), flat_vector.end(), is_positive);

    if (first_positive_it == flat_vector.end())
    {
        std::cout << "У масиві немає жодного додатного елемента." << std::endl;
        return 0;
    }

    auto second_positive_it = std::find_if(first_positive_it + 1, flat_vector.end(), is_positive);

    if (second_positive_it == flat_vector.end())
    {
        std::cout << "У масиві є лише один додатний елемент." << std::endl;
        return 0;
    }

    std::cout << "Перший додатний елемент: " << *first_positive_it << std::endl;
    std::cout << "Другий додатний елемент: " << *second_positive_it << std::endl;

    if (first_positive_it + 1 == second_positive_it)
    {
        std::cout << "Між першим та другим додатними елементами немає інших елементів." << std::endl;
        return 0;
    }

    int sum = std::accumulate(first_positive_it + 1, second_positive_it, 0);

    return sum;
}


int main()
{
    setlocale(LC_ALL, "Ukrainian");

    std::vector<std::vector<int>> matrix1 = {
        { -1, -5,  2, -3,  0 }, 
        { -8, -2, -7, 10, -4 }, 
        {  0,  6, -9, -1, 12 }
    };

    std::cout << "========== Перша матриця ==========\n";
    print_matrix(matrix1, "Вхідна матриця:");
    int sum1 = calculate_sum_between_positives(matrix1);
    std::cout << "Сума елементів між першим і другим додатними = " << sum1 << std::endl;

    std::cout << "\n============================================\n\n";

    std::vector<std::vector<int>> matrix2 = {
        { -1, -2, -3 },
        { -4,  5, -6 }, 
        { -7, -8, -9 }
    };

    std::cout << "========== Друга матриця  ==========\n";
    print_matrix(matrix2, "Вхідна матриця:");
    int sum2 = calculate_sum_between_positives(matrix2);
    std::cout << "Сума елементів між першим і другим додатними = " << sum2 << std::endl;

    return 0;
}