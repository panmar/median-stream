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
    test_capacities = { 10000 };
    test_number = 1;
    for capacity in test_capacities:
        random.seed()
        numbers = []
        for i in range(0, capacity):
            number = random.randint(-0x80000000, 0x7FFFFFFF)
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
        with open(outtest_filename, "w") as test_file:
            bar.start()
            for i in range(1, len(numbers) + 1):
                median = statistics.median(numbers[:i])
                stripped_median = ('%f' % median).rstrip('0').rstrip('.')
                test_file.write("%s\n" % stripped_median)
                bar.update(i)

        test_number += 1