inherit "room/room";

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
#undef EXTRA_INIT
#define EXTRA_INIT extra_init();

#define GAMES	"players/herp/games/"

#define TP	this_player()
#define TPN	TP->query_name()
#define TPRNAME (TP->query_real_name())
#define SAY(x);	tell_room(this_object(),x);

object board;
int is_locked;
string to_kill;

reset(arg) {
  if(!arg) {
    set_light(1);
    short_desc="Herp's residence";
    long_desc="nix.\n";
    write("This is the residence of Herp.\n"+

"Active Internet connections\n" +
"Proto Recv-Q Send-Q  Local Address          Foreign Address        (state)\n" +
"tcp        0      0  127.0.0.1.1189         127.0.0.1.111          TIME_WAIT\n" +
"tcp        0      0  140.78.3.1.4242        129.130.116.76.1265    SYN_RCVD\n" +
"tcp        0      0  140.78.3.1.1188        137.238.1.11.4444      SYN_SENT\n" +
"tcp        0      0  140.78.3.1.4242        129.186.102.49.1098    SYN_RCVD\n" +
"tcp        0      0  140.78.3.1.1187        137.238.1.11.4444      ESTABLISHED\n" +
"tcp     1024      0  140.78.3.1.1186        137.238.1.11.4444      ESTABLISHED\n" +
"tcp     1792      0  140.78.3.1.1185        137.238.1.11.4444      ESTABLISHED\n" +
"tcp     1792      0  140.78.3.1.1184        137.238.1.11.4444      ESTABLISHED\n" +
"tcp        0      0  127.0.0.1.1178         127.0.0.1.111          TIME_WAIT\n" +
"tcp        0      0  140.78.3.1.1154        137.238.1.11.4444      TIME_WAIT\n" +
"tcp        0      0  140.78.3.1.1153        137.238.1.11.4444      TIME_WAIT\n" +
"tcp        0      0  140.78.3.1.1152        137.238.1.11.4444      TIME_WAIT\n" +
"tcp        0      0  140.78.3.1.1151        137.238.1.11.4444      TIME_WAIT\n" +
"tcp        0      0  140.78.3.1.1150        137.238.1.11.4444      TIME_WAIT\n" +
"tcp        0      0  140.78.3.1.1149        137.238.1.11.4444      TIME_WAIT\n" +
"tcp        0      0  140.78.3.1.1148        137.238.1.11.4444      TIME_WAIT\n" +
"tcp        0      0  127.0.0.1.4242         127.0.0.1.1147         ESTABLISHED\n" +
"tcp        0      0  127.0.0.1.1147         127.0.0.1.4242         ESTABLISHED\n" +
"tcp        0      0  140.78.3.1.1146        137.238.1.11.4444      TIME_WAIT\n" +
"tcp        0      0  140.78.3.1.1145        137.238.1.11.4444      TIME_WAIT\n" +
"tcp        0      0  140.78.3.1.1144        137.238.1.11.4444      TIME_WAIT\n" +
"tcp        0      0  140.78.3.1.1143        137.238.1.11.4444      TIME_WAIT\n" +
"tcp        0      0  140.78.3.1.1142        137.238.1.11.4444      TIME_WAIT\n" +
"tcp        0      0  140.78.3.1.1141        137.238.1.11.4444      TIME_WAIT\n" +
"tcp        0      0  140.78.3.1.1140        137.238.1.11.4444      TIME_WAIT\n" +
"tcp        0      0  140.78.3.1.1139        137.238.1.11.4444      TIME_WAIT\n" +
"tcp        0      0  140.78.3.1.1138        137.238.1.11.4444      TIME_WAIT\n" +
"tcp        0      0  140.78.3.1.1137        137.238.1.11.4444      TIME_WAIT\n" +
"tcp        0      0  140.78.3.1.1136        137.238.1.11.4444      TIME_WAIT\n" +
"tcp        0      0  140.78.3.1.1135        137.238.1.11.4444      TIME_WAIT\n" +
"tcp        0      0  140.78.3.1.1134        137.238.1.11.4444      TIME_WAIT\n" +
"tcp        0      0  140.78.3.1.1133        137.238.1.11.4444      TIME_WAIT\n" +
"tcp        0      0  140.78.3.1.1132        137.238.1.11.4444      TIME_WAIT\n" +
"tcp        0      0  140.78.3.1.1131        137.238.1.11.4444      TIME_WAIT\n" +
"tcp        0      0  140.78.3.1.1130        137.238.1.11.4444      TIME_WAIT\n" +
"tcp        0      0  140.78.3.1.1129        137.238.1.11.4444      TIME_WAIT\n" +
"tcp        0      0  140.78.3.1.1128        137.238.1.11.4444      TIME_WAIT\n" +
"tcp        0      0  140.78.3.1.1126        137.238.1.11.4444      TIME_WAIT\n" +
"tcp        0      0  140.78.3.1.1125        137.238.1.11.4444      TIME_WAIT\n" +
"tcp        0      0  140.78.3.1.1124        137.238.1.11.4444      TIME_WAIT\n" +
"tcp        0      0  140.78.3.1.1123        137.238.1.11.4444      TIME_WAIT\n" +
"tcp        0      0  140.78.3.1.1122        137.238.1.11.4444      TIME_WAIT\n" +
"tcp        0      0  140.78.3.1.1121        137.238.1.11.4444      TIME_WAIT\n" +
"tcp        0      0  140.78.3.1.1120        137.238.1.11.4444      TIME_WAIT\n" +
"tcp        0      0  140.78.3.1.23          137.238.21.10.14347    LAST_ACK\n" +
"tcp        0      0  140.78.3.1.4242        131.111.8.1.4909       ESTABLISHED\n" +
"tcp        0      0  140.78.3.1.4242        192.73.75.2.3854       ESTABLISHED\n" +
"tcp        0      0  140.78.3.1.4242        134.53.7.2.2033        ESTABLISHED\n" +
"tcp        0      0  140.78.3.1.4242        130.161.181.168.34582  ESTABLISHED\n" +
"tcp        0     19  140.78.3.1.4242        128.204.1.12.2992      ESTABLISHED\n" +
"tcp        0      0  140.78.3.1.4871        137.238.1.11.4444      ESTABLISHED\n" +
"tcp        0      0  140.78.3.1.4242        137.238.1.1.2898       ESTABLISHED\n" +
"tcp        0      0  140.78.3.1.4242        129.79.1.19.3176       ESTABLISHED\n" +
"tcp        0      0  140.78.3.1.4242        129.186.102.47.2662    ESTABLISHED\n" +
"tcp        0      0  140.78.3.1.4242        129.186.102.49.1097    ESTABLISHED\n" +
"tcp        0      0  140.78.3.1.4242        136.204.1.2.1867       ESTABLISHED\n" +
"tcp        0      0  140.78.3.1.4242        134.36.38.5.3174       ESTABLISHED\n" +
"tcp        0      0  140.78.3.1.4242        140.78.4.41.3739       ESTABLISHED\n" +
"tcp        0      0  140.78.3.1.4242        130.68.1.2.2655        ESTABLISHED\n" +
"tcp        0      0  140.78.3.1.4242        134.53.2.10.4370       ESTABLISHED\n" +
"tcp        0     27  140.78.3.1.4242        128.204.1.114.2079     ESTABLISHED\n" +
"tcp        0      0  140.78.3.1.23          140.78.3.1.4819        CLOSE_WAIT\n" +
"tcp        0      0  140.78.3.1.4242        137.205.192.6.2023     ESTABLISHED\n" +
"tcp        0      0  140.78.3.1.4242        134.53.7.2.1677        ESTABLISHED\n" +
"tcp        0      0  140.78.3.1.4242        137.205.192.6.2007     ESTABLISHED\n" +
"tcp        0      0  140.78.3.1.4242        130.161.181.196.34576  ESTABLISHED\n" +
"tcp        0      0  140.78.3.1.4242        132.68.48.10.3714      ESTABLISHED\n" +
"tcp        0      0  140.78.3.1.4242        129.25.5.11.4922       ESTABLISHED\n" +
"tcp        0      0  140.78.3.1.4242        134.53.7.2.1541        ESTABLISHED\n" +
"tcp        0      0  140.78.3.1.4242        129.79.15.245.2136     ESTABLISHED\n" +
"tcp        0      0  140.78.3.1.4242        192.70.173.10.1693     ESTABLISHED\n" +
"tcp        0      0  140.78.3.1.4242        134.53.7.2.1509        ESTABLISHED\n" +
"tcp        0      0  140.78.3.1.4242        128.253.96.36.62817    ESTABLISHED\n" +
"tcp        0      0  140.78.3.1.4242        134.36.42.19.1244      ESTABLISHED\n" +
"tcp        0      0  140.78.3.1.4242        136.167.6.60.39921     ESTABLISHED\n" +
"tcp        0      0  140.78.3.1.4242        149.152.30.3.2325      ESTABLISHED\n" +
"tcp        0      0  140.78.3.1.4242        134.83.176.3.1114      ESTABLISHED\n" +
"tcp        0      0  140.78.3.1.4242        134.36.42.19.1243      ESTABLISHED\n" +
"tcp        0    483  140.78.3.1.4242        137.238.1.1.2633       ESTABLISHED\n" +
"tcp        0     23  140.78.3.1.4242        134.76.2.7.3093        ESTABLISHED\n" +
"tcp        0      0  140.78.3.1.4242        137.141.15.10.10068    ESTABLISHED\n" +
"tcp        2      7  140.78.3.1.4242        134.53.2.10.4329       ESTABLISHED\n" +
"tcp        0      0  140.78.3.1.4242        130.68.1.2.2642        ESTABLISHED\n" +
"tcp        0      0  140.78.3.1.4242        128.6.62.3.2197        ESTABLISHED\n" +
"tcp        0     58  140.78.3.1.4242        129.10.1.14.1812       ESTABLISHED\n" +
"tcp        0      0  140.78.3.1.4242        129.49.12.106.2343     ESTABLISHED\n" +
"tcp        0      0  140.78.3.1.4242        134.53.7.2.1455        ESTABLISHED\n" +
"tcp        0      0  140.78.3.1.4242        136.204.1.2.1824       ESTABLISHED\n" +
"tcp        0    616  140.78.3.1.4242        137.238.1.1.2629       ESTABLISHED\n" +
"tcp        0      0  140.78.3.1.4242        134.53.7.2.1454        ESTABLISHED\n" +
"tcp        0      0  140.78.3.1.4242        134.83.176.25.1115     ESTABLISHED\n" +
"tcp        0      0  140.78.3.1.23          140.78.4.42.14851      ESTABLISHED\n" +
"tcp        0      0  140.78.3.1.23          140.78.4.42.3480       ESTABLISHED\n" +
"tcp        0      0  140.78.3.1.23          140.78.4.42.15996      ESTABLISHED\n" +
"tcp        0      9  140.78.3.1.4242        134.36.6.81.3381       CLOSING\n" +
"tcp        0     16  140.78.3.1.4242        134.36.6.81.6196       CLOSING\n" +
"tcp        0      0  140.78.3.1.23          140.78.4.42.15536      ESTABLISHED\n" +
"tcp        0      0  140.78.3.1.23          140.78.4.42.15911      ESTABLISHED\n" +
"tcp        0      0  140.78.3.1.1023        140.78.3.8.513         ESTABLISHED\n" +
"tcp        0      0  140.78.3.1.1022        140.78.3.8.513         ESTABLISHED\n" +
"tcp        0     16  140.78.3.1.4242        134.36.6.82.2563       CLOSING\n" +
"tcp        0     16  140.78.3.1.4242        134.36.4.180.15768     CLOSING\n" +
"tcp        0     16  140.78.3.1.4242        134.36.6.81.11347      CLOSING\n" +
"tcp        0     16  140.78.3.1.4242        134.36.6.82.3095       CLOSING\n" +
"tcp        0     16  140.78.3.1.4242        134.36.6.85.14933      CLOSING\n" +
"tcp        0     16  140.78.3.1.4242        134.36.6.87.7976       CLOSING\n" +
"tcp        0     16  140.78.3.1.4242        134.36.6.85.11090      CLOSING\n" +
"Active UNIX domain sockets\n" +
"ff66d28c stream      0      0        0 ff64e78c        0        0\n");

    dest_dir=({
	"room/church","church",
	"players/herp/abbey/e01","abbey",
	"players/herp/toolong","bug",
	GAMES+"spz","p1",
	GAMES+"4win","p2" });
  }
  extra_reset(arg);
}

