import re

def read_data_line_by_line(file_name, array):
    with open(file_name, 'r') as file:
        lines = file.readlines()
        for line in lines:
            array.append(line)


def extract_mul_objects(s):
    pattern = r'mul\(\d{1,3},\d{1,3}\)'
    return re.findall(pattern, s)


def multiply_values(mul_objects):
    results = []
    for obj in mul_objects:
        numbers = re.findall(r'\d+', obj)
        if len(numbers) == 2:
            num1, num2 = map(int, numbers)
            results.append(num1 * num2)
    return results


def main():
    array = []
    read_data_line_by_line("day_3.txt", array)
    result = ''.join(array)
    mul_objects = extract_mul_objects(result)
    multiplied_results = multiply_values(mul_objects)
    total_result = sum(multiplied_results)
    print(total_result)

if __name__ == "__main__":
    main()
