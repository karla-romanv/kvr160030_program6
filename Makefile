#Karla Roman



#include the professor's include and lib folder
#with the cdk and the curses
CXX = g++
CXXFLAGS = -Wall -g
CPPFLAGS=-I/scratch/perkins/include
LDFLAGS = -L /scratch/perkins/lib
LDLIBS = -lcdk -lcurses 


#to execute program using ./program6
EXECFILE = program6
OBJS = program6.o

all:$(EXECFILE)

#remove files that are not needed
clean:
	rm -f $(OBJS) $(EXECFILE) *.P *~ \#*


#use objective files for execution
$(EXECFILE): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS) $(LDLIBS)


#YIKES! create a backup just in case something goes wrong
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
