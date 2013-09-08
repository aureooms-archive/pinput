from sys import argv
from pinput import parse
from sets import Set

def main():
	print parse(argv, Set(['-v', '-h', '--help']), Set([]))

if __name__ == '__main__':
	main()