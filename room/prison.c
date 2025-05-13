/* Changed by Ethereal Cashimor to disallow teleporting in general,
   and prevent shouting in general. 160393 
   Changed by Ethereal Cashimor, 230393: Now is a drunktank and contains
   a bed... */
inherit "room/room";

reset(arg) {
object bed;

  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc="The local drunktank";
    long_desc="This is the local drunktank. Players who misbehaved are stored "
            + "here till they are more relaxed. There is, of course, no way "
            + "out.\n";
    no_obvious_msg="";
    property=({"no_teleport"});
    smell="The smell of decay hangs in the air.";
    if(!present("bed",this_object())) {
      bed=clone_object("players/cashimor/things/bed");
      bed->set_short("A bed that is in a terrible shape");
      bed->set_long("It looks as if many people have slept in it already.\n");
      move_object(bed,this_object());
    }    
  }
}

init() {
    ::init();
    add_action("van","vanish");
    add_action("quit","goback");
    add_action("quit","goguild");
    add_action("quit","quo_vadis");
    add_action("stronghold","stronghold");
    add_action("shout_it","shout");
    add_action("tell_it","tell");
    add_action("quit","quit");
    add_action("try_prison", "prison");
}

quit() { return 1; }
stronghold() { return 1; }
van(str) {return 1;}
try_prison(str) { return 1; }  /* no escape through mage prison! */
shout_it() { return 1; }

tell_it(str) {
string tmp;
object who;

  if(!str) {
    write("Tell what?\n");
    return 1;
  }
  tmp=explode(str," ");
  who=find_player(tmp[0]);
  if(!who) {
    write("Tell who?\n");
    return 1;
  }
  if(!who->query_wizard()) {
    write("You can only tell to wizards now!\n");
    return 1;
  }
  return 0;
}
