EXTRA_CFLAGS=-O0 -ggdb
INC_CFLAGS=-Iinclude

CFLAGS=-Wall -fPIC $(EXTRA_CFLAGS) $(INC_CFLAGS)

TARGET = libbinn.so.1.0
LINK1  = libbinn.so.1
LINK2  = libbinn.so
SHORT  = binn
INSTALL_PREFIX?=$(HOME)/usr

.PHONY: test

$(TARGET): binn.o binn_json.o
	gcc -shared -Wl,-soname,$(LINK1) -o $@ $^
# 	strip $(TARGET)

binn.o: src/binn.c include/binn.h
	gcc $(CFLAGS) -c $<

binn_json.o: conversions/json/binn_json.c include/binn_json.h
	gcc $(CFLAGS) -c $<

install: $(TARGET)
	cp $(TARGET) $(INSTALL_PREFIX)/lib
	cd $(INSTALL_PREFIX)/lib && ln -sf $(TARGET) $(LINK1)
	cd $(INSTALL_PREFIX)/lib && ln -sf $(TARGET) $(LINK2)
	cp include/binn*.h $(INSTALL_PREFIX)/include

uninstall:
	rm -fv $(INSTALL_PREFIX)/lib/libbinn* $(INSTALL_PREFIX)/include/binn*.h 

clean:
	rm -fv *.o $(TARGET) test/test_binn

test: test/test_binn.c test/test_binn2.c src/binn.c
	gcc $(CFLAGS) -DDEBUG -o test/test_binn $^

run_test: test/test_binn
	cd test && ./test_binn
