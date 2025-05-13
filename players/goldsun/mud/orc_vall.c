/* 120593: Ethereal Cashimor, embellished. */
inherit "room/room";

string chats;

reset(arg) {
  if(!arg) {
    set_light(1);
    short_desc="The orc valley";
    long_desc="You are in the orc valley. This place is inhabited by orcs." 
            + " There is a fortress to the north, with lots of signs of "
            + "orcs.\n";
    items=({"valley","Well, it would be pretty, if it wasn't for those orcs..",
            "place","It's a valley",
            "fortress","It looks dangerous",
            "signs","Well, the smell is unmistakable"});
    dest_dir=({"room/fortress", "north",
	       "players/herp/orc/v0", "west",
	       "room/slope", "east"});
    smell="It stinks here.";
  }
  extra_reset();
}

get_chats() {
  if(!chats) {
    chats=({"Orc says: Kill @@do_objective@@!\n",
      "Orc says: Bloody @@do_races@@!\n",
      "Orc says: Stop @@do_objective@@!\n",
      "Orc says: Get @@do_objective@@!\n",
      "Orc says: Let's rip out @@do_possessive@@ guts!\n",
      "Orc says: Kill @@do_objective@@ before @@do_pronoun@@ runs away!\n",
      "Orc says: What is that @@do_race@@ doing here?\n"});
  }
  return(chats);
}

extra_reset() {
object orc;
int i;

  if(present("orc",this_object())) return;
  for(i=0;i<2;i++) {
    orc=clone_object("obj/orc");
    orc->load_a_chat(50,get_chats());
    move_object(orc,this_object());
  }
}
