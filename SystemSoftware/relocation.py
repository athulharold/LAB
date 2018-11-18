print('Enter program address:')
program_adr=int(input(),16)
obj=open('object.obj','r')
line=obj.readline().strip()
mem_map={}

while(line!=''):
	lines=line.split('^')
	if(lines[0]=='H'):
		counter=int(lines[2],16)
		counter+=program_adr
		start=hex(counter)[2:]
		while(len(start)<6):
			start='0'+start
		print('Program name ',lines[1],' starting adress:',start,'Program length:',lines[3])

	if(lines[0]=='T'):
		counter=int(lines[1],16)
		counter+=program_adr
		bit_mask=bin(int(lines[3],16))[2:]
		i=0
		for ob in lines[4:]:
			if(bit_mask[i]=='1'):
				lines[4+i]=hex(int(lines[4+i],16)+program_adr)[2:]
				while(len(lines[4+i])<6):
					lines[4+i]='0'+lines[4+i]
			
			mem_map[hex(counter)[2:]]=lines[4+i]
			
			counter+=int(len(lines[4+i])/2)
			i+=1
	if(lines[0]=='E'):
		counter=int(lines[1],16)+program_adr
		ex=hex(counter)[2:]
		while(len(ex)<6):
			ex='0'+ex
		print('Execution starts at ',ex)

	line=obj.readline().strip()
#print(mem_map)
for k in mem_map.keys():
	t=k
	while(len(t)<6):
		t='0'+t
print(t,'--',mem_map[k]+'\n')
