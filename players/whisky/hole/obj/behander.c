/* #########################################################################

                 S L A Y E R  O F  D A R K  P O W E R (c) Whisky

   ######################################################################### */

#define TP	this_player()
#define TPN	TP->query_name()

inherit "obj/weapon";

reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_id("slayer");
  set_weight(1);
  set_class(8);
  set_light(1);
  set_value(100000);
  set_alt_name("slayer of dark power");
  set_short("The slayer of dark power");
  set_long("This weapon is the guarded sword of gorgurack.\n"+
           "It looks like a normal fighter sword, but its\n"+
           "strange black glow seems to include some evil\n"+
           "magic power.\n");
  set_hit_func(this_object());
}

#define	obn	ob->query_name()
weapon_hit(ob) {
    write("Black energy streams out from your slayer !!!!\nYou granulate "+obn+" to death.\n");
    say("Black energy streams out from "+TPN+"'s slayer !!!!\n"+TPN+" granulates "+obn+" to death.\n");
    return random(20);
  }
