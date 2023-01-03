def main():
    n, m = list(map(int, input().split()))
    array = list(map(int, input().split()))

    curr_sum = 0
    max_sum = 0

    left_pointer = 0
    right_pointer = 0

    while left_pointer < n:
        if curr_sum < m:
            if right_pointer == n:
                break
            curr_sum += array[right_pointer]
            right_pointer += 1
        else:
            curr_sum -= array[left_pointer]
            left_pointer += 1

        if max_sum < curr_sum <= m:
            max_sum = curr_sum

    print(max_sum)


main()
