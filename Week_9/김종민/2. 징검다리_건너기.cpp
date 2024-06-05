// ���� 1: ���Ʈ����: 200_000 * 200_000_000 = �� 40�� ������ �ð� �ʰ�
// ���� 2: 
// - �̰� ������ for������ ���� �ٿ����鼭 �� �ʿ䰡 �ֳ�?
// - �ᱹ�� k ������ŭ 0�� ������ �׶������� ����� �� �ƴѰ�?
// - ������ ���ؿ��� Ǯ���� �ִ�� �볪�� �ڸ��� ������ �Ȱ��� > ���� Ž��
// https://www.acmicpc.net/problem/2805

#include <string>
#include <vector>
#include <algorithm>

using LL = long long;

// �ǳ� �� �ִ��� �������� �Ǵ��ϴ� �Լ�
bool CanCross(const std::vector<int>& stones, int k, int people)
{
    int skips = 0;
    for (const auto& stone : stones)
    {
        if (stone < people)
        {
            skips++;
            if (skips >= k)
                return false;
        }
        else
            skips = 0;
    }

    return true;
}

int solution(std::vector<int> stones, int k) 
{
    auto answer = LL(0);

    auto start = *std::min_element(stones.begin(), stones.end());   // �ּ� ���ڰ� ���� ¡�˴ٸ�
    auto end = *std::max_element(stones.begin(), stones.end());     // �ִ� ���ڰ� ���� ¡�˴ٸ�
    
    // ���� Ž���� ���� k��ŭ�� ���̸� ���� ������ ã�´�.
    while (start <= end)
    {
        auto mid = (start + end) / 2;
        if (CanCross(stones, k, mid))
            start = mid + 1;
        else
            end = mid - 1;
    }

    return end;
}