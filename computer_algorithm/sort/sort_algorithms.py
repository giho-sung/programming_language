def bubble_sort(array):
    l = len(array)
    for i in range(l - 1):
        for j in range(0, l - i - 1):
            if array[j] > array[j + 1]:
                array[j], array[j + 1] = array[j + 1], array[j]


def selection_sort(array):
    l = len(array)
    for i in range(l):
        min_idx = i
        for j in range(i, l):
            if array[min_idx] > array[j]:
                min_idx = j

        if min_idx != i:
            array[i], array[min_idx] = array[min_idx], array[i]


def insertion_sort(array):
    for i in range(len(array)):
        for j in range(i, 0, -1):
            if array[j] < array[j - 1]:
                array[j - 1], array[j] = array[j], array[j - 1]
            else:
                break


def quick_sort(array):
    # in-place and stable quick sort
    _quick_sort(array, 0, len(array) - 1)


def _quick_sort(array, start_idx, end_idx):
    if start_idx >= end_idx:
        return

    # let the end element is pivot
    pivot = array[end_idx]
    lower_idx = start_idx
    for idx in range(start_idx, end_idx):
        if array[idx] < pivot:
            array[idx], array[lower_idx] = array[lower_idx], array[idx]
            lower_idx += 1
    if array[lower_idx] > pivot:
        array[lower_idx], array[end_idx] = array[end_idx], array[lower_idx]
    # left
    _quick_sort(array, start_idx, lower_idx - 1)
    # right
    _quick_sort(array, lower_idx + 1, end_idx)


def count_sort(array):
    count = [0] * (max(array) + 1)

    for val in array:
        count[val] += 1

    array.clear()
    for idx in range(len(count)):
        if count[idx] != 0:
            array.extend([idx] * count[idx])


def heap_sort(arr):
    n = len(arr)
    # Build a maxheap.
    # Since last parent will be at ((n//2)-1) we can start at that location.
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

    # One by one extract elements
    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]  # swap
        heapify(arr, i, 0)


def heapify(arr, n, i):
    largest = i  # Initialize largest as root
    l = 2 * i + 1  # left = 2*i + 1
    r = 2 * i + 2  # right = 2*i + 2

    # See if left child of root exists and is
    # greater than root
    if l < n and arr[i] < arr[l]:
        largest = l
    # See if right child of root exists and is
    # greater than root
    if r < n and arr[largest] < arr[r]:
        largest = r

    # Change root, if needed
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]  # swap

        # Heapify the root.
        heapify(arr, n, largest)
