datasets_folder="datasets"

out_b="output/bab"

bab="CPP/bin/run.out"

eval="python3 Python/evaluate.py"

# Get all filenames in the datasets folder
filenames=$(ls $datasets_folder)

# Loop through each filename
for filename in $filenames; do
	# Run the program with the filename as an argument and redirect the output
	echo $filename
	/usr/bin/time -v --output=$out_b/time/$filename.time timeout 30m $bab datasets/$filename > $out_b/solution/$filename.out
done

/bin/bash eval.sh