inherit "room/room";

void reset(int arg) 
  {clone_list=({-1,1,"gold","obj/money",({"add_money",750}),
  1,3,"wizard","obj/monster",({"set_level",16,
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
  long_desc ="You are in a small chamber inside the caves.  To the south "+
  "can be seen some sort of barracks, while to the east can be\n"+
  "heard strange chanting.\n";
  smell = "The air smells of death and decay.";
  dest_dir = ({"players/kawai/areas/quest/barrack","south",
  "players/kawai/areas/quest/intersect","northwest",
  "players/kawai/areas/quest/inner","east"});
  items = ({"cave","It is cold and damp",
  "passage","It is cold and damp",
  "blood","A pool nearly a foot deep.  You wonder how many people\n"+
  "died for this.",
  "body","No wholes...just parts",
  "chamber","The rocks form a natural room here, with exits south and east",
  "rock","It is blood stained",
  "rocks","The blood stained walls form a natural chamber",
  "room","The rocks here form a natural chamber with exits south and east",
  "wall","The walls are damp and blood stained",
  "walls","The walls are damp and blood stained",
  "bodies","You only find fragments",
  "part","Looks like a foot...",
  "parts","Assorted body parts...",
  "rune","You can not read them",
  "runes","They are in some archaic language, foreign to you",
  "beds","There are hundreds of makeshift beds",
  "barrack","You see a room lined with makeshift beds and tables",
  "barracks","You see a room lined with makeshift beds and tables",
  "bed","It is made of only a board and a coarse blanket",
  "slate","It looks like it could function as a table"});
  ::reset(arg);
  replace_program("room/room");}
