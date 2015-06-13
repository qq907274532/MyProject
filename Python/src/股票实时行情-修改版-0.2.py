#! /usr/bin/env python
# -*- coding: utf8 -*-
'''

 Only For Windows
 Linux not support yet
 Author: Damon.shen 2015-5-20 17:05:00
 debug with python 2.7.x
 
 update Ver 0.2 @ 2015-6-2 15:36:27
	1、Fix out of lines bug
	2、Fix a logic bug
	3、Add a state prompt
'''

import urllib2,time,sys,os 
reload(sys)  
sys.setdefaultencoding('utf8')

#只需要加入自选股代码即可，不能去除前缀，否则无法获取
code_list = ['s_sh000001','s_sz399001','s_sh600460','s_sz000709']
cols = '43'

os.system("title 实时股票行情".decode('utf-8').encode('gbk'))
os.system("mode con cols=%s lines=%s" %(cols, str(len(code_list)+3)))
os.system("COLOR 0A")


title_data = u'股票名称 |' + u' 最新'.ljust(9,' ') + u'| 涨跌'.ljust(10,' ') + u'| 幅度\n' + u'='*(int(cols)-1)
API_url = "http://hq.sinajs.cn/list="

for code in code_list:
    API_url =  API_url  + code + ','
	
print title_data
print u'数据载入中....'	
while 1:

    try:
        res =  urllib2.urlopen(url = API_url, timeout = 15)
        res_data =  res.read()
        if res_data:
            os.system('cls')
            all_data = res_data.split(";")
            print title_data
            for i in range(0,len(code_list)):
                name =  all_data[i].split("=")[1].split(',')[0]
                price = all_data[i].split("=")[1].split(',')[1]
                updown = all_data[i].split("=")[1].split(',')[2]
                percent = str(abs(float(all_data[i].split("=")[1].split(',')[3]))) 
                
                if float(updown) > 0:
                    updown = '+' + updown
                    percent = '+' + percent + "%"
                elif float(updown) < 0:
                    updown = '-' + str(abs(float(updown)))
                    percent = '-' + str(abs(float(percent))) + "%"
                else:
                    updown = '=' + updown
                    percent = '=' + percent + "%"
                
                stock_data = name[1:].ljust(8,' ') + " | " +  price.ljust(9,' ') + " | " + updown.encode('utf8').ljust(9,' ') + " | " + percent.ljust(6,' ')
                
                print stock_data
        time.sleep(1)
    except:
        pass

        
       
    
    

