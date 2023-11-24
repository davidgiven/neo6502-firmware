# *******************************************************************************************
# *******************************************************************************************
#
#		Name : 		token_code.py
#		Purpose :	Generate token tables.
#		Date :		24th November 2023
#		Author : 	Paul Robson (paul@robsons.org.uk)
#
# *******************************************************************************************
# *******************************************************************************************

from tokens import *
import sys 

#
#		Make name suitable for assembler
#
def textProcess(k):
	k = k.replace("+","PLUS").replace("-","MINUS").replace("*","ASTERISK").replace("/","SLASH").replace("=","EQUAL")
	k = k.replace(">","GREATER").replace("<","LESS").replace("$","DOLLAR").replace("(","LPAREN").replace(")","RPAREN")
	k = k.replace("[","LSQ").replace("]","RSQ").replace(",","COMMA").replace(":","COLON").replace(";","SEMICOLON")
	k = k.replace("'","SQUOTE").replace("#","HASH").replace("&","AMPERSAND").replace(".","PERIOD").replace("%","PERCENT")
	k = k.replace("\\","BACKSLASH").replace("|","VBAR").replace("^","HAT").replace("!","PLING").replace("?","QMARK")
#	k = k.replace("","").replace("","").replace("","").replace("","").replace("","")
	return k		
#
#		Make file name in generated directory.
#
def file(name):
	return "sources/generated/"+name.lower()
#
#		Render keyword as assembler constants
#
def renderConstants(h,ts,startID):
	for t in ts.getRange(startID):
		name = textProcess(t.getName().upper())
		if name.startswith("PLINGPLING"):
			name = "SYS_"+name[10:]
		if name != "":
			h.write("KWD_{0:30} = ${1:02x} ; {2}\n".format(name,t.getID(),t.getName().lower()))
#
#		Check alternating pattern in structure
#
def checkStructures(ts):
	for t in ts.getRange(0xB0)[:16]:
		assert t.getModifier() == "+" if t.getID() % 2 == 0 else "-"
#
#		Render the token text arrays
#
def renderTokenText(h,ts,startID,label):
	h.write(label+":"+"\n")
	for t in ts.getRange(startID):
		name = t.getName().upper()
		name = "" if name.startswith("!!") else name 
		b = [ord(x) for x in name]
		b.insert(0,len(name))
		if len(name) != 0:
			b[-1] |= 0x80
		b = ",".join(["${0:02x}".format(x) for x in b])
		h.write("\t.byte\t{1:30}\t; ${2:3x} {3}\n".format(len(name),b,t.getID(),name))
	h.write("\t.byte\t$FF\n\n")
#
#		Render the precedence tables
#
def renderBinaryPrecedence(h,ts):
	h.write("BinaryPrecedence:\n")
	for t in ts.getRange(0x20):
		h.write("\t.byte\t{0}\t\t; {1}\n".format(int(t.getModifier()),t.getName()))

header = ";\n;\tThis file is automatically generated.\n;\n"


ts = TokenSet()	
checkStructures(ts)
h = open(file("kwdconst.h"),"w")
h.write(header)
renderConstants(h,ts,0x20)
renderConstants(h,ts,0x80)
renderConstants(h,ts,0x100)
h.close()

h = open(file("kwdtext.asm"),"w")
h.write(header)
renderTokenText(h,ts,0x20,"BinaryTokenText")
renderTokenText(h,ts,0x80,"BaseTokenText")
renderTokenText(h,ts,0x100,"Shift1TokenText")
renderBinaryPrecedence(h,ts)
