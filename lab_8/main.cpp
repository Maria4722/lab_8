#include <iostream>
#include <vector>
#include <numeric>   // ������� ��� std::accumulate
#include <algorithm> // ������� ��� std::find_if

// �������� ������� ��� ��������� ������ ������� � �������
void print_matrix(const std::vector<std::vector<int>>& matrix, const std::string& title)
{
    std::cout << title << std::endl;
    for (const auto& row : matrix)
    {
        for (const int& element : row)
        {
            // ������������� 4 ������� ��� ������� ����� ��� ������� ������������
            std::cout.width(4);
            std::cout << element;
        }
        std::cout << std::endl;
    }
}

// ������� �������, �� ������ ����� �������� � ������������� STL
int calculate_sum_between_positives(const std::vector<std::vector<int>>& matrix)
{
    // 1. "���������" ������� � ���� ����������� ������ ��� ������ ������ � �����������
    std::vector<int> flat_vector;
    for (const auto& row : matrix)
    {
        flat_vector.insert(flat_vector.end(), row.begin(), row.end());
    }

    auto is_positive = [](int n) { return n > 0; };

    auto first_positive_it = std::find_if(flat_vector.begin(), flat_vector.end(), is_positive);

    if (first_positive_it == flat_vector.end())
    {
        std::cout << "� ����� ���� ������� ��������� ��������." << std::endl;
        return 0;
    }

    auto second_positive_it = std::find_if(first_positive_it + 1, flat_vector.end(), is_positive);

    if (second_positive_it == flat_vector.end())
    {
        std::cout << "� ����� � ���� ���� �������� �������." << std::endl;
        return 0;
    }

    std::cout << "������ �������� �������: " << *first_positive_it << std::endl;
    std::cout << "������ �������� �������: " << *second_positive_it << std::endl;

    if (first_positive_it + 1 == second_positive_it)
    {
        std::cout << "̳� ������ �� ������ ��������� ���������� ���� ����� ��������." << std::endl;
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

    std::cout << "========== ����� ������� ==========\n";
    print_matrix(matrix1, "������ �������:");
    int sum1 = calculate_sum_between_positives(matrix1);
    std::cout << "���� �������� �� ������ � ������ ��������� = " << sum1 << std::endl;

    std::cout << "\n============================================\n\n";

    std::vector<std::vector<int>> matrix2 = {
        { -1, -2, -3 },
        { -4,  5, -6 }, 
        { -7, -8, -9 }
    };

    std::cout << "========== ����� �������  ==========\n";
    print_matrix(matrix2, "������ �������:");
    int sum2 = calculate_sum_between_positives(matrix2);
    std::cout << "���� �������� �� ������ � ������ ��������� = " << sum2 << std::endl;

    return 0;
}