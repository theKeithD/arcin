#!/usr/bin/env python

# Usage: hidloader_append.py arcin.elf hidloader_v2.exe arcin_flash_foo.exe

import sys, struct, shutil
from elftools.elf.elffile import ELFFile

e = ELFFile(open(sys.argv[1], 'rb'))
shutil.copyfile(sys.argv[2], sys.argv[3])
shutil.copymode(sys.argv[2], sys.argv[3])
f = open(sys.argv[3], 'ab')

buf = ''

for segment in sorted(e.iter_segments(), key = lambda x: x.header.p_paddr):
	if segment.header.p_type != 'PT_LOAD':
		continue
	
	data = segment.data()
	lma = segment.header.p_paddr
	
	# Workaround for LD aligning segments to a larger boundary than 8k.
	if lma == 0x8000000:
		lma += 0x2000
		data = data[0x2000:]
	
	# Add padding if necessary.
	buf += '\0' * (lma - 0x8002000 - len(buf))
	
	buf += data

# Align to 64B
if len(buf) & (64 - 1):
	buf += '\0' * (64 - (len(buf) & (64 - 1)))

fsize = f.tell()

f.write(struct.pack('<IHHHHHHI',
	0xb007f00d,
	1,
	0x1d50,
	0x6080,
	0x1d50,
	0x6084,
	0x0110,
	len(buf),
))

f.write(buf)

f.write(struct.pack('<I', fsize))

f.close()
