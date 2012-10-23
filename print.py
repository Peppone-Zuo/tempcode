import urllib2

class HeadRequest(urllib2.Request):
    def get_method(self):
        return 'HEAD'
        #return 'GET'

def getheadersonly(url, redirections=True):
    opener = urllib2.OpenerDirector()
    opener.add_handler(urllib2.HTTPHandler())
    opener.add_handler(urllib2.HTTPDefaultErrorHandler())
    if redirections:
        # HTTPErrorProcessor makes HTTPRedirectHandler work
        opener.add_handler(urllib2.HTTPErrorProcessor())
        opener.add_handler(urllib2.HTTPRedirectHandler())
    try:
        res = opener.open(HeadRequest(url))
    except urllib2.HTTPError, res:
        pass
    res.close()
    return dict(code=res.code, headers=res.info(), finalurl=res.geturl())

#print getheadersonly("http://ms.com", redirections = False)['finalurl']
#print getheadersonly("http://ms.com")['finalurl']
#
#
#print getheadersonly("http://www.example.com", redirections = False)['finalurl']
#print getheadersonly("http://www.example.com")['finalurl']
#
print getheadersonly("http://file0.shooter.cn/c/The_Walking_Dead_S03E02_HDTV_x264_KILLERS_YTET_YDY.rar?p=20121022&s=5dc2757b344838079bf204d2a1acb64c&t=1350922070&h=25iHsOr83yM3mMG9qpP2Ug")['finalurl']
print getheadersonly("http://www.example.com")['finalurl']
