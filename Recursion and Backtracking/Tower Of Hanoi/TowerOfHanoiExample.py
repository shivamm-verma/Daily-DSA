def tower_of_hanoi(n, src, dest, aux):
    if n == 1:
        print(f"Move disk 1 from source {src} to destination {dest}")
        return

    tower_of_hanoi(n - 1, src, aux, dest)
    print(f"Move disk {n} from source {src} to destination {dest}")
    tower_of_hanoi(n - 1, aux, dest, src)

# Driver code
n = 4  # Number of disks
tower_of_hanoi(n, 'A', 'B', 'C')  # A, B, C are the names of rods


# // Steps Followed:
# // Move disk 1 from source A to destination C
# // Move disk 2 from source A to destination B
# // Move disk 1 from source C to destination B
# // Move disk 3 from source A to destination C
# // Move disk 1 from source B to destination A
# // Move disk 2 from source B to destination C
# // Move disk 1 from source A to destination C