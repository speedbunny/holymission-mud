inherit "room/room";
 
object obj;
 
reset(arg) {
    if (arg) return;
    set_light(0);
    no_castle_flag=1;
    short_desc="In a cell";
    long_desc="You're in a cell. There's no opening here except the door to the south.\n";

    items=({
      "door","No chance to move it",
    });
    if(!obj) {
      obj=clone_object("obj/monster");
      obj->set_name("skeleton");
      obj->set_race("dead");
      obj->set_size(3);
      obj->set_level(4);
      obj->set_short("A skeleton");
      obj->set_long("A old and dirty skeleton.\n");
      obj->set_aggressive(1);
      obj->set_spell_mess1("The skeleton rips out one of its bones and strikes.");
      obj->set_spell_mess2("The skeleton rips out one of his bones and strikes you.");
      obj->set_chance(20);
      obj->set_spell_dam(20);
      move_object(obj,this_object());
    }
}
 
init() {
::init();
  add_action("south","south");
}
 
south() {
   if(!"players/bobo/krooms/castle/dungeon1"->query_lever_up())
	this_player()->move_player("north#players/bobo/krooms/castle/dungeon2");
  else {
    write("The cell-door is locked!\n");
    say(this_player()->query_name()+" tries to go south, but runs "+
       "straight into the door.\n");
    }
  return 1;
}
