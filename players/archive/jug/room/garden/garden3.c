inherit "room/room";
 
void reset(int arg) {
  set_light(1);
 
  short_desc = "Garden dead end";
  long_desc = 
    "This is a really peaceful place. To the south is a wall and to the east "+
    "and north is a hedge. There is a big oak here which casts a shadow upon "+
    "you. You feel that you could stay in the shade of this huge tree for "+
    "quite awhile.\n";
 
  items = ({
    "oak", "A big old oak peacfuly stands here giving off a nice cool shadow",
    "wall","It is to the south",
    "hedge","It blocks any passage to the north",
    "shadow","It is the shadow of a tree",
  });
 
  dest_dir = ({
    "/players/jug/room/garden/garden2", "west",
  });
 
  clone_list = ({
    1,1,"mole","/players/jug/monster/baby_mole",0,
  });
 
  ::reset(arg);
  replace_program("/room/room");
}
