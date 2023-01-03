#include <iostream>
#include <vector>
#include <algorithm>
#include <cstddef>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<std::pair<int, int> > cards;
    for (int i = 0; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        cards.emplace_back(a, b);
    }

    std::sort(cards.begin(), cards.end());

    std::vector<int> second_nums;
    for (int i = 0; i < n; i++) {
        second_nums.push_back(cards[i].second);
    }

    size_t inversion_count = 0;

    std::function<void(int *, int, int)> merge_sort = [&](int *array, int left, int right) {
        if (left >= right) {
            return;
        }

        int middle = (left + right) / 2;

        merge_sort(array, left, middle);
        merge_sort(array, middle + 1, right);

        int i = left;
        int j = middle + 1;
        int k = 0;
        int temp[right - left + 1];

        while (i <= middle && j <= right) {
            if (array[i] <= array[j]) {
                temp[k++] = array[i++];
            } else {
                temp[k++] = array[j++];
                inversion_count += middle - i + 1;
            }
        }

        while (i <= middle) {
            temp[k++] = array[i++];
        }

        while (j <= right) {
            temp[k++] = array[j++];
        }

        for (i = left, k = 0; i <= right; i++, k++) {
            array[i] = temp[k];
        }
    };


    merge_sort(&second_nums[0], 0, second_nums.size() - 1);
    std::cout << inversion_count << std::endl;
}
