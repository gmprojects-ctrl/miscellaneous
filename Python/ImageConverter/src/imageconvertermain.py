# Libraries

from PIL import Image
from PIL import ImageFont
from PIL import ImageDraw

# Chekcking names
if __name__ == "__main__":
    exit("This file is not executable")
else:
    pass



# Defines the correct font with ttf and relative to the image
def correctfont(imagewidth,text,ttf):
    size = round((0.25 * imagewidth / 8) * 6)
    font = ImageFont.truetype(ttf,size)
    while font.getsize_multiline(text)[0] > imagewidth:
        size-=1
        font=ImageFont.truetype(ttf,size)
    return font

# Converts Images to memes
def ImageConverter(name, text,new_name,tolerance=128, colour_1=(255,0,0), 
                   colour_2=(0,0,0), text_colour=(255,255,255),output="../Output/"):
    with Image.open(name) as im:   # Opening the file as a Image Object
        pixelmap_original = im.load()
        image2 = Image.new(im.mode, im.size)
        # Creating an empty ImageObject of the same height and length
        pixelmap_new = image2.load()
        for i in range(im.size[0]): 
            # Goes through each pixel of the original image 
            # and checks if the image fits a certain tolerance
            for j in range(im.size[1]):
                pixel_value = round(sum(pixelmap_original[i, j]) / 3)
                if pixel_value <= int(tolerance):
                    pixelmap_new[i, j] = colour_1
                else:
                    pixelmap_new[i, j] = colour_2

        # Writes text on the image
        font = correctfont(image2.size[0],text,"../fonts/impact.ttf")
        draw_obj = ImageDraw.Draw(image2)
        text_width = font.getsize_multiline(text)[0]
        draw_obj.text((round(
            (image2.size[0] - text_width) / 2), round(image2.size[1] * 0.75)),
                      text,
                      fill=text_colour,
                      font=font)
        image2.save(output+new_name)


#name = "cr2.jpg"
#red = (255, 0, 0)
#blue=(0,0,255)
#green=(0,255,0)
#black = (0, 0, 0)
#white = (255, 255, 255)
#text = "Sweet\nDreams"
#
#ImageConverter(name, text,"maggie3.jpg", 128,green, blue, blue)
#
