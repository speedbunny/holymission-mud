 // see file's /players/jewel/quest/quest_changes/README and README.2nd DRAGONN
inherit "room/room";

object co;

reset(arg) {
int i;

  if (!arg) {
    co=allocate(3);
    set_light(0);
    short_desc="The vampire kings tomb";
    long_desc=
      ("You are standing in the vampire kings tomb, you see three huge\n"+
       "black coffins with golden ornaments\n");
    items=({
       "ornaments","They look very nice, a master of art must have made them"
          });
     property = ({
       "no_teleport","no_sneak","no_steal",
              });      /* fighting with quest cheaters 12apr96 Dragonn*/
    dest_dir=({
       "/players/jewel/quest/vtower9","south"
             });
    for(i=0;i<3;i++) {
      move_object(co[i]=clone_object("obj/container"),this_object());
      co[i]->set_weight(500);
      co[i]->set_max_weight(600);
      co[i]->set_value(10000); 
      co[i]->set_name("coffin");
      co[i]->set_short("A huge, black coffin");
      co[i]->set_long("A huge, black coffin with golden ornaments.\n");
    }
  }
}

init() {
    ::init();
    add_action("hammer","hammer");
}

hammer(arg) {
    int i,ki,c,w;
    object vamp,o;

  for(i=0;i<3 && !vamp;i++) {
        vamp=present("vampire king",co[i]);
  }

   if(this_player()->query_level()<15){
      write("Vampire shouts: '"+this_player()->query_real_name()+" isn't allowed to come there.\n");
      this_player()->move_object("south#/players/jewel/quest/vtower9");
    }
  if(!present("mallet",this_player())) {
        write("With what ?\n");
        return 1;
  }
  if(!arg) {
        write("Hammer what ?\n");
        return 1;
  }
  if(arg=="pole") {
        if(!present("wooden pole",this_player())) {
          write("You havn't got a pole.\n");
          return 1;
        }
        write("Hammer pole in what ?\n");
        return 1;
  }
  if(arg=="pole in vampire" || arg=="pole into vampire" ||
     arg=="pole in vampire king" || arg=="pole into vampire king") {
        if(!present("wooden pole",this_player())) {
          write("You havn't got a pole.\n");
          return 1;
        }
        if(!vamp) {
          write("The vampire king is not here.\n");
          return 1;
        }
        write("Where in vampire ?\n");
        return 1;
  }
  if(arg=="pole in vampires heart" || arg=="pole into vampires heart" ||
     arg=="pole in vampire kings heart" || 
     arg=="pole into vampire kings heart" ||
     arg=="pole in vampire heart" || arg=="pole into vampire heart" ||
     arg=="pole in vampire king heart" || 
     arg=="pole into vampire king heart") {
        if(!present("wooden pole",this_player())) {
          write("You havn't got a pole.\n");
          return 1;
        }
        if(!vamp) {
          write("The vampire king is not here.\n");
          return 1;
        }
        for(i=c=w=0;i<3;i++) {
          if(!present(vamp,co[i]) && present("cross",co[i])) c=1;
          else if(!present(vamp,co[i]) && present("holy water",co[i])) w=1;
        }
        if(c && w) {
          shout(
"The vampire king shouts: AAAAAHHHHHHHHHRRRRRRRRRGGGGGGGGGGGGGGgggg g g .... \n"
               );
          tell_room(this_object(),"The vampire king crumbles to dust.\n");
      this_player()->set_quest("vampirequest");
      for(i=0;i<3;i++) {
        if(o=present("cross",co[i])) destruct(o);
        if(o=present("holy water",co[i])) destruct(o);
      }
      destruct(vamp);
    } else {
      i=random(3);
      while(present("cross",co[i]) ||
            present("holy water",co[i])) i=random(3);
      write("The vampire king transforms into a cloud of gas and "+
            "floats to another coffin.\n");
      transfer(vamp,co[i]);
    }
    return 1;
  }
  write("You cant hammer that or there.\n");
}

get_coffin(c) { return co[c]; }
