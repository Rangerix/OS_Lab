#check if a file exists and its type
#the filename is passed as command line argument
if test -e $1  
then
	printf "file exists\n"

	if test -b $1
	then
		printf "block file type\n"
	elif test -c $1
	then
		printf "character special file\n"
	elif test -d $1
	then
		printf "directory\n"
	elif test -h $1
	then
		printf "symbolic link\n"
	elif test -p $1
	then
		printf "named pipe\n"
	fi

else
	printf "does not exist\n"
fi
