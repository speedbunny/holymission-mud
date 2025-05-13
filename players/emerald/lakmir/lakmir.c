#define TPN this_player()->query_name()
inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("lakmir");
    set_alt_name("Lakmir");
    set_alias("druid");
    set_short("The Druid Lakmir");
    set_long("The Druid Lakmir.\n"
           + "He is gesturing wildly and is chanting in an archaic tongue.\n");
    set_race("druid");
    set_al(200);
    set_level(75);
    set_wc(42);
    set_ac(25);
    set_chance(50);
    set_spell_dam(100);
    set_spell_mess1("Lakmir casts a spell!");
    set_spell_mess2("Lakmir hurls lightning at you!");
    set_no_steal();
    add_money(50+random (51));
    load_chat(50,({
         "Lakmir says: I am hungry!\n",
         "Lakmir says: Bring me my fishsoup!\n",
       }) );
  }
}


void init() {
  ::init();

  add_action("_give", "give");
}

int _give(string str) {
  object soupbowl;

  switch(str) {
    case "soup to lakmir" :
    case "fish soup to lakmir" :
    case "soup to druid" :
    case "fish soup to druid" :
      soupbowl = present("fishsoup",this_player());
      if(!soupbowl) {
        write ("Hmmm...  looks like you need to get something.\n");
        return 1;
      }
      write("You give the bowl of fish soup to the Druid Lakmir.\n" +
            "The Druid Lakmir thanks you for bringing him his soup!\n");
      say(TPN + " gives the soup to Lakmir.\n");
      this_player()->set_quest("fishsoup");
      destruct(soupbowl);
      return 1;
    case "soup" :
    case "fish soup" :
      notify_fail("Give fish soup to whom?\n");
      return 0;
    default :
      notify_fail("Give what?\n");
      return 0;
  }
}
