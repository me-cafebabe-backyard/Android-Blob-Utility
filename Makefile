
BUILD_WITH_READLINE := false

CC = gcc
CFLAGS += -Wall -Wextra

ifeq ($(BUILD_WITH_READLINE), true)
	CFLAGS += -DUSE_READLINE
	LDFLAGS += -lreadline
endif

MODULE = android-blob-utility


all: $(MODULE)

$(MODULE): $(MODULE).h

clean:
	-rm -f $(MODULE)

