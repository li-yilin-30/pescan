#!/bin/sh 
path="/home/liyilin/桌面/c语言对exe文件的特征提取/virus" 
for file in ${path}/*
do 
temp_file=`basename $file` 
echo $temp_file 
done
