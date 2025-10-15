from collections import Counter

class StatisticsCalculator:
    def __init__(self, numbers):
        self.numbers = sorted(numbers)
        if not self.numbers:
            raise ValueError("Empty list")

    def mean(self):
        return sum(self.numbers) / len(self.numbers)

    def median(self):
        n = len(self.numbers)
        mid = n // 2
        if n % 2 == 1:
            return float(self.numbers[mid])
        return (self.numbers[mid - 1] + self.numbers[mid]) / 2.0

    def mode(self):
        counts = Counter(self.numbers)
        maxc = max(counts.values())
        modes = [k for k, v in counts.items() if v == maxc]
        return modes, maxc


if __name__ == "__main__":
    # Fixed data — runs immediately (you can edit these numbers)
    nums = [1, 2, 2, 3, 4, 5, 5, 5, 6]

    calc = StatisticsCalculator(nums)
    modes, freq = calc.mode()

    print("--- Statistics Result ---")
    print(f"Input: {nums}")
    print(f"Input count: {len(nums)}")
    print(f"Mean: {calc.mean():.2f}")
    print(f"Median: {calc.median():.2f}")
    print(f"Mode(s): {', '.join(map(str, modes))} (freq = {freq})")