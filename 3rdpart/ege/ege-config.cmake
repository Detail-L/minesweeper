find_path(EGE_INCLUDE_DIRS graphics.h PATHS ./3rdpart/ege/include REQUIRED)
find_path(EGE_LIBS_DIRS libgraphics64.a PATHS ./3rdpart/ege/lib REQUIRED)

add_library(EGE INTERFACE IMPORTED)
set_target_properties(
	EGE
	PROPERTIES
	INTERFACE_INCLUDE_DIRECTORIES "${EGE_INCLUDE_DIRS}"
	INTERFACE_LINK_LIBRARIES "-L${EGE_LIBS_DIRS} -lgraphics64 -lgdiplus -luuid -lmsimg32 -lgdi32 -limm32 -lole32 -loleaut32 -lwinmm -mwindows"
)