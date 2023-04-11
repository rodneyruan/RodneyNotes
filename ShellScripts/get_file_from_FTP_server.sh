#!/bin/bash
# A shell script to get a file from an FTP server
# Usage: ./get_file.sh ip username password filename

# Check if the number of arguments is 4
if [ $# -ne 4 ]; then
  echo "Invalid number of arguments."
  echo "Usage: ./get_file.sh ip username password filename"
  exit 1
fi

# Assign the arguments to variables
ip=$1
username=$2
password=$3
filename=$4

# Use ftp command to connect to the server and get the file
ftp -n $ip <<END_SCRIPT
user $username $password
binary
get $filename
quit
END_SCRIPT

# Check if the file was downloaded successfully
if [ -f $filename ]; then
  echo "File downloaded successfully."
else
  echo "File download failed."
  exit 2
fi
