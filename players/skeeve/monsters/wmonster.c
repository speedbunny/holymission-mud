
/* wmonsters */
// Last Edit: Whisky, to change the call_out into a heart_beat

inherit "/obj/monster";

int t1,t2, count, delay;
int stay_land,stay_sea;

set_call_time (i1,i2) {
  int i;
  string s;
  t1 = i1;
  t2 = i2;
  if (sscanf(file_name(this_object()),"%s#%d",s,i)==2) 
  {
      set_heart_beat(1);
      count = t1 + random(t2);
      delay = 5;
  }
}

init()
{
   ::init();
   if (!delay && test_if_any_here())
   {
       delay = 5;
       set_heart_beat(1);
   }
}


reset(arg) {
  string s; 
  int i;
  ::reset(arg);
  if (!arg) {
    set_name("wmonster");
    set_short("A wandering monster");
    set_race("wmonster");
    set_gender(random(2)+1);
    set_level(3);
    set_al(0);
    set_sp(0);
    set_wc(5+random(4));
    set_ac(1);
    set_whimpy(-1); 
    set_size(2);
    stay_sea =0;
    stay_land=1;
  }
}

set_stay_sea(i)  { stay_sea = i; }
query_stay_sea() { return stay_sea; }

set_stay_land(i) { stay_land = i; }
query_stay_land(){ return stay_land;}

heart_beat()  
{
   if (count == 0)
   {
      random_move();
      count = t1 + random(t2);
      delay--;
   }
   if (!delay)
       set_heart_beat(0);
    ::heart_beat();
}
