#define   SAMPLE_PERIOD   317

#define   BTN1   0x01
#define   BTN2   0x02
#define   BTN3   0x04
#define   BTN4   0x08

#define   BTN6   0x32
#define   BTN8   0x128

#define   FLAAKLYPA 1
#define   COIN 2
#define   JUMP 3
#define   DEATH 4
#define   NONE 0
#define   FREQUENCY 44100

uint32_t *CURRENT_SONG; // Might be redundant
struct song *current_song;
uint32_t *ticks;
uint32_t *volume;