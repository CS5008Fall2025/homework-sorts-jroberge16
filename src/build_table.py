import subprocess

START = 100
END = 100_100
STEPS = 500
SAVE_PATH = "results.txt"

for i in range(START, END, STEPS):
    command = f'./tester.out 5 {i} >> {SAVE_PATH}'
    subprocess.run(command, shell=True)
    subprocess.run(f'printf "\\n" >> {SAVE_PATH}', shell=True)
    print(f"Step:\t {i}")