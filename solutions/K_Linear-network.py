def main():
    n, q = list(map(int, input().split()))
    groups = 1

    shut_down_computers = {0, n + 1}
    for _ in range(q):
        t, *args = list(map(int, input().split()))
        if t == 1:
            if args[0] not in shut_down_computers:
                shut_down_computers.add(args[0])
                if args[0] - 1 not in shut_down_computers and args[0] + 1 not in shut_down_computers:
                    groups += 1
                elif args[0] - 1 in shut_down_computers and args[0] + 1 in shut_down_computers:
                    groups -= 1
        else:
            print(groups)


main()
