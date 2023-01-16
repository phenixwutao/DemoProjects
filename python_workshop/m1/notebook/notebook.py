import datetime

# store the next available id for all new notes
last_id = 0

class Note:
  def __init__(self, memo, tags=''):
    self.memo = memo
    self.tags = tags
    self.creation_date = datetime.date.today()
    global last_id
    last_id += 1
    self.id = last_id
    pass

  def match(self, filter):
    ''' filter match is based on case sensitive searching, match noth memo text and tags'''
    return filter in self.memo or filter in self.tags
    pass

class Notebook:
  ''' Notebook class manage a list of Notes'''
  def __init__(self):
    self.notes = []
    pass

  def new_note(self, memo, tags=''):
    self.notes.append(Note(memo, tags))
    pass

  def _find_note(self, note_id):
      for note in self.notes:
        print(note.id, note_id)
        if str(note.id) == str(note_id):
          return note
      return None

  def modify_memo(self, note_id, memo):
      note = self._find_note(note_id)
      if note:
        note.memo = memo
        return True
      return False

  def modify_tags(self, note_id, tags):
      note = self._find_note(note_id)
      if note:
        note.tags = tags
        return True
      return False

  def search(self, filter):
    return [note for note in self.notes if note.match(filter)]

def testnote():
  print("--------- test Note class ---------")
  n1 = Note("hello first")
  n2 = Note("hello again")
  print(n1.match('hello'))
  print(n2.match('second'))
  pass

def testnotebook():
  print("--------- test Notebook class ---------")
  notebook = Notebook()
  notebook.new_note("hello world")
  notebook.new_note("hello again")
  print(notebook.notes)
  print(notebook.search('hello'))
  notebook.modify_memo(3, "hi world")
  print(notebook.notes[0].id, notebook.notes[0].memo)
  print(notebook.notes[1].id, notebook.notes[1].memo)
  pass


if __name__ == '__main__':
  testnote()
  testnotebook()

