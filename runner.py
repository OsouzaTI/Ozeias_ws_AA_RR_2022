from array import array
import random
import subprocess

def run(exec, args : list[str]):    
    return subprocess.run([exec] + args)

def generateArrayOfNumbers(n : int) -> list[str]:
    return [str(random.randrange(1, n, 1)) for i in range(n)]
# ultimo teste: 392000
def testFileWithNumbers():
    for test in [x for x in range(1000, 10**6, 1000)]:
        N = str(test)
        fileName = f'./test/n_{test}.txt'
        print(f'Teste com {test} entradas.')
        run('main.exe', [fileName, N])

def generateFileWithNumbers():
    for test in [x for x in range(0, 10**6, 1000)]:
        filePath = 'seminario01\selection_sort_c\\test'
        with open(f'{filePath}\\n_{test}.txt', 'w+') as f:
            f.write(' '.join(generateArrayOfNumbers(test)))
            f.close()

testFileWithNumbers()