inherit "/room/room";

void reset(int arg) {
  if(!arg) {
   set_light(0);
    short_desc="The Caverns of the Hourons.";
   long_desc="You have stumbled into a vast cavern that has been.\n";
             "hidden from all, since the very early days of Holy .\n";
             "mission. Time seems to have sttod still in this most.\n";
             "unholy of places. It is said that any who enter here.\n";
             "will surly parish at the hands of the Houron'sIf you.\n";
             "choose to enter here be warned that death may find you!.\n";
             
    dest_dir=({
      "/players/thumper/workroom","north",
      "/players/sauron/workroom","south",
    });
    items=({
      "nothing","There's sure alot of nothing in here...",
      "space","That's all there is in this room... space.",
    });
  }
  ::reset(arg);
}
