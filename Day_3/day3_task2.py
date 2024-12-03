import re

def read_data_line_by_line(file_name, array):
    with open(file_name, 'r') as file:
        lines = file.readlines()
        for line in lines:
            array.append(line.strip())


def extract_mul_objects(s):
    pattern = r'mul\(\d{1,3},\d{1,3}\)'
    return re.findall(pattern, s)


def remove_dont_do_sections(s):
    s = re.sub(r"don't\(\).*?do\(\)", '', s)
    s = re.sub(r"don't\(\).*", '', s) ## Remove don't() at the end of the string
    return s


def mult_add_values(mul_objects):
    sum = 0
    for obj in mul_objects:
        numbers = re.findall(r'\d+', obj)
        if len(numbers) == 2:
            num1, num2 = map(int, numbers)
            sum += num1 * num2
    return sum


def main():
    array = []
    read_data_line_by_line("day_3.txt", array)
    result = ''.join(array)
    cleaned_result = remove_dont_do_sections(result)
    mul_objects = extract_mul_objects(cleaned_result)
    total_result = mult_add_values(mul_objects)

    print("Sum of Multiplied Results:", total_result)

if __name__ == "__main__":
    main()
