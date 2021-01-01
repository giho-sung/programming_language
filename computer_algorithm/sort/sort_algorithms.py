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

from random import randint # to get random pivot in quick_sort

def quick_sort(array):
    # in-place quick sort
    # quick is not stable method since swapping pivot and data would collapse stable property.
    _quick_sort(array, 0, len(array) - 1)


def _quick_sort(array, start_idx, end_idx):
    if start_idx >= end_idx:
        return

    # let the random element is pivot
    # and put the random element on the end
    i_pivot = randint(start_idx, end_idx)
    pivot = array[i_pivot]
    # only swap pivot and last element if values are different to be stable sort
    if pivot != array[end_idx]:
        array[i_pivot], array[end_idx] = array[end_idx], array[i_pivot]
    # now, array[end_idx] is the pivot from this line to below.

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

def merge_sort(array):
    # This merge sort is 2-way merge sort (dividing 2 block in each steps)
    # It is stable, but not in-place. It needs extra memory as many as size of array 
    _merge_sort(array, 0, len(array) - 1)

def _merge_sort(array, start_idx, end_idx):
    if start_idx >= end_idx:
        return
    mid_idx = (start_idx + end_idx) // 2
    _merge_sort(array, start_idx, mid_idx)
    _merge_sort(array, mid_idx + 1, end_idx)

    # merging two sorted sequences
    # merge(array, [start_idx, mid_idx], [mid_idx + 1, end_idx])
    left_idx, right_idx = start_idx, mid_idx + 1
    extra_array = []
    while left_idx <= mid_idx and right_idx <= end_idx:
        # comparison on values on left_idx and right_idx
        if array[left_idx] <= array[right_idx]:
            extra_array.append(array[left_idx])
            left_idx += 1
        else:
            extra_array.append(array[right_idx])
            right_idx += 1
    # all left elements are added in extra_array. append remaining right elements to extra_array 
    if left_idx > mid_idx:
        extra_array.extend(array[right_idx:end_idx + 1])
    # all right elements are added in extra_array. append remaning left elements to extra_array
    else:
        extra_array.extend(array[left_idx:mid_idx + 1])
    
    # exception
    assert len(extra_array) == end_idx - start_idx + 1, 'In _merge_sort, size error in copied extra_array'

    # overwrite array by extra_array
    for i in range(end_idx - start_idx + 1):
        array[start_idx + i] = extra_array[i]




def count_sort(array, radix_digit=None):
    # count_sort is stable but not in place
    # k
    count = [0] * (max(array) + 1)
    # n
    for val in array:
        count[val] += 1
    # k
    for idx in range(1, len(count)):
        count[idx] += count[idx - 1]
    # n
    copied_array = [x for x in array]
    for idx in reversed(range(len(array))):
        count[copied_array[idx]] -= 1
        array[count[copied_array[idx]]] = copied_array[idx]

def count_sort_for_radix(array, radix_digit):
    # radix_digit is n-th digit. For 532, 3-th digit is 5, 2-th digit is 3 and 1-th digit is 2. 
    # count is limited to 0 - 9
    # 10
    count = [0] * 10
    # n
    for val in array:
        val = (val // int(10**(radix_digit - 1))) % 10
        count[val] += 1
    # 10
    for idx in range(1, len(count)):
        count[idx] += count[idx - 1]
    # n
    copied_array = [x for x in array]
    for idx in reversed(range(len(array))):
        copied_val_for_radix = (copied_array[idx] // int(10**(radix_digit - 1))) % 10
        count[copied_val_for_radix] -= 1
        array[count[copied_val_for_radix]] = copied_array[idx]        

def radix_sort(array):

    # find maxmum digit
    max_value = max(array)
    max_digit = 0
    while max_value > 0:
        max_value //= 10
        max_digit += 1

    # count sort from lowest to largest digits
    for digit in range(1, max_digit + 1):
        count_sort_for_radix(array, digit)
            

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
