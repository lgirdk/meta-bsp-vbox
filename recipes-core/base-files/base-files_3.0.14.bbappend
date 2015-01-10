
do_install_append () {
    cat >> ${D}${sysconfdir}/profile <<EOF
# this is needed to run Qt5 applications with EGLFS
export EGL_PLATFORM=fbdev
export QT_QPA_EGLFS_DEPTH=32
EOF
}
