DIRS = cat mv rm pwd ln tail cd cp rmdir tee ls command

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

