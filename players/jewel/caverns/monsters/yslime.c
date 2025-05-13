/* Coded by Jewel of Holy Mission  on 12Aug94 */
/* Heather Whelessh  whelessh@hamlet.uncg.edu */
/* revisions here please */
 
inherit "obj/monster";
 
void reset(int arg) 
{
  ::reset(arg);
 
  if (arg > 0) return;
  set_name("Yellow Slime");
  set_alias("yellow slime");
  set_race("slime");
  set_level(5);
  set_short("yellow Slime");
  set_long("A mucky mass of gelatinous yellow slime.\n" +
           "You have just stepped on it!\n");
  set_aggressive(0);
  set_ac(5);
  set_wc(5);
  load_chat(25,
    ({
       "Yellow Slime oozes all over you.\n",
       "Yellow Slime sticks to your shoes.\n",
       "Yellow Slime says: Ouch!  That hurt!\n",
    }));
}
 
