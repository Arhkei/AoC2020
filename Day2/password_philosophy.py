import re

with open("input.txt", "r") as f:
    passwords = f.readlines()


def part_one():
    validPasswords = []
    isValid = 0
    for password in passwords:
        positions = re.findall(r"(\d+)-(\d+)\s(\w):\s(\w+)", password)[0]
        min = int(positions[0])
        max = int(positions[1])
        char = positions[2]
        word = positions[3]
        if min <= word.count(char) <= max:
            isValid += 1
    print(f"Part 1: {isValid}")


def part_two():
    validPasswords = []
    isValid = 0
    for password in passwords:
        positions = re.findall(r"(\d+)-(\d+)\s(\w):\s(\w+)", password)[0]
        pos = int(positions[0]) - 1
        pos2 = int(positions[1]) - 1
        char = positions[2]
        word = positions[3]
        if (word[pos] == char) ^ (word[pos2] == char):
            isValid += 1
    print(f"Part 2: {isValid}")

part_one()
part_two()
