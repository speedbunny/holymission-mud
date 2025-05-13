inherit "obj/weapon";

int magic_hit_power;
int poison_level;

void reset(int arg) 
{
   ::reset(arg);
   if (arg) return 0;
   set_name("A small dagger");
   set_id("dagger");
   set_short("A small dagger");
   set_long("An ancient dagger.  It is said to\n"
	    "contain the power of an evil god.\n");
   set_value(10000);
   set_weight(0);
   set_type(3);
   set_hit_func(this_object());
   magic_hit_power=0;
   poison_level=0;
}

int magic_hit(object attacker) 
{
   write("You deftly stab "+ attacker->query_name()+ " in the back.\n"
        +"The small dagger drinks the blood of Blade's enemy.\n");
   return magic_hit_power;
}

void init()
{
  ::init();
  if(!(this_player()->query_immortal())) {
    say("The dagger does not like its new owner!  It destroys itself.\n");
    write("The dagger does not like you!  It destroys itself.\n");
    destruct(this_object());
  }
  add_action("change_wc","change_wc");
  add_action("change_mh","change_mh");
  add_action("change_po","change_po");
  add_action("dagger_stat","dagger_stat");
  add_action("help","help");
}

int weapon_hit(object attacker) 
{
  if(poison_level) {
    write("You watch as your attacker chokes on the poison.\n");
    attacker->add_poison(poison_level);
  }
return 1;
}

int help(string arg) {
  if(!(arg=="dagger")) { return 0; }
  else{
    write("change_wc x - Changes the Weapon Class of the weapon to x.\n"  +
	"change_mh x - Changes the Magic Hit of the weapon to x.\n"       +
        "dagger_stat - Shows the current levels of the dagger.\n")        ;
    return 1;
  }  
}

int dagger_stat() {
  write("The Weapon Class of this dagger is: "+set_class()+"\n"   +
	"The Magic Hit of this dagger is: "+magic_hit_power+"\n"  +
        "The Poison Level of this dagger is: "+poison_level+"\n") ;   
  return 1;
}

int change_po(int arg)
{
  if(sscanf(arg, "%d", poison_level)==1) {
    write("Poison Level changed to "+arg+"\n");
    return 1;
  }
}

int change_mh(int arg) {
  if(!arg) {
    write("What would you like to change the magic hit power to?\n");
    return 1;
  }
  if(sscanf(arg, "%d", magic_hit_power)==1) {
    write("Magic hit power is now "+arg+"\n");
    return 1;
  }
}

int change_wc(int arg)
{
  int class;
  
  if(!arg)
  {
    write("What would you like to change the wc to?\n");
    return 1;
  }
  if(sscanf(arg, "%d", class) == 1)
  {
    write("Weapon class is now "+arg+"\n");
    set_class(class);
    return 1;
  }
}
    

