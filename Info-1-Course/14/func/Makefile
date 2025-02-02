
CEXE = main
CSRC := $(CEXE).c func1.c func2.c
COBJ := $(patsubst %.c,%.o,$(CSRC))

$(CEXE): $(COBJ)
	$(CC) $^ -o $@

%.o: %.c
	$(CC) -c $< -o $@

clean: 
	rm -f $(COBJ)
