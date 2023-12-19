#!/bin/bash

pid_max=$(< /proc/sys/kernel/pid_max)
echo "The Maximun process of ID: $pid_max"
