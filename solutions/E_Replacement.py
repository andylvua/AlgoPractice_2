def main():
    # Ignore first line
    input()
    array = list(map(int, input().split()))

    stack = [array[-1]]

    for i, element in enumerate(reversed(array)):
        previous = stack[-1]
        while stack and element >= previous:
            stack.pop()
            if stack:
                previous = stack[-1]

        array[-i - 1] = previous if stack else 0
        stack.append(element)

    array[-1] = 0
    print(*array)


main()
