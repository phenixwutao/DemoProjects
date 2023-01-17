
class ContactList(list):
    def search(self, name):
        matching_contacts = []
        for contact in self:
            if name in contact.name:
                matching_contacts.append(contact)
        return matching_contacts


class Contact:
    all_contacts = ContactList()  # class variable: list of contact shared by all instances

    def __init__(self, name, email):
        self.name = name
        self.email = email
        Contact.all_contacts.append(self)


class Friend(Contact):
    def __init__(self, name, email, phone):
        super().__init__(name, email)
        self.phone = phone


if __name__ == "__main__":
  c1 = Contact("John A", "johna@example.net")
  c2 = Contact("John B", "johnb@example.net")
  c3 = Contact("Jenna C", "jennac@example.net")
  print([c.name for c in Contact.all_contacts.search('John')])
