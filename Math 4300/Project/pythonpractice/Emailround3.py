#!/usr/bin/env python3
# coding: utf-8
import smtplib

# For guessing MIME type
import mimetypes

# Import the email modules we'll need
from email.mime.text import MIMEText
import email
# import email.mime.application
from email.mime.multipart import MIMEMultipart
# Create a text/plain message
msg = MIMEMultipart()
msg['Subject'] = 'Attach a File'
msg['From'] = 'team5Math4300@gmail.com'
msg['To'] = 'collegexach.18@gmail.com'
#msg['Cc'] = 'linglinus@gmail.com'
recipients = []
#f = file("emailList.txt","r")
filename = "emailList.txt"
filename = "/home/zach/Desktop/Math 4300/Project/pythonpractice/dist/hello/hello"

with open(filename, "r") as txt:
    for line in txt:
        recipients.append(line)
        #new line
        ",".join(recipients)
        #print lineemail.mime.application.email.mime.application.
    #print("Program ran")
# The main body is just another attachment
body = MIMEText(""Body"")
msg.attach(body)

# PDF attachment
filename='smptTest.py'
fp=open(filename,'rb')
att = MIMEApplication(fp.read(),_subtype="py")

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
