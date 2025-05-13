inherit "room/room";

reset(arg) {

if (!arg) {
  set_light(1);
  short_desc="A dimly light corridor";
  long_desc=
     ("You are in a dimly light corridor, from the east you can hear\n"+
      "a huge bat beating softly with her wings.\n");
  items=({
     "bat","A huge bat",
     "corridor","A dimly light corridor"
        });
  dest_dir=({
     "/players/jewel/quest/vtower7","west",
     "/players/jewel/quest/vtower9","east"
           }); 
  }
}

init() {
object vam;

  ::init();
  if((vam=present("vampire king")) && (this_player()!=vam)) 
    call_out("run_vamp",2,vam);
}

run_vamp(vam) {
  vam->move_player("east#players/jewel/quest/vtower9");
  vam->set_aggressive(1);
}
