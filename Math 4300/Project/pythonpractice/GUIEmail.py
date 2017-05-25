#!/usr/bin/env python3

from appJar import gui
import smtplib
import mimetypes
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
from email.mime.application import MIMEApplication
from email.message import Message
EmailLogin = ""
EmailPW = ""
# function called by pressing the buttons
def press(btn):
#!/usr/bin/env python3


    # me == my email address
    # you == recipient's email address
    me = "team5Math4300@gmail.com"
    you = me

    # Create message container - the correct MIME type is multipart/alternative.
    msg = MIMEMultipart('alternative')
    msg['Subject'] = "HTML Formatted"
    msg['From'] = me
    msg['To'] = you

    # Create the body of the message (a plain-text and an HTML version).
    text = "Hi!\nHow are you?\nHere is the link you wanted:\nhttps://www.python.org"
    html = """\
    <html>
      <head>
        <style>
        body{
        background-color: blue;
        }
        </style>
      </head>
      <body style="color:blue;">
        <p>Hi!<br>
           How are you?<br>
           Here is the <a href="file:///home/zach/Desktop/Test.txt">link</a> you wanted.
           here is another link <a href="file://home/zach/Desktop/Test.txt">Download link</a>
        </p>
        <form method="get" action="Test.txt">
        <button type="submit">Download!</button>
        <button type="submit" onclick="window.open('Test.txt')">File Download!</button>
        <button><a href = "file:///home/zach/Desktop/Test.txt" download>Click to Download!</a></button>
        </form>
      </body>
    </html>
    """

    # Record the MIME types of both parts - text/plain and text/html.
    part1 = MIMEText(text, 'plain')
    part2 = MIMEText(html, 'html')

    # Attach parts into message container.
    # According to RFC 2046, the last part of a multipart message, in this case
    # the HTML message, is best and preferred.
    msg.attach(part1)
    msg.attach(part2)
    fileName = "Test.txt"
    fileName = '/home/zach/Desktop/Math 4300/Project/pythonpractice/dist/hello/hello'




    if btn=="Cancel":
        app.stop()
    else:
        Username = app.getEntry('user')
        password = app.getEntry('pass')
    #    print("User:", app.getEntry('user'), "Pass:", app.getEntry("pass"))
        app.stop()
        print("It works " + Username)
        print("Pw: is " + password)
        # EmailLogin = Username
        # EmailPW = password
        EmailLogin = "team5Math4300@gmail.com"
        EmailPW = "Python123."
    with open(fileName,"rb") as fp:
        att = MIMEApplication(fp.read(),_subtype="txt")
        fp.close()
        att.add_header('Content-Disposition','attachment',filename=fileName)
        msg.attach(att)

    # Send the message via local SMTP server.
    try:
        s = smtplib.SMTP('smtp.gmail.com', 587)
        s.starttls()
        s.login(EmailLogin,EmailPW)

        #s.login("team5Math4300@gmail.com  ","Python123.")
        # sendmail function takes 3 arguments: sender's address, recipient's address
        # and message to send - here it is sent as one string.
        s.sendmail(me, you, msg.as_string())
        s.quit()
        print("Email sent")
    except:
        print("Something went wrong")
app = gui()

app.addLabel("title", "Welcome to appJar", 0, 0, 2)  # Row 0,Column 0,Span 2
app.addLabel("user", "Username:", 1, 0)              # Row 1,Column 0
app.addEntry("user", 1, 1)                           # Row 1,Column 1
app.addLabel("pass", "Password:", 2, 0)              # Row 2,Column 0
app.addSecretEntry("pass", 2, 1)                     # Row 2,Column 1
app.addButtons(["Submit", "Cancel"], press, 3, 0, 2) # Row 3,Column 0,Span 2

app.setEntryFocus("user")

app.go()
