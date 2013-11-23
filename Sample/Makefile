#
# These are the variables you need to edit when files are added / removed
#
# PROGRAM_SOURCE is the name of the .cpp file holding the main method (including the .cpp suffix)
# INTERMEDIATE_FOLDER is the name of the folder to contain the build files (do not include the ending /).
#

PROGRAM_SOURCE := main.cpp
LIBRARY_SOURCE := MyClass.cpp
TEST_PROGRAM_SOURCE :=
#INTERMEDIATE_FOLDER := build

#
# OS specific suffixes, prefixes, and switches used by make
#
# FOR OS/X: CPP=.cpp, OBJ=.o, DYS=.dylib, DYP=lib, ARS=.a, ARP=lib, EXE=<blank>, DEP=.d, USE_RPATH=yes, USE_INSTALLDIR=yes
#

CPP := .cpp
OBJ := .o
EXE :=
DEP := .d
G++ := clang++ --std=c++11 --stdlib=libstdc++
CPP11_LIB := -lstdc++

#
# Variables used internally by make
#

ifeq ($(INTERMEDIATE_FOLDER),)
	INTERMEDIATE_FOLDER := .
endif

INTERMEDIATE_FOLDER := $(addsuffix /,$(INTERMEDIATE_FOLDER))

PROGRAM_OBJECT := $(addprefix $(INTERMEDIATE_FOLDER),$(PROGRAM_SOURCE:$(CPP)=$(OBJ)))
LIBRARY_OBJECTS := $(addprefix $(INTERMEDIATE_FOLDER),$(LIBRARY_SOURCE:$(CPP)=$(OBJ)))
PROGRAM_BINARY := $(PROGRAM_OBJECT:$(OBJ)=$(EXE))

PROGRAM_DEPEND := $(PROGRAM_OBJECT:$(OBJ)=$(DEP))
LIBRARY_DEPEND := $(LIBRARY_OBJECTS:$(OBJ)=$(DEP))

# end of variables - start of targets

.PHONY: all clean deliver cleanall run cleancover cover runtest
.PRECIOUS: $(LIBRARY_OBJECTS)

all: $(PROGRAM_BINARY)

clean: 
	rm -f $(PROGRAM_OBJECT) $(PROGRAM_BINARY) $(LIBRARY_OBJECTS)
	rm -f $(INTERMEDIATE_FOLDER)*.d

test: all $(PROGRAM_BINARY)
	@mkdir -p cover
	@for progs in $(PROGRAM_BINARY); do \
		$$progs ; \
	done

$(INTERMEDIATE_FOLDER)%$(OBJ): %$(CPP)
	$(G++) -Wall $(COVERAGE) -c $< $(CPP_INCDIR) -o $@
	@$(G++) -MM $< $(CPP_INCDIR) > $(@:$(OBJ)=$(DEP))
	@mv -f $(@:$(OBJ)=$(DEP)) $(@:$(OBJ)=$(DEP).tmp)
	@sed -e 's|.*:|$(@):|' < $(@:$(OBJ)=$(DEP).tmp) > $(@:$(OBJ)=$(DEP))
	@sed -e 's/.*://' -e 's/\\$$//' < $(@:$(OBJ)=$(DEP).tmp) | fmt -1 | \
  		sed -e 's/^ *//' -e 's/$$/:/' >> $(@:$(OBJ)=$(DEP))
	@rm -f $(@:$(OBJ)=$(DEP).tmp)

$(PROGRAM_BINARY): % : %$(OBJ)
	$(G++) -Wall $(<) $(CPP_INCDIR) $(LIBRARY_OBJECTS) -o $(@) $(CPP_LIBDIR) -L$(INTERMEDIATE_FOLDER)
	@$(G++) -MM $(CPP_INCDIR) $(notdir $(<:$(OBJ)=$(CPP))) > $(<:$(OBJ)=$(DEP))
	@mv $(<:$(OBJ)=$(DEP)) $(<:$(OBJ)=.tmp)
	@sed "s|^.*:|$(@):|" $(<:$(OBJ)=.tmp) > $(<:$(OBJ)=$(DEP))
	@rm $(<:$(OBJ)=.tmp)
    
$(PROGRAM_BINARY): $(LIBRARY_OBJECTS)

-include $(PROGRAM_DEPEND) $(LIBRARY_DEPEND)
