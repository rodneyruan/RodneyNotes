FTP_SERVER=10.88.70.151
ftp -n << _EOF_
open $FTP_SERVER
user username password
bin
get $1 
bye

_EOF_
echo "FTP download $1 is complete!"
