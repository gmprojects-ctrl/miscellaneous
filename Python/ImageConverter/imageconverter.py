import os
image_name = "jc2.jpg"

# Defining the Colours
image_decimal = []
red_colour = bytearray([255, 0, 0])
yellow_colour = bytearray([255, 255, 0])
black_colour = bytearray([0, 0, 0])


# Defining the functions
def bintodecimal(array):
    empty_array = []
    for i in array:
        empty_array.append(int(i))

    return empty_array


def Iconvert(name, colour_1, colour_2):
    image_ppm = "{}.ppm".format(name[0:name.index(".")])
    command = "convert " + name + " " + image_ppm
    os.system(command)
    with open(image_ppm, "rb") as f:
        lines = f.readlines()
        image_size = lines[1]
        lines = lines[3:len(lines)]
        dec_lines = []
        for i in lines:
            dec_lines.extend(bintodecimal(i))
        for i in range(0, len(dec_lines), 3):
            pixel = dec_lines[i:i + 3]
            pixel = round(sum(pixel) / 3)
            image_decimal.append(pixel)
    with open("2" + image_ppm, "wb") as b:
        b.write(b"P6\n")
        b.write(image_size)
        b.write(b"255\n")
        for i in image_decimal:
            if i >= 192:
                b.write(colour_1)
            else:
                b.write(colour_2)


Iconvert(image_name, red_colour, black_colour)
