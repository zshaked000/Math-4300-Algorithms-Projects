with open(filename, "r") as txt:
    for line in txt:
        recipients.append(line)
        #new line
        ",".join(recipients)
        print(recipients)
