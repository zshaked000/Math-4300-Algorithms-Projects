#chmod u+x testing.py
#!#########
#./ testing.py

# python3 testing.py

import smtplib

gmail_user = 'team5math4300'
gmail_password = 'Python123.'
bcc = ['collegexach.18@gmail.com']
sent_from = gmail_user
to = ['beckylaw2318@gmail.com']
cc = ['biying.luo@baruchmail.cuny.edu','linglinus@gmail.com']

subject = 'Testing from Becky'
body = 'Hello!\n\n\n\n    How are you?'

email_text = """\
From: %s
To: %s
Cc: %s
Subject: %s

%s
""" % (sent_from,", ".join(to),", ".join(cc),subject,body)
# ", ".join(to) means adding the "," between each receipients on
# the to list.
# "_".join(to) means: 1_2_3_4_......etc.

# everyone can see the body part """ xxxxx""" above,
# see from, to , cc, subject, but no bcc.

try:
	server = smtplib.SMTP_SSL('smtp.gmail.com',465)
	server.ehlo
	server.starttls
	server.login(gmail_user,gmail_password)
	server.sendmail(sent_from,to+cc+bcc,email_text)
	server.close()
	#...send emails
	print('Email sent!')
	# to+cc+bcc includes the actual recipients, which means the bcc
	# people can still receive the emails, but to people and cc people
	# cannot see bcc receipients' emails shown on the email list.
except:
	print ('Something went wrong...')
