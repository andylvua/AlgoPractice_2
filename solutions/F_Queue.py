import queue


def main():
    n, k = list(map(int, input().split()))
    array = list(map(int, input().split()))
    q = queue.PriorityQueue()

    for i in range(n):
        time = array[i]
        if q.qsize() != k:
            q.put(time)
        else:
            q.put(time + q.get())

    print(max(q.queue))


main()
