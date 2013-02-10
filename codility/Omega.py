
def falling_disks(A, B):
    now_depth = len(A)
    depth = len(A)
    count = 0
    for disk in B:
        fall_flag = now_depth
        for i in range(0, now_depth):
            if disk > A[i]:
                if i == 0:
                    fall_flag = -1
                else:
                    fall_flag = i
                break

        if fall_flag == -1:
            break
        elif fall_flag == 0:
            if now_depth != 0:
                count += 1
            break;
        elif fall_flag == now_depth and now_depth != 0:
            count += 1
            now_depth -= 1
        else :
            count += 1
            now_depth = fall_flag - 1

    return count;

if __name__ == "__main__":

    A = [5, 6, 4, 3, 6, 2, 3]
    B = [2, 3, 5, 2, 4]
    print falling_disks(A, B)

    A = [7, 6, 8, 10, 9, 3, 10]
    B = [7, 4, 2, 8]
    print falling_disks(A, B)

    A = [10, 8, 6, 4]
    B = [4, 3, 2, 1]
    print falling_disks(A, B)

    A = [4, 6, 8, 10]
    B = [9,8,7,6]
    print falling_disks(A, B)

    A = [4, 6, 8, 10]
    B = [9,8,7,3]
    print falling_disks(A, B)

    A = [4, 6, 8, 10]
    B = [9,3,7,2]
    print falling_disks(A, B)

    A = [4, 6, 8, 10]
    B = [9,4,3,2,1]
    print falling_disks(A, B)

    A = [5, 4, 3, 2, 1]
    B = [4, 3, 2, 1]
    print falling_disks(A, B)

    A = [5, 4, 3, 2, 1]
    B = [4, 3, 2, 1, 1, 1]
    print falling_disks(A, B)

    A = [5, 5, 5, 5, 5]
    B = [4, 3, 2, 1]
    print falling_disks(A, B)

    A = [5, 5,5,5,5]
    B = [4, 3, 6, 5]
    print falling_disks(A, B)

    A = [5, 5,5,5,5,5]
    B = [4, 1,1,1,1,1,1]
    print falling_disks(A, B)
