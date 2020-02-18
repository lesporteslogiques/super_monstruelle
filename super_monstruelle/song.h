#ifndef SONG_H
#define SONG_H

#define Song const uint8_t PROGMEM

Song music[] = {
0x09,      // Number of tracks
0x00, 0x00,   // Address of track 0
0x09, 0x00,   // Address of track 1
0x0a, 0x00,   // Address of track 2
0x0b, 0x00,   // Address of track 3
0x10, 0x00,   // Address of track 4
0x16, 0x00,   // Address of track 5
0x1d, 0x00,   // Address of track 6
0x27, 0x00,   // Address of track 7
0x5c, 0x00,   // Address of track 8
0x00,     // Channel 0 entry track
0x01,     // Channel 1 entry track
0x02,     // Channel 2 entry track
0x03,     // Channel 3 entry track
//"Track channel 0"
0x9D, 24,   // FX: SET TEMPO: tempo = 24
0x40, 64,   // FX: SET VOLUME: volume = 64
0xFC, 7,    // GOTO track 7
0xFC, 0,    // GOTO track 0
0x9F,     // FX: STOP CURRENT CHANNEL
//"Track channel 1"
0x9F,     // FX: STOP CURRENT CHANNEL
//"Track channel 2"
0x9F,     // FX: STOP CURRENT CHANNEL
//"Track channel 3"
0xFC, 8,    // GOTO track 8
0xFC, 3,    // GOTO track 3
0x9F,     // FX: STOP CURRENT CHANNEL
//"Track tick"
0x40, 32,   // FX: SET VOLUME: volume = 32
0x9F + 1,   // DELAY: ticks = 1
0x40, 0,    // FX: SET VOLUME: volume = 0
0xFE,     // RETURN
//"Track snare"
0x40, 32,   // FX: SET VOLUME: volume = 32
0x41, -16,    // FX: VOLUME SLIDE ON: steps = -16
0x9F + 2,   // DELAY: ticks = 2
0x43,     // FX: VOLUME SLIDE OFF
0xFE,     // RETURN
//"Track shake"
0x49, 4 + 0,    // FX: RETRIG NOISE: point = 1 (*4) / speed = 0 (fastest)
0x40, 32,   // FX: SET VOLUME: volume = 32
0x41, -8,   // FX: VOLUME SLIDE ON: steps = -8
0x9F + 4,   // DELAY: ticks = 4
0x4A,     // FX: RETRIG: off
0x43,     // FX: VOLUME SLIDE OFF
0xFE,     // RETURN
//"Track melo2"
0x00 + 26,    // NOTE ON: note = 26
0x9F + 1,   // DELAY: ticks = 1
0x00 + 0,   // NOTE ON: note = 0
0x9F + 6,   // DELAY: ticks = 6
0x00 + 26,    // NOTE ON: note = 26
0x9F + 1,   // DELAY: ticks = 1
0x00 + 0,   // NOTE ON: note = 0
0x9F + 3,   // DELAY: ticks = 3
0x00 + 29,    // NOTE ON: note = 29
0x9F + 1,   // DELAY: ticks = 1
0x00 + 0,   // NOTE ON: note = 0
0x9F + 1,   // DELAY: ticks = 1
0x00 + 18,    // NOTE ON: note = 18
0x9F + 1,   // DELAY: ticks = 1
0x00 + 0,   // NOTE ON: note = 0
0x9F + 1,   // DELAY: ticks = 1
0x00 + 33,    // NOTE ON: note = 33
0x9F + 1,   // DELAY: ticks = 1
0x00 + 0,   // NOTE ON: note = 0
0x9F + 7,   // DELAY: ticks = 7
0x00 + 34,    // NOTE ON: note = 34
0x9F + 1,   // DELAY: ticks = 1
0x00 + 0,   // NOTE ON: note = 0
0x9F + 1,   // DELAY: ticks = 1
0x00 + 46,    // NOTE ON: note = 46
0x9F + 1,   // DELAY: ticks = 1
0x00 + 0,   // NOTE ON: note = 0
0x9F + 1,   // DELAY: ticks = 1
0x00 + 23,    // NOTE ON: note = 23
0x9F + 1,   // DELAY: ticks = 1
0x00 + 0,   // NOTE ON: note = 0
0x9F + 3,   // DELAY: ticks = 3
0x00 + 26,    // NOTE ON: note = 26
0x9F + 1,   // DELAY: ticks = 1
0x00 + 0,   // NOTE ON: note = 0
0x9F + 3,   // DELAY: ticks = 3
0x00 + 28,    // NOTE ON: note = 28
0x9F + 1,   // DELAY: ticks = 1
0x00 + 0,   // NOTE ON: note = 0
0x9F + 7,   // DELAY: ticks = 7
0x00 + 36,    // NOTE ON: note = 36
0x9F + 1,   // DELAY: ticks = 1
0x00 + 0,   // NOTE ON: note = 0
0x9F + 3,   // DELAY: ticks = 3
0x00 + 28,    // NOTE ON: note = 28
0x9F + 1,   // DELAY: ticks = 1
0x00 + 0,   // NOTE ON: note = 0
0x9F + 7,   // DELAY: ticks = 7
0x00 + 34,    // NOTE ON: note = 34
0x9F + 1,   // DELAY: ticks = 1
0x00 + 0,   // NOTE ON: note = 0
0x9F + 8,   // DELAY: ticks = 8
0xFE,     // RETURN
//"Track Drum"
0xFC, 4,    // GOTO track 4
0x9F + 2,   // DELAY: ticks = 2
0xFC, 5,    // GOTO track 5
0x9F + 6,   // DELAY: ticks = 6
0xFC, 5,    // GOTO track 5
0x9F + 10,    // DELAY: ticks = 10
0xFC, 6,    // GOTO track 6
0x9F + 4,   // DELAY: ticks = 4
0xFC, 4,    // GOTO track 4
0x9F + 11,    // DELAY: ticks = 11
0xFC, 6,    // GOTO track 6
0x9F + 8,   // DELAY: ticks = 8
0xFC, 6,    // GOTO track 6
0x9F + 5,   // DELAY: ticks = 5
0xFE,     // RETURN

};



#endif
