#define WIZ "Ted"         /* Substitute wizard's name here */
#define GENDER "he"               /* Substitute wiz's gender (he/she/it) */
 
inherit "room/room";
 
object target, ob;
int count, no;
string messages;
 
reset(arg) {
  
  if(!present("list")) {
    move_object(clone_object("obj/level_list"), this_object());
  }
  if(!arg) {
    set_light(1);
    short_desc=WIZ+"'s workroom.";
    long_desc=
    "This is a place of dark shadows and hidden niches.  The walls of this\n"+
    "room are lined with bookcases stuffed with books and tomes of all color\n"+
    "shapes and sizes.  There are no obvious sources of light, it just seems\n"+
    "to permeate the air around you.  There is a chaotic swirling pool of\n"+
    "raw chaos in the center of the room.\n";
    dest_dir=({
      "room/adv_inner","adv",
      "room/church","church",
      "room/post","post",
      "room/shop", "shop",
      "room/clearing", "clear",
      "room/pub2", "pub2",
#if 0
      "obj/guild/thief_guild", "thief_guild",
      "obj/guild/mage_guild", "mage_guild",
      "obj/guild/monk_guild", "monk_guild",
      "obj/guild/bard_guild", "bard_guild",
      "obj/guild/priest_guild", "priest_guild",
#endif
      "players/ted/path/path1", "path"
    });
    items=({
      "bookcases","These large bookcases are made of oak with a dark stain\n"+
                  "to cover them.  The flickering light casts strange shadows.",
      "bookcase","These large bookcases are made of oak with a dark stain\n"+
                 "to cover them.  The flickering light casts strange shadows.",
      "pool","This raw pool of rampagent energies hums and throbs with power"
    });
    if(!messages) {
      messages = allocate(10);
      messages[0] =
"Ted bubbles happily.";
      messages[1] =
"Ted pokes you in the ribs.";
      messages[2] =
"Ted stares into his pool of chaos.";
      messages[3] =
"Ted gives you 10 gold coins.";
      messages[4] =
"Ted's image suddenly blurs and changes form!";
      messages[5] =
"A swirling mass of Chaos appears and envelops Ted.\n"+
"Ted emerges from the mass of Chaos totaly replenished.";
      messages[6] =
"Ted smiles at you.";
      messages[7] =
"Ted begins to shake uncontrolably.";
      messages[8] =
"Suddenly a big burst of violent energy bursts from Ted!";
      messages[9] =
"The earth rumbles as Ted paces around the room.";
	no = 0;
    }
  }
}
 
init() {
 ::init();
 add_action("test_time"); add_verb("time");
 add_action("yes"); add_verb("yes");
 add_action("no"); add_verb("no");
 add_action("shadow"); add_verb("shadow");
 target = find_living("ted");
 set_heart_beat(1);
}

no() { no = 1; set_heart_beat(0); return 1; }
yes() { no = 0; set_heart_beat(1); return 1; }

heart_beat() {
 if(!test_if_any_here()) say("No one here!\n");
 if(!test_if_any_here()) set_heart_beat(0);
 if(no) {
   set_heart_beat(0);
   return;
 }
 if(target && present("ted")) {
   if(random(100) >= random(300)) {
     count = random(10);
     say(messages[count]+"\n",target);
   }
 }
 if(!present("ted"))
   say("Ted would wonder what you are doing here.\n");
}

test_time() {
 write(" "+(ctime(time()))+"\n");
 return 1;
}

shadow() {
  object junk;
  this_player()->new_shadow();
  if(junk) {
    write("Old shadow found.\n");
    destruct(junk);
  }
  junk = clone_object("players/ted/teds_shadow");
  junk->set_owner(this_player());
  junk->start();
  write("Ok.\n");
  return 1;
}

test_if_any_here() {
object *ob;
int i;

  ob=all_inventory(this_object());
  for (i=0;i<sizeof(ob);i++)
    if (ob[i]->query_player()) return 1;
}
