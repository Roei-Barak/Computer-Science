def validate_url(url):
    url_split = url.split('.')
    if url_split[0] != 'www':
        return False
    if url_split[1] == '':
        return False
    if url_split[2] == 'com' or (url_split[2] == 'co' and url_split[3] == 'il'):
        return True
    return False
import validators

valid=validators.url('https://www.codespeedy.com/')
valid =validators.url('https://www.go.com/')
valid=validators.url('https://www.=.com/')


s = 'www.go.com'
if validate_url(s) is True:
    print('ok0')
spl = s.split('.')
if spl[0] == 'www':
    print("OK1")
if spl[1].isascii():
    print("OK2")
if spl[2] == 'com':
    print("OK3")