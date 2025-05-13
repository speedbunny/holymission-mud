inherit "/room/room";

void reset(int arg) {
  if(!arg) {
    set_light(0);
    short_desc="The Caverns of the Hourons.";
    long_desc="\
You have stumbled into a vast cavern that has been hidden from all \
since the very early days of Holy Mission. Time seems to have stood \
still in this most unholy of places. It is said that any who enter \
here will surely perish at the hands of the houron's. If you choose to \
 enter here be warned death may find you. Caution: You have already  \
stepped into a puddle of acid, better be more careful!\n";
             
    dest_dir=({
      "/players/thumper/workroom","north",
      "/players/sauron/workroom","south",
    });
    items=({
     "acid pools","There are bubbling pools of acid all around...",
      "Blood","The walls are stained with dried blood.",
    });
  }
  ::reset(arg);
}
