
import smtplib
import time
import imaplib
import email

# -------------------------------------------------
#
# Utility to read email from Gmail Using Python
#
# ------------------------------------------------



mail = imaplib.IMAP4_SSL('imap.gmail.com')
mail.login("team5Math4300@gmail.com","Python123.")
mail.select('inbox','(UNSEEN)')
type, data = mail.search(None, '(UNSEEN)')
mail_ids = data[0]

id_list = mail_ids.split()
first_email_id = int(id_list[0])
latest_email_id = int(id_list[-1])


for i in range(latest_email_id,first_email_id, -1):
    typ, data = mail.fetch(i, '(RFC822)' )
    # Emailfile = open("emailFile.txt",'w')
    for response_part in data:
        if isinstance(response_part, tuple):
            msg = email.message_from_string(response_part[1])
            email_subject = msg['subject']
            email_from = msg['from']
            #Emailfile.write(email_subject + ", " + email_subject)
            print ('From : ' + email_from + '\n')
            print ('Subject : ' + email_subject + '\n')

    Emailfile.close()



#
# mail = imaplib.IMAP4_SSL('imap.gmail.com')
# (retcode, capabilities) = mail.login('team5Math4300@gmail.com','Python123.')
# mail.list()
# mail.select('inbox')
#
# n=0
# (retcode, messages) = mail.search(None, '(UNSEEN)')
# if retcode == 'OK':
#
#    for num in messages[0].split() :
#       print"Processing"
#       n=n+1
#       typ, data = mail.fetch(num,'(RFC822)')
#       for response_part in data:
#          if isinstance(response_part, tuple):
#              original = email.message_from_string(response_part[1])
#
#              print original['From']
#              print original['Subject']
#              typ, data = mail.store(num,'+FLAGS','\\Seen')
#
# print n
#
# import imaplib
# import email
# mail = imaplib.IMAP4_SSL('imap.gmail.com')
# mail.login('team5Math4300@gmail.com', 'Python123.')
# mail.list()
# # Out: list of "folders" aka labels in gmail.
# mail.select("inbox") # connect to inbox.
# result, data = mail.search(None, "(UNSEEN)")
#
# ids = data[0] # data is a list.
# id_list = ids.split() # ids is a space separated string
# latest_email_id = id_list[-1] # get the latest
#
# result, data = mail.fetch(latest_email_id, "(RFC822)") # fetch the email body (RFC822) for the given ID
#
# raw_email = data[0][1] # here's the body, which is raw text of the whole email
# # including headers and alternate payloads
#
# print(email_message['To'])
#
# print email.utils.parseaddr(email_message['From'])
#
# print email_message.items() # print all headers
#
# # note that if you want to get text content (body) and the email contains
# # multiple payloads (plaintext/ html), you must parse each message separately.
# # use something like the following: (taken from a stackoverflow post)
# def get_first_text_block(self, email_message_instance):
#     maintype = email_message_instance.get_content_maintype()
#     if maintype == 'multipart':
#         for part in email_message_instance.get_payload():
#             if part.get_content_maintype() == 'text':
#                 return part.get_payload()
#     elif maintype == 'text':
#         return email_message_instance.get_payload()
