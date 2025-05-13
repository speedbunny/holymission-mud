/* Coded by Jewel of Holy Mission  on 12Aug94 */
/* Heather Whelessh  whelessh@hamlet.uncg.edu */
/* revisions here please */
 
inherit "obj/monster";
 
void reset(int arg) 
{
  ::reset(arg);
 
  if (arg > 0) return;
  set_name("Black Slime");
  set_alias("black slime");
  set_race("slime");
  set_level(10);
  set_short("black Slime");
  set_long("A huge gelatinous mass of tar-black gooey slime.\n" +
           "It just oozed down off the wall onto you!\n");
  set_aggressive(1);
  set_ac(9);
  set_wc(5);
  load_chat(25,
    ({
       "Black Slime oozes all over you.\n",
       "Black Slime emits a foul stench.\n",
     "Black Slime leaves a streak of black goo all over you.\n",
    }));
}
 
