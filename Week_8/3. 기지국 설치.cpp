#include <iostream>
#include <vector>

int solution(int size, std::vector<int> stations, int range)
{
    auto count = 0;
    auto current_station_idx = 0;   // ���� �������� �ε���
    auto current_location = 1;      // ���� ��ġ

    while (current_location <= size)
    {
        // ���� �������� ���� �ܺο� �ִٸ� 
        if (current_station_idx < stations.size() and current_location >= stations[current_station_idx] - range)
        {
            // ���� �����̼��� ���� �ܺη� �̵��Ѵ�.
            current_location = stations[current_station_idx] + range + 1;
            current_station_idx++;
        }
        // ���� �������� ���� ���ο� �ִٸ�
        else
        {
            // ���� ��ġ�� �������� ��� ���� �ܺη� �̵��Ѵ�.
            current_location += 2 * range + 1;
            count++;
        }
    }

    return count;
}