inherit "obj/monster";
 
reset(){
::reset();
set_name("bear");
set_race("bear");
set_short("A bear");
set_ac(1);
set_wc(4);
set_alias("bear");
set_long("This stupid bear hits lots of times.\n");
set_level(4);
set_hp(80);
set_heart_beat(1);
}

heart_beat()
{
 int x;

 for (x = 0; x < 2; x++)
 {
  this_object()->attack();
 }
 ::heart_beat();
}



