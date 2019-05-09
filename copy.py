import sys
import pyperclip
path="labexam/"+sys.argv[1]+".cpp"
try:
	fo = open(path, 'r').read()
	pyperclip.copy(fo)
except:
	print("File not found")