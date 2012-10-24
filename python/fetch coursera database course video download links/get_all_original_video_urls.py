import urllib2, re
from bs4 import BeautifulSoup 

f = open("courses.html", "r")
page = f.read()
soup = BeautifulSoup(page)

def find_title(source):
    start_str = "Video (MP4) for "
    source = str(source)
    start = source.find(start_str)
    start_pos = start + len(start_str)

    source = source[start_pos:]
    pattern = '\([0-9]* min\)'
    match = re.search(pattern, source)
    if not match:
        end = source.find("<")
    else:
        end = match.start()
    return source[: end]

def find_lecture_id(source):
    source = str(source)
    start_str = "lecture_id="
    start = source.find(start_str)
    start += len(start_str)
    end = source.find('"', start)
    return source[start : end]




videos = soup.findAll("div", { "class" : "item_resource" })


res = []

for v in videos:
    vstr = str(v)
    lecture_title = find_title(vstr)
    lecture_id = find_lecture_id(vstr)
    url = lecture_id
    #url = "https://class.coursera.org/db/lecture/view?lecture_id="+lecture_id
    res.append((lecture_title, url))

url = "https://class.coursera.org/db/lecture/download.mp4?lecture_id="
fout = open("videos.txt", "w")

for t, i in res:
#    fout.write(t)
#    fout.write('\n')
    fout.write(url + i)
    fout.write('\n')

