inherit "room/room";

#include "/players/jake/defs.h"

reset (arg) {
 if(arg) return;
 set_light(1);
 short_desc = "An empty stable";
 long_desc  = "You are standing in an empty stable.  It looks as is this stable\n" +
              "isn't used for horses, because of the large pile of hay and\n" +
              "various pitch forks and rakes stored here.  A few saddles are\n" +
              "also here.\n";
 items = ({
  "hay","A large pile of hay to feed the horses.\nIt looks like something may be in there",
  "pitchforks","Pitch forks used to shovel the hay",
  "forks","Pitch forks used to shovel the hay",
  "rakes","Rakes used to rake the hay",
  "saddles","Saddles used when the horses are ridden",
 });
 DD = ({
      CAS + "s3","west",
      });
}
init() {
 ::init();
 add_action("search","search");
}
 search(str) {
 switch(str) {
  case "hay":
  write("You search through the hay and find nothing. :(\n");
  say(TPN + " searches through the hay.\n");
return 1;
}
}
