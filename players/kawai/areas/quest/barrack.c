inherit "room/room";

void reset(int arg) 
  {clone_list=({-1,1,"gold","obj/money",({"add_money",750}),
  1,5,"wizard","obj/monster",({"set_level",16,
  "set_hp",700,
  "set_race","human",
  "set_gender",1,
  "set_name","cult wizard",
  "set_alias","wizard",
  "set_al",-200,
  "set_chance",30,
  "set_spell_dam",30,
  "set_spell_mess1","Cult Member mumbles a word and you double over in pain.",
  "set_spell_mess2","Cult Member knocks you over with a bolt of lightning.",
  "set_short","A Cult member",
  "set_long","The cult member looks around as if paranoid.  His clothes are\n"+
  "stained in blood and bits of flesh and blood are encrusted around\n"+
  "his mouth.\n",
  "set_wc",18,
  "set_ac",10,
  "set_aggressive",1})});
  set_light(-4);
  short_desc = "Anteroom";
  long_desc ="You are in the cult barracks.  Not much can be said about it, "+
  "other than they don't treat themselves well.  Only makeshift "+
  "beds and slate slabs make for living arrangements.\n";
  smell = "The air smells of death and decay.";
  dest_dir = ({"players/kawai/areas/quest/anteroom","north"});
  items = ({"cave","It is cold and damp",
  "passage","It is cold and damp",
  "blood","A pool nearly a foot deep.  You wonder how many people\n"+
  "died for this.",
  "body","No wholes...just parts",
  "bodies","You only find fragments",
  "part","Looks like a foot...",
  "table","A piece of slate used as a table",
  "tables","The walls are lined with makeshift beds and tables of slate",
  "wall","The walls here are cleaner than the rest of the cave",
  "walls","The walls here are cleaner than the rest of the cave",
  "cave","You are in an underground cave",
  "slab","The slate functions as a nice table",
  "slabs","The slate functions as a nice table",
  "parts","Assorted body parts...",
  "rune","You can not read them",
  "runes","They are in some archaic language, foreign to you",
  "beds","There are hundreds of makeshift beds",
  "bed","It is made of only a board and a coarse blanket",
  "slate","It looks like it could function as a table"});
  ::reset(arg);
  replace_program("room/room");}
