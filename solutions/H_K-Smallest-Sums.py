import queue


def main():
    while True:
        try:
            k = int(input())
        except EOFError:
            return

        arrays = [list(map(int, input().split())) for _ in range(k)]
        [array.sort() for array in arrays]

        for array in arrays[1:]:
            q = queue.PriorityQueue()
            [q.put((arrays[0][i] + array[0], 0)) for i in range(k)]

            for i in range(k):
                total, index = q.get()
                arrays[0][i] = total

                if index == k - 1:
                    continue

                q.put((total - array[index] + array[index + 1], index + 1))

        print(*arrays[0])


main()
