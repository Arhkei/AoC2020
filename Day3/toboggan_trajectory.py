with open("input.txt", "r") as f:
    treeMap = list(map(str.strip, f.readlines()))


def calc_trees(x, y):
    position = 0
    treesHit = 0

    for i in treeMap[::y]:
        if i[position] == "#":
            treesHit += 1
        position = (position+x) % len(i)

    return treesHit


def part_one():
    answer = calc_trees(3, 1)
    print(f"Part 1: {answer}")


def part_two():
    slope1 = calc_trees(1, 1)
    slope2 = calc_trees(3, 1)
    slope3 = calc_trees(5, 1)
    slope4 = calc_trees(7, 1)
    slope5 = calc_trees(1, 2)
    answer = slope1*slope2*slope3*slope4*slope5
    print(f"Part 2: {answer}")

part_one()
part_two()
