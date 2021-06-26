#!/usr/local/python

import sys
import psycopg2

scripts = ['./database.sql', './schema.sql']

def main():
    host = sys.argv[0]
    port = sys.argv[1]
    database = sys.argv[2]
    username = sys.argv[3]
    password = sys.argv[4]

    con = psycopg2.connect(database=database, user=username, password=password, host=host, port=port)

    for script in scripts:
        sqlScript = open(script, "r")
        con.execute(sqlScript.read())

    con.commit()
    con.close()

if __name__ == '__main__':
    main()