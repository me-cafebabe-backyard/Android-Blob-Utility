
BUILD_WITH_READLINE := false
DEBUG ?= false
NON_TREBLE ?= false

CC = gcc
CFLAGS += -Wall -Wextra

ifeq ($(BUILD_WITH_READLINE), true)
	CFLAGS += -DUSE_READLINE
	LDFLAGS += -lreadline
endif
ifeq ($(DEBUG), true)
	CFLAGS += -DDEBUG
endif
ifeq ($(NON_TREBLE), true)
	CFLAGS += -DNON_TREBLE
endif

MODULE = android-blob-utility


all: $(MODULE)

$(MODULE): $(MODULE).h

clean:
	-rm -f $(MODULE)