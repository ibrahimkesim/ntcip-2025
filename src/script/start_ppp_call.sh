#!/bin/bash

# Make LOW RESETKEY of Simcard
echo "27" > /sys/class/gpio/export
sleep 0.1
echo "out" > /sys/class/gpio/gpio27/direction
echo "0" > /sys/class/gpio/gpio27/value

# Make HIGH PWRKEY of Simcard
echo "22" > /sys/class/gpio/export
sleep 0.1
echo "out" > /sys/class/gpio/gpio22/direction

echo "0" > /sys/class/gpio/gpio22/value
sleep 0.2
echo "1" > /sys/class/gpio/gpio22/value
sleep 1
echo "0" > /sys/class/gpio/gpio22/value

sleep 18

sudo rm -f /etc/ppp/peers/quectel-chat-connect
sudo rm -f /etc/ppp/peers/quectel-ppp

sudo echo "ABORT "BUSY"
ABORT "NO CARRIER"
ABORT "NO DIALTONE"
ABORT "ERROR"
ABORT "NO ANSWER"
TIMEOUT 30
'' AT
OK ATE0
OK ATI;+CSUB;+CSQ;+COPS?;+CGREG?;&D2
OK AT+CPIN=5550
OK AT+CGDCONT=2,"IP","internetstatik"
OK ATDT*99***2#
CONNECT ''" > /etc/ppp/peers/quectel-chat-connect

sudo echo "/dev/ttyS0
115200
user "internet"
#user "vodafone"
#password "vodafone"
connect 'chat -s -v -f /etc/ppp/peers/quectel-chat-connect'
disconnect '/usr/sbin/chat -e -v "" +++ath'
hide-password
noauth
debug
#defaultroute
noipdefault
noccp
#persist
nocrtscts" > /etc/ppp/peers/quectel-ppp
