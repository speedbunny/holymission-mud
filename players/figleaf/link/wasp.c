inherit "obj/monster";

void reset(int arg){

  ::reset(arg);
  if (arg)return;
    set_name("wasp");
    set_race("wasp");
    set_short("A giant wasp");
    set_long(
"This wasp is HUGE! It looks about three feet long with an evil stinger at one \
end.\n");
    set_level(20);
    set_hp(1500);
    set_wc(30);
    set_ac(11);     
    set_al(0);
    set_gender(0);
    set_aggressive(1);
}  
