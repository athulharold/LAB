inp=open("ObjectFile.txt","r")
flag=-1 #to facilitate checking for large gaps in the address
for i in inp.readlines():
	if i[0]=="T":
		ls=i.strip().split('^') #get each block in a single text record
		if flag!=-1:
			oldlen=int(start,16)+int(length,16)
			if  oldlen!=int(ls[1][2:],16):
				diff=int(ls[1][2:],16)-oldlen
				print(".\n.\nAfter "+str(diff)+" locations\n.\n.")	
		
		addr=ls[1][2:] 	#to print each address
		start=ls[1][2:]	#storing starting address of the text record
		length=ls[2]	#length of the text record			
		for j in range (3,len(ls)-1):									
			print("\n0x"+addr+"\t"+ls[j])  
			flag=0
			addr=str(hex(int(addr,16)+len(ls[j])/2))
			addr=addr[2:]
			
			
								
