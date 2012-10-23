what = {
    "direction" : ["north", "south", "east", "west", "down", "up", "left", "right", "back"], 
    "verb" : ["go", "stop", "kill", "eat"],
    "stop" : ["the", "in", "of", "from", "at", "it"],
    "noun" : ["door", "bear", "princess", "cabinet"]
}

def convert_number(s):
    try:
        return int(s)
    except ValueError:
        return None

def scan(sentence):
    res = []
    words = sentence.split()
    for w in words:
        error = True
        num = convert_number(w)
        if num:
            res.append(("number", num))
            error = False
        for t in what:
            if w in what[t]:
                res.append((t, w))
                error = False
        if error:
            res.append(("error", w))
    return res

#print scan("bear IAS princess")

