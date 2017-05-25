#
# import smtplib
# import time
# # -------------------------------------------------
# #
# # Utility to read email from Gmail Using Python
# #
# # ------------------------------------------------
#
#
# import imaplib
# import email
#
# mail = imaplib.IMAP4_SSL(SMTP_SERVER)
# mail.login(FROM_EMAIL,FROM_PWD)
# mail.select('inbox')
#
# type, data = mail.search(None, 'ALL')
# mail_ids = data[0]
#
# id_list = mail_ids.split()
# first_email_id = int(id_list[0])
# latest_email_id = int(id_list[-1])
#
#
# for i in range(latest_email_id,first_email_id, -1):
#     typ, data = mail.fetch(i, '(RFC822)' )
#
# for response_part in data:
#     if isinstance(response_part, tuple):
#         msg = email.message_from_string(response_part[1])
#         email_subject = msg['subject']
#         email_from = msg['from']
#         print ('From : ' + email_from + '\n')
#         print ('Subject : ' + email_subject + '\n')
#         print("Program ran")

############################################################################
############################################################################
import smtplib
import time
import imaplib
import email

# -------------------------------------------------
#
# Utility to read email from Gmail Using Python
#
# ------------------------------------------------
ORG_EMAIL   = "@gmail.com"
FROM_EMAIL  = "team5Math4300" + ORG_EMAIL
FROM_PWD    = "Python123."
SMTP_SERVER = "imap.gmail.com"
SMTP_PORT   = 993

mail = imaplib.IMAP4_SSL(SMTP_SERVER)
mail.login(FROM_EMAIL,FROM_PWD)
mail.select('inbox')

type, data = mail.search(None, 'INBOX')
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
            print ('From : ' + email_from + '\n')
            print ('Subject : ' + email_subject + '\n')
            print("Sucess")
    # except Exception, e:
    #     print str(e)
#
#
# read_email_from_gmail(
#
# username  = "team5Math4300"
# password    = "Python123."
#
#     # Login to INBOX
# imap = imaplib.IMAP4_SSL("imap.gmail.com", 993)
# imap.login(username, password)
# imap.select('INBOX')
#
#     # Use search(), not status()
# status, response = imap.search(None, 'INBOX', '(UNSEEN)')
# unread_msg_nums = response[0].split()
#
#     # Print the count of all unread messages
# print len(unread_msg_nums)
#
#     # Print all unread messages from a certain sender of interest
# status, response = imap.search(None, '(UNSEEN)')
# unread_msg_nums = response[0].split()
# da = []
# for e_id in unread_msg_nums:
#     _, response = imap.fetch(e_id, '(UID BODY[TEXT])')
#     da.append(response[0][1])
# print da
#
#     # Mark them as seen
# for e_id in unread_msg_nums:
#     imap.store(e_id, '+FLAGS', '\Seen'
