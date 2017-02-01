#!/bin/bash

for i in {0..255}
do
	for j in {0..255}
	do
		echo "Scanning 10.$i.$j.0/24"
		sleep 1
		arp-scan --interface=wlan0 10.$i.$j.0/24
		sleep 10
	done
done
