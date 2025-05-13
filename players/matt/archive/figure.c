inherit "obj/monster";

#include "/players/matt/definitions"

object parchment;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("hooded figure");
  set_alias("figure");
  set_short("A hooded figure");
  set_long("A mysterious figure garbed in midnight-black robes; he looks\n" +
	   "human, but the black hood darkening his face betrays nothing.\n");
  set_race("human");
  set_gender(1);
  set_level(1);
  set_no_fight(1);
  set_prevent_poison(1);
  load_chat(20, ({
    "The figure beckons you to approach.\n",
                 }));
           }

init() {
  ::init();
  add_action("approach", "approach");
  add_action("show", "show");
       }

approach(arg) {
  if(id(arg)) {
    if(!parchment) {
      write("You approach the dark figure.\n");
      say(TP->NAME + " approaches the dark figure.\n");
      write("As you look at him, you can see the gnarled contours of an\n");
      write("old man's face in the shadows of his black hood.\n");
      write("He whispers: Restore us to power, young one. Restore us...\n");
      write("The figure reaches into his robes and gives you something.\n");
      parchment = clone_object("players/matt/guild/objects/parchment");
      transfer(parchment, TP);
      say("The figure whispers to " + TP->SNAME + " and then gives\n");
      say(TP->OBJ + " something.\n");
      return 1;
                   }
    write("You approach the dark figure.\n");
    say(TP->NAME + " approaches the dark figure.\n");
    if(ENV(parchment) == TP)
      write("He whispers: Restore us...\n");
    else write("He whispers: Find " + ENV(parchment)->SNAME + ", who " +
	       "holds the parchment.\n");
    say("The figure whispers something to " + TP->SNAME + ".\n");
    return 1;
              }
  write("Approach whom?\n");
  return 1;
              }

show(arg) {
  object prism, scroll;
  if(arg == "prism to figure" || arg == "prism") {
    prism = present("masterdiamond", TP);
    if(prism) {
      TELLR(ENV(TO), "Figure exclaims: Ahhhh! The Prism of Elements!\n");
      TELLR(ENV(TO), "Figure says: You've done it, " +
	    TP->SNAME + "!\n");
      scroll = clone_object("players/matt/guild/objects/scroll");
      transfer(scroll, TP);
      write("The figure hands you a scroll from his robes.\n");
      say("The figure hands something to " + TP->SNAME + ".\n");
      TELLR(ENV(TO), "Figure says: Give this to our Creator, Lord Matt.\n");
      if(!TP->query_immortal())
	shout(TP->NAME + " has restored the Prism of Elements!\n");
      destruct(prism);
      write("The Prism of Elements floats out of your hands.\n");
      say("The Prism of Elements floats out of " + TP->SNAME +
	  "'s hands.\n");
      TELLR(ENV(TO), "It moves forward, then sinks into the ground.\n");
      write("Well done, " + TP->NAME + "!\n");
      write_file("/players/matt/logfiles/summquest",
		 TP->SNAME + " solved the Summoner Quest on " +
		 ctime(time()) + ".\n");
      TP->set_quest("summoner_open");
      load_chat();
      return 1;
              }
    write("You do not have that.\n");
    return 1;
                                                 }
  write("Show what?\n");
  return 1;
          }

hit_player(arg) {
  object att;
  att = TO->query_attack();
  if(att && present(att, ENV(TO))) {
    TELLR(ENV(TO), "The figure says: Attack me not, Mortal.\n");
    return 1;
                                   }
  return 1;
                }
