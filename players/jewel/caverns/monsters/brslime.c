/* Coded by Jewel of Holy Mission  on 12Aug94 */
/* Heather Whelessh  whelessh@hamlet.uncg.edu */
/* revisions here please */
 
inherit "obj/monster";
 
void reset(int arg) 
{
  ::reset(arg);
 
  if (arg > 0) return;
  set_name("Brown Slime");
  set_alias("brown slime");
  set_race("slime");
  set_level(10);
  set_short("brown Slime");
  set_long("A huge gelatinous mass of brown gooey slime.\n" +
           "It is brown like the caves and totally surprised you!\n");
  set_aggressive(1);
  set_ac(9);
  set_wc(5);
  load_chat(25,
    ({
       "Brown Slime oozes all over you.\n",
       "Brown Slime emits a foul stench.\n",
       "Brown Slime drips residue.\n",
    }));
}
 

