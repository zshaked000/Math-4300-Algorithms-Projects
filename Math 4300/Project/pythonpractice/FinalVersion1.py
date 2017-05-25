#!/usr/bin/env python3

from appJar import gui
import smtplib
from smtplib import SMTP
import mimetypes
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
from email.mime.image import MIMEImage
from email.mime.application import MIMEApplication
from email.message import Message
EmailLogin = ""
EmailPW = ""
# function called by pressing the buttons
def press(btn):

    msg = MIMEMultipart('alternative')

    if btn=="Cancel":
        app.stop()
    else:
        Username = app.getEntry('user')
        password = app.getEntry('pass')
    #    print("User:", app.getEntry('user'), "Pass:", app.getEntry("pass"))
        app.stop()
        # print("It works " + Username)
        # print("Pw: is " + password)
        EmailLogin = Username
        EmailPW = password
        fileName = "emailList.txt"
        # EmailLogin = "team5Math4300@gmail.com"
        # EmailPW = "Python123."
    with open(fileName,"rb") as fp:
        att = MIMEApplication(fp.read(),_subtype="txt")
        fp.close()
        att.add_header('Content-Disposition','attachment',filename=fileName)
        msg.attach(att)

    # Send the message via local SMTP server.
    try:


        recipients = []
        lst = []
        namelist = []
        with open("emailList.txt", "r") as txt:
            for line in txt:
                #recipients.append(line)
                lst.append(line.rstrip())
            for i in lst:
                i = i.strip().split(",")
                namelist.append(i[0].replace("'",""))
                recipients.append(i[1])

        me = "team5Math4300@gmail.com"
        you = me

        for x in range(len(recipients)):
            # Create message container - the correct MIME type is multipart/alternative.
            msg = MIMEMultipart('alternative')
            msg['Subject'] = "TEAM 5 PROJECT"
            msg['From'] = me
            msg['To'] = you

            fp = open('Zach.jpg','rb')
            msgImage = MIMEImage(fp.read())
            fp.close()
            msgImage.add_header('Content-ID', '<image1>')
            msg.attach(msgImage)

            fp = open('Linus.jpg','rb')
            msgImage = MIMEImage(fp.read())
            fp.close()
            msgImage.add_header('Content-ID', '<image2>')
            msg.attach(msgImage)

            fp = open('Ivana.jpg','rb')
            msgImage = MIMEImage(fp.read())
            fp.close()
            msgImage.add_header('Content-ID', '<image3>')
            msg.attach(msgImage)

            usrnme = namelist[x]
            name = recipients[x]

            # Create the body of the message (a plain-text and an HTML version).
            text = "Hi!\nHow are you?\nHere is the link you wanted:\nhttps://www.python.org"
            html = """\
            <html>
              <head>
                <style>
                body:hover{
                background-color:#FF0000;
                }
                a:hover{
                font-size: 100px;
                }
                p:hover{
                font-size: 25px;
                }
                </style>
              </head>
              <body>
                <p>Hi! %s, <br>
                    How are you?<br>
                    CLICK <a href = "https://www.google.com" >THIS</a> TO GET INCREDIBLE SAVINGS <br>
                    <div>
                    <img src= "cid:image1">
                    <p id = "Zach">Hi my name is Zach, I'm a junior and I major in Math
                    <br>Fun Fact: I am Fun
                    </p>
                    </div>
                    <div>
                    <img src = "cid:image2">
                    <p id = "Linus">Hi my name is Linus, I'm a senior and I major in Accounting
                    <br>Fun Fact: I was born on Christmas
                    </p>
                    </div>
                    <div>
                    <img style = "width:200px;height:200px;" src = "cid:image3">
                    <p id = "Becky">Hi my name is Becky, I'm a senior and I major in Finance <br>
                    Fun Fact: The picture is not me
                    </p>
                    </div>
                </p>
              </body>
            </html>
            """%(usrnme)

            # Record the MIME types of both parts - text/plain and text/html.
            part1 = MIMEText(text, 'plain')
            part2 = MIMEText(html, 'html')


            attName = "emailList.txt"
            with open(attName,"r") as fp:
                att = MIMEApplication(fp.read(),_subtype="txt")
                fp.close()
                att.add_header('Content-Disposition','attachment',filename=attName)
                msg.attach(att)
                        #######################################################################
            # Attach parts into message container.
            # According to RFC 2046, the last part of a multipart message, in this case
            # the HTML message, is best and preferred.
            msg.attach(part1)
            msg.attach(part2)
            #Attach File
            #EmailLogin = "team5Math4300@gmail.com"; EmailPW = "Python123."
            #s = smtplib.SMTP('smtp.gmail.com',587)
            s = smtplib.SMTP_SSL('smtp.gmail.com',465)
            #s.starttls()
            s.ehlo()
            s.login("team5Math4300@gmail.com","Python123.")
            #s.login(EmailLogin,EmailPW)
            print("Sent To: " ,usrnme)

            s.sendmail(me, name, msg.as_string())

                    #new line
                    #",".join(recipients)

##################################################################

        s.quit()
        print("Emails sent")
    except:
        print("Something went wrong")


app=gui("Team 5", "350x200")
app.addLabel("title", "Login With Your Gmail", 0, 0, 2)  # Row 0,Column 0,Span 2
app.addLabel("user", "Username:", 1, 0)              # Row 1,Column 0
app.addEntry("user", 1, 1)                           # Row 1,Column 1
app.addLabel("pass", "Password:", 2, 0)              # Row 2,Column 0
app.addSecretEntry("pass", 2, 1)                     # Row 2,Column 1
app.addButtons(["Submit", "Cancel"], press, 3, 0, 2) # Row 3,Column 0,Span 2

app.setEntryFocus("user")

app.go()