for file in $(ls | grep .cpp) ; do
	if [[ $(echo $file | wc -m) -eq 6 ]] ; then
		mv $file "00$file"
		echo "moved"
	elif [[ $(echo $file | wc -m) -eq 7 ]] ; then
		mv $file "0$file"
		
	fi
	echo $file
done
