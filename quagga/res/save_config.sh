#!/bin/bash
if [ $# -eq 0 ] ; then
	vtysh -c write
	if [ 0 -eq $? ] ; then
		exit 0
	else
		exit 1
	fi
else
	exit 1
fi
