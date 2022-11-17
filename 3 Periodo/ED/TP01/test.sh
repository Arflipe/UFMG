make clean
make

./bin/run.out -i inputs/input_01 -p log > output_01.txt
./bin/run.out -i inputs/input_02 -p log > output_02.txt
./bin/run.out -i inputs/input_03 -p log > output_03.txt
./bin/run.out -i inputs/input_04 -p log > output_04.txt
./bin/run.out -i inputs/input_05 -p log > output_05.txt
./bin/run.out -i inputs/input_06 -p log > output_06.txt
./bin/run.out -i inputs/input_07 -p log > output_07.txt
./bin/run.out -i inputs/input_08 -p log > output_08.txt

diff output_01.txt outputs/output_01.txt
diff output_02.txt outputs/output_02.txt
diff output_03.txt outputs/output_03.txt
diff output_04.txt outputs/output_04.txt
diff output_05.txt outputs/output_05.txt
diff output_06.txt outputs/output_06.txt
diff output_07.txt outputs/output_07.txt
diff output_08.txt outputs/output_08.txt