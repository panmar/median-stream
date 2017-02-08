import random
import statistics
import os
import progressbar

def clean_tests():
    working_dir = os.getcwd()
    files = [f for f in os.listdir(working_dir)
            if os.path.isfile(os.path.join(working_dir, f))]
    test_files = [f for f in files if f.endswith(".in") or f.endswith(".out")]
    for f in test_files:
        os.remove(f)

if __name__ == "__main__":
    clean_tests();
    test_capacities = [10000, 100000, 30000, 60000, 50000, 25000]
    test_number = 1;
    for capacity in test_capacities:
        random.seed()
        numbers = []
        for i in range(0, capacity):
            if test_number < 4:
                number = random.randint(-0x80000000, 0x7FFFFFFF)
            elif test_number < 6:
                noise_simulator = random.random()
                if noise_simulator < 0.95:
                    number = random.randint(-100000, 400000)
                elif noise_simulator < 0.97:
                    number = random.randint(5000000, 100000000)
                else:
                    number = random.randint(-100000000, -1000000)
            else:
                noise_simulator = random.random()
                if noise_simulator < 0.95:
                    number = random.randint(0, 500000)
                else:
                    number = random.randint(50000000, 1000000000)
            numbers.append(number)

        intest_filename = "test" + str(test_number).zfill(2) + ".in"
        with open(intest_filename, "w") as test_file:
            for n in numbers:
                test_file.write("%s\n" % n)

        widgets = [progressbar.FormatLabel(''), '',
                    progressbar.Percentage(), ' ',
                    progressbar.Bar('#'), '',
                    progressbar.RotatingMarker()]
        outtest_filename = "test" + str(test_number).zfill(2) + ".out"
        bar = progressbar.ProgressBar(widgets=widgets, maxval=len(numbers))
        widgets[0] = outtest_filename

        bar.start()
        medians = []
        for i in range(1, len(numbers) + 1):
            median = statistics.median(numbers[:i])
            stripped_median = ('%f' % median).rstrip('0').rstrip('.')
            medians.append(stripped_median)
            bar.update(i)
        with open(outtest_filename, "w") as test_file:
            for m in medians:
                test_file.write("%s\n" % m)

        test_number += 1