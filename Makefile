

CXX = g++
CXXFLAGS = -g
CPPFLAGS= Wall -l ~/Program6/include


backup:
	@make clean
	@mkdir -p ~/backups; chmod 700 ~/backups
	@$(eval CURDIRNAME := $(shell baseame "`pwd`"))
	@$(eval MKBKUPNAME := ~/backups/$(PROJECTNAME)-$(shell date + '%Y.%m.%d-%H:%M:%S').tar.gz)
	@echo
	@echo Writing the backup file
	@echo
	@echo
	@-tar zcfv $(MKBKUPNAME) ../$(CURDIRAME) 2> /dev/null
	@echo
	@echo
	@chmod 600 $(MKBKNAME)
	@echo
	@echo Done!
