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
    long_desc="This is the residence of Herp.\n"+
	      "You might want to lock or unlock the room ...\n";
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
		     "Yet he is caught, to guard Herp's workroom ...\n");
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
