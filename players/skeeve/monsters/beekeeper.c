

/* Last edit: jan 95, Whisky, to avoid those many call_outs */

inherit "/obj/monster";

#include "/players/skeeve/area.h"
#include "/players/skeeve/code.h"

mixed function, type, match;
object victim;
int count, delay;

/* prototyping */   
void setup_arrays();

void reset(int arg) 
{
  string s;
  int i;
  
  ::reset(arg);
  if (!arg) 
  {
    set_name("beekeeper");
    set_alias ("keeper");
    set_short("An old but strong beekeeper");
    set_long("The beekeeper guards his bees.\n"
            +"If you destroy a beehouse he will be very angry.\n");
    set_race("human");
    set_gender(1);
    set_level(8);
    set_sp(0);
    set_wc(3);
    set_ac(0);
    set_size(3);
    set_no_steal();
    set_light(1);
    add_money(50 + random(101));

    victim = 0;

    if (sscanf(file_name(this_object()),"%s#%d",s,i)==2) 
    {
        count = 0;
        delay = 15;
        set_heart_beat(1);
    }
  }
    
  /* Equipment */
  ARMOUR("beemail","beemail",this_object());

  WEAPON("sharp_sword",this_object());
  
  if (!present("bag")) transfer(clone_object("obj/bag"),this_object());
  if (!present("torch")) transfer(clone_object("obj/torch"),this_object());
  
  if (!function) {
    setup_arrays();
    set_match(this_object(), function, type, match);
} }

init()
{
    if (!delay && test_if_any_here())
    {
        delay = 15;
        set_heart_beat(1);
    }
   ::init();
}

void setup_arrays() 
{
  function = allocate(1);
  type = allocate(1);
  match = allocate(1);
  function[0] = "handle_leave"; type[0] = "leaves";  match[0] = "";
}

handle_leaves( arg ) {
  string who, where;
  if (  victim 
     && (sscanf(arg,"%s leaves %s",who,where)==2) 
     && (who==capitalize(victim->query_real_name())) ) {
    command(where); 
} }

query_stay_garden() { return 1; }

void heart_beat()  
{
   count ++;
   if (count == 30)
   {
       random_move();
       count = 0;
       delay--;
   }
   if ( !present("beehouse",environment(this_object()))
      &&(!random(5)) ) {
     move_object (clone_object(OBJECTS+"beehouse"),environment(this_object()));
     tell_room (environment(this_object()),"The beekeeper builds a little beehouse.\n");
   }  
   if (!delay)
       set_heart_beat(0);
       ::heart_beat();
}

help(thekiller) {
  victim=thekiller;
  this_object()->attack_object(victim);
  return (1);
}
