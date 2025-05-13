/* mud@alijku05.edvz.uni-linz.ac.at Herbert Rosmanith */

/* Dragon grow stages:
 *
 * dragon hatchling	0	Level 1
 * little dragon	1	Level 5
 * adult dragon		2	Level 10
 * dragon		3	Level 20
 * huge dragon		4	Level 30
 * Wyrm			5	Level 50
 * greater Wyrm		6	Level 80
 * The Dragon		7	Level 100 (Gorshzug)
 *
 */

#define	MAX_STAGE	8

inherit "obj/monster";
int grow_stage;			/* are we a kid or a grown dragon ? */

#define PATH	"players/herp/dragon"

#define	TO	this_object()
#define	TP	this_player()
#define	TPN	TP->query_name()
#define	env	environment

#define	SAY(x);	tell_room(environment(TO),x);

reset(arg) {
string s;
int i;

  if (!arg) {
     ::reset(arg);
     set_name("dragon");
     mmsgout="flies away";
     mmsgin="lands";
     set_stage0();
     return;
  }
  if (sscanf(file_name(TO),"%s#%d",s,i)!=2) return; /* master object */
#if 0
  if (!random(3))
#endif
     grow_stage++;
 SAY("grow_stage "+grow_stage+"\n");
     switch(grow_stage) {
     case 1: set_stage1(); break;
     case 2: set_stage2(); break;
     case 3: set_stage3(); break;
     case 4: set_stage4(); break;
     case 5: set_stage5(); break;
     case 6: set_stage6(); break;
     case 7: set_stage7(); return;
     } 
 SAY("processing call_out, "+grow_stage+"\n");
}

set_stage0() {			/* Level 1 */
  set_alias("hatchling");
  set_short("A lightgreen dragon hatchling");
  set_long("It is a little dragon, just hatched from its egg.\n"
+ "It looks very dull, sucking on its claws.\n"
+ "It looks like you could catch it ...\n");
  set_level(1);
  set_spell_mess1("The hatchling burps fire and burns its claw.");
  set_spell_mess2("The hatchling burps fire and burns its claw.");
  set_chance(60);
  set_whimpy();
  set_dead_ob(this_object());
}

set_stage1() {			/* Level 5 */
  SAY("The hatchling grows ...\n");
  set_short("A little green dragon");
  set_long("It is a little green dragon with tiny brown spots on its back.\n"
+ "At this age they look rather nice than mean. But it seems that this one\n"
+ "is of the family of Gorshzug ... and surely will grow to deadly power !\n"
+ "Catch it and tame it !\n");
   set_level(5+random(3));
   set_spell_mess1("The little dragon coughs and tries to spit fire.");
   set_spell_mess1("The little dragon coughs and tries to spit fire.");
   set_spell_dam(10);
   set_chance(30);
   set_whimpy();
}

set_stage2() {			/* Level 10 */
  SAY("The little green dragon grows ...\n");
  set_short("An adult dragon");
  set_long("It is a medium darkgreen dragon with yellow spots on its back.\n"
+ "It looks supsicious, grimmble and bored in your direction.\n"
+ "Steam is coming out of its mouth, nose and ears.\n");
  set_level(random(3)+10);
  set_spell_mess1("The dragon breathes in your direction. You get burned.");
  set_spell_mess2("The dragon breathes fire.");
  set_spell_dam(20);
  set_chance(30);
  whimpy=0;
}

set_stage3() {			/* Level 20 */
  SAY("The dragon grows ...\n");
  set_short("A dragon");
  set_long("It is a firm dragon. It seems to purr, yet the sound reminds you\n"
+ "on Carriots rumpling over the Via Romana. Little flames tonguele from its\n"
+ "from its nose, and color the earth where it lays down its head black.\n"
+ "You feel quit a dwarf beside this beast ...\n");
  set_level(20+random(4));
  set_spell_mess1("The dragon farts in your direction, you feel like in hell.");
  set_spell_mess2("The dragon farts at his opponent.");
  set_spell_dam(30);
  set_chance(30);
}

