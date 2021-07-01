import hashlib

# Checking if the py is not a executing as a main function
if __name__=="__main__":
    exit("This is library module")
else:
    pass

# Function definitons
def checkhash(name, hash_item):
    with open(name,"r") as f:
        for line in f:
            if line.rstrip() == hash_item:
                return True
    return False

def writehash(name,item):
    item_bytes = bytearray(item,"utf-8")
    hash_item = hashlib.sha512(item_bytes).hexdigest()
    try:
        with open(name,"a") as f:
            f.write(hash_item+"\n")
    except FileNotFoundError:
        print("File not found")


