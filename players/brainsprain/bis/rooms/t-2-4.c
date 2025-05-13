inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"

void qcheck(){
  if(present("#QC#",TP)){
    if(!present("#QR#",TP)){
    call_out("give_sig",3);
  }
}
}
void give_sig(){
  object signet;
  remove_call_out("give_sig");
  write(
	"\n"+
	"Thelgar says: Oh! A messenger from my brother!\n"+
	"Thelgar grabs your arm and whispers conspiratorily: You wondering\n"+
	"how i knew? That is his clasp you have.  I miss my brother a lot.\n"+
	"Please do me a favor and bring him this so he knows I am ok.\n"+
	"Thelgar give you his signet.\n");
  signet = clone_object(q2+"/qring.c");
  move_object(signet,TP);
}

void reset(int arg) {
  clone_list = ({ 1, 1, "thelgar", bm+"/thelgar.c", 0, }); 
  ::reset(arg);
  if(arg) return;

  short_desc = "The Royal Armoury";
  long_desc =
    "A huge forge dominates this room.  In the center of the room is a "+
    "massive anvil with a newly forged sword sitting on it.  A work bench "+
    "and cooling trough sit against the northern curve of the wall.  A rack "+
    "sitting along the southern wall contains weapons and armour of "+
    "magnificient quality. Next to the anvil is a trapdoor leading down.\n";
  set_light(1);
  dest_dir = ({
    br+"/t-2-3.c","down",
  });
  items = ({
    "trapdoor",
    "It leads to the lower levels of the tower",
    "room",
    "The Royal Armoury",
    "bismarck",
    "The kingdom you are in",
    "weapons",
    "Weapons of every type",
    "armour",
    "The quality astounds you",
    "forge",
    "The royal forge",
    "anvil",
    "A huge anvil on which many fine weapons are beat into shape",
    "bench",
    "A massive wooden bench",
    "trough",
    "A cooling trough used to quickly cool a newly made item",
    "rack",
    "A steel rack with a protection spell where all items are stored",
    "sword",
    "A sword with the seal of Bismarck on it",
  });
}
init(){
  ::init();
  qcheck();
}
