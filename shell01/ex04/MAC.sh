ifconfig -a | grep 'ether' | sed 's/ether//' | sed 's/[[:space:]]//g'
