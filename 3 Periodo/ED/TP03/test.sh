make clean
make

./bin/run.out -i inputs/input_01  -o output_01a -t a >> time.txt
./bin/run.out -i inputs/input_02  -o output_02a -t a >> time.txt
./bin/run.out -i inputs/input_03  -o output_03a -t a >> time.txt
./bin/run.out -i inputs/input_04  -o output_04a -t a >> time.txt

./bin/run.out -i inputs/input_01  -o output_01h -t h >> time.txt
./bin/run.out -i inputs/input_02  -o output_02h -t h >> time.txt
./bin/run.out -i inputs/input_03  -o output_03h -t h >> time.txt
./bin/run.out -i inputs/input_04  -o output_04h -t h >> time.txt

diff output_01a.txt outputs/output_01.txt
diff output_02a.txt outputs/output_02.txt
diff output_03a.txt outputs/output_03.txt
diff output_04a.txt outputs/output_04.txt

diff output_01h.txt outputs/output_01.txt
diff output_02h.txt outputs/output_02.txt
diff output_03h.txt outputs/output_03.txt
diff output_04h.txt outputs/output_04.txt