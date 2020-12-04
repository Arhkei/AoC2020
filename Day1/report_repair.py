with open("input.txt", "r") as f:
    reportNumbers = list(map(int, f.readlines()))


def part_one():
    for pos, num in enumerate(reportNumbers):
        for num2 in reportNumbers[pos+1:]:
            if num + num2 == 2020:
                print(f"Part 1: {num * num2}")


def part_two():
    for pos, num in enumerate(reportNumbers):
        for pos2, num2 in enumerate(reportNumbers[pos+1:]):
            for num3 in reportNumbers[pos+pos2+1:]:
                if num + num2 + num3 == 2020:
                    print(f"Part 2: {num * num2 * num3}")

part_one()
part_two()
