#!/usr/bin/env python
#
# Very basic example of using Python and IMAP to iterate over emails in a
# gmail folder/label.  This code is released into the public domain.
#
# RKI July 2013
# http://www.voidynullness.net/blog/2013/07/25/gmail-email-with-python-via-imap/
#
import sys
import imaplib
import getpass
import email
import email.header
import datetime

EMAIL_ACCOUNT = "team5Math4300@gmail.com"
EMAIL_FOLDER = "inbox"


def process_mailbox(M):
    """
    Do something with emails messages in the folder.
    For the sake of this example, print some headers.
    """

    rv, data = M.search(None, "(UNSEEN)")
    if rv != 'OK':
        print "No messages found!"
        return

    for num in data[0].split():
        rv, data = M.fetch(num, '(RFC822)')
        if rv != 'OK':
            print "ERROR getting message", num
            return

        msg = email.message_from_string(data[0][1])
        decode = email.header.decode_header(msg['Subject'])[0]
        subject = unicode(decode[0])
        #print 'Message %s: %s' % (num, subject)
        print 'From:', msg['From']
        print 'Subject' , msg['Subject']
        # Now convert to local date-time


M = imaplib.IMAP4_SSL('imap.gmail.com')

#try:
rv, data = M.login(EMAIL_ACCOUNT,"Python123.")
# except imaplib.IMAP4.error:
#     print "LOGIN FAILED!!! "
#     sys.exit(1)
#
# print rv, data
#
# rv, mailboxes = M.list()
# if rv == 'OK':
#     print "Mailboxes:"
#     print mailboxes
#
# rv, data = M.select(EMAIL_FOLDER)
# if rv == 'OK':
#     print "Processing mailbox...\n"
#     process_mailbox(M)
#     M.close()
# else:
#     print "ERROR: Unable to open mailbox ", rv

M.logout()
#
# import imaplib
# mail = imaplib.IMAP4_SSL('imap.gmail.com')
# mail.login('team5Math4300@gmail.com', 'Python123.')
# mail.list()
# # Out: list of "folders" aka labels in gmail.
# mail.select("inbox") # connect to inbox.
#
# result, data = mail.search(None, "(UNSEEN)")
#
# ids = data[0] # data is a list.
# id_list = ids.split() # ids is a space separated string
# latest_email_id = id_list[-1] # get the latest
#
# result, data = mail.uid('search', None, "(UNSEEN)") # search and return uids instead
# latest_email_uid = data[0].split()[-1]
# result, data = mail.uid('fetch', latest_email_uid, '(RFC822)')
# raw_email = data[0][1]
#
#
# ######################################################
# import email
# email_message = email.message_from_string(raw_email)
#
# # print "To: " + email_message['To'] + '\n'
# #
# # print email.utils.parseaddr(email_message['From']) # for parsing "Yuji Tomita" <yuji@grovemade.com>
#
# print "From: "  + email_message['From'] + '\n'
# print "Subject: " + email_message['Subject'] + '\n'
