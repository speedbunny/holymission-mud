inherit "obj/treasure";
object tengu;
 
reset(arg){
 ::reset(arg);
if (arg) return;
 set_id("goldsun_whistle");
 set_alias("whistle");
 set_short("A silver whistle");
 set_long("This is silver whistle with dragon picture on it.\n");
 set_value(0);
 
}

init(){
 ::init();
 add_action("blow","blow");
 add_action("tengu","tengu");
 }

blow(str){
 if ((str)=="whistle"){
  say(this_player()->query_name()+" blows to whistle.\n");
  say("\nWheeeeeeeeee\n"+
       "Tengu arrives.\n");
  write("You blow the whistle.\n"
   	+"Tengu arrives.\n");
  if (!tengu)  tengu=clone_object("/players/goldsun/monster/tengu");
  transfer(tengu,file_name(environment(this_player())));
  
 
 return 1;
}
}  
tengu(str){
 object mon;

  tengu=present("tengu",environment(this_player()));
 if (!tengu){ write("Tengu is not here.\n");}
  if(!command(str,tengu)) write("Tengu refuses.\n");
 return 1;
}
