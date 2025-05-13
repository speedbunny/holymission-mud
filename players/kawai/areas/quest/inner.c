inherit "room/room";

void reset(int arg)
  {clone_list=({1,5,"wizard","obj/monster",({"set_level",16,
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
  "add_money",500,
  "set_aggressive",1}),
  2,1,"kq1-statue","/players/kawai/obj/statue",0});
  set_light(1);
  short_desc = "Inner Chambers";
  long_desc ="You are in the cults sacred inner chambers.  Here, amidst piles "+
  "of decaying bodies, the cult performs their ritual sacrifices to "+
  "their idol Kazak.  There is a small alcove along the southeast wall.\n";
  smell = "The air smells of death and decay.";
  dest_dir = ({"players/kawai/areas/quest/anteroom","west",
  "players/kawai/areas/quest/alcove","southeast"});
  items = ({"cave","It is cold and damp",
  "passage","It is cold and damp",
  "blood","A pool nearly a foot deep.  You wonder how many people\n"+
  "died for this.",
  "body","No wholes...just parts",
  "fragments","A foot!",
  "fragment","A finger!",
  "alcove","A small cave, just big enough to fit a person or two",
  "finger","Just a finger....just like the ones you have",
  "foot","Somebody's right foot",
  "bodies","You only find fragments",
  "part","Looks like a foot...",
  "parts","Assorted body parts...",
  "rune","You can not read them",
  "runes","They are in some archaic language, foreign to you"});
  ::reset(arg);
  replace_program("room/room");}
