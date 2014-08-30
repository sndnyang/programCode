#!/usr/bin/env python
# -*- coding: utf-8 -*-  
#####################################################
#  
# File: python_sqlite.py 
# Created: 2014-08-29 21:06:36
# Last Modified:  
#   
# Author: 杨秀隆 sndnyang <xiulong.yancey.yang@gmail.com>
#         sndnyang.github.io
# Description:
#  
#####################################################

import sqlite3
def main():
    conn = sqlite3.connect("/tmp/movies.db")
    sql_cmd = "create table MOVIES ( name char(40), year char(4), rating smallint)"

    conn.execute(sql_cmd)

    data_set = [('Rise of the Planet of the Apes', '2011', 77), 
                ('Dawn of the Planet of the Apes', '2014', 91),
                ('Alien', '1979', 97),
                ('Aliens', '1986', 98),
                ('Mad Max', '1979', 95),
                ('Mad Max 2: The Road Warrior', '1981', 100)]

    for name, year, rating in data_set:
        sql_data = "insert into movies values('%s', '%s', %d)" % (name, year, rating)
        conn.execute(sql_data)

    conn.commit()

    conn.close()

main()
