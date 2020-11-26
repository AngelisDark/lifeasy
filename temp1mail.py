import requests
import json
from bs4 import BeautifulSoup

url = 'https://www.1secmail.com/api/v1/'
email = ''

# gen mail

def genRandomMailbox():
    params = {
        'action' : 'genRandomMailbox'
    }
    r = requests.get(url, params)
    return eval(r.text)[0]


# check your mailbox

def getMessages(email):
    params = {
        'action' : 'getMessages',
        'login' : email.split('@')[0],
        'domain' : email.split('@')[1]
    }
    r = requests.get(url, params)
    print(r.text)


# check mail

def readMessage(email, mail_id):
    params = {
        'action' : 'readMessage',
        'login' : email.split('@')[0],
        'domain' : email.split('@')[1],
        'id' : mail_id
    }
    r = requests.get(url, params)
    html = json.loads(r.text)['body']
    soup = BeautifulSoup(html, features="html5lib")
    for a in soup.find_all('a', href=True):
        print("Found the URL:", a['href'])
        


def main():
    op = input('1.Generate Mail\n2.Custom Mail\nEnter Option : ')
    email = genRandomMailbox()
    if op == '2':
        email = input('Enter a name : ') + '@' + email.split('@')[1]  
    print(email)
    while True:
        input()
        getMessages(email)
        mail_id = input('\nEnter any mail id : ')
        readMessage(email, mail_id)


if __name__ == '__main__':
    main()

