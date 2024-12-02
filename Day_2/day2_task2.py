def read_data_line_by_line(file_name, array):
    with open(file_name, 'r') as file:
        lines = file.readlines()
        for line in lines:
            array.append([int(x) for x in line.split()])

def subarrays_missing_one_element(array):
    for i in range(len(array)):
        yield array[:i] + array[i+1:]

def is_increasing(array):
    for i in range(len(array) - 1):
        if array[i] >= array[i + 1] or abs(array[i] - array[i + 1]) > 3:
            return False
    return True

def is_decreasing(array):
    for i in range(len(array) - 1):
        if array[i] <= array[i + 1] or abs(array[i] - array[i + 1]) > 3:
            return False
    return True

def main():
    array = []
    read_data_line_by_line("day_2.txt", array)

    safe_counter = 0

    for elem in array:
        stop = False
        for subarray in subarrays_missing_one_element(elem):
            print(subarray)
            if (is_increasing(subarray) or is_decreasing(subarray)) and not stop:
                safe_counter += 1
                print(f"{elem} Safe")
                stop = True
        if not stop:
            print(f"{elem} Unsafe")
    print(f"Total safe arrays: {safe_counter}")

if __name__ == "__main__":
    main()
