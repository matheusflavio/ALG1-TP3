# ALG1-TP3
Repository to save my ALG1-TP1 Implementation.
I personally consider my implementation bad, so I suggest to see this other one that I've found a couple of days after sending my implementation:
[Babi's AG1-TP3 Github](https://github.com/babimartins/alg1-tp3)

90% of the grade adquired

## Compiling and Running the Program
First of all, clone this repo into a folder of your preference inside your machine by opening a terminal inside that folder and than enter the project folder by running these commands:
```
git clone https://github.com/matheusflavio/ALG1-TP3.git
cd ALG1-TP3
```
Then, build the tp03 executable. To do that, use the terminal that previously is located inside the project root folder and run the command:
```
make
```
After that, run a test instance by using a command like this:
```
./tp03 < test_files/easy.in
```

You can test the output of single inputs like that by running:
```
diff <(./tp02 < test_files/easy.in) output/easy.out
```

Or, if you want to try the additional tests command, run on the terminal a command like this:
```
bash run_tests.sh
```
Note that 'test_files/easy.in' is just a location of a .in file named 'easy.in' that comes within this repository. It can be used with any location and any .in, .txt or any other input format that reffers to a input file. By running the command that way, the terminal show a line with one integer, that relates to that amount of cloth rolls in exhibition by the seller.

## Cleaning compiled files
Just run on the terminal:
```
make clean
```
