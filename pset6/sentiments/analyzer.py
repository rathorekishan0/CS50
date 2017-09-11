import nltk

class Analyzer():
    """Implements sentiment analysis."""

    def __init__(self, positives, negatives):
        """Initialize Analyzer."""
        self.p=set()
        self.n=set()
        file=open(positives,"r")
        for i in file:
            if i[0]!=';':
                self.p.add(i.rstrip('\n'))
        file.close()
        file=open(negatives,"r")
        for i in file:
            if i[0]!=';':
                self.n.add(i.rstrip('\n'))
        file.close()
        # TODO

    def analyze(self, text):
        """Analyze text for sentiment, returning its score."""
        tokenizer = nltk.tokenize.TweetTokenizer()
        w = tokenizer.tokenize(text)
        self.c = 0
        for i in w:
            if i.lower() in self.p:
                self.c += 1
            elif i.lower() in self.n:
                self.c -= 1
            else:
                continue
        if self.c>0:
            self.c=1
        elif self.c<0:
            self.c=-1
        else:self.c=0
        return self.c