inherit "room/room";

object monster,note;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    dest_dir=({"players/padrone/tower/hall", "west",
	       "players/padrone/tower/garbage_room", "east"});
    short_desc="Laboratory";
    long_desc="This is the Wizard's laboratory, where he performs his strange\n"
            + "and mysterious experiments. Tables and shelves are packed with\n"
            + "strange and mysterious equipment, from test tubes and ancient\n"
            + "spellbooks to sound generators and storage devices. A small\n"
            + "door leads east. There is a sign on the door.\n";
    set_light(1);
    items=({"laboratory","It looks very intrigueing",
            "tables","Filled with strange equipment",
            "shelves","Filled with mysterious equipment",
            "equipment","You will never figure out how these work",
            "tubes","Filled with colourful liquids",
            "spellbooks","In a strange language",
            "generators","Made of paper and wood",
            "devices","Made of glass and copper",
            "door","Very small",
            "sign","It looks rather old"});
    smell="Don't do that too often! It might be bad for your health here!"; 
  }
  if(!monster) {
    monster=clone_object("obj/monster");
    monster->set_name("half-finished monster");
    monster->set_alias("monster");
    monster->set_level(3);
    monster->set_wc(4);
    monster->set_al(0);
    monster->set_short("A half-finished monster");
    monster->set_long("This is a monster that the Wizard seems to still be\n"
                    + "working on. It has no legs, and only one arm. Parts of\n"
                    + "it are still stored in big glass jars on the table.\n");
    monster->set_aggressive(1);
    monster->set_spell_mess1("The half-finished monster says: Error! Brain not yet inserted.");
    monster->set_spell_mess2("The half-finished monster says: Error! Brain not yet inserted.");
    monster->set_chance(50);
    move_object(monster, this_object());
  }
  if(!note || !present(note)) {
    note=clone_object("players/padrone/obj/thing");
    note->set_name("note");
    note->set_alias("paper");
    note->set_short("A note");
    note->set_can_get(1);
    note->set_weight(1);
    note->set_value(1);
    note->set_read_file("/players/padrone/tower/hatnote.txt");
    move_object(note, this_object());
  }
} /* extra_reset */

init() {
 ::init();
 add_action("read","read");
}
  
read(str) {
  if(str=="sign") {
    write("The sign reads 'GARBAGE ROOM'.\n");
    say(this_player()->query_name()+" reads a sign.\n");
    return 1;
  }
  if(str=="spellbooks") {
    write("The spellbooks are REALLY unreadable.\n");
    say(this_player()->query_name()+" attempts to read spellbooks.\n");
    return 1;
  }
  notify_fail("Read what?\n");
  return 0;
}
