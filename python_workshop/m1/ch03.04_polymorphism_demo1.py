class AudioFile:
    def __init__(self, filename):
        if not filename.endswith(self.ext):
            raise Exception("Invalid file format")
        self.filename = filename


class MP3File(AudioFile):
    ext = "mp3"
    def play(self):
        print("playing {} as mp3".format(self.filename))

class WavFile(AudioFile):
    ext = "wav"
    def play(self):
        print("playing {} as wav".format(self.filename))


class OggFile(AudioFile):
    ext = "ogg"
    def play(self):
        print("playing {} as ogg".format(self.filename))


''' duck typing classL no inheritance from super class '''
class FlacFile:
    def __init__(self, filename):
        if not filename.endswith(".flac"):
            raise Exception("Invalid file format")
        self.filename = filename

    def play(self):
        print("playing {} as flac".format(self.filename))


def testfunction():
    ogg = OggFile("test.ogg")
    ogg.play()
    flac = FlacFile("olala.flac")
    flac.play()


if __name__ == '__main__':
    testfunction()