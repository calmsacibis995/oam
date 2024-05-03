#
# sysadm - Main program
#
add_executable(sysadm
	print_err.c
	sysadm.c
)

target_include_directories(sysadm PRIVATE ../include)
target_link_libraries(sysadm termcap intf)

#
# object_gen
#
add_executable(object_gen
	get_desc.c
	interface.c
)

target_include_directories(object_gen PRIVATE ../include)
target_link_libraries(object_gen intf)

#
# ie_build
#
add_executable(ie_build
	ie_build.c
	print_err.c
)

target_include_directories(ie_build PRIVATE ../include)
target_link_libraries(ie_build intf)

#
# itemhelp
#
add_executable(itemhelp
	itemhelp.c
)

target_include_directories(itemhelp PRIVATE ../include)
target_link_libraries(itemhelp intf)
