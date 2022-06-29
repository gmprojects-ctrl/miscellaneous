import numpy as np
import pandas as pd


class StoOneWord:
    def __init__(self, pathtotext):
        self.text = self.genfiltertext(pathtotext)
        self.uniw = np.unique(self.text)
        self.Sto = self.onegramSto()

    def genfiltertext(self, pathtotext):
        with open(pathtotext, "r") as file:
            textfile = "".join(
                i for i in file.read() if not i.isdigit()
            )  # Removes any Digits
            textfile = "".join(
                i for i in textfile if i.isalpha() or i.isspace()
            )  # Removes any Spaces
        textfile = textfile.lower()  # Makes everything lower case
        textfile = textfile.split()  # Converts into a list
        return textfile

    def onegramSto(self):
        uniw = self.uniw  # Finds the unique words in the text
        stm = pd.DataFrame(
            np.zeros((uniw.shape[0], uniw.shape[0])), index=uniw, columns=uniw
        )
        # Creates a DataFrame in Pandas with the unique words  as column and row names.
        # For loop below goes through text an calculating the relative frequency
        # between seeing one word and another word right afer
        for i, word in enumerate(self.text[:-1]):
            stm[word][self.text[i + 1]] += 1
            # Note by nature of indexing the datafame (pandas indexes the column first and row second)
            # the matrix given by stm is the transpose
        stm = stm.div(stm.sum(axis=0))  # Divide the coulmn by its sum
        stm = stm.fillna(0)  # Fill any Nan with 0
        return stm  # Return StochasticMatrix

    def gentext(self, firstword, limit):
        firstword = firstword.lower()  # Converts the letters to lower case
        if firstword not in self.uniw:  # Checks if word is in self.unie
            raise KeyError("Word not in text")
        else:
            sentence = [firstword]  # Adds the first word on to the list
            for i in range(1, limit):
                nextword = np.random.choice(
                    self.uniw, p=self.Sto[sentence[i - 1]]
                )  # Probability using the Stochastic Matrix (Note self.Sto is the transpose)
                sentence.append(nextword)
            return " ".join(sentence)  # Returns the generated Text


X = StoOneWord("../NewTest/newtest.txt")
print(X.gentext("Jesus", 10))
