import smtplib
import time
import imaplib
import email
#import Parser from email.parser


mail = imaplib.IMAP4_SSL("imap.gmail.com")
mail.login("team5Math4300@gmail.com","Python123.")
mail.select("inbox")
SMTP = 993


type , data = mail.search(None, "(UNSEEN)")
mail_ids = data[0]

id_list = mail_ids.split()
first_email_id = int(id_list[0])
latest_email_id = int(id_list[-1])


for i in range(latest_email_id,first_email_id, -1):
    typ, data = mail.fetch(i, '(RFC822)' )

for response_part in data:
    if isinstance(response_part, tuple):
        msg = email.message_from_string(response_part[1])
        email_subject = msg['subject']
        email_from = msg['from']
        writeToFile = email_subject + ", " + email_from
        print ('From : ' + email_from + '\n')
        print ('Subject : ' + email_subject + '\n')
        print('Writing to File: ' + writeToFile + '\n')
        f = open("emailList.txt","a")
        f.write(writeToFile)
        f.close()
        #print(email_msg)
        #print(msg)
print("Email read")
