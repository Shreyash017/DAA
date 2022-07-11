class solution:
    def __init__(self):
        self.MAX = 100    # size of array
        self.A = [0]*self.MAX
        self.count = 1

    def placement(self, i, j):    # to check if queen can be placed
        for k in range(1, i):
            if (self.A[k] == j) or abs(self.A[k] - j) == abs(k - i):
                return False
        return True

    def printplacedqueen(self, N):  # method for print the placed Queen
        print()
        print(f'\nArrangment-{self.count}')
        self.count += 1
        print()

        for i in range(1, N+1):
            for j in range(1, N+1):
                if self.A[i] != j:
                    print('\t_', end=' ')
                else:
                    print('\tQ', end=' ')
            print()
            print()

    def N_Queens(self, i, j):
        for k in range(1, N+1):
            if self.placement(i, k):
                self.A[i] = k
                if i == N:
                    self.printplacedqueen(N)
                else:
                    self.N_Queens(i+1, N)


if __name__ == '__main__':
    print()
    N = int(input("Enter Number of Queens: "))
    print()
    obj = solution()
    obj.N_Queens(1, N)
    print()
