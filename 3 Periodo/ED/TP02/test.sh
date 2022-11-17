make clean
make

./bin/run.out -v 1 -s 10 -i Inputs/Input.txt -o Outputs/RQuickSort

./bin/run.out -v 2 -s 10 -i Inputs/Input.txt -o Outputs/M3QuickSort -k 3
./bin/run.out -v 2 -s 10 -i Inputs/Input.txt -o Outputs/M5QuickSort -k 5
./bin/run.out -v 2 -s 10 -i Inputs/Input.txt -o Outputs/M7QuickSort -k 7

./bin/run.out -v 3 -s 10 -i Inputs/Input.txt -o Outputs/S10QuickSort -m 10
./bin/run.out -v 3 -s 10 -i Inputs/Input.txt -o Outputs/S100QuickSort -m 100

./bin/run.out -v 4 -s 10 -i Inputs/Input.txt -o Outputs/IQuickSort

./bin/run.out -v 5 -s 10 -i Inputs/Input.txt -o Outputs/SSQuickSort