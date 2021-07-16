
# Module Import
import json
import os
from pathlib import Path
from random  import randint
import imageconvertermain
import hashchecker
# Function
def loadjson(name):
    with open(name) as FOBJ:
        FILE = json.load(FOBJ)
        return FILE
FOCUS="JeremyCorbyn"

if __name__ != "__main__":
    exit("Not a library" )
else:
    # Checks if the hash list exists
    if os.path.exists("img.txt") == False:
        with open("img.txt","w") as f:
            pass
    else:
        mainjson = loadjson("main.json")[FOCUS]
        quotesjson = loadjson(mainjson["qtxt"])
        imglist=os.listdir(mainjson["imgsrc"])
        TOTAL_COMBINATIONS= len(imglist)*len(quotesjson)
        LIMITER=0
        while LIMITER<=TOTAL_COMBINATIONS:
            img_file= imglist[randint(0,len(imglist)-1)]
            quote_index=str(randint(1,len(quotesjson)))
            quote = quotesjson[quote_index]
            image_name=mainjson['imgsrc']+img_file
            if hashchecker.checkhash('img.txt',image_name) != True:
                imageconvertermain.ImageConverter(image_name,quote,quote_index+img_file)
                hashchecker.writehash('img.txt',image_name);
                LIMITER+=1
            else: 
                pass
