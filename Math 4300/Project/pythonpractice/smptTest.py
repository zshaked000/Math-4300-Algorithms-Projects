# import smtplib
# server = smtplib.SMTP('smtp.gmail.com', 587)
# server.ehlo()
# server.starttls()
# server.ehlo()
# server.login("team5Math4300@gmail.com  ","Python123.")
# msg = "\nHello!" # The /n separates the message from the headers (which we ignore for this example)
# server.sendmail("team5Math4300@gmail.com", "team5Math4300@gmail.com", msg)
# print("Program run sucess")

#Output Input test
# print("Enter some text")
# userInput = raw_input('What is your name?')
# print( "you input: " + userInput)

#Working with files
# n = "10"
# print("Program is running")
# f = file("Test.txt", "r")
# for line in f:
#     print line[]
#     f.close()
#
#
# with open("Test.txt", "r") as txt:
#     for line in txt:
#         print line
#     print("Program ran")

# import smtplib
# from email.mime.text import MIMEText
#
# server = smtplib.SMTP('smtp.gmail.com', 587)
#
# msg = MIMEText("""body""")
# sender = 'me@example.com'
# recipients = ['john.doe@example.com', 'john.smith@example.co.uk']
# msg['Subject'] = "subject line"
# msg['From'] = sender
# msg['To'] = ", ".join(recipients)
# s.sendmail(sender, recipients, msg.as_string())




#Eamil reading files
###########################################################################
# import smtplib
# from email.mime.text import MIMEText
# server = smtplib.SMTP('smtp.gmail.com', 587)
# server.ehlo()
# server.starttls()
# server.ehlo()
# server.login("team5Math4300@gmail.com  ","Python123.")
# msg = MIMEText("""body""")
# sender = 'team5Math4300@gmail.com'
# ##msg = "\nHello!" # The /n separates the message from the headers (which we ignore for this example)
# recipients = []
# f = file("emailList.txt","r")
# with open("emailList.txt", "r") as txt:
#     for line in txt:
#         recipients.append(line)
#         #print line
#     print("Program ran")
#
# msg['Subject'] = "Email From File "
# msg['From'] = sender
# msg['To'] = ", ".join(recipients)
# server.sendmail("team5Math4300@gmail.com", recipients, msg.as_string())
# print("Program run sucess")
# server.quit()




##############################################################################
# #BCC and CC
# import smtplib
# from email.MIMEMultipart import MIMEMultipart
# from email.MIMEText import MIMEText
# from email.MIMEBase import MIMEBase
# from email import encodersserver = smtplib.SMTP('smtp.gmail.com', 587)
# server = smtplib.SMTP('smtp.gmail.com', 587)
# server.ehlo()
# server.starttls()
# server.ehlo()
# server.login("team5Math4300@gmail.com  ","Python123.")
# msg = MIMEText("""body""")
# sender = 'team5Math4300@gmail.com'
# ##msg = "\nHello!" # The /n separates the message from the headers (which we ignore for this example)
# recipients = []
# f = file("emailList.txt","r")
# with open("emailList.txt", "r") as txt:
#     for line in txt:
#         recipients.append(line)
#         #print line
#     print("Program ran")
#
# msg['Subject'] = "Email From File "
# msg['From'] = sender
# msg['To'] = recipients[0]
# msg['Cc'] = recipients[1]
# msg['BCC'] = recipients[2]
#
# server.sendmail("team5Math4300@gmail.com", recipients, msg.as_string())
# print("Program run sucess")
# server.quit()




#Here is an example of a message with a PDF attachment, a text "body" and sending via Gmail.

# Import smtplib for the actual sending function
#!/usr/bin/env python3
# coding: utf-8
import smtplib

# For guessing MIME type
import mimetypes

# Import the email modules we'll need
import email.mime.text
import email
import email.mime.application

# Create a text/plain message
msg = email.mime.multipart.MIMEMultipart()
msg['Subject'] = 'Attach a File'
msg['From'] = 'team5Math4300@gmail.com'
msg['To'] = 'collegexach.18@gmail.com'
#msg['Cc'] = 'linglinus@gmail.com'
recipients = []
f = file("emailList.txt","r")
with open("emailList.txt", "r") as txt:
    for line in txt:
        recipients.append(line)
        #new line
        ",".join(recipients)
        #print line
    #print("Program ran")
# The main body is just another attachment
body = email.mime.Text.MIMEText("""Body""")
msg.attach(body)

# PDF attachment
filename='smptTest.py'
fp=open(filename,'rb')
att = email.mime.application.MIMEApplication(fp.read(),_subtype="py")
fp.close()
att.add_header('Content-Disposition','attachment',filename=filename)
msg.attach(att)

# send via Gmail server
# NOTE: my ISP, Centurylink, seems to be automatically rewriting
# port 25 packets to be port 587 and it is trashing port 587 packets.
# So, I use the default port 25, but I authenticate.
s = smtplib.SMTP('smtp.gmail.com', 587)
s.starttls()
s.login("team5Math4300@gmail.com  ","Python123.")
s.sendmail('team5Math4300@gmail.com ', recipients, msg.as_string())
print("Program ran")
s.quit()
