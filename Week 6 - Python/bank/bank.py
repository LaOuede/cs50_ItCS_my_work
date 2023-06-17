text = input("Greeting: ")
text = text.strip()
text = text.capitalize()

if text.split()[0] == "Hello" or text.split()[0] == "Hello,":
    print("$0", end="")
elif text.split()[0] != "Hello" and text[0] == 'H':
    print("$20", end="")
else:
    print("$100", end="")