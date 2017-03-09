import nltk

class Analyzer():
    """Implements sentiment analysis."""

    def __init__(self, positives, negatives):
        """Initialize Analyzer."""
        self.positive=set()
        self.negative=set()
        self.count=0
        with open(positives,"r") as file:
            for line in file:

                if not (line[0] ==";" or line[0]==" "):
                    self.positive.add(line.rstrip("\n"))

        with open(negatives,"r") as file1:
            for line in file1:
                if not (line[0] == ";" or line[0] == " "):
                    self.negative.add(line.rstrip("\n"))
        # TODO

    def analyze(self, text):
        """Analyze text for sentiment, returning its score."""
        #text=text.lower()
        if text in self.positive:
            self.count=self.count+1
        elif text in self.negative:
            self.count=self.count-1

        return self.count
        # TODO

