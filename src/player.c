#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include <ao/ao.h>
#include <mpg123.h>

#define BITS 8

/**
 * play_music - Play an MP3 file.
 * @filename: The path to the MP3 file
 * 
 * Initialized the audio output and decodes the
 * MP3 file, playing it through the speakers.
 */
void play_music(const char *filename) {
    mpg123_handle *mh;
    unsigned char *buffer;
    size_t buffer_size;
    size_t done;
    int err;
    int driver;
    ao_device *dev;
    ao_sample_format format;
    int channels, encoding;
    long rate;

    /* Initializations */
    ao_initialize();
    driver = ao_default_driver_id();
    mpg123_init();
    mh = mpg123_new(NULL, &err);
    buffer_size = mpg123_outblock(mh);
    buffer = (unsigned char*) malloc(buffer_size * sizeof(unsigned char));

    /* Open the mp3 file */
    mpg123_open(mh, filename);
    mpg123_getformat(mh, &rate, &channels, &encoding);

    /* Set the output format */
    format.bits = mpg123_encsize(encoding) * BITS;
    format.rate = rate;
    format.channels = channels;
    format.byte_format = AO_FMT_NATIVE;
    format.matrix = 0;

    /* Open the audio device */
    dev = ao_open_live(driver, &format, NULL);

    /* Decode and play */
    while(mpg123_read(mh, buffer, buffer_size, &done) == MPG123_OK) {
        ao_play(dev, (char *)buffer, done);
    }

    /* Clean up */
    free(buffer);
    ao_close(dev);
    mpg123_close(mh);
    mpg123_delete(mh);
    mpg123_exit();
    ao_shutdown();
}
