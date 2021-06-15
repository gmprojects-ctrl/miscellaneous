# Libraries

from PIL import Image
from PIL import ImageFont
from PIL import ImageDraw


def correctfontsize(imageheight):
    size = round((0.25 * imageheight / 8) * 6)
    return size


def ImageConverter(name, text, tolerance, colour_1, colour_2, text_colour):
    with Image.open(name) as im:
        pixelmap_original = im.load()
        image2 = Image.new(im.mode, im.size)
        pixelmap_new = image2.load()
        for i in range(im.size[0]):
            for j in range(im.size[1]):
                pixel_value = round(sum(pixelmap_original[i, j]) / 3)
                if pixel_value <= int(tolerance):
                    pixelmap_new[i, j] = colour_1
                else:
                    pixelmap_new[i, j] = colour_2
        font = ImageFont.truetype("impact.ttf",
                                  correctfontsize(image2.size[1]))
        draw_obj = ImageDraw.Draw(image2)
        text_width = draw_obj.textlength(text, font)
        draw_obj.text((round(
            (image2.size[0] - text_width) / 2), round(image2.size[1] * 0.75)),
                      text,
                      fill=text_colour,
                      font=font)
        image2.save("2" + name)


name = "jc.jpg"
red = (255, 0, 0)
black = (0, 0, 0)
white = (255, 255, 255)
text = "*Socialism Intensifies"

ImageConverter(name, text, "128", red, black, white)
