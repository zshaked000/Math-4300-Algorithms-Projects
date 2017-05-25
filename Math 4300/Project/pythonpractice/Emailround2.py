#Email Round 2
import smtplib
from email import encoders
from email.message import Message
from email.mime.audio import MIMEAudio
from email.mime.base import MIMEBase
from email.mime.image import MIMEImage
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
msg = MIMEMultipart()
msg.attach(MIMEText(file("Test.txt").read()))



sender = 'team5Math4300@gmail.@gmail.com'
reciever  = 'collegexach@gmail.com'

# ***here don't overwrite the MIMEMultipart() obj***
# msg = 'Hello'


# Credentials (if needed)
username = 'team5Math4300'
password = 'Python123.'

# The actual mail send
server = smtplib.SMTP('smtp.gmail.com', 587)  
server.starttls()
server.login(username,password)

# ***here msg.as_string() to convert the MIMEMultipart() obj to a string***
server.sendmail(sender, reciever, msg.as_string())

server.quit()
