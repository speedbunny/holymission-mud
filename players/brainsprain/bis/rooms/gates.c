inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg) {

  short_desc = "Bismarck Keep gates";
  long_desc =
"Before you lies an enormous castle gate.  This is the primary protection "+
"for Bismarck Keep. And what an impressive keep it is too.  It is evident "+
"that its owner is a very rich man.  From the sounds of the noise coming "+
"from inside it sounds as if they are having a party!\n";
  set_light(1);
  dest_dir = ({
    br+"/ch-1","west",
    br+"/castle_path.c","east",

  });
items = ({
  "gate","Huge steel gates with wrought iron hinges",
  "hinges","The hinges of the gate",
  "castle","Castle Bismarck",
  "keep","Castle Bismarck",
  "bismarck","Castle Bismarck",
  "gates",
  "Huge steel gates with wrought iron hinges",
  });
clone_list = ({ 1, 2, "guard", bm+"/guard.c", 0 });

   ::reset(arg);

    replace_program("room/room");
}
