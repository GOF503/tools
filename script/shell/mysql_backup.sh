#!/bin/bash
mysql_user=[ ]
mysql_password= [ ]
MYDATE=`date +%Y%m%d`
#--single-transaction  ���INNODB
mysqldump -u$mysql_user -p$mysql_password --all-databases --single-transaction [ ] > [ ]$MYDATE.sql