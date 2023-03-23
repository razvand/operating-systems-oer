NASM = nasm
CPPFLAGS = -nostdinc -Iinclude
CFLAGS = -Wall -Wextra -fno-PIC -fno-stack-protector -fno-builtin

.PHONY: all clean

SRCS = syscall.c \
       process/exit.c process/nanosleep.c process/sleep.c\
       mm/malloc.c mm/mmap.c mm/mem_list.c \
       string/string.c \
       stat/fstatat.c stat/fstat.c stat/stat.c \
       io/open.c io/close.c io/read_write.c \
       io/lseek.c io/truncate.c io/ftruncate.c io/puts.c \
       errno.c \
       crt/__libc_start_main.c

OBJS = $(patsubst %.c,%.o,$(SRCS))

all: libc.a

libc.a: $(OBJS) crt/start.o
	$(AR) -rc $@ $^

$(OBJS): %.o:%.c

crt/start.o: crt/start.asm
	$(NASM) -f elf64 -o $@ $<

clean:
	-rm -f *~
	-rm -f $(OBJS) crt/start.o
	-rm -f libc.a
