eval="python3 Python/evaluate.py"

datasets_folder="datasets"
solutions="tp2_datasets.txt"

out_b="output/bab"
out_t="output/tatt"
out_c="output/christofides"

filenames=$(ls $out_b/solution)

rm $out_b/quality.txt

for filename in $filenames; do
	echo $filename 'bab'
	$eval $out_b/solution/$filename $solutions >> $out_b/quality.txt
done

filenames=$(ls $out_t/solution)

rm $out_t/quality.txt

for filename in $filenames; do
	echo $filename 'tatt'
	$eval $out_t/solution/$filename $solutions >> $out_t/quality.txt
done

filenames=$(ls $out_c/solution)

rm $out_c/quality.txt

for filename in $filenames; do
	echo $filename 'christofides'
	$eval $out_c/solution/$filename $solutions >> $out_c/quality.txt
done