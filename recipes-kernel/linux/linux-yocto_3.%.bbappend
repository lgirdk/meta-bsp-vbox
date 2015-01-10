FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

COMPATIBLE_MACHINE_append = "|vbox32|vbox64"

KMACHINE_vbox32 = "qemux86"
KMACHINE_vbox64 = "qemux86-64"

KERNEL_EXTRA_FEATURES = "cfg/sound.scc"

SRC_URI += "file://my_gfx.cfg"
SRC_URI += "file://enable_uinput.cfg"