init() {
  ::init();
  extra_init();
  add_action("make_cookie","cookie");
  add_action("make_dragons","dragons");
}   

extra_reset(arg) {
object ob;
int i;

    if (!(present("tracer",this_object())))
	move_object(clone_object("obj/trace"),this_object());

    if (!(present("camera",this_object())))
	move_object(clone_object("players/herp/obj/camera"),this_object());

    if (!board) {
	board = clone_object("obj/board");
	board->set_file("players/herp/boards/god_board");
	board->set_name("god");
	board->set_short("the board of God");
	move_object(board,this_object());
    }
    if (!(present("lcout"))) 
       move_object(clone_object("players/herp/lcout"),this_object());
    if (!present("punisher"))
       move_object(clone_object("players/herp/obj/punisher"),this_object());

    if (!present("torch"))
	for (i=0;i<3;i++) move_object(clone_object("obj/torch"),this_object());

    if (!(ob=present("gorshzug")) || !living(ob))
	move_object(create_dragon(),this_object());
#if 0
    if (!present("shit"))
       move_object(clone_object("players/whisky/garden/obj/shit"),this_object());
#endif

}

create_dragon() {
object ob;

	ob=clone_object("obj/monster");
	ob->set_name("gorshzug");
	ob->set_race("dragon");
	ob->set_short("Gorshzug, Dragon, mean and menacing");
	ob->set_long("You see in front of you one of the great Dragons from the swamps of Mordor.\n"+
		     "Long ago it has been, in the war of the Rings, that Gorshzug took the life\n" +
		     "of many a brave elfen, dwarven and human warrior.\n" +
		     "Yet he is cought, to guard Herp's workroom ...\n");
	ob->set_level(100);
	ob->set_wc(100);
	ob->set_ac(100);
	ob->set_ep(1);
	ob->set_dead_ob(this_object());	/* let the workroom handle g.'s death */
	return ob; 
}

