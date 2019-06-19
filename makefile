CC := gcc
CFLAGS := -g -O2 -Wall
INCLUDE += $(shell pkg-config --cflags allegro-5 allegro_acodec-5 allegro_audio-5 allegro_color-5 allegro_dialog-5 allegro_font-5 allegro_image-5 allegro_main-5 allegro_memfile-5 allegro_physfs-5 allegro_primitives-5 allegro_ttf-5)
LIBS := $(shell pkg-config --libs allegro-5 allegro_acodec-5 allegro_audio-5 allegro_color-5 allegro_dialog-5 allegro_font-5 allegro_image-5 allegro_main-5 allegro_memfile-5 allegro_physfs-5 allegro_primitives-5 allegro_ttf-5)
SOURCES := $(shell find src/ -type f -name "*.cpp")
TARGET := game
#------------------------------------------------------------------------

all: 
	$(CC) $(CFLAGS) $(INCLUDE) $(LIBS) $(SOURCES)
	mv a.out $(TARGET)
run:
	./game
clean:
	rm $(TARGET)

.PHONY: 
	all clean

