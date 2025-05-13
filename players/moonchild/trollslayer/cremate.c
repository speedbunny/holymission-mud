#include "room.h"

object gnome;
int corpseno;
string corpsetype;

#undef EXTRA_RESET
#define EXTRA_RESET\
  extra_reset();

extra_reset() {
  if(!gnome) {
    gnome=clone_object("obj/monster");
    gnome->set_name("gnome");
    gnome->set_short("A small gnome");
    gnome->set_long("A small ugly gnome.\n");
    gnome->set_level(7);
    gnome->set_wc(14);
    gnome->set_al(-100);
    gnome->set_aggressive(1);
    move_object(gnome,this_object());
  }
  corpsetype=allocate(6);
  corpsetype[0]="frog";
  corpsetype[1]="orc";
  corpsetype[2]="dwarf";
  corpsetype[3]="troll";
  corpsetype[4]="giant";
  corpsetype[5]="";
}

ONE_EXIT("room/mine/tunnel5", "west",
	"A blood-red room",
	"This is a blood-red room in the mines with a huge blood-red pentagram on the\n" +
	"floor and a massive blood-red sacrificial altar. This place stinks of evil.\n", 0)

init() {
  ::init();
  add_action("sacrifice", "sacrifice");
  add_action("sacrifice", "cremate");
}

id(str) { return str=="pentagram" || str=="altar"; }

sacrifice(str) {
  object corpse,sword;
  if(str!="corpse") {
    write("Sacrifice what?\n");
    return 1;
  }
  corpse=present("corpse",this_object());
  if(!corpse) {
    write("There are no corpses in the room.\n");
    return 1;
  }
  if(present("gnome")) {
    write("The gnome bars your way.\n");
    return 1;
  }
  write("You sacrifice " + corpse->short() + " on the altar.\n");
  say(this_player()->query_name() + " sacrifices " + corpse->short()
	 + " on the altar.\n");
  if((corpse->query_name() != corpsetype[corpseno]) &&
	(corpse->query_race() != corpsetype[corpseno])) {
    destruct(corpse);
    tell_room(this_object(),"Nothing happens.\n");
    return 1;
  }
  destruct(corpse);
  if(!present("trollslayer vision object",this_player())) {
    tell_room(this_object(), "You hear a rattling and a shaking from below.\n");
    return 1;
  }
  corpseno++;
  if(corpseno!=5) {
    tell_room(this_object(), "You hear a distant rumbling sound.\n");
    log_file("moonchild.quest", ctime(time()) + ": " + this_player()->query_name() + " (level " + this_player()->query_level() + ") sacrificed corpse of " + corpsetype[corpseno-1] + ".\n");
    return 1;
  }
  tell_room(this_object(), "There is a flash of light and a giant longsword appears on the altar!\n");
  move_object(clone_object("players/moonchild/trollslayer/trollslayer"),this_object());
  log_file("moonchild.quest", ctime(time()) + ": " + this_player()->query_name() + " (level " + this_player()->query_level() + ") got the sword Trollslayer.\n");
  call_out("new",180,0);
  return 1;
}
  
long(str) {
  if(str=="pentagram") {
    write("A truly horrible looking blood-red pentagram.\n");
    return 1;
  }
  if(str=="altar") {
    write("An enormous altar, used for sacrificing corpses to the gods.\n");
    return 1;
  }
  if(!str && present("trollslayer vision object", this_player())) call_out("vision",2,0);
  ::long();
}

vision() {
  if(corpseno==5) return;
  write("You see a fleeting vision of the dead body of a " + corpsetype[corpseno] + ".\n");
}

new() { corpseno=0; }
