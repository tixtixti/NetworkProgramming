#List all my proceses
ps
#Certain program
ps |grep "name of program"
#Kill certain process
kill -9 "processID"
#Kill all processes running certain program.
killall "process name"
#kill all for certain member
pkill -9 -u 'id -u "username"'
#be "nice"
nice -n -20 "utility" 
