#!/bin/bash - 
#===============================================================================
#
#          FILE: exec_program.sh
# 
#         USAGE: ./exec_program.sh pno
# 
#   DESCRIPTION: 放到环境变量， 在当前路径查找可执行的特征文件和数据
# 
#       OPTIONS: ---
#  REQUIREMENTS: ---
#          BUGS: ---
#         NOTES: ---
#        AUTHOR: 杨秀隆
#  ORGANIZATION: 
#       CREATED: 2014年08月17日 15:03
#      REVISION:  ---
#===============================================================================

set -o nounset                              # Treat unset variables as an error

if [[ $# = 0 ]]
then
    echo " usage:"
    echo "\t exec_program.sh pno"
    exit 
fi

for file in ` ls $1_*`
do
    name=${file%.*}
    exten=${file#*.}

    if [[ $exten = "txt" ]]
    then
        continue
    fi

    case $exten in
        c)
            gcc $file -o $name
            ./$name `ls $1_*.txt `;;
        cc|cpp)
            g++ $file -o $name
            ./$name `ls $1_*.txt `;;
        py)
            python $file ` ls $1_*.txt`;;
    esac

done
