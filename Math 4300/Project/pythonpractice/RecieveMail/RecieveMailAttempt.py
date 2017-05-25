import smtplib
import time
import imaplib
import email


mail = imaplib.IMAP4_SSL("imap.gmail.com")
mail.login("team5Math4300","Python123.")
mail.select("inbox")

type, data = mail.search(None,'(UNSEEN)')
print(type)
print(data)
print(mail.search(None,'ALL'))
mail_ids = data[0]
print(mail_ids)


id_list = mail_ids.split()
print(id_list)
first_email_id = int(id_list[0])
latest_email_id = int(id_list[-1])
print first_email_id
print latest_email_id

for i in range(latest_email_id,first_email_id,-1):
    typ, data = mail.fetch(i, '(RFC822)' )

    for response_part in data
          if isinstance(response_part, tuple):
              msg = email.message_from_string(response_part[1])
              email_subject = msg['subject']
              email_from = msg['from']
              email_body = msg['body']
              print 'From : ' + email_from + '\n'
              print 'Subject : ' + email_subject + '\n'
              print 'Body : ' + email_body + '\n'

print("Program ran sucess")
