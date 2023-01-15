import sys
from notebook import Note, Notebook

class Menu:
  def __init__(self):
    self.nootbook = Notebook()
    ''' choices is a dictionary of string and any function '''
    self.choices = {
      "1" : self.show_notes,
      "2" : self.search_notes,
      "3" : self.add_note,
      "4" : self.modify_note,
      "5" : self.quit
    }

  def display_menu(self):
    print("""
    Notebook Menu
    1. Show all notes
    2. Search notes
    3. Add notes
    4. Modify notes
    5. Quit
    """)

  def run(self):
    while True:
      self.display_menu()
      choice = input("Enter an option: ")
      action = self.choices.get(choice)
      if action:
        action()
      else:
        print("{0} is not a valid choice".format(choice))
    pass

  def show_notes(self, notes=None):
    if not notes:
      notes = self.nootbook.notes
    for note in notes:
      print("ID {0}: memo '{1}' , tags '{2}'".format(note.id, note.tags, note.memo))

  def search_notes(self):
    filter = input("Search for: ")
    notes = self.nootbook.search(filter)
    self.show_notes(notes)

  def add_note(self):
    memo = input("Enter a memo: ")
    self.nootbook.new_note(memo)
    print("Your note is added")

  def modify_note(self):
    id = input("Enter a note id: ")
    memo = input("Enter a memo: ")
    tags = input("Enter tags: ")
    if memo:
      self.nootbook.modify_memo(id, memo)
    if tags:
      self.nootbook.modify_tags(id, tags)

  def quit(self):
    print("Thanks for using notebook today")
    sys.exit(0)

if __name__ == "__main__":
  Menu().run()
