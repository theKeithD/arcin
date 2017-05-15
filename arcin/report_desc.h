#ifndef REPORT_DESC_H
#define REPORT_DESC_H

// TODO: move these defs into device config
#ifndef KEYBOARD_MODE
#define KEYBOARD_MODE 0
#endif
#ifndef B9_LIGHTING
#define B9_LIGHTING 1
#endif
#ifndef ANALOG_MODE
#define ANALOG_MODE 1
#endif
#ifndef SMOOTHING_FACTOR
#define SMOOTHING_FACTOR 2
#endif

#include <usb/hid.h>

#if KEYBOARD_MODE==1
auto report_desc = keyboard(
#else
auto report_desc = gamepad(
#endif
	// Inputs.
	report_id(1),
	
	#if KEYBOARD_MODE==1
	# if B9_LIGHTING==1
	// keyboard HID report with B9 skipped
	usage_page(UsagePage::Keyboard),
	usage(0x8b),          // B1  - FX-L  (muhen)
	usage('d' - 'a' + 4), // B2  - BT-A  (D)
	usage(0x8a),          // B3  - FX-R  (henkan)
	usage('f' - 'a' + 4), // B4  - BT-B  (F)
	usage('q' - 'a' + 4), // B5  - undef (Q) 
	usage('j' - 'a' + 4), // B6  - BT-C  (J)
	usage('w' - 'a' + 4), // B7  - undef (W)
	usage('k' - 'a' + 4), // B8  - BT-D  (K)
	logical_minimum(0),
	logical_maximum(1),
	report_count(8),
	report_size(1),
	input(0x02),

	padding_in(1),        // B9  - undef (reserved for lights)

	usage_page(UsagePage::Keyboard),
	usage(0x28),          // B10 - Start (Enter)
	usage('p' - 'a' + 4), // B11 - undef (P)
	usage('s' - 'a' + 4), // B12 - VOL-L right (S)
	usage('a' - 'a' + 4), // B13 - VOL-L left  (A)
	usage(0x33),          // B14 - VOL-R right (;)
	usage('l' - 'a' + 4), // B15 - VOL-R left  (L)
	logical_minimum(0),
	logical_maximum(1),
	report_count(6),
	report_size(1),
	input(0x02),
	
	padding_in(1 + 8 + 8), // 15 + 1 for buttons and remaining space, then 8 + 8 for X/Y (now unused)
	# else
	// keyboard HID report with B9 included
	usage_page(UsagePage::Keyboard),
	usage(0x8b),          // B1  - FX-L  (muhen)
	usage('d' - 'a' + 4), // B2  - BT-A  (D)
	usage(0x8a),          // B3  - FX-R  (henkan)
	usage('f' - 'a' + 4), // B4  - BT-B  (F)
	usage('q' - 'a' + 4), // B5  - undef (Q) 
	usage('j' - 'a' + 4), // B6  - BT-C  (J)
	usage('w' - 'a' + 4), // B7  - undef (W)
	usage('k' - 'a' + 4), // B8  - BT-D  (K)
	usage('o' - 'a' + 4), // B9  - undef (O)
	usage(0x28),          // B10 - Start (Enter)
	usage('p' - 'a' + 4), // B11 - undef (P)
	usage('s' - 'a' + 4), // B12 - VOL-L right (S)
	usage('a' - 'a' + 4), // B13 - VOL-L left  (A)
	usage(0x33),          // B14 - VOL-R right (;)
	usage('l' - 'a' + 4), // B15 - VOL-R left  (L)
	logical_minimum(0),
	logical_maximum(1),
	report_count(15),
	report_size(1),
	input(0x02),
	
	padding_in(1 + 8 + 8), // 15 + 1 for buttons and remaining space, then 8 + 8 for X/Y (now unused)
  # endif
  #else
	// normal gamepad buttons
	buttons(15),
	padding_in(1),

	usage_page(UsagePage::Desktop),
	usage(DesktopUsage::X),
	logical_minimum(0),
	logical_maximum(255),
	report_count(1),
	report_size(8),
	input(0x02),

	usage_page(UsagePage::Desktop),
	usage(DesktopUsage::Y),
	logical_minimum(0),
	logical_maximum(255),
	report_count(1),
	report_size(8),
	input(0x02),
  #endif

	// Outputs.
	report_id(2),
	logical_minimum(0),
	logical_maximum(1),
	
	usage_page(UsagePage::Ordinal),
	usage(1),
	collection(Collection::Logical, 
		usage_page(UsagePage::LED),
		usage(0x4b),
		report_size(1),
		report_count(1),
		output(0x02)
	),
	
	usage_page(UsagePage::Ordinal),
	usage(2),
	collection(Collection::Logical, 
		usage_page(UsagePage::LED),
		usage(0x4b),
		report_size(1),
		report_count(1),
		output(0x02)
	),
	
	usage_page(UsagePage::Ordinal),
	usage(3),
	collection(Collection::Logical, 
		usage_page(UsagePage::LED),
		usage(0x4b),
		report_size(1),
		report_count(1),
		output(0x02)
	),
	
	usage_page(UsagePage::Ordinal),
	usage(4),
	collection(Collection::Logical, 
		usage_page(UsagePage::LED),
		usage(0x4b),
		report_size(1),
		report_count(1),
		output(0x02)
	),
	
	usage_page(UsagePage::Ordinal),
	usage(5),
	collection(Collection::Logical, 
		usage_page(UsagePage::LED),
		usage(0x4b),
		report_size(1),
		report_count(1),
		output(0x02)
	),
	
	usage_page(UsagePage::Ordinal),
	usage(6),
	collection(Collection::Logical, 
		usage_page(UsagePage::LED),
		usage(0x4b),
		report_size(1),
		report_count(1),
		output(0x02)
	),
	
	usage_page(UsagePage::Ordinal),
	usage(7),
	collection(Collection::Logical, 
		usage_page(UsagePage::LED),
		usage(0x4b),
		report_size(1),
		report_count(1),
		output(0x02)
	),
	
	usage_page(UsagePage::Ordinal),
	usage(8),
	collection(Collection::Logical, 
		usage_page(UsagePage::LED),
		usage(0x4b),
		report_size(1),
		report_count(1),
		output(0x02)
	),
	
	usage_page(UsagePage::Ordinal),
	usage(9),
	collection(Collection::Logical, 
		usage_page(UsagePage::LED),
		usage(0x4b),
		report_size(1),
		report_count(1),
		output(0x02)
	),
	
	usage_page(UsagePage::Ordinal),
	usage(10),
	collection(Collection::Logical, 
		usage_page(UsagePage::LED),
		usage(0x4b),
		report_size(1),
		report_count(1),
		output(0x02)
	),
	
	usage_page(UsagePage::Ordinal),
	usage(11),
	collection(Collection::Logical, 
		usage_page(UsagePage::LED),
		usage(0x4b),
		report_size(1),
		report_count(1),
		output(0x02)
	),
	
	padding_out(5),
	
	logical_maximum(255),
	
	usage_page(UsagePage::Ordinal),
	usage(12),
	collection(Collection::Logical, 
		usage_page(UsagePage::LED),
		usage(0x4b),
		report_size(8),
		report_count(1),
		output(0x02)
	),
	
	usage_page(UsagePage::Ordinal),
	usage(13),
	collection(Collection::Logical, 
		usage_page(UsagePage::LED),
		usage(0x4b),
		report_size(8),
		report_count(1),
		output(0x02)
	),
	
	usage_page(UsagePage::Ordinal),
	usage(14),
	collection(Collection::Logical, 
		usage_page(UsagePage::LED),
		usage(0x4b),
		report_size(8),
		report_count(1),
		output(0x02)
	),
	
	usage_page(UsagePage::Ordinal),
	usage(15),
	collection(Collection::Logical, 
		usage_page(UsagePage::LED),
		usage(0x4b),
		report_size(8),
		report_count(1),
		output(0x02)
	),
	
	usage_page(UsagePage::Ordinal),
	usage(16),
	collection(Collection::Logical, 
		usage_page(UsagePage::LED),
		usage(0x4b),
		report_size(8),
		report_count(1),
		output(0x02)
	),
	
	// Bootloader
	report_id(0xb0),
	
	usage_page(0xff55),
	usage(0xb007),
	logical_minimum(0),
	logical_maximum(255),
	report_size(8),
	report_count(1),
	
	feature(0x02), // HID bootloader function
	
	// Configuration
	report_id(0xc0),
	
	usage(0xc000),
	feature(0x02), // Config segment
	
	usage(0xc001),
	feature(0x02), // Config segment size
	
	feature(0x01), // Padding
	
	usage(0xc0ff),
	report_count(60),
	feature(0x02) // Config data
);

struct input_report_t {
	uint8_t report_id;
	uint16_t buttons;
	uint8_t axis_x;
	uint8_t axis_y;
} __attribute__((packed));

struct output_report_t {
	uint8_t report_id;
	uint16_t leds;
	uint8_t led1;
	uint8_t led2;
	uint8_t r;
	uint8_t g;
	uint8_t b;
} __attribute__((packed));

struct bootloader_report_t {
	uint8_t report_id;
	uint8_t func;
} __attribute__((packed));

struct config_report_t {
	uint8_t report_id;
	uint8_t segment;
	uint8_t size;
	uint8_t pad;
	uint8_t data[60];
} __attribute__((packed));

#endif
