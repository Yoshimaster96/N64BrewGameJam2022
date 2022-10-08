#######################
#GLOBAL BUILD SETTINGS#
#######################
include $(ROOT)/usr/include/make/PRdefs

#SDK dirs
N64KITDIR		= C:\nintendo\n64kit
NUSYSINCDIR		= $(N64KITDIR)/nusys/include
NUSYSLIBDIR		= $(N64KITDIR)/nusys/lib

#binary tools
LIB		= $(ROOT)/usr/lib
LPR		= $(LIB)/PR
INC		= $(ROOT)/usr/include
CC		= gcc
LD		= ld
MAKEROM	= mild

#audio libs
NUAUDIOLIB = -lnualsgi_n -lgn_audio

#flags
LCDEFS	= -DF3DEX_GBI_2
LCINCS	= -I. -I$(NUSYSINCDIR) -I$(ROOT)/usr/include/PR
LCOPTS	= -G 0
LDFLAGS	= $(MKDEPOPT) -L$(LIB) -L$(NUSYSLIBDIR) $(NUAUDIOLIB) -lnusys -lgultra -L$(GCCDIR)/mipse/lib -lkmc
OPTIMIZER	= -O2

#output
APP		= main.out
TARGETS	= main.z64

###################
#BUILDING SEGMENTS#
###################
#code segment
C_ROOT_FILES	= $(wildcard *.c)
C_GFX_FILES		= $(wildcard data/graphics/*.c)
CFILES		= $(C_ROOT_FILES) $(C_GFX_FILES)
H_ROOT_FILES	= $(wildcard *.h)
H_GFX_FILES		= $(wildcard data/graphics/*.h)
HFILES		= $(H_ROOT_FILES) $(H_GFX_FILES)
CODEOBJECTS	= $(C_ROOT_FILES:.c=.o) $(NUSYSLIBDIR)/nusys.o
CODESEGMENT = codesegment.o

#data segments
DATAOBJECTS = $(C_GFX_FILES:.c=.o)

#all objects
OBJECTS 	= $(CODESEGMENT) $(DATAOBJECTS)

##############
#BUILDING ROM#
##############
default: $(TARGETS)

#code segment
.c.o: Makefile
	$(CC) $(CFLAGS) $< -o $@
$(CODESEGMENT):	$(CODEOBJECTS) Makefile
	$(LD) -o $(CODESEGMENT) -r $(CODEOBJECTS) $(LDFLAGS)

#all objects
$(TARGETS):	$(OBJECTS) spec
	$(MAKEROM) spec -s 32 -I$(NUSYSINCDIR) -r $(TARGETS) -e $(APP)
	MAKEMASK $(TARGETS)
