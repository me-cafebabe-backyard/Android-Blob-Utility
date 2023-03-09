
DEBUG ?= false
NON_TREBLE ?= false

CC = gcc
CFLAGS += -Wall -Wextra

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
