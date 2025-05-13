#define TPN this_player()->query_name()
#define TO this_object()
#define TP this_player()
#define ENV environment
inherit "/obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("gardener");
    set_short("The gardener");
    set_long("This is the gardener of this wonderful garden.\n" +
      "He looks rather busy, chasing away vermin from his plants.\n");
    set_race("human");
    set_level(15);
    set_ac(99);
    set_move_at_reset();
    load_chat(30, ({
      "The gardener says: Hello there!\n",
    "The gardener says: Can you kill some vermin for me?\n",
      "The gardener says: Those darn moles.\n",
      "The gardener says: I love my honey.\n",
      "The gardener says: You know those rabbits breed like...\n",
      "The gardener scratches his head.\n",
      "The gardener rakes a bit.\n",
      "The gardener shrugs.\n",
      "The gardener blushes.\n",
    }));
    set_gender(1);
}

void init() {
  ::init();
  add_action("ask_weapon", "ask");
}

ask_weapon(str) {
  object shears;
  switch (str) {  
    case "gardener for shears" :
    case "gardener for weapon" :
    case "for shears" :
    case "for weapon" :
      write("You ask the gardener for a weapon.\n");
      say(TPN+" asks the gardener "+"for a weapon.\n");
        if(!present("shears", this_player())) {
          write("Gardener says: Ahh, now you can help me keep my garden " +
                "clean.\n" +
                "The gardener gives you some pruning shears.\n");
          say("Gardener says to " +TPN+
              ": Now you can help me keep my garden clean.\n"+
              "The gardener gives"+TPN+" pruning shears.\n");
          shears = clone_object("/players/emerald/garden/p-shears");
          transfer(shears, TP);
          return 1;
        }
      write("Gardener says: I have already given you a weapon.\n");
      tell_room(ENV(TO),"'Go away!!!, the gardener shouts.\n");
      return 1;
    default:
    write("Ask for what?\n");
    return 1;
  }
}
