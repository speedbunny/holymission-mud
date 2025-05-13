inherit "room/room";

reset(arg) {
  set_light(1);
  short_desc = "samroom";
  long_desc = 
        "This is Sam the janitor's office.\n"
        "You see Sam sitting at his desk writing.  He looks very tired.\n";
  items = ({ "desk" , "a small brown desk" });
  dest_dir = ({ "players/jake/basek.c","east" });
  clone_list = ({ 1, 1, "janitor", "players/jake/monster/janitor", 0 });

::reset();
replace_program("room/room");
}
