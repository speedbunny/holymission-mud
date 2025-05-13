#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob;
  if (!arg) {
     set_light(1);
     short_desc="Yorge's Secret Room";
     long_desc=
"You have entered a small cluttered room.  Books and papers lie untidily\n"+
"strewn about.  A desk lies tipped over.  It looks like someone has been\n"+
"searching about.\n";
     dest_dir=({ PATH+"/r16","north" });
  }
  if (!(ob=present("yorge")) || !living(ob)) {
	ob=clone_object("obj/monster");
	ob->set_name("yorge");
	ob->set_alias("monk");
	ob->set_level(7);
	ob->set_short("A blind monk, with blackened lips");
	ob->set_long("A monk, drooling green filth.\n");
	ob->load_chat(60,
	({ "Blind Yorge says: The church must suppress this book.\n",
	   "Blind Yorge says: This book is Aristotele's work!\n",
	   "Blind Yorge says: This book of comedy will kill the church.\n",
	   "Blind Yorge turns his white eyes toward you.\n" }) );
	ob->load_a_chat(70,
	({ "Yorge' says: If people neither fear nor hate, they need no religion.\n",
	   "Yorge' says: Laughter kills fear, without fear, no religion.\n"
	}) ); 

	move_object(ob,this_object());
  }
  if (!find_object(PATH+"/r17b")) {		/* This is the book */
     (PATH+"/r17b")->reset();
     move_object(PATH+"/r17b",ob);
  }	
}
