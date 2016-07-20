#!/usr/bin/env python
# -*- coding: utf-8 -*-

import struct

from hidapi import hidapi
import ctypes

hiddev = hidapi.hid_open(0x1d50, 0x6080, None)
report_size = 2
	
if not hiddev: 
	raise RuntimeError('Target not found.')

def print_row(row):
	buttons = [0] * 4

	buttons[0] = (row & 0b0001) >> 0
	buttons[1] = (row & 0b0010) >> 1
	buttons[2] = (row & 0b0100) >> 2
	buttons[3] = (row & 0b1000) >> 3

	print " ".join("{0}".format('□' if b == 0 else '■') for b in buttons)

while 1:
	data = ctypes.create_string_buffer(report_size)
	if hidapi.hid_read(hiddev, data, report_size) != report_size:
		raise RuntimeError('Reading failed.')
	
	raw_buttons = struct.unpack('<H', data)

	a = (raw_buttons[0] & 0b0000000000001111) >> 0
	b = (raw_buttons[0] & 0b0000000011110000) >> 4
	c = (raw_buttons[0] & 0b0000111100000000) >> 8
	d = (raw_buttons[0] & 0b1111000000000000) >> 12

	button_rows = a, b, c, d	

	map(print_row, button_rows)
	print "-------"
