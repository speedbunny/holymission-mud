inherit "obj/treasure";

reset(arg)
{

   ::reset(arg);
   if(arg)
     return;
   set_id("lantern");
   set_short("A strange lantern");
  set_long("A strange lantern, maybe you could rub it?\n");
}

init()
{
  ::init();
  add_action("rub","rub");
  add_action("visit","visit");
}
rub(str){
object sarge;
	if(!find_living(sarge)){
        write("Sorry, but Sarge is not here at the moment.\n");
        return 1;
        }
        else{
        object me;
        me=find_living("sarge");
        call_other(me,"move_player",environment(this_player()));
        tell_object(me,"You have been summoned!!\n");
        return 1;
        }
}
visit(str){
        if(str=="sarge"){
	object wheel;
		if(present(wheel,environment(this_player()))){
		call_other(this_player(),"move_player","players/sarge/workroom");
                }
        }
}
