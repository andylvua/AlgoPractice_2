def main():
    n, k = list(map(int, input().split()))
    array = list(map(int, input().split()))

    queries = [tuple(map(int, input().split())) for _ in range(k)]

    hash_table = {}

    for i, element in enumerate(array):
        if element in hash_table:
            hash_table[element].append(i)
        else:
            hash_table[element] = [i]

    for query in queries:
        if len(hash_table.get(query[0], [])) >= query[1] > 0:
            print(hash_table[query[0]][query[1] - 1] + 1)
        else:
            print(-1)


main()
