import json

class DialogController:
  def __init__(self, file):
    self.file = file
    self.access = open(self.file)
    self.data = self.access.readlines()
    self.num = 0
    self.max = sum(1 for line in open('text.json')) - 1

  def get_dialog(self):
    x = open(self.file)
    return x.readlines()
  
  def next(self):
    self.num += 1
    return json.loads(self.data[self.num])
  
  def jump(self, point):
    self.num = point
    return json.loads(self.data[point])
  
  def options(self, num):
    the_options = []
    y = json.loads(self.data[num])
    for i in y['line']:
      temp = json.loads(self.data[i-1])
      the_options.append(temp['text'])
    return the_options

  def has_next(self):
    return (self.num < self.max)

  def waiting(self):
    y = json.loads(self.data[self.num])
    return (type(y['line']) == list)

text = DialogController('text.json')
print(text.next())
print(text.next())
text.num = 5
print(text.waiting())