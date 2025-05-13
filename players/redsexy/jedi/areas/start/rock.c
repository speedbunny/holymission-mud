//This room to replace "/players/emerald/seaworld/room/rock.c"
//Thanks - Redsexy
inherit "/room/room";

void reset(int arg) {

  if (arg) return;

  set_light(1);

  short_desc="On a rock";

  long_desc="You are standing on a big rock in the sea.  The wind is softly "+
            "blowing through your hair.  An old sailor usually sits here, "+
            "watching the sea.  There is a big rope hanging down to the "+
            "sea, allowing you to climb back up if you risk jumping down "+
            "into the waves.\n";

  items=({"rock","You see a big black rock standing in the sea",
          "rope","You see a long brown rope hanging down to the sea",
          "sea","You see the blue sea and the waves rolling up the rock",
          "wind","It softly ruffles your hair",
          "waves","They do not appear terribly rough.  You could jump into "+
                  "them if you wanted to",
        });

  dest_dir=({"/players/emerald/seaworld/room/path_end", "west",
             "/players/redsexy/jedi/areas/start/port1", "north",
             "/players/warlord/trans/port4", "up",
           });

  clone_list=({
    1,1,"sailor","/players/emerald/seaworld/obj/sailor",0,
    -1,1,"sword","obj/weapon",({
      "set_name","sword",
      "set_class",12,
      "set_alias","sailors sword",
      "set_short","A sailors sword",
      "set_long","The good weapon of the drunken sailor.\n",
      "set_type",2,
      "set_value",400,
      "set_weight",2,
    }),
    -1,1,"jacket","obj/armour",({
      "set_name","jacket",
      "set_alias","sailors jacket",
      "set_short","A dirty sailors jacket",
      "set_long","The dirty jacket of the drunken sailor.\n",
      "set_type","armour",
      "set_ac",2,
      "set_size",3,
      "set_weight",2,
      "set_value",120,
    }),
    -1,1,"rucksack","obj/container",({
      "set_name","rucksack",
      "set_alias","sack",
      "set_max_weight",30,
      "set_short","A rucksack",
      "set_long","A nice little bag, with two belts to carry it over your back.\n",
      "set_value",75,
      "set_weight",1,
    }),
    -1,1,"beer","obj/alco_drink",({
      "set_name","beer",
      "set_empty_container","bottle",
      "set_short","A bottle of beer",
      "set_long","A bottle of beer.\n",
      "set_strength",10,
      "set_value",10,
      "set_weight",1,
      "set_drinking_mess"," drinks some beer.\n",
      "set_drinker_mess","It's a little bitter.\n",
    }),
  });

  ::reset(arg);
}

void init() {
  ::init();
  add_action("_jump","jump");
  }

int _jump(string str) {
  write("****  Y o u    a r e    f a l l i n g  ****\n\n\n\n");
  write("****  Y o u    a r e    f a l l i n g  ****\n\n\n\n");
  write("****  Y o u    a r e    f a l l i n g  ****\n\n\n\n");
  write("****  Y o u    a r e    f a l l i n g  ****\n\n\n\n");
  write("****  Y o u    a r e    f a l l i n g  ****\n\n\n\n");
  write("****  Y o u    a r e    f a l l i n g  ****\n\n\n\n");
  write("****  Y o u    a r e    f a l l i n g  ****\n\n\n\n");
  write("****  Y o u    a r e    f a l l i n g  ****\n\n\n\n");

  this_player()->move_player("down#players/emerald/seaworld/room/sw1");
  return 1;
}
