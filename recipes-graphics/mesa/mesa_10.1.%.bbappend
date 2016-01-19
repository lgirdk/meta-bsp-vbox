# Use gallium and llvmpipe for rendering
PACKAGECONFIG_append = " gallium gallium-egl gallium-gbm gallium-llvm"

# We want the fbdev platform as well
EGL_PLATFORMS_append = ",fbdev"

# Newer versions of libdrm (2.4.66 and above?) don't seem to provide
# the nouveau header files in the location expected by Mesa 10.1.x
# As a workaround, disable the nouveau (not required for vbox builds).
# Note that because of the way that DRIDRIVERS is constructed in
# mesa.inc, it's hard to remove "nouveau" from DRIDRIVERS, so
# over-ride the dri PACKAGECONFIG instead.
PACKAGECONFIG[dri] = "--enable-dri --with-dri-drivers=swrast, --disable-dri, dri2proto libdrm"

# Use the same approach as above to over-ride GALLIUMDRIVERS too.
PACKAGECONFIG[gallium] = "--with-gallium-drivers=swrast, --without-gallium-drivers"
