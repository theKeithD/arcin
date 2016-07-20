#!/usr/bin/env python

import struct

from hidapi import hidapi
import ctypes

hiddev = hidapi.hid_open(0x1d50, 0x6080, None)
	
if not hiddev: 
	raise RuntimeError('Target not found.')

while 1:
	data = ctypes.create_string_buffer(5)
	if hidapi.hid_read(hiddev, data, 5) != 5:
		raise RuntimeError('Reading failed.')
	
	report_id, a, b = struct.unpack('<xHBB', data)
	
	#if b != 0:
#        print a, b
        print report_id, a, b
