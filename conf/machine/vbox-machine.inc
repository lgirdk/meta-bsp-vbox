# ----------------------------------------------------------------------

MACHINE_FEATURES = "\
    acpi \
    alsa \
    openglesv2 \
    pci \
    screen \
    x86 \
"

MACHINE_EXTRA_RDEPENDS += "kernel-modules"
MACHINE_EXTRA_RDEPENDS += "kernel-module-snd-intel8x0"
MACHINE_EXTRA_RDEPENDS += "vboxguestdrivers"
MACHINE_EXTRA_RDEPENDS += "alsa-conf"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "v86d"

KERNEL_MODULE_AUTOLOAD += "snd-intel8x0"

# ----------------------------------------------------------------------

PREFERRED_PROVIDER_virtual/egl ?= "mesa"
PREFERRED_PROVIDER_virtual/libgl ?= "mesa"
PREFERRED_PROVIDER_virtual/libgles1 ?= "mesa"
PREFERRED_PROVIDER_virtual/libgles2 ?= "mesa"

PREFERRED_PROVIDER_virtual/xserver ?= "xserver-xorg"

PREFERRED_VERSION_qtwebkit ?= "5.4.2+git%"
PREFERRED_VERSION_qtbrowser ?= "2.0.5%"

# ----------------------------------------------------------------------

# Webkit GStreamer media player needs SW decoders when running on VirtualBox
LICENSE_FLAGS_WHITELIST += "commercial_gst-ffmpeg"
LICENSE_FLAGS_WHITELIST += "commercial_gstreamer1.0-libav"
LICENSE_FLAGS_WHITELIST += "commercial_libav"
LICENSE_FLAGS_WHITELIST += "commercial_libpostproc"
LICENSE_FLAGS_WHITELIST += "commercial_x264"

# ----------------------------------------------------------------------

PREFERRED_PROVIDER_virtual/kernel ?= "linux-yocto"
PREFERRED_VERSION_linux-yocto ?= "3.14%"

KERNEL_IMAGETYPE = "bzImage"
MODULE_TARBALL_DEPLOY = "0"

# Don't include kernels in standard images
RDEPENDS_kernel-base = ""

# ----------------------------------------------------------------------

# Disable kernel startup messages so they don't spew all over the VirtualBox window
# (This is added to qemux86 kernel cmdline by openembedded-core/meta/classes/syslinux.bbclass)
# APPEND_append_qemuall = " quiet"

# By default, VirtualBox VMs don't have serial ports
SERIAL_CONSOLE = ""
SERIAL_CONSOLES = ""

# Set USE_VT to 0 to disable consoles on the framebuffer device.
# Warning: since vbox images don't have serial consoles, disabling USE_VT
# implies no direct console (ie login via ssh only).
# To debug sshd startup issues etc USE_VT should be set to "1".
USE_VT = "1"

# ----------------------------------------------------------------------

IMAGE_FSTYPES = "vmdk"

# ----------------------------------------------------------------------
