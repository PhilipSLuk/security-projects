#! /bin/bash

ip a | egrep -oh "inet 10.10.".{4} | cut -c6-16