set_stage4() { 			/* Level 30 */
  SAY("The dragon grows into an even more huge dragon ...\n");
  set_short("A huge dragon");
  set_long("It is a huge and grim dragon. It has brown, black and green spots\n"
+ "on its grey back. It stares at you with its red eyes. You feel as tiny as\n"
+ "a mouse under this beast, towering up to the sky.\n");
  set_level(30+random(4));
  set_spell_mess1("You are enshrouded in the dragon's deadly flames.");
  set_spell_mess2("The dragon enshrouds his opponent in its flames."); 
  set_spell_dam(50);
  set_chance(30);
}

set_stage5() {			/* Level 50 */
  SAY("The huge dragon grows into a wyrm.\n");
  set_short("A wyrm");
  set_alias("wyrm");
  set_long("It is a long, great, gigantic wyrm. You close your eyes before his\n"
+ "threatening majesty. It doesn't even notice, you are to him not more than\n"
+ "a flow to a cow, sucking its excrements.\n");
  set_level(50+random(4));
  set_spell_mess1("The wyrm cast a severe demolition spell at you.");
  set_spell_mess2("The wyrm does some strange magic.");
  set_spell_dam(80);
  set_chance(30);
}

set_stage6() {			/* Level 80 */
  SAY("The Wyrm grows into an even greater Wyrm.\n");
  set_short("A greater Wyrm");
  set_long("It is a Wyrm, and even its sight takes your breath away.\n"
+ "You nearly pee in your shoes, at the thought of having it attacking you.\n"
+ "Flee, fool, or the reaper will have you ...\n");
  set_level(80+random(4));
  set_spell_mess1("The wyrm roars like a vulcano. You are burned.");
  set_spell_mess2("The wyrm roars like a vulcano.");
  set_spell_dam(90);
  set_chance(35);
}

set_stage7() {			/* Level 100 (Gorshzug) */
object ob;
  ob=find_living("gorshzug");
  SAY("set_stage7\n");
  if (find_living("gorshzug")) return;	/* may only exist once */
  SAY("The wyrm grows ...\n");
  SAY("FLEE, FOOL !!! The Wyrm was Gorshzug, and now he is grown !\n");
  set_name("gorshzug");
  set_short("Gorshzug, Dragon, mean and menacing");
  set_long("You see in front of you one of the great dragons from the swamps of Mordor.\n" +
 "Long ago it has been, when the evil one has made his One Ring, that Gorshzug\n" +
 "took the life of many a brave elfen, dwarven and human warrior.\n" +
 "What is the value of your life now ... ?\n");
  set_level(100);
  set_spell_mess1("Gorshzug summons a flash from the sky.");
  set_spell_mess2("Gorshzug summons a flash from the sky.");
  set_spell_dam(1000);
  set_chance(20);
}

init() {
  ::init();
  add_action("do_catchs","catch");
}

do_catchs(str) {
  if (str!="dragon") return;
  switch(grow_stage) {
  case 0:do_catch(); break;
  case 1:do_catch(); break;
  default:
    write(short()+" would rather catch you ...\n");
  }
  return 1;
}

do_catch() {
   write("You try to catch the dragon, but it doesn't like being cought.\n");
   say(TPN+" tries to catch "+short()+".\n",TP);
   if (!random(3)) {
      TO->move_player("X#"+PATH+"/egg");
      return 1;
   }
   TO->run_away();
   if (env(TO)==env(TP)) {
      SAY(short()+" gets mad with panic and attacks !\n");
      TO->attack_object(TP);
   }
   return 1;
}

monster_died() {

  log_file("herp.dragon",TPN+" killed "+short()+" ("+level+", "+grow_stage+")"+" at "+ctime(time())+".\n");
  return;
}

