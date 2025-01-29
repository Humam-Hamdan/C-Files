
CEXE = main
CSRC := $(CEXE).c datum.c ostern.c
COBJ := $(patsubst %.c,%.o,$(CSRC))

$(CEXE): $(COBJ)
	$(CC) $^ -o $@

%.o: %.c
	$(CC) -c $< -o $@

clean: 
	rm -f $(COBJ)
