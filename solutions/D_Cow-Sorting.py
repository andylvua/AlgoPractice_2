def main():
    n = int(input())
    array = [int(input()) for _ in range(n)]

    indexes = sorted([*enumerate(array)], key=lambda x: x[1])
    seen = set()

    min_element = indexes[0][1]
    sum_of_swapped_elements = 0

    for index, element in indexes:
        if index in seen:
            continue

        cycle_minimum = element
        cycle_size, cycle_sum = 0, 0

        while index not in seen:
            seen.add(index)
            cycle_size += 1
            cycle_sum += element
            index, element = indexes[index]
            cycle_minimum = min(cycle_minimum, element)

        sum_of_swapped_elements += min(
            cycle_sum + (cycle_size - 2) * cycle_minimum,
            cycle_sum + cycle_minimum + (cycle_size + 1) * min_element
        )

    print(sum_of_swapped_elements)


main()
