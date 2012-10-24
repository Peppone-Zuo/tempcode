import urllib2, re
from bs4 import BeautifulSoup 

fin = open("headers.txt", "r")
headers = fin.read()
fout = open("locations.txt", "w")


def find_next_location(source, res = []):
    anchor = "Location: "
    start = source.find(anchor)
    if start < 0:
        return
    start += len(anchor)
    source = source[start:]
    anchor = "Pragma:"
    end = source.find(anchor)
    #print source[:end-1]
    res.append(source[:end-1])
    find_next_location(source, res)
    return res

#print find_next_location(headers, )
Locations = find_next_location(headers)
for l in Locations:
    fout.write(l)
    fout.write("\n")
#print len(Locations)
