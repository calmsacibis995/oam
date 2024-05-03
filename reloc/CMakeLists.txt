add_executable(reloc_menus
	reloc.c
	oldmenu.c
	pkginfo.c
)

target_include_directories(reloc_menus PRIVATE ../include)
target_link_libraries(reloc_menus intf)
