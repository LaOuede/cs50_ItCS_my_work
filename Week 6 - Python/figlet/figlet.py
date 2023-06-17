from pyfiglet import Figlet
import sys, random

figlet = Figlet()

len = len(sys.argv)

if len == 1:
    str = input("Input : ")
    font = random.choice(figlet.getFonts())
    figlet.setFont(font=font)
    print(f"output:{figlet.renderText(str)}")
elif len == 3:
    f = sys.argv[1]
    if ((f == "-f" or f == "--font")):
        if sys.argv[2] in figlet.getFonts():
            str = input("Input : ")
            figlet.setFont(font=sys.argv[2])
            print(f"output:{figlet.renderText(str)}")
        else:
            print("Invalid usage")
            sys.exit(1)
    else:
       print("Invalid usage")
       sys.exit(1)
else:
    print("Invalid usage")
    sys.exit(1)

# List of fonts :
# http://www.figlet.org/examples.html