clear
echo "Cleaning...";
rm Server.o

gcc Webserver/Server.c -o  Server.o

echo "Running Server";
sudo ./Server.o
