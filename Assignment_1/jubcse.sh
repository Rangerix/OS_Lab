newdir(){
	mkdir $1
	if [ $? ]
	then
		printf "built a directory %s\n" $1
	fi
	echo ""
}
getnewfilename(){
	maxx=1000
	name="newfile"
	for (( i=1 ; i<= $maxx; i++ ))
	do
		filename="$name$i"
		#echo $filename
		if [ ! -f filename ]
		then 
			break
		fi
	done
	if [ $i -eq $maxx ]
	then
		filename=""
	fi
	echo ""
}
info(){
	if [ -f $1 ]
	then
		path=$(readlink -f $1)
		details=$(ls -l $1)
		size=$(echo $details| cut -d ' ' -f 5)
		owner=$(echo $details| cut -d ' ' -f 3)
		moddate=$(echo $details| cut -d ' ' -f 6,7,8)
		printf "full path : %s\n" $path
		printf "size : %d bytes\n" $size
		printf "owner : %s\n" $owner
		printf "last modified : %s\n" "$moddate"
	fi
	echo ""
}
editfile(){
	vi $1
}
content(){
	cat $1
	echo ""
}
exitbcse(){
	exit 1
}

#--------------- main script ------------------------

tod=$(date +"%T" | cut -d ':' -f 1)
if [ $tod -ge 5 -a $tod -lt 12 ]
then
	echo "Good morning"
elif [ $tod -ge 12 -a $tod -lt 18 ]
then
	echo "Good afternoon"
elif [ $tod -ge 18 -a $tod -lt 22 ]
then
	echo "Good evening"
else 
	echo "Good night"
fi

while [ 0 ]
do
	printf "BCSEIII:"
	read var
	cnt=$(echo $var | wc -w )
	command=$(echo $var| cut -d ' ' -f 1 )
	#printf "command = %s\n" $command
	if [ $command = "exitbcse" ]
	then
		exitbcse
	elif [ $command = "newdir" ]
	then
		if [ $cnt -lt 2 ]
		then
			echo "newdir dirname"
		else
			dirname=$(echo $var| cut -d ' ' -f 2- )
			newdir $dirname
		fi
	elif [ $command = "editfile" ]
	then
		if [ $cnt -lt 2 ]
		then
			#echo "here"
			getnewfilename
			echo $filename
			editfile $filename
		else
			filename=$(echo $var| cut -d ' ' -f 2- )
			editfile $filename
		fi
	elif [ $command = "content" ]
	then
		if [ $cnt -lt 2 ]
		then
			echo "content filename"
		else
			filename=$(echo $var| cut -d ' ' -f 2- )
			content $filename
		fi
	elif [ $command = "info" ]
	then
		if [ $cnt -lt 2 ]
		then
			for file in ./*
			do 
				info $file
			done
		else
			filename=$(echo $var| cut -d ' ' -f 2- )
			info $filename
		fi
	fi

done
