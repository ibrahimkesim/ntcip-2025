# isbak-ntcip-2a9
# hhi
#### Prerequests

The project uses CMake build tool. To install it:
    
    sudo apt install -y cmake

The project needs wiringPi library on raspberry pi. To install it:
    
    git clone https://github.com/WiringPi/WiringPi.git
	cd wiringPi
	git pull origin
	./build
  
Check the installation:

	gpio -v
	
Install systemd library:

	sudo apt install libsystemd-dev
	

#### Build 

run build.sh to compile project. 

    bash build.sh
    
#### Test 

run project on rpi:

    cd build
    sudo ./haberlesme_karti
    
Send snmp read command on different PC to rpi, Dont forget to change below IP address:

    for counter in {1..100}; do snmpwalk -v 2c -c public -On 192.168.1.110 ISBAV-MIB::signalState.signalStateTable; sleep 1; done
    for counter in {1..100}; do snmpwalk -v 2c -c public -On 192.168.1.110 ISBAV-MIB::channel.trafficLightFaultStatusTable; sleep 1; done
	
