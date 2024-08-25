#include <string>
#include <vector>
#include <queue>

using LL = long long;

int solution(std::vector<int> queue1, std::vector<int> queue2)
{
    auto que1 = std::queue<int>();
    auto que2 = std::queue<int>();
    auto que1_sum = LL(0);      // ť1 ������ ��
    auto que2_sum = LL(0);      // ť2 ������ ��

    // ������ ��ҵ��� ť�� �ű�� �����̴�.
    for (auto i = 0; i < queue1.size(); i++)
    {
        que1.push(queue1[i]);
        que1_sum += queue1[i];
        
        que2.push(queue2[i]);
        que2_sum += queue2[i];
    }

    // ������ ť�� �����·� ���͵� ������ ���� ��ġ�ϴ� ������ ���ٸ� ���� ����.
    for (auto answer = 0; answer < 4 * queue1.size() + 1; answer++)
    {
        if (que1_sum == que2_sum)
            return answer;

        // ť1�� ���� ť2�� �պ��� ũ�ٸ�
        if (que1_sum > que2_sum)
        {
            // ť1�� ���Ҹ� ť2�� �ű��.
            que1_sum -= que1.front();
            que2_sum += que1.front();
            que2.push(que1.front());
            que1.pop();
        }

        // ť2�� ���� ť1�� �պ��� ũ�ٸ�
        else if (que1_sum < que2_sum)
        {
            // ť2�� ���Ҹ� ť1���� �ű��.
            que1_sum += que2.front();
            que2_sum -= que2.front();
            que1.push(que2.front());
            que2.pop();
        }
    }

    return -1;
}