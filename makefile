CC := g++ -std=c++14
CFLAGS := -g -Wall

SRCDIR := src
BUILDDIR := build
TARGETDIR := bin
TARGET := bin/engiCalc.out
GTEST_TARGET := bin/gtester.out
SRCEXT := cpp

TARGET_SRC := main.cpp
TARGET_SRC_PATH := src/main.cpp
GTEST_SRC := tester.cpp
GTEST_SRC_PATH := test/tester.cpp

INC := -I include
GTEST := -lgtest -lgtest_main -lpthread

SOURCES := $(shell find $(SRCDIR) -type f ! -name $(TARGET_SRC) -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

all: target gtest

target: $(TARGET)
gtest: $(GTEST_TARGET)

$(TARGET): $(OBJECTS)
	@echo " Linking..."
	@mkdir -p $(TARGETDIR)
	@echo " $(CC) $(TARGET_SRC_PATH) $^ -o $(TARGET)"; 
	$(CC) $(INC) $(TARGET_SRC_PATH) $^ -o $(TARGET)

$(GTEST_TARGET): $(OBJECTS)
	@echo " Linking"
	@mkdir -p $(TARGETDIR)
	@echo " $(CC) $(GTEST_SRC_PATH) $^ -o $(GTEST_TARGET)";
	$(CC) $(INC) $(GTEST_SRC_PATH) $^ -o $(GTEST_TARGET) $(GTEST)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@echo " Building..."
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning..."; 
	@echo " $(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET) 

.PHONY: clean
