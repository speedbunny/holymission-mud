#include "../defs.h"

inherit GEN_GRAVE;

void reset( int arg ) {
  ::reset( arg );
  if( arg ) return;

  short_desc = "At a weather beaten mausoleum.";
  long_desc = "You are standing in front of a weather beaten mausoleum. "
    + "It consists of a black granite block of stone, on which the marble "
    + "statues of a lord and a lady have been placed. The finest features "
    + "of the statures did not withstand the ravages of time. Also the "
    + "once fine materials now have a dull grey haze on them.\n";
  hidden_dir = ({
    ROOM_DIR + "cemetry6", "north",
  });
  no_obvious_msg = "The gravel path lies directly north of this grave.\n";
  items=({
    "mausoleum", "It's the only one around, so it probably belongs to the "
      + "family that ruled these lands before they were cursed",
    "block", "In the black granite the words \"Lord Sashya & Lady Karinev\" "
      + "are engraved",
    "statues", "The statues of a stern bearded man and a richly dresses "
      + "woman, lying hand in hand are on top of the granite block. They "
      + "have a peaceful look on their faces, which seems oddly out of "
      + "place here",
  });
}

int do_dig() {
  printf( "You cannot dig here!\nThe entire grave is covered with a few "
    + "tons of granite and marble.\n" );
  return 1;
}
