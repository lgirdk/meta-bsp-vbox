
FILESEXTRAPATHS_prepend := "${THISDIR}/${BPN}-${PV}:"

SRC_URI += "\
    file://eglfswindow.patch \
"

# ----------------------------------------------------------------------

PACKAGECONFIG_GL = "gles2"

EXTRA_OECONF += "-qpa eglfs"

MESA_RDEPENDS = "mesa-driver-swrast"
RDEPENDS_${PN}_append = " ${MESA_RDEPENDS}"
