import os

env = Environment(
	ENV = os.environ,
  PROGSUFFIX = '.elf',
)

SConscript('laks/build_rules')

env.SelectMCU('stm32f303rc')

env.Firmware('arcin', Glob('arcin/*.cpp'), LINK_SCRIPT = 'arcin/arcin.ld')

env.Firmware('bootloader', Glob('bootloader/*.cpp'), LINK_SCRIPT = 'bootloader/bootloader.ld')

env.Firmware('test', Glob('test/*.cpp'))
