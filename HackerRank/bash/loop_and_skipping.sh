#!/bin/bash - 
#===============================================================================
#
#          FILE: loop_and_skipping.sh
# 
#         USAGE: ./loop_and_skipping.sh 
# 
#   DESCRIPTION: 
# 
#       OPTIONS: ---
#  REQUIREMENTS: ---
#          BUGS: ---
#         NOTES: ---
#        AUTHOR: 杨秀隆
#  ORGANIZATION: 
#       CREATED: 2014年08月29日 20:08
#      REVISION:  ---
#===============================================================================

set -o nounset                              # Treat unset variables as an error

n=1

while (( n < 100 )) 
do
    echo $n;
    ((n = n+2));
done

