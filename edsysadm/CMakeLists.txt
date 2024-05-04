add_executable(getintdef
    getintdef.c
)

target_include_directories(getintdef PRIVATE ../include)
target_link_libraries(getintdef intf)

add_executable(getfld
    getfld.c
)

target_include_directories(getfld PRIVATE ../include)
target_link_libraries(getfld intf)

add_executable(findmenu
    findmenu.c
)

target_include_directories(findmenu PRIVATE ../include)
target_link_libraries(findmenu intf)

add_executable(delsysadm delsysadm.c)
target_include_directories(delsysadm PRIVATE ../include)
target_link_libraries(delsysadm intf)

add_executable(getpkgdesc getpkgdesc.c)
target_include_directories(getpkgdesc PRIVATE ../include)
target_link_libraries(getpkgdesc intf)

add_executable(updt_pkgdesc updt_pkgdesc.c)
target_include_directories(updt_pkgdesc PRIVATE ../include)
target_link_libraries(updt_pkgdesc intf)

