/* Coded by Jewel of Holy Mission  on 12Aug94 */
/* Heather Whelessh  whelessh@hamlet.uncg.edu */
/* revisions here please */
 
inherit "obj/monster";
 
void reset(int arg) 
{
  ::reset(arg);
 
  if (arg > 0) return;
  set_name("Green Slime");
  set_alias("green slime");
  set_race("slime");
  set_level(5);
  set_short("green Slime");
  set_long("A huge gelatinous mass of green gooey slime.\n" +
           "It just oozed down off the wall onto you!\n");
  set_aggressive(1);
  set_ac(5);
  set_wc(5);
  load_chat(25,
    ({
       "Green Slime oozes all over you.\n",
       "Green Slime emits a foul stench.\n",
       
    }));
}
 

