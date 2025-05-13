// Original code written by Adept@fotD
// Minor bugs and glitches fixed by Aryk@fotD & Spadex@fotD
// quest added by Aryk@archon
// Ported to Holy Mission by Aryk@archon/Brainsprain@holy mission

inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
static object armourer;

int read(string str) {
  if(str == "sign") {
    write("Thorin's Forge........Usage: make <armour/weapon>\n");
    return 1;
  }
  return 0;
}

void qcheck() {
  object clasp;
  object potion;
  remove_call_out("qcheck");
// 090398: Sauron: Should just check if a non 0 return value since the
//                 return value is the weight of the quest, not 1.
  if(TP->query_quests("dwarven_brothers")){
    return;
  }
  else
    clasp = present("#QR#",TP);
  if(clasp) {
    write(
	  "Thorin says: OH! My brothers signet, he must be alive, no, dont\n"+
	  "tell me where he is, i will be tempted to go to him, it is enough\n"+
          "to know he is alive.\n");
    potion = clone_object(bi+"/scroll1.c");
    if(!transfer(potion,TP))
        write("Thorin says: Thank you, the only reward I can give you is"
             +" this scroll\nthat a mage gave to me.\nThorin gives you"
             +" the morphic scroll.\n");
    else {
        write("Thorin says: Thank you. I would reward you with a scroll that"
             +" a mage gave\nto me, but you don't seem to be able to carry"
             +" it.\n");
        destruct(potion);
    }
    destruct(clasp);
    this_player()->set_quest("dwarven_brothers");
    return;
  }
  if(TP->query_race() == "dwarf" || ((clasp = present("#QP#",TP)) &&
                                      clasp->query_worn())) {
    clasp = clone_object("/players/brainsprain/bis/quest2/qclasp.c");
    if(!present("#QC#",TP) && present("thorin") && !transfer(clasp,TP)) {
      write(
	    "\n"+
	    "\n"+
	    "Thorin says: Finally, another dwarf has come along.  Please,\n"+
	    "you must help me.  My brother, Thelgar disappeared a few weeks\n"+
	    "ago.  Because of my focus, i am not able to leave this forge\n"+
	    "until I have created a masterpiece.  I fear for my brothers life.\n"+
	    "Please find him and bring him to me. This item will prove to my\n"+
	    "brother that you are my messenger.\n"+
	    "Thorin gives you a clasp.\n");
    }
    else
        destruct(clasp);
// Cannot start the quest if they cannot carry the clasp.
  }
}

void reset(int arg) {
  clone_list = ({ 1, 1, "thorin", br+"/armourer.c", 0 });
  ::reset(arg);
  
  if(arg) return;
  set_light(1);
  short_desc = "The Armoury";
  long_desc = 
    "The smell of metal and steel, mixed with the sounds "+
    "of the forging hammer beating iron fills your senses. A rack "+
    "of fine weapons stands in a place of pride against the west wall, "+
    "while a mighty forge stands in the middle of the room. There is "+
    "a sign beside the door.\n";
  items = ({
    "hammer",
    "The blacksmith's hammer",
    "wall",
    "A rack of fine weapons sits against it",
    "door",
    "A door leading back onto the streets of Towpath",
    "Towpath",
    "The town you are currently in",
    "iron",
    "Raw iron ore",
    "ore",
    "Raw iron ore",
    "sign",
    "Perhaps you should read it?",
    "rack",
    "A rack of fine dwarvish weapons",
    "weapons",
    "There are many sorts; battle axes, war hammers, swords...",
    "forge",
    "An ever burning, fiery forge",
  });
  dest_dir=({
    br+"/tr-6", "north",
  });
}

void init() {
  ::init();
  add_action("read", "read");
  call_out("qcheck",3);
}
