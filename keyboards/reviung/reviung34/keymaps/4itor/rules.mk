#* Generic Settings
# BOOTMAGIC_ENABLE = lite    # Virtual DIP switch configuration
BOOTMAGIC_ENABLE = yes
MOUSEKEY_ENABLE = yes      # Mouse keys
EXTRAKEY_ENABLE = yes      # Audio control and System control
CONSOLE_ENABLE = no        # Console for debug
COMMAND_ENABLE = no        # Commands for debug and configuration
NKRO_ENABLE = yes          # USB Nkey Rollover
# LTO_ENABLE = yes
RGBLIGHT_ENABLE = yes
COMBO_ENABLE = yes

#* Via
VIA_ENABLE = no

#* Vial
# VIAL_ENABLE = no
# QMK_SETTINGS = no

#* Features
SRC += features/layer_lock.c
SRC += features/caps_word.c
