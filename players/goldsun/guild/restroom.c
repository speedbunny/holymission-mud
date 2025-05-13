inherit "room/room";

object board;
int x;

reset(arg) {

    if(!present("lvlbook")) 
        move_object(clone_object("/players/capablanca/guild/book.c"),
		    this_object());

    if(!board) {
       board=clone_object("obj/board");
       board->set_file("players/goldsun/guild/confer/g_board");
       board->set_name("fighters");
       board->set_short("The fighters board");
       move_object(board,this_object());
    }
    if (!present("blue scroll",this_object()))
    {
        for(x=0;x<3;x++)
        {
           move_object(clone_object("/players/whisky/obj/recall_scroll"),
           this_object());
        }
    }
    
    if (arg) return;
    set_light(1);
   short_desc = "Resting room";
    no_castle_flag = 0;
    long_desc="This is the fighters most favourite room. You may stay "+
      "here as long as you want and cure your wounds after bashing "+
      "your favourite monster. Guild rooms. Type 'mantle' and/or 'sword' "+
      "to get your own "+
      "Fighter's mantle and sword. This room is only for fighters!!!\n";
    property=({"no_fight","no_steal"});
    dest_dir = 
        ({
        "players/goldsun/guild/room","west",
        });
}

try_attack(ob) {
  write("This is a peaceful place.\n");
return 1;
}

init() {
  if(this_player()->query_guild() != 3 && !this_player()->query_immortal()) {
    say("It is a non fighter! Throw him out!\n");
    printf("You are booted out of the guild rooms!\n");
    this_player()->move_player("off the foot of a fighter#players/portil/guild/room");
    return;
  }
  ::init();
  add_action("mantle","mantle");
  add_action("sword","sword");
}

sword() {
  object sword;
  if (present("bastardsword",this_player())) {
     write("You already have one.\n");
     return 1;
  }
  if(this_player()->query_guild() != 3) {
    write("PISS OFF SCUM\n");
    return 1;
  }
  sword = clone_object("players/capablanca/weapons/bas_sword.c");
 sword->set_weight(0);
  if(transfer(sword,this_player())) { /* Moonchild 051092 - move_object() fix */
    write("You are carrying too much!\n");
    destruct(sword);
    return 1;
  }
  write("You get your own Fighter sword.\n");
  return 1;
}

mantle() {
  object ob2;
  if (present("fighter_mantle",this_player())) {
     write("You already have one.\n");
     return 1;
  }
  if(this_player()->query_guild() != 3) {
    write("ARE YOU NUTS SCUM ???\n");
    return 1;
  } 
  ob2 = clone_object("players/capablanca/guild/mantle.c");
  if(transfer(ob2,this_player())) { /* Moonchild 051092 - move_object() fix */
    write("You are carrying too much!\n");
    destruct(ob2);
    return 1;
  }
  write("You get your own Fighter's mantle.\n");
  return 1;
}

