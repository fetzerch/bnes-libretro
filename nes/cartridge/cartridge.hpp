#include "chip/chip.hpp"
#include "board/board.hpp"

struct Cartridge : Processor, property<Cartridge> {
  static void Main();
  void main();

  void load(const string &markup, const uint8_t *data, unsigned size);
  void unload();

  unsigned ram_size();
  uint8* ram_data();

  void power();
  void reset();

  readonly<bool> loaded;
  readonly<string> sha256;

  void serialize(serializer&);
  Cartridge();

//privileged:
  Board *board;

  uint8 prg_read(unsigned addr);
  void prg_write(unsigned addr, uint8 data);

  uint8 chr_read(unsigned addr);
  void chr_write(unsigned addr, uint8 data);

  //scanline() is for debugging purposes only:
  //boards must detect scanline edges on their own
  void scanline(unsigned y);
};

extern Cartridge cartridge;
