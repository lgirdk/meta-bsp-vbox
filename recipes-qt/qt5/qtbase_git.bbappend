
FILESEXTRAPATHS_prepend := "${THISDIR}/${BPN}-git:"

SRC_URI += "\
    file://eglfswindow.patch \
"

# ----------------------------------------------------------------------

PACKAGECONFIG_GL = "gles2"

EXTRA_OECONF += "-qpa eglfs"

MESA_RDEPENDS = "libegl-gallium mesa-driver-swrast"
RDEPENDS_${PN}_append = " ${MESA_RDEPENDS}"
