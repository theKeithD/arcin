Pre-Built Images
----------------
The `.elf` files can be flashed onto a device using the `hidflash.py` script. Standalone `.exe` files are also provided.

- `arcin-sdvx-[ac|copal]`: Firmware for use with SVRE9 or SVSE5 controllers using either AC or Copal encoders, presented as a gamepad. WS2812B lighting available via B9. (`arcin-sdvx-ac` is effectively the same as `arcin-svre9-alpha2`)
- `arcin-sdvx-[ac|copal]-kb`: Same as the above, except presented as a keyboard.
- `arcin-sdvx-[ac|copal]-nolight`: Same as `arcin-sdvx-[ac|copal]`, except with WS2812B lighting disabled. This means B9 can be used as a button.
- `arcin-sdvx-[ac|copal]-kb-nolight`: Combination of the two firmwares above. No WS2812B lighting, presented as a keyboard.