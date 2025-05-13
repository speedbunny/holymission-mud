inherit "/obj/treasure";
#define HERE "players/goldsun/green_island/room/hill2"
#define TPN this_player()->query_name()

 reset(arg){
  ::reset(arg);
 if (arg) return;
 set_name("handful of stones");
 set_short("A handful of stones");
 set_alias("stones");
 set_long("A handful of stones.\n");
 set_value(1);
 set_weight(2);
 }

init(){
 ::init();
add_action("throw","throw");
}

int throw(string str){
 if (str=="stones" || str=="handful of stones"){
   if (file_name(environment(this_player()))==HERE){
     move_object(clone_object("/players/goldsun/green_island/obj/pass"),
	this_player());
  write("You throw handful of stones into the abyss.\nOh.\nYou see a secret"+
         " way over the abyss.\n");
     say(TPN+" throws handful of stones into the abyss.\n");
     destruct(this_object());
     return 1;
   }
  write("You throw handful of stones high up in the air.\n");
  say(TPN+" throws handful of stones high up in the air.\n");
  destruct(this_object());
  return 1;
}
}


query_plural(){ return "handful of stones"; }
