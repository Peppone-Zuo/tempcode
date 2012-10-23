#!/usr/bin/env python  
#-*- coding:utf-8 -*-  
import sys

import urllib  
import simplejson as json  
import gzip  
import cStringIO  

def save_to_file(data, filename):
    f = open(filename, "w")
    pickle.dump(data, f)
    f.close()

def read_from_file(filename):
    f = open(filename, "r") 
    return pickle.load(f)

def get_data_from_url(url):
    c = urllib.urlopen(url).read()  
    s = cStringIO.StringIO(c)  
    gzfile = gzip.GzipFile(fileobj=s, mode='rb')  
    #content = gzfile.read()  
    content = gzfile
    #data = json.loads(content)  
    data = content
    return data

#print get_data_from_url("http://www.baidu.com")
#print get_data_from_url("http://class.coursera.org/db/lecture/subtitles?q=6_en&format=srt")
#print get_data_from_url("http://class.coursera.org/db/lecture/subtitles?q=6_en&format=srt")
#print get_data_from_url("http://class.coursera.org/db/lecture/download.mp4?lecture_id=6")

print urllib.urlretrieve("http://www.baidu.com")
#print urllib.urlretrieve("http://class.coursera.org/db/lecture/download.mp4?lecture_id=6")
