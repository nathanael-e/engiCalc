#Compiler and debug flags.
CC := g++ -std=c++11
CFLAGS := -g -Wall

#Include directory, source directory and build directory.
INCDIR := include
SRCDIR := src
BUILDDIR := build
TARGETDIR := bin

#Source and header filename extension.
INCEXT := hpp
SRCEXT := cpp

#Find all subdirectories within the directory set as INCDIR.
INCDIRS := $(shell find $(INCDIR) -depth ! -name *.$(INCEXT) ! -name *.swp)

#Replace the folder set as INCDIR with the folder set as BUILDDIR. \
	I.e., $(INCDIR)/sub_dir_1 becomes $(BUILDDIR)/sub_dir_1.
BUILDDIRS := $(subst $(INCDIR), $(BUILDDIR), $(INCDIRS))

#Excecutable tragets.
TARGET := bin/main.out
GTEST_TARGET := bin/gtester.out

#Source target.
TARGET_SRC := main.cpp
TARGET_SRC_PATH := src/main.cpp

#Source target.
GTEST_SRC := tester.cpp
GTEST_SRC_PATH := test/tester.cpp

#Libraries.
#-lboost_thread
#-lboost_atomic
GTEST := -lgtest -lgtest_main -lpthread
SIMPLE_WEB_SERVER = -rdynamic -lboost_regex -lboost_system -lboost_filesystem -lboost_date_time -lboost_chrono -lpthread

#Include the headers in every subdirectory.
INC := $(subst $(INCDIR), -I $(INCDIR), $(INCDIRS))

#Find all sources.
SOURCES := $(shell find $(SRCDIR) -type f ! -name $(TARGET_SRC) -name *.$(SRCEXT))

#Create an object file for every source.
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

all: target gtest

target: $(TARGET)
gtest: $(GTEST_TARGET)

#Link libraries.
$(TARGET): $(OBJECTS)
	@echo " Linking..."
	@mkdir -p $(TARGETDIR)
	@echo " $(CC) $(TARGET_SRC_PATH) $^ -o $(TARGET)"; 
	$(CC) $(INC) $(TARGET_SRC_PATH) $^ -o $(TARGET) $(SIMPLE_WEB_SERVER)

#Link libraries.
$(GTEST_TARGET): $(OBJECTS)
	@echo " Linking"
	@mkdir -p $(TARGETDIR)
	@echo " $(CC) $(GTEST_SRC_PATH) $^ -o $(GTEST_TARGET)";
	$(CC) $(INC) $(GTEST_SRC_PATH) $^ -o $(GTEST_TARGET) $(GTEST) $(SIMPLE_WEB_SERVER)

#Compile object files.
$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@echo " Building..."
	@mkdir -p $(BUILDDIRS)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; 
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

#Removes executables and $(BUILDDIR)
clean:
	@echo " Cleaning..."; 
	@echo " $(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET) 

.PHONY: clean
