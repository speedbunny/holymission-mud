/* ALTAR.C - Programmed by Moonchild */
/* 261094: Ethereal Cashimor: Changed the queries to the corpse */
// 27.02.95 Whisky a bug was in now its gone :)

inherit "room/room";

object gnome;
int corpseno;
string *corpsetype;

reset(arg) {
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
  if(corpseno || !arg) {
    tell_room(this_object(),
        "A small gnome arrives and dusts the pentagram and altar.\n");
    corpsetype=allocate(5);
    corpsetype[0]=({ "frog", "ant", "sparrow" })[random(3)];
    corpsetype[1]=({ "bear", "sheep", "orc" })[random(3)];
    corpsetype[2]=({ "dwarf", "octopus", "gnome" })[random(3)];
    corpsetype[3]=({ "troll", "goblin", "ogre" })[random(3)];
    corpsetype[4]=({ "giant", "shark", "dragon" })[random(3)];
    corpseno=0;
  }
  if(arg) return;
  short_desc="A blood-red room";
  long_desc="This is a blood-red room in the mines with a huge blood-red pentagram on the\n"
        + "floor and a massive blood-red sacrificial altar. This place stinks of evil.\n";
  dest_dir=({ "room/mine/tunnel27", "south" });
  items=({ "pentagram", "A truly horrible looking blood-red pentagram",
        "altar", "An enormous altar, used for sacrificing corpses to the gods" });
}

init() {
  ::init();
  add_action("sacrifice", "sacrifice");
  add_action("sacrifice", "cremate");
  call_out("vision", 2, 0);
}

vision() {
  if(corpseno!=5)
    printf("You see a fleeting vision of the dead body of a %s.\n",
        corpsetype[corpseno]);
}

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
  if (corpseno<5 && corpse && corpse->query_real_name()!=(corpsetype[corpseno])
      && corpse->query_race()!= (corpsetype[corpseno]) )
   {
    destruct(corpse);
    tell_room(this_object(),"Nothing happens.\n");
    return 1;
  }
  if (corpse)
  {
    destruct(corpse);
    corpseno = corpseno + 1;
   }
  if(corpseno!=5) {
    tell_room(this_object(), "You hear a distant rumbling sound.\n");
    call_out("vision", 2, 0);
    return 1;
  }
  tell_room(this_object(), "There is a flash of light and a giant longsword appears on the altar!\n");
  move_object(clone_object("players/moonchild/trollslayer/trollslayer"),this_object());
  call_out("reset", 180, 0);
  return 1;
}
query_corpsetypes()
{
   return corpsetype;
}
