#!/bin/bash
. ~/.bash_profile

APP_PATH=[]
#ɾ�������������־
find ${APP_PATH}/log/ -name "*" -ctime +7 | xargs rm -f
