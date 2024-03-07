datasets_folder="datasets"

out_t="output/tatt"
out_c="output/christofides"

tatt="python3 Python/tatt.py"
christofides="python3 Python/christofides.py"

eval="python3 Python/evaluate.py"

# Get all filenames in the datasets folder
filenames=$(ls $datasets_folder)

# Loop through each filename
for filename in $filenames; do
	# Run the program with the filename as an argument and redirect the output
	echo $filename
	/usr/bin/time -v --output=$out_t/time/$filename.time timeout 30m $tatt $datasets_folder/$filename > $out_t/solution/$filename.out
	/usr/bin/time -v --output=$out_c/time/$filename.time timeout 30m $christofides $datasets_folder/$filename > $out_c/solution/$filename.out
done

/bin/bash eval.sh