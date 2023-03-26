# Postform zephyr integration

This is a test to integrate Postform with Zephyr into a working executable. Targets the raspberry pi pico board.

```
# Init and build the app
west init -l app
west update
cd app
west build -b rpi_pico -- -DMODULE_EXT_ROOT=.

# Install postform rtt
cargo install --path ../modules/lib/postform/postform_rtt

# Run postform_rtt
postform_rtt --chip RP2040 build/zephyr/zephyr.elf
```
