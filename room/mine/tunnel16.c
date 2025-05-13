/* 12.10.93 Airborne: Fixed. */

inherit "room/room";
object dwarf;

reset(arg){
 if(!arg){
  set_light(0);
  short_desc = "Tunnel";
  long_desc =  "In the tunnel into the mines.\n";
  dest_dir=({"room/mine/tunnel17","north",
             "room/mine/tunnel15","west"});

  if(!present("dwarf", this_object())){
      	dwarf = clone_object("obj/monster");
	dwarf->set_name("dwarf");
	dwarf->set_level(10);
        dwarf->set_race("dwarf");
        dwarf->set_size(2);
	dwarf->set_al(-100);
	dwarf->set_short("A short and sturdy dwarf");
	dwarf->set_wc(10);
	dwarf->set_ac(1);
	move_object(dwarf, this_object());
	}
    }
}
init(){
 ::init();
   add_action("block", "west");
}

block(){
    if (dwarf && present(dwarf)) {
	write("The dwarf bars the way !\n");
	return 1;
	}
    else {
	this_player()->move_player("west#room/mine/tunnel15");
	return 1;
	}
   }
