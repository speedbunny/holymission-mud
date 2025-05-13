inherit "/obj/thing";

#define wizstuff "/players/blade/wiz/"
#define TP this_player()

reset(arg) {
  if (arg) return 1;
   set_name("box");
   set_alias("box of goodies");
    set_short("A box of Blade's goodies.");
      set_long("Its a small box made of mohagany.  It looks expensive.\n" +
	     "\"Blade's Goodies\" is carved on the top of the box.\n"   +
	     "There is something in it:\n" +
	     "        Box contains:\n"     +
	     "A small dagger.\n"           +
	     "A dark cloak.\n");
  set_value(0);
  set_weight(20000);
  can_get = 0;
  return 1;
  }

get(string arg){
  int error;
  if (!arg) return 0;
  if (arg=="all from box"||arg=="dagger from box") {
    if (this_player()->query_immortal()) {
      move_object((clone_object(wizstuff+"wizdagger.c")),this_player());
      write("You feel powerful as you take the magical dagger.\n");
      say(TP->query_name()+" takes the magical dagger from the box.  You feel jealous.\n");
      error=1;
    }
    else{
      write("Players are not allowed to take Blade's Goodies!\n");
      say(TP->query_name()+" tries to take a wiztool, but fails!\n");
      return 1;
    }
 }   
    if(arg=="all from box"||arg=="cloak from box"){
      if (this_player()->query_immortal()) {
	move_object((clone_object(wizstuff+"wizcloak.c")),this_player());
	write("You feel wiser as you take the magical cloak.\n");
	say(TP->query_name()+" takes the magical cloak from the box.  You want one too!\n");
	error=1;
      }
      else{
	write("Players are not allowed to take Blade's Goodies!\n");
	say(TP->query_name()+" tries to take a wiztool, but fails!\n");
	return 1;
      }
    }
  return error;
}
  
init(){
  ::init();
    add_action("get","get");
  }