monster_died() {
object ob;
  write(TPN+" killed Gorshzug.\n");
  say("You killed Gorshzug.\n");
  write("\nSuddenly, the dragon reincarnates !\n\n");
  ob=create_dragon();
  move_object(ob,this_object());
  ob->attack_object(TP);
}

extra_init() {
   add_action("lock","lock");
   add_action("unlock","unlock");
   add_action("test","test");
   if (TPRNAME!="herp" && is_locked) {
      tell_object(this_player(),"The room is currently locked. You are moved to the church.\n");
      move_object(this_player(),"room/church");
   }
   if (board && board!=first_inventory(this_object())) {	/* rearrange inventory */
      move_object(board,"room/church");
      move_object(board,this_object());
   }
}

test(str) { write(query_snoop(find_player(str)));write("\n"); return 1; }
lock() {
  if (query_myself()) {
     is_locked=1;
     say("Herp locked the room.\n"); 
  } 
  return 1;
}

unlock() {
  if (query_myself()) {
      is_locked=0;
      say("Herp unlocked the room.\n"); 
  } 
  return 1;
}

query_myself() {
  if (TPRNAME!="herp") {
     write("Only one can do that here.\n");
     return 0;
  }
  return 1;
}

receive_roses(n) {
string *rdest;
object ob,rd;

  ob =clone_object("players/herp/obj/rose");
  ob->set_name("rose");
  ob->set_short("a rose grows here");
  ob->set_long("A rose for the management, from "+
	capitalize(n)+" with frank admiration.\n");
  ob->set_can_get(1);

  rdest=({ "room/church", "room/main_shop", "room/adv_guild",
	   "room/vill_road1", "players/herp/workroom", "room/slope" });

  move_object(ob,rd=rdest[random(sizeof(rdest))]);
  tell_room(rd,"A rose starts growing here.\n");
}

