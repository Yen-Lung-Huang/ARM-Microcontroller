<<<<<<< HEAD
source target/common.gdb

define reset
  jlink_connect
  reset_peripherals
  disable_ddr

  init_ddr
  load_in_ddr
  # Show registers state
  mon regs
end
=======
source target/common.gdb

define reset
  jlink_connect
  reset_peripherals
  disable_ddr

  init_ddr
  load_in_ddr
  # Show registers state
  mon regs
end
>>>>>>> 16c66438 (Upload from PC.)
