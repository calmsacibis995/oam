add_library(intf STATIC
	find_menu.c
	iexpr.c
	inst_err.c
	main.c
	menu_io.c
	menutok.c
	read_item.c
	rec_pkg.c
	save_old.c
	sys_calls.c
	write_item.c
)

target_include_directories(intf PRIVATE ../include)
