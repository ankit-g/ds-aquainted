default:
	@g++ -o attack_methods.o -c my_attack_methods/attack_methods.cpp
	@g++ -o stratigy.o -c my_attack_stratigy/stratigy.cpp
	@g++ -o result.o -c my_result_after_the_move/result.cpp
	@g++ -o attack_area.o -c the_areas_m_attacking/attack_area.cpp
	@g++ -o how_to_this_crappy_work.o -c the_xxx_and_the_xxx_i_use/how_to_this_crappy_work.cpp
	@g++ -o main.o -c you_start_here/main.cpp
	g++ -o dont_exe main.o \
			how_to_this_crappy_work.o \
			attack_area.o \
			result.o \
			stratigy.o \
			attack_methods.o
clean:
	rm *.o
