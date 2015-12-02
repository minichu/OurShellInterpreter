DIRS = cat cp ln mv rm tail cd ls pwd rmdir tee
.PHONY:all clean

all:
	@for d in $(DIRS);\
	do\
		$(MAKE) -C $$d;\
	done

clean:
	@for d in $(DIRS);\
	do\
		$(MAKE) -C $$d clean;\
	done