make_cookie() {
object ob,co;
int i,x;

    ob=clone_object("obj/container");
    ob->set_alias("sack");
    ob->set_short("big sack");
    ob->set_long("A big sack from Santa Claus.\n");
    ob->set_can_close(1);
    ob->set_weight(1);
    ob->set_max_weight(15);
    ob->set_value(19);
    ob->set_only_for("cookie");

    x=1+random(20);
    for (i=0;i<x;i++) {
	co=clone_object("obj/food");
	co->set_name("cookie");
	co->set_strength(1);
	co->set_eating_mess(" eats a cookie.\n");
	co->set_eater_mess("Just like your granny made them !\n");
	if (transfer(co,ob)) destruct(co);
    }

    transfer(ob,this_object());
    tell_room(this_object(),"Santa Claus arrives and leaves a big sack full of cookies.\n");
    return 1;
}

#define	EGG	"/players/herp/dragon/egg"
#define DEST_LOCATIONS ({ \
	"/room/church", \
	"/room/vill_green", \
	"/room/slope", \
	"/players/herp/orc/v1", \
	"/players/moonchild/pot/orc4", \
	"/players/uglymouth/vikings/jungle_n", \
	"/players/patience/ezo/meadow1", \
	"/players/patience/ezo/armoury", \
	"/players/ted/path/path7" \
	})

make_dragons() {
object *dl;
int i;

    for (i=0,dl=DEST_LOCATIONS;i<sizeof(dl);i++) {
	move_object(clone_object(EGG),dl[i]);
	tell_room(dl[i],"Suddenly you notice something that hasn't been here \
before.\n");
    }
   
    tell_room(this_object(),"The Dragons have been positioned, Master.\n");
    return 1;
}
