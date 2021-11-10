ifconfig | grep ether | sed 's/^.*ether //' | awk '{print $1}'
