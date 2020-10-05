#define   SAMPLE_PERIOD   60000//317
#define   SINE 0
#define   SAWTOOTH 1
#define   TRIANGLE 2
#define   SQUARE 3
#define   BTN1   0x01
#define   BTN2   0x02
#define   BTN3   0x04
#define   BTN4   0x08

// sound effect
typedef struct {
  uint32_t *buffer;
  unsigned int buffersize;
} soundeffect;

soundeffect *currentsound;
unsigned int playhead;
