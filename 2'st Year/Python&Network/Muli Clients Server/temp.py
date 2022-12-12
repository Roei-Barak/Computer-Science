import os

ROOT_DIR =r'C:\Networks\webroot'

def get_file_data(filename):
    """ Get data from file """
    filename = filename.replace('/', '\\')
    name = ROOT_DIR + '\\' + filename
    if os.path.isfile(name) is True:
        file = open(filename, 'rb')
        data = file.read()
        return data
    return

get_file_data('index.html')